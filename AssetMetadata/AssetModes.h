#ifndef ASSET_MODES
#define ASSET_MODES

#include "base.h"

namespace Pipeline {
	namespace AssetModes {
		enum Enum
		{
			kEmpty = 0x00,

			kLabel = 0x01,
			kCached = 0x02,
			kBoundingBox = 0x03,
			kProxy = 0x04,
			kAnimationRig = 0x05,
			kRender = 0x06
		};

		Enum getEnum(const char* name);
		bool setName(const char* name, uint8* const value);
		std::string getName(const Enum& value);
	}
}

#endif