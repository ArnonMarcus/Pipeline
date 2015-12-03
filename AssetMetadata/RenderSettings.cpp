#include "RenderSettings.h"

namespace Pipeline {
	namespace RenderSettings {
		const char used = 4;
		const char count = 32;
		const char* names[count + 1] = {
			"",

			"renderable",
			"visible2camera",
			"visible2reflections",
			"visible2refractions",

			"render_setting_05",
			"render_setting_06",
			"render_setting_07",
			"render_setting_08",
			"render_setting_09",
			"render_setting_10",
			"render_setting_11",
			"render_setting_12",
			"render_setting_13",
			"render_setting_14",
			"render_setting_15",
			"render_setting_16",
			"render_setting_17",
			"render_setting_18",
			"render_setting_19",
			"render_setting_20",
			"render_setting_21",
			"render_setting_22",
			"render_setting_23",
			"render_setting_24",
			"render_setting_25",
			"render_setting_26",
			"render_setting_27",
			"render_setting_28",
			"render_setting_29",
			"render_setting_30",
			"render_setting_31",
			"render_setting_32"
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