#include "CustomFlags.h"

namespace Pipeline {
	namespace CustomFlags {
		const char count = 64;
		const char* names[count + 1] = {
			"",

			"custom_flag_01",
			"custom_flag_02",
			"custom_flag_03",
			"custom_flag_04",
			"custom_flag_05",
			"custom_flag_06",
			"custom_flag_07",
			"custom_flag_08",
			"custom_flag_09",
			"custom_flag_10",
			"custom_flag_11",
			"custom_flag_12",
			"custom_flag_13",
			"custom_flag_14",
			"custom_flag_15",
			"custom_flag_16",
			"custom_flag_17",
			"custom_flag_18",
			"custom_flag_19",
			"custom_flag_20",
			"custom_flag_21",
			"custom_flag_22",
			"custom_flag_23",
			"custom_flag_24",
			"custom_flag_25",
			"custom_flag_26",
			"custom_flag_27",
			"custom_flag_28",
			"custom_flag_29",
			"custom_flag_30",
			"custom_flag_31",
			"custom_flag_32",
			"custom_flag_33",
			"custom_flag_34",
			"custom_flag_35",
			"custom_flag_36",
			"custom_flag_37",
			"custom_flag_38",
			"custom_flag_39",
			"custom_flag_40",
			"custom_flag_41",
			"custom_flag_42",
			"custom_flag_43",
			"custom_flag_44",
			"custom_flag_45",
			"custom_flag_46",
			"custom_flag_47",
			"custom_flag_48",
			"custom_flag_49",
			"custom_flag_40",
			"custom_flag_51",
			"custom_flag_52",
			"custom_flag_53",
			"custom_flag_54",
			"custom_flag_55",
			"custom_flag_56",
			"custom_flag_57",
			"custom_flag_58",
			"custom_flag_59",
			"custom_flag_60",
			"custom_flag_61",
			"custom_flag_62",
			"custom_flag_63",
			"custom_flag_64"
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