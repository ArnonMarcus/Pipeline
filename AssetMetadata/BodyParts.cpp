#include "BodyParts.h"

namespace Pipeline {
	namespace BodyParts {
		const char used = 14;
		const char count = 32;
		const char* names[count + 1] = {
			"",

			"head",
			"neck",
			"torso",
			"ribcage",
			"pelvic",
			"leg",
			"ankle",
			"foot",
			"thumb",
			"hand",
			"arm",
			"palm",
			"finger",
			"indexfinger",

			"body_part_15",
			"body_part_16",
			"body_part_17",
			"body_part_18",
			"body_part_19",
			"body_part_20",
			"body_part_21",
			"body_part_22",
			"body_part_23",
			"body_part_24",
			"body_part_25",
			"body_part_26",
			"body_part_27",
			"body_part_28",
			"body_part_29",
			"body_part_30",
			"body_part_31",
			"body_part_32"
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
