#ifndef CUSTOM_PARTS
#define CUSTOM_PARTS

#include "base.h"

namespace Pipeline {
	namespace CustomParts {
		using namespace Pipeline::bits::for_64bit;

		enum Enum
		{
			kEmpty = bit_00,

			kCustomPart_01 = bit_01,
			kCustomPart_02 = bit_02,
			kCustomPart_03 = bit_03,
			kCustomPart_04 = bit_04,
			kCustomPart_05 = bit_05,
			kCustomPart_06 = bit_06,
			kCustomPart_07 = bit_07,
			kCustomPart_08 = bit_08,
			kCustomPart_09 = bit_09,
			kCustomPart_10 = bit_10,
			kCustomPart_11 = bit_11,
			kCustomPart_12 = bit_12,
			kCustomPart_13 = bit_13,
			kCustomPart_14 = bit_14,
			kCustomPart_15 = bit_15,
			kCustomPart_16 = bit_16,
			kCustomPart_17 = bit_17,
			kCustomPart_18 = bit_18,
			kCustomPart_19 = bit_19,
			kCustomPart_20 = bit_20,
			kCustomPart_21 = bit_21,
			kCustomPart_22 = bit_22,
			kCustomPart_23 = bit_23,
			kCustomPart_24 = bit_24,
			kCustomPart_25 = bit_25,
			kCustomPart_26 = bit_26,
			kCustomPart_27 = bit_27,
			kCustomPart_28 = bit_28,
			kCustomPart_29 = bit_29,
			kCustomPart_30 = bit_30,
			kCustomPart_31 = bit_31
			//kCustomPart_32 = bit_32,
			//kCustomPart_33 = bit_33,
			//kCustomPart_34 = bit_34,
			//kCustomPart_35 = bit_35,
			//kCustomPart_36 = bit_36,
			//kCustomPart_37 = bit_37,
			//kCustomPart_38 = bit_38,
			//kCustomPart_39 = bit_39,
			//kCustomPart_40 = bit_40,
			//kCustomPart_41 = bit_41,
			//kCustomPart_42 = bit_42,
			//kCustomPart_43 = bit_43,
			//kCustomPart_44 = bit_44,
			//kCustomPart_45 = bit_45,
			//kCustomPart_46 = bit_46,
			//kCustomPart_47 = bit_47,
			//kCustomPart_48 = bit_48,
			//kCustomPart_49 = bit_49,
			//kCustomPart_40 = bit_50,
			//kCustomPart_51 = bit_51,
			//kCustomPart_52 = bit_52,
			//kCustomPart_53 = bit_53,
			//kCustomPart_54 = bit_54,
			//kCustomPart_55 = bit_55,
			//kCustomPart_56 = bit_56,
			//kCustomPart_57 = bit_57,
			//kCustomPart_58 = bit_58,
			//kCustomPart_59 = bit_59,
			//kCustomPart_60 = bit_60,
			//kCustomPart_61 = bit_61,
			//kCustomPart_62 = bit_62,
			//kCustomPart_63 = bit_63,
			//kCustomPart_64 = bit_64
		};

		Enum getEnum(const char* name);
		bool setName(const char* name, uint64* const value);
		bool setNames(std::vector<std::string>& new_names, uint64* const value);
		std::string getName(const Enum& value);
		std::vector<std::string> getNames(const uint64& value);
	}
}

#endif