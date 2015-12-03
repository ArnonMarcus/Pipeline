#ifndef LIGHT_ROLES
#define LIGHT_ROLES

#include <vector>
#include <string>
#include "base.h"

namespace Pipeline {
	namespace LightRoles {
		using namespace Pipeline::bits::for_8bit;

		enum Enum
		{
			kEmpty = bit_00,

			kKey = bit_01,
			kFill = bit_02,
			kRim = bit_03,
			kGI = bit_04,

			kLightRole_05 = bit_05,
			kLightRole_06 = bit_06,
			kLightRole_07 = bit_07,
			kLightRole_08 = bit_08
		};

		Enum getEnum(const char* name);
		bool setName(const char* name, uint8* const value);
		bool setNames(std::vector<std::string>& new_names, uint8* const value);
		std::string getName(const Enum& value);
		std::vector<std::string> getNames(const uint8& value);
	}
}

#endif