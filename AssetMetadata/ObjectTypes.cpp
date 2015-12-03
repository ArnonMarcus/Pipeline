#include <string>
#include "ObjectTypes.h"

namespace Pipeline {
	namespace ObjectTypes {
		const char used = 4;
		const char count = 8;
		const char* names[count + 1] = {
			"",

			"geometry",
			"rig",
			"camera",
			"light",

			"object_type_05",
			"object_type_06",
			"object_type_07",
			"object_type_08"
		};

		Enum getEnum(const char* name) { return Enum(indexOf(name, names, count)); }
		bool setName(const char* name, uint8* const value)
		{
			char index = indexOf(name, names, count);
			if (index) return true;
			return false;
		}
		std::string getName(const Enum& value) { return names[(uint8)value]; }
	};	
}