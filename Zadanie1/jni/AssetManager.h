/*
 * AssetManager.h
 *
 *  Created on: 10-12-2012
 *      Author: Luke
 */

#ifndef ASSETMANAGER_H_
#define ASSETMANAGER_H_


#include "Log.h"
#include <android/asset_manager.h>

namespace PG {

class AssetManager {
public:
	 ~AssetManager();
	 static AssetManager &getInstance();
	 AAsset *getAssetFile(const char * fileName);
	 void closeAssetFile(AAsset *destr);
private:
	 AssetManager();
	 AssetManager(const AssetManager &assetMng);
	 AssetManager &operator= (const AssetManager &asset);
	 AAssetManager *androidAssetManager;
};

} /* namespace PG */
#endif /* ASSETMANAGER_H_ */
