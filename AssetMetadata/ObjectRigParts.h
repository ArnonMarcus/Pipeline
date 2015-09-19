#ifndef OBJECT_RIG_PARTS
#define OBJECT_RIG_PARTS

#include <string>
#include "base.h"

namespace Pipeline {
	namespace ObjectRigParts {
		enum Enum
		{
			kEmpty = 0x00,

			// Facial Center:
			kForhead = 0x01,
			kEars = 0x02,
			kEyes = 0x03,
			kEyeBrows = 0x04,
			kEyeLashes = 0x05,
			kNose = 0x06,
			kMouth = 0x07,
			kLips = 0x08,
			kUpperLip = 0x09,
			kLowerLip = 0x0A,
			kTeeth = 0x0B,
			kUpperTeeth = 0x0C,
			kLowerTeeth = 0x0D,
			kTong = 0x0E,
			kChin = 0x0F,

			// Facial Sided:
			kEar = 0x10,
			kEye = 0x11,
			kEyeBrow = 0x12,
			kLowerEyeLashes = 0x13,
			kUpperEyeLashes = 0x14,
			kCheek = 0x15,

			// Body Center:
			kHead = 0x16,
			kNeck = 0x17,
			kTorso = 0x18,
			kHands = 0x19,
			kArms = 0x2A,
			kPalms = 0x2B,
			kLegs = 0x2C,
			kFeet = 0x2D,
			kAnkles = 0x2E,
			kRibCage = 0x2F,
			kPelvic = 0x30,

			// Body Sided:
			kHand = 0x31,
			kArm = 0x32,
			kPalm = 0x33,
			kFingers = 0x34,
			kIndexFinger = 0x35,
			kLeg = 0x36,
			kFoot = 0x37,
			kAnkle = 0x38,
			kThumbs = 0x39
		};

		Enum getEnum(const char* name);
		std::string getName(const Enum& value);
	}
}

#endif