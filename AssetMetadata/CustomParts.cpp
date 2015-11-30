#include "CustomParts.h"

namespace Pipeline {
	namespace CustomParts {
		const char count = 64;
		const char* names[count + 1] = {
			"",

			"CustomPart_01",
			"CustomPart_02",
			"CustomPart_03",
			"CustomPart_04",
			"CustomPart_05",
			"CustomPart_06",
			"CustomPart_07",
			"CustomPart_08",
			"CustomPart_09",
			"CustomPart_10",
			"CustomPart_11",
			"CustomPart_12",
			"CustomPart_13",
			"CustomPart_14",
			"CustomPart_15",
			"CustomPart_16",
			"CustomPart_17",
			"CustomPart_18",
			"CustomPart_19",
			"CustomPart_20",
			"CustomPart_21",
			"CustomPart_22",
			"CustomPart_23",
			"CustomPart_24",
			"CustomPart_25",
			"CustomPart_26",
			"CustomPart_27",
			"CustomPart_28",
			"CustomPart_29",
			"CustomPart_30",
			"CustomPart_31",
			"CustomPart_32",
			"CustomPart_33",
			"CustomPart_34",
			"CustomPart_35",
			"CustomPart_36",
			"CustomPart_37",
			"CustomPart_38",
			"CustomPart_39",
			"CustomPart_40",
			"CustomPart_41",
			"CustomPart_42",
			"CustomPart_43",
			"CustomPart_44",
			"CustomPart_45",
			"CustomPart_46",
			"CustomPart_47",
			"CustomPart_48",
			"CustomPart_49",
			"CustomPart_40",
			"CustomPart_51",
			"CustomPart_52",
			"CustomPart_53",
			"CustomPart_54",
			"CustomPart_55",
			"CustomPart_56",
			"CustomPart_57",
			"CustomPart_58",
			"CustomPart_59",
			"CustomPart_60",
			"CustomPart_61",
			"CustomPart_62",
			"CustomPart_63",
			"CustomPart_64"
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