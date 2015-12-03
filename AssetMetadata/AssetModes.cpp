#include <string>
#include "AssetModes.h"

namespace Pipeline {
	namespace AssetModes {
		const char used = 6;
		const char count = 8;
		const char* names[count + 1] = {
			"",

			"label",
			"cached",
			"bounding_box",
			"proxy",
			"animation_rig",
			"render",

			"asset_mode_07",
			"asset_mode_08"
		};
		
		Enum getEnum(const char* name) { return Enum(indexOf(name, names, count)); }
		bool setName(const char* name, uint8* const value)
		{
			char index = indexOf(name, names, count);
			if (index) return true;
			return false;
		}
		std::string getName(const Enum& value) { return names[(uint8)value]; }
	}
}