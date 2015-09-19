#include <string>
#include "ObjectRigParts.h"

namespace Pipeline {
	namespace ObjectRigParts {
		const char count = 40;
		const char* names[count + 1] = {
			"",

			// Facial Center:
			"forehead",
			"ears",
			"eyes",
			"eyebrows",
			"eyelashes",
			"nose",
			"mouth",
			"lips",
			"upperlip",
			"lowerlip",
			"upperteeth",
			"lowerteeth",
			"tong",
			"chin",

			// Facial Sided:
			"ear",
			"eye",
			"eyebrow",
			"lowereyelashes",
			"uppereyelashes",
			"cheek",

			// Body Center:
			"head",
			"neck",
			"torso",
			"hands",
			"arms",
			"palms",
			"legs",
			"feet",
			"ankle",
			"ribcage",
			"pelvic",

			// Body Sided:
			"hand",
			"arm",
			"palm",
			"fingers",
			"indexfinger",
			"leg",
			"foot",
			"ankle",
			"thumbs"
		};

		Enum getEnum(const char* name) { return Enum(findStringArrayIndex(name, names, count)); }
		std::string getName(const Enum& value) { return names[(uint8)value]; }
	};
}