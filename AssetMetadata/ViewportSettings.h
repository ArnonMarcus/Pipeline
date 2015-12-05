#ifndef VIEWPORT_SETTINGS
#define VIEWPORT_SETTINGS

#include "base.h"

namespace Pipeline {
	namespace ViewportSettings {
		using namespace Pipeline::bits::for_32bit;

		enum Enum
		{
			kEmpty = bit_00,

			kHidden = bit_01,
			kTemplate = bit_02,
			kLocked = bit_03,
			
			kViewportSetting_04 = bit_04,
			kViewportSetting_05 = bit_05,
			kViewportSetting_06 = bit_06,
			kViewportSetting_07 = bit_07,
			kViewportSetting_08 = bit_08,
			kViewportSetting_09 = bit_09,
			kViewportSetting_10 = bit_10,
			kViewportSetting_11 = bit_11,
			kViewportSetting_12 = bit_12,
			kViewportSetting_13 = bit_13,
			kViewportSetting_14 = bit_14,
			kViewportSetting_15 = bit_15,
			kViewportSetting_16 = bit_16,
			kViewportSetting_17 = bit_17,
			kViewportSetting_18 = bit_18,
			kViewportSetting_19 = bit_19,
			kViewportSetting_20 = bit_20,
			kViewportSetting_21 = bit_21,
			kViewportSetting_22 = bit_22,
			kViewportSetting_23 = bit_23,
			kViewportSetting_24 = bit_24,
			kViewportSetting_25 = bit_25,
			kViewportSetting_26 = bit_26,
			kViewportSetting_27 = bit_27,
			kViewportSetting_28 = bit_28,
			kViewportSetting_29 = bit_29,
			kViewportSetting_30 = bit_30,
			kViewportSetting_31 = bit_31,
			kViewportSetting_32 = bit_32
		};

		Enum getEnum(const char* name);
		bool setName(const char* name, uint32* const value);
		bool setNames(std::vector<std::string>& new_names, uint32* const value);
		std::string getName(const Enum& value);
		std::vector<std::string> getNames(const uint32& value);
	}
}

#endif