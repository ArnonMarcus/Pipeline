#include "PartSides.h"

namespace Pipeline {
	namespace PartSides {
		const char count = 8;
		const char* names[count + 1] = {
			"center",

			"right",
			"left",
			"upper",
			"lower",
			"top",
			"bottom",
			"inner",
			"outer"
		};

		Enum getEnum(const char* name) { return Enum(static_cast<uint8>(indexToValue((indexOf(name, names, count))))); }
		bool setName(const char* name, uint8* const value)
		{
			const char index = indexOf(name, names, count);
			if (index)
			{
				*value |= static_cast<uint8>(indexToValue(index));
				return true;
			}
			return false;
		}
		bool setNames(std::vector<std::string>& new_names, uint8* const value)
		{
			std::vector<char> indices;
			for (std::vector<std::string>::iterator name = new_names.begin(); name != new_names.end(); ++name)
			{
				const char index = indexOf(name->c_str(), names, count);
				if (index) indices.push_back(index);
			}

			if (indices.size() != new_names.size()) return false;

			uint8 new_values = 0;
			std::vector<char>::iterator index = indices.begin();
			for (; index != indices.end(); ++index) new_values |= static_cast<uint8>(indexToValue(*index));
			*value |= new_values;
			return true;
		}
		std::string getName(const Enum& value) { return names[valueToIndex(value)]; }
		std::vector<std::string> getNames(const uint8& value)
		{
			std::vector<std::string> result;
			uint8 bit = 1;
			for (char i = 1; i <= count; i++, bit <<= 1) if (value & bit) result.push_back(names[valueToIndex(bit)]);
			return result;
		}
	};
}