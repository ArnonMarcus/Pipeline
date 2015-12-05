#ifndef ASSET_NAMES
#define ASSET_NAMES

#include "base.h"

namespace Pipeline {
	namespace AssetNames {
		std::string getAssetName(const uint64& productionID);
		void setAssetName(const uint64& productionID, const char* assetName);
	}
}

#endif