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
