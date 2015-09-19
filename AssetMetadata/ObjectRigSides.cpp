#include <string>
#include "ObjectRigSides.h"

namespace Pipeline {
	namespace ObjectRigSides {
		const char count = 10;
		const char* names[count + 1] = {
			"",
			"center",
			"right",
			"left",
			"upper",
			"lower",
			"top",
			"alembic",
			"bottom",
			"inner",
			"outer"
		};

		Enum getEnum(const char* name) { return Enum(findStringArrayIndex(name, names, count)); }
		std::string getName(const Enum& value) { return names[value]; }
	};
}