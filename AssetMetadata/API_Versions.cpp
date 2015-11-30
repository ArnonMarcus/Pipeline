#include <string>
#include "API_Versions.h"

namespace Pipeline {
	namespace API_Versions {
		const char count = 3;
		const char* names[count + 1] = {
			"",
			"prealpha",
			"alpha1",
			"alpha2"
		};

		Enum getEnum(const char* name) { return Enum(indexOf(name, names, count)); }
		std::string getName(const Enum& value) { return names[(uint8)value]; }
	}
}