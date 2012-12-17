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
 * Punkt wej�cia dla natywnej aplikacji Android
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



