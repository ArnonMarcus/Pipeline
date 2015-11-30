#ifndef BODY_PARTS
#define BODY_PARTS

#include <vector>
#include <string>
#include "base.h"

namespace Pipeline {
	namespace BodyParts {
		using namespace Pipeline::bits::for_32bit;

		enum Enum
		{
			kEmpty = bit_00,
			kHead = bit_01,
			kNeck = bit_02,
			kTorso = bit_03,
			kRibCage = bit_04,
			kPelvic = bit_05,
			kLeg = bit_06,
			kAnkle = bit_07,
			kFoot = bit_08,
			kThumb = bit_09,
			kHand = bit_10,
			kArm = bit_11,
			kPalm = bit_12,
			kFinger = bit_13,
			kIndexFinger = bit_14,

			kBodyPart_15 = bit_15,
			kBodyPart_16 = bit_16,
			kBodyPart_17 = bit_17,
			kBodyPart_18 = bit_18,
			kBodyPart_19 = bit_19,
			kBodyPart_20 = bit_20,
			kBodyPart_21 = bit_21,
			kBodyPart_22 = bit_22,
			kBodyPart_23 = bit_23,
			kBodyPart_24 = bit_24,
			kBodyPart_25 = bit_25,
			kBodyPart_26 = bit_26,
			kBodyPart_27 = bit_27,
			kBodyPart_28 = bit_28,
			kBodyPart_29 = bit_29,
			kBodyPart_30 = bit_30,
			kBodyPart_31 = bit_31,
			kBodyPart_32 = bit_32
		};

		Enum getEnum(const char* name);
		std::string getName(const Enum& value);
		std::vector<std::string> getNames(const uint32& value);
	}
}

#endif