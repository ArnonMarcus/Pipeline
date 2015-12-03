#include "CameraRoles.h"

namespace Pipeline {
	namespace CameraRoles {
		const char used = 3;
		const char count = 8;
		const char* names[count + 1] = {
			"",

			"render",
			"projection",
			"ui",

			"camera_role_04",
			"camera_role_05",
			"camera_role_06",
			"camera_role_07",
			"camera_role_08"
		};

		Enum getEnum(const char* name) { return Enum(static_cast<uint8>(powerOf2((indexOf(name, names, count))))); }
		bool setName(const char* name, uint8* const value)
		{
			const char index = indexOf(name, names, count);
			if (index)
			{
				*value |= static_cast<uint8>(powerOf2(index));
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
			for (; index != indices.end(); ++index) new_values |= static_cast<uint8>(powerOf2(*index));
			*value |= new_values;
			return true;
		}
		std::string getName(const Enum& value) { return names[log2(value)]; }
		std::vector<std::string> getNames(const uint8& value)
		{
			std::vector<std::string> result;
			uint8 bit = 1;
			for (char i = 1; i <= count; i++, bit <<= 1) if (value & bit) result.push_back(names[log2(bit) + 1]);
			return result;
		}
	};
}