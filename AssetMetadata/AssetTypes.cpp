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
	}
}