#ifndef OBJECT_FLAGS
#define OBJECT_FLAGS

#include <string>
#include "base.h"

namespace Pipeline {
	namespace ObjectFlags {
		enum Enum
		{
			kEmpty = 0x00000000,
			kHidden = 0x00000001,
			kFrozen = 0x00000002,
			kRenderable = 0x00000004,
			kVisibleToCamera = 0x00000008,
			kVisibleToReflections = 0x00000010,
			kVisibleToRefractions = 0x00000020,
			kAlembic = 0x00000040,
			kUniqueGeomertry = 0x00000080
		};

		Enum getEnum(const char* name);
		std::string getName(const Enum& value);
		std::string getString(const uint64& flags);
	}
}

#endif