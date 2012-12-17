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

/*
 * android_main.cpp
 *
 *  Created on: 03-12-2012
 *      Author: Luke
 */

#include <jni.h>
#include <errno.h>

#include <android/log.h>
#include <android_native_app_glue.h>
#include <android/asset_manager.h>
#include <stdio.h>
#include "AndroidDevice.h"
#include "AssetManager.h"


struct android_app* _state;

using namespace PG;
AndroidDevice *device;

/**
 * Punkt wejœcia dla natywnej aplikacji Android
 * Korzysta z NativeActivity, wymaga systemy Android w wersji minimum 2.3
 * param state strutura z danymi przekazywanymi do aplikacji przez system
 */
void android_main(struct android_app* state)
{
	app_dummy();
	_state = state;

//	AAsset *a =  AssetManager::getInstance().getAssetFile("test.txt");
//	long size = AAsset_getLength(a);
//	GLchar *src = (GLchar *) malloc(sizeof(char) * size);
//	AAsset_read(a, (void *)src, size);
//	AssetManager::getInstance().closeAssetFile(a);
//	LOGI("File = %s", src );

	device = new AndroidDevice(state);
	device->init();
	device->appLoop();
}



