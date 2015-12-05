#ifndef PIPELINE_FLAGS
#define PIPELINE_FLAGS

#include "base.h"

namespace Pipeline {
	namespace PipelineFlags {
		using namespace Pipeline::bits::for_64bit;

		enum Enum
		{
			kEmpty = bit_00,

			kBake = bit_01,
			kCache = bit_02,
			kSimulate = bit_03,
			kUniqueGeometry = bit_04,
			kUniqueMaterial = bit_05,

			kPipelineFlag_06 = bit_06,
			kPipelineFlag_07 = bit_07,
			kPipelineFlag_08 = bit_08,
			kPipelineFlag_09 = bit_09,
			kPipelineFlag_10 = bit_10,
			kPipelineFlag_11 = bit_11,
			kPipelineFlag_12 = bit_12,
			kPipelineFlag_13 = bit_13,
			kPipelineFlag_14 = bit_14,
			kPipelineFlag_15 = bit_15,
			kPipelineFlag_16 = bit_16,
			kPipelineFlag_17 = bit_17,
			kPipelineFlag_18 = bit_18,
			kPipelineFlag_19 = bit_19,
			kPipelineFlag_20 = bit_20,
			kPipelineFlag_21 = bit_21,
			kPipelineFlag_22 = bit_22,
			kPipelineFlag_23 = bit_23,
			kPipelineFlag_24 = bit_24,
			kPipelineFlag_25 = bit_25,
			kPipelineFlag_26 = bit_26,
			kPipelineFlag_27 = bit_27,
			kPipelineFlag_28 = bit_28,
			kPipelineFlag_29 = bit_29,
			kPipelineFlag_30 = bit_30,
			kPipelineFlag_31 = bit_31
			//kPipelineFlag_32 = bit_32,
			//kPipelineFlag_33 = bit_33,
			//kPipelineFlag_34 = bit_34,
			//kPipelineFlag_35 = bit_35,
			//kPipelineFlag_36 = bit_36,
			//kPipelineFlag_37 = bit_37,
			//kPipelineFlag_38 = bit_38,
			//kPipelineFlag_39 = bit_39,
			//kPipelineFlag_40 = bit_40,
			//kPipelineFlag_41 = bit_41,
			//kPipelineFlag_42 = bit_42,
			//kPipelineFlag_43 = bit_43,
			//kPipelineFlag_44 = bit_44,
			//kPipelineFlag_45 = bit_45,
			//kPipelineFlag_46 = bit_46,
			//kPipelineFlag_47 = bit_47,
			//kPipelineFlag_48 = bit_48,
			//kPipelineFlag_49 = bit_49,
			//kPipelineFlag_40 = bit_50,
			//kPipelineFlag_51 = bit_51,
			//kPipelineFlag_52 = bit_52,
			//kPipelineFlag_53 = bit_53,
			//kPipelineFlag_54 = bit_54,
			//kPipelineFlag_55 = bit_55,
			//kPipelineFlag_56 = bit_56,
			//kPipelineFlag_57 = bit_57,
			//kPipelineFlag_58 = bit_58,
			//kPipelineFlag_59 = bit_59,
			//kPipelineFlag_60 = bit_60,
			//kPipelineFlag_61 = bit_61,
			//kPipelineFlag_62 = bit_62,
			//kPipelineFlag_63 = bit_63,
			//kPipelineFlag_64 = bit_64
		};

		Enum getEnum(const char* name);
		bool setName(const char* name, uint64* const value);
		bool setNames(std::vector<std::string>& new_names, uint64* const value);
		std::string getName(const Enum& value);
		std::vector<std::string> getNames(const uint64& value);
	}
}

#endif