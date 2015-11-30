#ifndef FACIAL_PARTS
#define FACIAL_PARTS

#include <vector>
#include <string>
#include "base.h"

namespace Pipeline {
	namespace FacialParts {
		using namespace Pipeline::bits::for_32bit;

		enum Enum
		{
			kEmpty = bit_00,
			kForhead = bit_01,
			kEar = bit_02,
			kEye = bit_03,
			kEyebrow = bit_04,
			kEyelashes = bit_05,
			kNose= bit_06,
			kMouth = bit_07,
			kLip = bit_08,
			kTeeth = bit_09,
			kTong = bit_10,
			kCheek = bit_11,
			kChin = bit_12,

			kFacialPart_13 = bit_13,
			kFacialPart_14 = bit_14,
			kFacialPart_15 = bit_15,
			kFacialPart_16 = bit_16,
			kFacialPart_17 = bit_17,
			kFacialPart_18 = bit_18,
			kFacialPart_19 = bit_19,
			kFacialPart_20 = bit_20,
			kFacialPart_21 = bit_21,
			kFacialPart_22 = bit_22,
			kFacialPart_23 = bit_23,
			kFacialPart_24 = bit_24,
			kFacialPart_25 = bit_25,
			kFacialPart_26 = bit_26,
			kFacialPart_27 = bit_27,
			kFacialPart_28 = bit_28,
			kFacialPart_29 = bit_29,
			kFacialPart_30 = bit_30,
			kFacialPart_31 = bit_31,
			kFacialPart_32 = bit_32
		};

		Enum getEnum(const char* name);
		std::string getName(const Enum& value);
		std::vector<std::string> getNames(const uint32& value);
	}
}

#endif