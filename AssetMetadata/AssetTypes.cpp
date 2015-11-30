#include <string>
#include "AssetTypes.h"

namespace Pipeline {
	namespace AssetTypes {
		const char count = 6;
		const char* names[count + 1] = {
			"",
			"env",
			"envprop",
			"prop",
			"character",
			"vehicle",
			"effect"
		};
		
		Enum getEnum(const char* name) { return Enum(indexOf(name, names, count)); }
		std::string getName(const Enum& value) { return names[(uint8)value]; }
	}
}