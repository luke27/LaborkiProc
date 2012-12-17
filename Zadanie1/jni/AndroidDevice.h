/**
 * 2010-10-31
	2011-11-02 
	2012-02-24
 Łukasz Durlej
 */


#pragma once

#include "IDevice.h"
#include "IRenderer.h"
#include "Log.h"

#include <android_native_app_glue.h>

#include <EGL/egl.h>
#include <GLES2/gl2.h>

namespace PG
{
	/// struktura pomocnicza
	struct SavedState
	{
		float angle;
		int32_t x;
		int32_t y;
	};
	/// struktura pomocnicza
	struct Engine
	{
		android_app *app;
		int animating;
		EGLDisplay display;
		EGLSurface surface;
		EGLContext context;
		int32_t width;
		int32_t heigth;
		SavedState state;
	};

	
	/**
	 * klasa odpowiedzilna za komunikację z systemem Android
	 * tworzy za pomocą EGL kontekst rendererowania
	 */
	class AndroidDevice : public IDevice
	{
	public:
		/**
		 * Konstruktor
		 * @param struktura z danymi dostarczanymi przez system
		 */
		AndroidDevice(android_app *state);

		/// inicjalizacja
		void init();
		/// pętla
		void appLoop();
		/// inicjalizacja EGL
		void initEGLDisplayWindow();
		/// zniszczenie EGL
		void termEGLDisplayWindow();
		void drawFrame(); //patrz jeszcze wyżej
		void sendAndroidDevice(AInputEvent *event);
	private:
		/// zmienna z dannymi z systemu
		android_app *state;
		/// zminna pomocnicza
		Engine engine;
		/// przetwarzanie komend od systemu operacyjnego
		friend void androidHandleCmd(android_app *app, int32_t cmd);
		/// uchwyt zdarzeń
		friend int32_t androidHandleInput(android_app *app, AInputEvent *event);
		/// szerokość i wysokość ekranu
		int width, heigth;
		
		IRenderer *renderer;

	};
}
