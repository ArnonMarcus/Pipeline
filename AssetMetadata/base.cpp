#include <string>
#include <algorithm>
#include "base.h"

namespace Pipeline {
	char indexOf(const char* str, const char* names[], const short& length)
	{
		std::string lowercase = str;
		std::transform(lowercase.begin(), lowercase.end(), lowercase.begin(), ::tolower);
		for (char i = 1; i <= length; i++) if (!lowercase.compare(names[i])) return i;
		return 0;
	}

	uint64 powerOf2(const uint8 value)
	{
		uint64 result = 1;
		result = result << value;
		return result;
	}

	uint8 log2(const uint64 value)
	{
		if (value == 0) return 0;
		uint8 i = 0;
		uint64 search = 1;
		for (; i <= 64; i++)
		{
			if (search == value) break;
			search = search << 1;
		}

		return i;
	}
}