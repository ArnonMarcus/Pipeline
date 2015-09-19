#ifndef OBJECT_TYPES
#define OBJECT_TYPES

#include <string>
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
		std::string getName(const Enum& value);
	}
}

#endif