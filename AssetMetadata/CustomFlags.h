#ifndef CUSTOM_FLAGS
#define CUSTOM_FLAGS

#include <vector>
#include <string>
#include "base.h"

namespace Pipeline {
	namespace CustomFlags {
		using namespace Pipeline::bits::for_64bit;

		enum Enum
		{
			kEmpty = bit_00,
			kCustomFlag_01 = bit_01,
			kCustomFlag_02 = bit_02,
			kCustomFlag_03 = bit_03,
			kCustomFlag_04 = bit_04,
			kCustomFlag_05 = bit_05,
			kCustomFlag_06 = bit_06,
			kCustomFlag_07 = bit_07,
			kCustomFlag_08 = bit_08,
			kCustomFlag_09 = bit_09,
			kCustomFlag_10 = bit_10,
			kCustomFlag_11 = bit_11,
			kCustomFlag_12 = bit_12,
			kCustomFlag_13 = bit_13,
			kCustomFlag_14 = bit_14,
			kCustomFlag_15 = bit_15,
			kCustomFlag_16 = bit_16,
			kCustomFlag_17 = bit_17,
			kCustomFlag_18 = bit_18,
			kCustomFlag_19 = bit_19,
			kCustomFlag_20 = bit_20,
			kCustomFlag_21 = bit_21,
			kCustomFlag_22 = bit_22,
			kCustomFlag_23 = bit_23,
			kCustomFlag_24 = bit_24,
			kCustomFlag_25 = bit_25,
			kCustomFlag_26 = bit_26,
			kCustomFlag_27 = bit_27,
			kCustomFlag_28 = bit_28,
			kCustomFlag_29 = bit_29,
			kCustomFlag_30 = bit_30,
			kCustomFlag_31 = bit_31
			//kCustomFlag_32 = bit_32,
			//kCustomFlag_33 = bit_33,
			//kCustomFlag_34 = bit_34,
			//kCustomFlag_35 = bit_35,
			//kCustomFlag_36 = bit_36,
			//kCustomFlag_37 = bit_37,
			//kCustomFlag_38 = bit_38,
			//kCustomFlag_39 = bit_39,
			//kCustomFlag_40 = bit_40,
			//kCustomFlag_41 = bit_41,
			//kCustomFlag_42 = bit_42,
			//kCustomFlag_43 = bit_43,
			//kCustomFlag_44 = bit_44,
			//kCustomFlag_45 = bit_45,
			//kCustomFlag_46 = bit_46,
			//kCustomFlag_47 = bit_47,
			//kCustomFlag_48 = bit_48,
			//kCustomFlag_49 = bit_49,
			//kCustomFlag_40 = bit_50,
			//kCustomFlag_51 = bit_51,
			//kCustomFlag_52 = bit_52,
			//kCustomFlag_53 = bit_53,
			//kCustomFlag_54 = bit_54,
			//kCustomFlag_55 = bit_55,
			//kCustomFlag_56 = bit_56,
			//kCustomFlag_57 = bit_57,
			//kCustomFlag_58 = bit_58,
			//kCustomFlag_59 = bit_59,
			//kCustomFlag_60 = bit_60,
			//kCustomFlag_61 = bit_61,
			//kCustomFlag_62 = bit_62,
			//kCustomFlag_63 = bit_63,
			//kCustomFlag_64 = bit_64
		};

		Enum getEnum(const char* name);
		std::string getName(const Enum& value);
		std::vector<std::string> getNames(const uint64& value);
	}
}

#endif