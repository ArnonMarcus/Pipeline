#include "CustomFlags.h"

namespace Pipeline {
	namespace CustomFlags {
		const char count = 64;
		const char* names[count + 1] = {
			"",

			"CustomFlag_01",
			"CustomFlag_02",
			"CustomFlag_03",
			"CustomFlag_04",
			"CustomFlag_05",
			"CustomFlag_06",
			"CustomFlag_07",
			"CustomFlag_08",
			"CustomFlag_09",
			"CustomFlag_10",
			"CustomFlag_11",
			"CustomFlag_12",
			"CustomFlag_13",
			"CustomFlag_14",
			"CustomFlag_15",
			"CustomFlag_16",
			"CustomFlag_17",
			"CustomFlag_18",
			"CustomFlag_19",
			"CustomFlag_20",
			"CustomFlag_21",
			"CustomFlag_22",
			"CustomFlag_23",
			"CustomFlag_24",
			"CustomFlag_25",
			"CustomFlag_26",
			"CustomFlag_27",
			"CustomFlag_28",
			"CustomFlag_29",
			"CustomFlag_30",
			"CustomFlag_31",
			"CustomFlag_32",
			"CustomFlag_33",
			"CustomFlag_34",
			"CustomFlag_35",
			"CustomFlag_36",
			"CustomFlag_37",
			"CustomFlag_38",
			"CustomFlag_39",
			"CustomFlag_40",
			"CustomFlag_41",
			"CustomFlag_42",
			"CustomFlag_43",
			"CustomFlag_44",
			"CustomFlag_45",
			"CustomFlag_46",
			"CustomFlag_47",
			"CustomFlag_48",
			"CustomFlag_49",
			"CustomFlag_40",
			"CustomFlag_51",
			"CustomFlag_52",
			"CustomFlag_53",
			"CustomFlag_54",
			"CustomFlag_55",
			"CustomFlag_56",
			"CustomFlag_57",
			"CustomFlag_58",
			"CustomFlag_59",
			"CustomFlag_60",
			"CustomFlag_61",
			"CustomFlag_62",
			"CustomFlag_63",
			"CustomFlag_64"
		};
		
		Enum getEnum(const char* name) { return Enum(powerOf2(indexOf(name, names, count))); }
		std::string getName(const Enum& value) { return names[log2(value)]; }
		std::vector<std::string> getNames(const uint64& value)
		{
			std::vector<std::string> result;
			uint64 bit = 1;
			for (char i = 1; i <= count; i++, bit <<= 1) if (value & bit) result.push_back(names[log2(bit) + 1]);
			return result;
		}
	};
}