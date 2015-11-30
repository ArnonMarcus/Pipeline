#include <string>
#include "ObjectTypes.h"

namespace Pipeline {
	namespace ObjectTypes {
		const char count = 4;
		const char* names[count + 1] = {
			"",

			"geometry",
			"rig",
			"camera",
			"light"
		};

		Enum getEnum(const char* name) { return Enum(indexOf(name, names, count)); }
		std::string getName(const Enum& value) { return names[(uint8)value]; }
	};
}