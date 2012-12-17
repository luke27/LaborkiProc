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
