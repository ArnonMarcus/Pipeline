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

	uint64 indexToValue(const uint8 value)
	{
		if (value == 0 || value == 1) return (uint64)value;
		uint64 result = 1;
		result = result << (value - 1);
		return result;
	}

	uint8 valueToIndex(const uint64 value)
	{
		if (value == 0 || value == 1) return (uint8)value;
		uint8 i = 1;
		uint64 search = 1;
		for (; i <= 64; i++)
		{
			if (search == value) break;
			search = search << 1;
		}

		return i;
	}

	std::string csv(std::vector<std::string> names)
	{
		std::string result;
		for (std::vector<std::string>::iterator name = names.begin(); name != names.end(); ++name)
			result += ((name + 1) == names.end()) ? *name : (*name + ",");
		return result;
	}
}