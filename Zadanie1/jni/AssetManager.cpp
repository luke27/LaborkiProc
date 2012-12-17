/*
 * AssetManager.cpp
 *
 *  Created on: 10-12-2012
 *      Author: Luke
 */

#include "AssetManager.h"
#include <android_native_app_glue.h>

extern struct android_app *_state;
namespace PG {



AssetManager::AssetManager()
{
	androidAssetManager = NULL;
	androidAssetManager = _state->activity->assetManager;
}

AssetManager::AssetManager(const AssetManager &assetMng)
{
	androidAssetManager = NULL;
}

AssetManager &AssetManager::operator= (const AssetManager &asset)
{
	return *this;
}

AssetManager::~AssetManager() {
	// TODO Auto-generated destructor stub
}


AssetManager &AssetManager::getInstance()
{
	static AssetManager instance;
	return instance;
}


AAsset *AssetManager::getAssetFile(const char *fileName)
{
	AAsset *asset = AAssetManager_open(androidAssetManager, fileName, AASSET_MODE_STREAMING);
	if(!asset)
	{
		LOGE("Error when opening file = %s", fileName);
	}
	else
		LOGI("File was opening : %s", fileName);
	return asset;
}

void AssetManager::closeAssetFile(AAsset *destr)
{
	if(!destr)
		AAsset_close(destr);
}

} /* namespace PG */
