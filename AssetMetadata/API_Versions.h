#ifndef API_VERSIONS
#define API_VERSIONS

#include "base.h"

namespace Pipeline {
	namespace API_Versions {
		enum Enum
		{
			kEmpty = 0x00,
			kPreAlpha = 0x01,
			kAlpha1 = 0x02,
			kAlpha2 = 0x03
		};

		Enum getEnum(const char* name);
		std::string getName(const Enum& value);
	}
}

#endif