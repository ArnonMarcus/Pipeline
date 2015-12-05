#include "FacialParts.h"

namespace Pipeline {
	namespace FacialParts {
		const char used = 12;
		const char count = 32;

		const char* names[count + 1] = {
			"",

			"forehead",
			"ear",
			"eye",
			"eyebrow",
			"eyelashes",
			"nose",
			"mouth",
			"lip",
			"teeth",
			"tong",
			"cheek",
			"chin",

			"facial_part_13",
			"facial_part_14",
			"facial_part_15",
			"facial_part_16",
			"facial_part_17",
			"facial_part_18",
			"facial_part_19",
			"facial_part_20",
			"facial_part_21",
			"facial_part_22",
			"facial_part_23",
			"facial_part_24",
			"facial_part_25",
			"facial_part_26",
			"facial_part_27",
			"facial_part_28",
			"facial_part_29",
			"facial_part_30",
			"facial_part_31",
			"facial_part_32"
		};

		Enum getEnum(const char* name) { return Enum(static_cast<uint32>(indexToValue((indexOf(name, names, count))))); }
		bool setName(const char* name, uint32* const value)
		{
			const char index = indexOf(name, names, count);
			if (index)
			{
				*value |= static_cast<uint32>(indexToValue(index));
				return true;
			}
			return false;
		}
		bool setNames(std::vector<std::string>& new_names, uint32* const value)
		{
			std::vector<char> indices;
			for (std::vector<std::string>::iterator name = new_names.begin(); name != new_names.end(); ++name)
			{
				const char index = indexOf(name->c_str(), names, count);
				if (index) indices.push_back(index);
			}

			if (indices.size() != new_names.size()) return false;

			uint32 new_values = 0;
			std::vector<char>::iterator index = indices.begin();
			for (; index != indices.end(); ++index) new_values |= static_cast<uint32>(indexToValue(*index));
			*value |= new_values;
			return true;
		}
		std::string getName(const Enum& value) { return names[valueToIndex(value)]; }
		std::vector<std::string> getNames(const uint32& value)
		{
			std::vector<std::string> result;
			uint32 bit = 1;
			for (char i = 1; i <= count; i++, bit <<= 1) if (value & bit) result.push_back(names[valueToIndex(bit)]);
			return result;
		}
	};
}