#ifndef RENDER_SETTINGS
#define RENDER_SETTINGS

#include <vector>
#include <string>
#include "base.h"

namespace Pipeline {
	namespace RenderSettings {
		using namespace Pipeline::bits::for_32bit;

		enum Enum
		{
			kEmpty = bit_00,

			kRenderable = bit_01,
			kVisibleToCamera = bit_02,
			kVisibleToReflections = bit_03,
			kVisibleToRefractions = bit_04,

			kRenderSetting_05 = bit_05,
			kRenderSetting_06 = bit_06,
			kRenderSetting_07 = bit_07,
			kRenderSetting_08 = bit_08,
			kRenderSetting_09 = bit_09,
			kRenderSetting_10 = bit_10,
			kRenderSetting_11 = bit_11,
			kRenderSetting_12 = bit_12,
			kRenderSetting_13 = bit_13,
			kRenderSetting_14 = bit_14,
			kRenderSetting_15 = bit_15,
			kRenderSetting_16 = bit_16,
			kRenderSetting_17 = bit_17,
			kRenderSetting_18 = bit_18,
			kRenderSetting_19 = bit_19,
			kRenderSetting_20 = bit_20,
			kRenderSetting_21 = bit_21,
			kRenderSetting_22 = bit_22,
			kRenderSetting_23 = bit_23,
			kRenderSetting_24 = bit_24,
			kRenderSetting_25 = bit_25,
			kRenderSetting_26 = bit_26,
			kRenderSetting_27 = bit_27,
			kRenderSetting_28 = bit_28,
			kRenderSetting_29 = bit_29,
			kRenderSetting_30 = bit_30,
			kRenderSetting_31 = bit_31
		};

		Enum getEnum(const char* name);
		bool setName(const char* name, uint32* const value);
		bool setNames(std::vector<std::string>& new_names, uint32* const value);
		std::string getName(const Enum& value);
		std::vector<std::string> getNames(const uint32& value);
	}
}

#endif