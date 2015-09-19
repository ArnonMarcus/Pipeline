#include <string>
#include <algorithm>
#include "base.h"

namespace Pipeline {
	char findStringArrayIndex(const char* str, const char* names[], const short& length)
	{
		std::string lowercase = str;
		std::transform(lowercase.begin(), lowercase.end(), lowercase.begin(), ::tolower);
		char i = 1;
		for (; i <= length; i++) if (!lowercase.compare(names[i])) return i;
		return 0;
	}
}