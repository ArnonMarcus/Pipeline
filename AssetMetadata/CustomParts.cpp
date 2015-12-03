#include "CustomParts.h"

namespace Pipeline {
	namespace CustomParts {
		const char count = 64;
		const char* names[count + 1] = {
			"",

			"custom_part_01",
			"custom_part_02",
			"custom_part_03",
			"custom_part_04",
			"custom_part_05",
			"custom_part_06",
			"custom_part_07",
			"custom_part_08",
			"custom_part_09",
			"custom_part_10",
			"custom_part_11",
			"custom_part_12",
			"custom_part_13",
			"custom_part_14",
			"custom_part_15",
			"custom_part_16",
			"custom_part_17",
			"custom_part_18",
			"custom_part_19",
			"custom_part_20",
			"custom_part_21",
			"custom_part_22",
			"custom_part_23",
			"custom_part_24",
			"custom_part_25",
			"custom_part_26",
			"custom_part_27",
			"custom_part_28",
			"custom_part_29",
			"custom_part_30",
			"custom_part_31",
			"custom_part_32",
			"custom_part_33",
			"custom_part_34",
			"custom_part_35",
			"custom_part_36",
			"custom_part_37",
			"custom_part_38",
			"custom_part_39",
			"custom_part_40",
			"custom_part_41",
			"custom_part_42",
			"custom_part_43",
			"custom_part_44",
			"custom_part_45",
			"custom_part_46",
			"custom_part_47",
			"custom_part_48",
			"custom_part_49",
			"custom_part_40",
			"custom_part_51",
			"custom_part_52",
			"custom_part_53",
			"custom_part_54",
			"custom_part_55",
			"custom_part_56",
			"custom_part_57",
			"custom_part_58",
			"custom_part_59",
			"custom_part_60",
			"custom_part_61",
			"custom_part_62",
			"custom_part_63",
			"custom_part_64"
		};

		Enum getEnum(const char* name) { return Enum(static_cast<uint64>(powerOf2((indexOf(name, names, count))))); }
		bool setName(const char* name, uint64* const value)
		{
			const char index = indexOf(name, names, count);
			if (index)
			{
				*value |= static_cast<uint64>(powerOf2(index));
				return true;
			}
			return false;
		}
		bool setNames(std::vector<std::string>& new_names, uint64* const value)
		{
			std::vector<char> indices;
			for (std::vector<std::string>::iterator name = new_names.begin(); name != new_names.end(); ++name)
			{
				const char index = indexOf(name->c_str(), names, count);
				if (index) indices.push_back(index);
			}

			if (indices.size() != new_names.size()) return false;

			uint64 new_values = 0;
			std::vector<char>::iterator index = indices.begin();
			for (; index != indices.end(); ++index) new_values |= static_cast<uint64>(powerOf2(*index));
			*value |= new_values;
			return true;
		}
		std::string getName(const Enum& value) { return names[log2(value)]; }
		std::vector<std::string> getNames(const uint64& value)
		{
			std::vector<std::string> result;
			uint64 bit = 1;
			for (char i = 1; i <= count; i++, bit <<= 1) if (value & bit) result.push_back(names[log2(bit) + 1]);
			return result;
		}
	};
}