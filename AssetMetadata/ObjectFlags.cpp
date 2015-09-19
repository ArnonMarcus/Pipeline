#include <string>
#include "ObjectFlags.h"

namespace Pipeline {
	namespace ObjectFlags {
		const char count = 8;
		const char* names[count + 1] = {
			"",
			"hidden",
			"frozen",
			"rend",
			"vis2cam",
			"vis2refl",
			"vis2refr",
			"alembic",
			"uniquegeo"
		};
		
		Enum getEnum(const char* name) { return Enum(findStringArrayIndex(name, names, count)); }
		std::string getName(const Enum& value) { return names[(uint8)value]; }
		std::string getString(const uint64* flags)
		{
			uint64 bit = 1;
			std::string flagString;
			for (int i = 1; i <= count; i++, bit <<= 1) if (*flags & bit)
			{
				flagString.append(names[i]);
				if (i < count) flagString.append(",");
			}
			return flagString;
		}
	};
}