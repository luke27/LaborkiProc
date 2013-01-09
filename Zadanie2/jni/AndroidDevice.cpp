/**
 *
    Copyright (C) 2012 Łukasz Durlej

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <jni.h>
#include <android\window.h>
#include <android/log.h>
#include "AndroidDevice.h"
#include "Zad1Rend.h"

using namespace PG;

inline void maxAllocTest()
{
	void *p = NULL;
	int b = 1;
	do
	{
		p = (void *)malloc(b);
		//LOGI("MB = %d", b / 1024 / 1024);
		free(p);
		b++;
	}
	while(p != NULL);
	LOGI("MAX = %d", b / 1024 / 1024);
}





AndroidDevice *_androidDevice;

void androidHandleCmd(android_app *app, int32_t cmd);
int32_t androidHandleInput(android_app *app, AInputEvent *event);

AndroidDevice::AndroidDevice(android_app *state)
{
	heigth = width = 0;
	this->state = state;
	renderer = NULL;
}

void AndroidDevice::init()
{
	LOGI("Android inicjalizacja");
	memset(&engine, 0, sizeof(engine));
	state->userData = &engine;
	state->onAppCmd = androidHandleCmd;
	state->onInputEvent = androidHandleInput;
	engine.app = state;

	//rozpoczęcie od poprzedniego stanu aplikcaji
	if(state->savedState != NULL)
		engine.state = *(SavedState *)state->savedState;

	_androidDevice = this;
	LOGI("Android::init end");
}

void AndroidDevice::appLoop()
{

	//pętla aplikacji
	while(1)
	{
		//zdarzenia
		int ident;
		int events;
		android_poll_source *source;

		while((ident=ALooper_pollAll(engine.animating ? 0 : -1, NULL, &events, (void**)&source)) >= 0)
		{
			//przetwórz to zdarzenie
			if(source != NULL)
				source->process(state, source);

			//jeśli sensor posiada jakie kolwiek dane przetwórz go
			if(ident == LOOPER_ID_USER)
			{

			}

			//spradzenie czy Dalvik pozwala jeszcze żyć aplikacji
			if(state->destroyRequested != 0)
				//funkcja zamykająca aplikację;
				termEGLDisplayWindow();
		}

		if(engine.animating)
		{
			//rysowanie klatki
			engine.state.angle += .01f;
			if(engine.state.angle > 1)
				engine.state.angle = 0;

			drawFrame();
		}
	}
}


void AndroidDevice::initEGLDisplayWindow()
{
	const EGLint attribs[] = 
		{
            EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
            EGL_BLUE_SIZE, 8,
            EGL_GREEN_SIZE, 8,
            EGL_RED_SIZE, 8,
            EGL_DEPTH_SIZE, 16,
            EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,
            EGL_NONE
		};
	EGLint w, h, dummy, format;
    EGLint numConfigs;
    EGLConfig config;
    EGLSurface surface;
    EGLContext context;

	EGLDisplay display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
	eglInitialize(display, 0, 0);



	eglChooseConfig(display, attribs, &config, 1, &numConfigs);
	eglGetConfigAttrib(display, config, EGL_NATIVE_VISUAL_ID, &format);

	ANativeWindow_setBuffersGeometry(engine.app->window, 0, 0, format);

	surface = eglCreateWindowSurface(display, config, engine.app->window, NULL);

	EGLint configAttrs[] =
		{
    		EGL_CONTEXT_CLIENT_VERSION,
    		2,
    		EGL_NONE
		};

	context = eglCreateContext(display, config, NULL, configAttrs);
	if(eglMakeCurrent(display, surface, surface, context) == EGL_FALSE)


	eglQuerySurface(display, surface, EGL_WIDTH, &w);
	width = w;
	eglQuerySurface(display, surface, EGL_HEIGHT, &h);
	heigth = h;

	engine.display = display;
	engine.context = context;
	engine.surface = surface;
	engine.width = w;
	engine.heigth = h;
	engine.state.angle = 0;

	//stan OpenGL
	//glEnable(GL_CULL_FACE);
	//TODO: miejsce na rysowanie
	
	LOGI("initEGL end");
}

void AndroidDevice::termEGLDisplayWindow()
{
	if(renderer != NULL)
		delete renderer;
	if(engine.display != EGL_NO_DISPLAY)
	{
		eglMakeCurrent(engine.display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
		if(engine.context != EGL_NO_CONTEXT)
			eglDestroyContext(engine.display, engine.context);
		if(engine.surface != EGL_NO_SURFACE)
			eglDestroySurface(engine.display, engine.surface);
		eglTerminate(engine.display);
	}
	engine.animating = 0;
	engine.display = EGL_NO_DISPLAY;
	engine.context = EGL_NO_CONTEXT;
	engine.surface = EGL_NO_SURFACE;
}


void AndroidDevice::drawFrame()
{
	if(engine.display == NULL)
		//nic do rysowania
		return;


	//wywołanbie renderera
	LOGV("Renderer calls");
	glClearColor(1.0f, 1.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable( GL_DEPTH_TEST );
	glEnable( GL_CULL_FACE );

	if(renderer == NULL)
		renderer = new Zad1Rend();
	renderer->render();
	
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);
	eglSwapBuffers(engine.display, engine.surface);

}

void androidHandleCmd(android_app *app, int32_t cmd)
	{
		Engine *engine = (Engine *)app->userData;
		switch(cmd)
		{
			//zapisanie stanu aplikacji
		case APP_CMD_SAVE_STATE:
			engine->app->savedState = malloc(sizeof(SavedState));
			*((SavedState *)engine->app->savedState) = engine->state;
			engine->app->savedStateSize = sizeof(SavedState);
			break;
			//inicjalizacja okna
		case APP_CMD_INIT_WINDOW:
			//jeśli nie ma okna stowrzyć je
			if(engine->app->window != NULL)
			{
				_androidDevice->initEGLDisplayWindow();
				_androidDevice->drawFrame();
			}
			break;
			//zamknięcie okna
		case APP_CMD_TERM_WINDOW:
			//funkcja niszcząca okno
			_androidDevice->termEGLDisplayWindow();
			break;
			//zdarzenie
		case APP_CMD_GAINED_FOCUS:

			break;
		case APP_CMD_LOST_FOCUS:


			//zatrzymanie animacji
			engine->animating = 0;
			_androidDevice->drawFrame();
			break;
		}
	}

int32_t androidHandleInput(android_app *app, AInputEvent *event)
{
	Engine *engine = (Engine *)app->userData;
	if(AInputEvent_getType(event) == AINPUT_EVENT_TYPE_MOTION)
	{
		engine->animating = 1;
		engine->state.x = AMotionEvent_getX(event, 0);
		engine->state.y = AMotionEvent_getY(event, 0);
		_androidDevice->sendAndroidDevice(event);

		LOGI("X = %d Y = %d", engine->state.x, engine->state.y);
		return 1;
	}
	return 0;
}

///przekazuje gdzie informację, że zaszedł input
inline void AndroidDevice::sendAndroidDevice(AInputEvent *event)
{

}


