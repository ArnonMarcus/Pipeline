#include "BodyParts.h"

namespace Pipeline {
	namespace BodyParts {
		const char count = 14;
		const char* names[count + 1] = {
			"",
			"head",
			"neck",
			"torso",
			"ribcage",
			"pelvic",
			"leg",
			"ankle",
			"foot",
			"thumb",
			"hand",
			"arm",
			"palm",
			"finger",
			"indexfinger"
		};

		Enum getEnum(const char* name) { return Enum(static_cast<uint32>(powerOf2((indexOf(name, names, count))))); }
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
