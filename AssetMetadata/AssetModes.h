#ifndef ASSET_MODES
#define ASSET_MODES

#include <string>
#include "base.h"

namespace Pipeline {
	namespace AssetModes {
		using namespace Pipeline::bits::for_8bit;

		enum Enum
		{
			kEmpty = bit_00,

			kLabel = bit_01,
			kCached = bit_02,
			kBoundingBox = bit_03,
			kProxy = bit_04,
			kAnimationRig = bit_05,
			kRender = bit_06,

			kAssetMode_07 = bit_07,
			kAssetMode_08 = bit_08
		};

		Enum getEnum(const char* name);
		bool setName(const char* name, uint8* const value);
		std::string getName(const Enum& value);
	}
}

#endif