#ifndef OBJECT_TYPE_FLAGS
#define OBJECT_TYPE_FLAGS

#include <vector>
#include <string>
#include "base.h"

namespace Pipeline {
	namespace ObjectTypeFlags {
		using namespace Pipeline::bits::for_8bit;

		enum Enum
		{
			kEmpty = bit_00,

			kRoot = bit_01,
			kIK = bit_02,
			kFK = bit_03,
			kSkinned = bit_04,

			kObjectTypeFlag_05 = bit_05,
			kObjectTypeFlag_06 = bit_06,
			kObjectTypeFlag_07 = bit_07,
			kObjectTypeFlag_08 = bit_08
		};

		Enum getEnum(const char* name);
		bool setName(const char* name, uint8* const value);
		bool setNames(std::vector<std::string>& new_names, uint8* const value);
		std::string getName(const Enum& value);
		std::vector<std::string> getNames(const uint8& value);
	}
}

#endif