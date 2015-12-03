#ifndef OBJECT_TYPES
#define OBJECT_TYPES

#include <string>
#include "base.h"

namespace Pipeline {
	namespace ObjectTypes {
		using namespace Pipeline::bits::for_8bit;

		enum Enum
		{
			kEmpty = bit_00,

			kGeometry = bit_01,
			kRig = bit_02,
			kCamera = bit_03,
			kLight = bit_04,

			kObjectType_05 = bit_05,
			kObjectType_06 = bit_06,
			kObjectType_07 = bit_07,
			kObjectType_08 = bit_08
		};

		Enum getEnum(const char* name);
		bool setName(const char* name, uint8* const value);
		std::string getName(const Enum& value);
	}
}

#endif