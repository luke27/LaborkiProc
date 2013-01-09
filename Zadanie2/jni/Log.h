/**
 *
    Copyright (C) 2012 £ukasz Durlej

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

#ifndef LOG_H_
#define LOG_H_

#include <GLES2/gl2.h>
#include <android/log.h>
/// makra wyœwietlaj¹ce komunikoaty widocze w DDMS
#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, "UJ", __VA_ARGS__))
#define LOGW(...) ((void)__android_log_print(ANDROID_LOG_WARN, "UJ warning", __VA_ARGS__))
#define LOGE(...) ((void)__android_log_print(ANDROID_LOG_ERROR, "UJ error", __VA_ARGS__))
#define LOGV(...) ((void)__android_log_print(ANDROID_LOG_VERBOSE, "UJ verbose", __VA_ARGS__))
#define LOGD(...) ((void)__android_log_print(ANDROID_LOG_DEFAULT, "UJ default", __VA_ARGS__))


/**
 * sprawdzenie czy dane wyo³anie OpenGL zwraca b³¹d
 * w przypadku b³edu wyœwietla odpowiedni komunikat W DDMS
 * @param funcName nazwa funkcji OpenGL ES 2.0
 */
inline void glesError(const char *funcName )
{
	GLenum err = glGetError();
	while(err != GL_NO_ERROR)
	{
		LOGE("OpenGL error %s  %d", funcName, err);
		switch(err)
		{
		case GL_INVALID_ENUM:
			LOGE("Enum argument out of range");
			break;
		case GL_INVALID_FRAMEBUFFER_OPERATION:
			LOGE("Framebuffer is incoplete");
			break;
		case GL_INVALID_VALUE:
			LOGE("Numeric argument out of range");
			break;
		case GL_INVALID_OPERATION:
			LOGE("Operation illegal in current state");
			break;
		case GL_OUT_OF_MEMORY:
			LOGE("No enough memory execute command");
			break;
		}
		err = glGetError();
	}
	if(err == GL_NO_ERROR)
		LOGV("No error %s", funcName);
}

#endif /* LOG_H_ */
