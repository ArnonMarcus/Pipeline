#ifndef OBJECT_RIG_SIDES
#define OBJECT_RIG_SIDES

#include <string>
#include "base.h"

namespace Pipeline {
	namespace ObjectRigSides {
		enum Enum
		{
			kEmpty = 0x00,
			kCenter = 0x01,
			kRight = 0x02,
			kLeft = 0x03,
			kUpper = 0x04,
			kLower = 0x05,
			kTop = 0x06,
			kBottom = 0x07,
			kInner = 0x08,
			kOuter = 0x09
		};

		Enum getEnum(const char* name);
		std::string getName(const Enum& value);
	}
}

#endif