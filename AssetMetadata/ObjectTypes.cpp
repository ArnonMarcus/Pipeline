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
		bool setName(const char* name, uint8* const value)
		{
			char index = indexOf(name, names, count);
			if (index)
			{
				*value = index;
				return true;
			}
			return false;
		}
		std::string getName(const Enum& value) { return names[(uint8)value]; }
	};	
}