#include "RenderSettings.h"

namespace Pipeline {
	namespace RenderSettings {
		const char count = 4;
		const char* names[count + 1] = {
			"",

			"renderable",
			"visible2camera",
			"visible2reflections",
			"visible2refractions"
		};

		Enum getEnum(const char* name) { return Enum(powerOf2(indexOf(name, names, count))); }
		std::string getName(const Enum& value) { return names[log2(value)]; }
		std::vector<std::string> getNames(const uint32& value)
		{
			std::vector<std::string> result;
			uint32 bit = 1;
			for (char i = 1; i <= count; i++, bit <<= 1) if (value & bit) result.push_back(names[log2(bit) + 1]);
			return result;
		}
	};
}