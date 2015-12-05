#ifndef ASSET_TYPES
#define ASSET_TYPES

#include "base.h"

namespace Pipeline {
	namespace AssetTypes {
		enum Enum
		{
			kEmpty = 0x00,

			kEnvironment = 0x01,
			kEnvironmentProp = 0x02,
			kProp = 0x03,
			kCharacter = 0x04,
			kVehicle = 0x05,
			kEffect = 0x06
		};

		Enum getEnum(const char* name);
		bool setName(const char* name, uint8* const value);
		std::string getName(const Enum& value);
	}
}

#endif