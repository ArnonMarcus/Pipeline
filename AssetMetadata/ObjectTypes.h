#ifndef OBJECT_TYPES
#define OBJECT_TYPES

#include "base.h"

namespace Pipeline {
	namespace ObjectTypes {
		enum Enum
		{
			kEmpty = 0x00,

			kGeometry = 0x01,
			kRig = 0x02,
			kCamera = 0x03,
			kLight = 0x04
		};

		Enum getEnum(const char* name);
		bool setName(const char* name, uint8* const value);
		std::string getName(const Enum& value);
	}
}

#endif