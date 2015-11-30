#include <string>
#include <map>

#include "AssetNames.h"

namespace Pipeline {
	namespace AssetNames {
		std::map<const uint64, std::string> assetNames;
		std::string getAssetName(const uint64& assetProductionID) { return assetNames.at(assetProductionID); }
		void setAssetName(const uint64& assetProductionID, const char* assetName) { assetNames.at(assetProductionID) = assetName; }
	}
}