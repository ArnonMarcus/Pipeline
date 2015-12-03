#ifndef ASSET_TYPES
#define ASSET_TYPES

#include <string>
#include "base.h"

namespace Pipeline {
	namespace AssetTypes {
		using namespace Pipeline::bits::for_8bit;

		enum Enum
		{
			kEmpty = bit_00,

			kEnvironment = bit_01,
			kEnvironmentProp = bit_02,
			kProp = bit_03,
			kCharacter = bit_04,
			kVehicle = bit_05,
			kEffect = bit_06,

			kAssetType_07 = bit_07,
			kAssetType_08 = bit_08
		};

		Enum getEnum(const char* name);
		bool setName(const char* name, uint8* const value);
		std::string getName(const Enum& value);
	}
}

#endif