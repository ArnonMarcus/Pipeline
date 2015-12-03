#include "ViewportSettings.h"

namespace Pipeline {
	namespace ViewportSettings {
		const char used = 3;
		const char count = 32;
		const char* names[count + 1] = {
			"",

			"hidden",
			"template",
			"locked"

			"viewport_setting_04",
			"viewport_setting_05",
			"viewport_setting_06",
			"viewport_setting_07",
			"viewport_setting_08",
			"viewport_setting_09",
			"viewport_setting_10",
			"viewport_setting_11",
			"viewport_setting_12",
			"viewport_setting_13",
			"viewport_setting_14",
			"viewport_setting_15",
			"viewport_setting_16",
			"viewport_setting_17",
			"viewport_setting_18",
			"viewport_setting_19",
			"viewport_setting_20",
			"viewport_setting_21",
			"viewport_setting_22",
			"viewport_setting_23",
			"viewport_setting_24",
			"viewport_setting_25",
			"viewport_setting_26",
			"viewport_setting_27",
			"viewport_setting_28",
			"viewport_setting_29",
			"viewport_setting_30",
			"viewport_setting_31",
			"viewport_setting_32"
		};

		Enum getEnum(const char* name) { return Enum(static_cast<uint32>(powerOf2((indexOf(name, names, count))))); }
		bool setName(const char* name, uint32* const value)
		{
			const char index = indexOf(name, names, count);
			if (index)
			{
				*value |= static_cast<uint32>(powerOf2(index));
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
			for (; index != indices.end(); ++index) new_values |= static_cast<uint32>(powerOf2(*index));
			*value |= new_values;
			return true;
		}
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