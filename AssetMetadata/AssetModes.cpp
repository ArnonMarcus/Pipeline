#include <string>
#include "AssetModes.h"

namespace Pipeline {
	namespace AssetModes {
		const char count = 6;
		const char* names[count + 1] = {
			"",
			"label",
			"cached",
			"bbox",
			"proxy",
			"animrig",
			"shaded"
		};
		
		Enum getEnum(const char* name) { return Enum(findStringArrayIndex(name, names, count)); }
		std::string getName(const Enum& value) { return names[(uint8)value]; }
	}
}