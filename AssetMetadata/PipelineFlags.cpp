#include "PipelineFlags.h"

namespace Pipeline {
	namespace PipelineFlags {
		const char used = 5;
		const char count = 64;
		const char* names[count + 1] = {
			"",

			"bake",
			"cache",
			"simulate",
			"uniquegeometry",
			"uniquematerial",

			"pipeline_flags_06",
			"pipeline_flags_07",
			"pipeline_flags_08",
			"pipeline_flags_09",
			"pipeline_flags_10",
			"pipeline_flags_11",
			"pipeline_flags_12",
			"pipeline_flags_13",
			"pipeline_flags_14",
			"pipeline_flags_15",
			"pipeline_flags_16",
			"pipeline_flags_17",
			"pipeline_flags_18",
			"pipeline_flags_19",
			"pipeline_flags_20",
			"pipeline_flags_21",
			"pipeline_flags_22",
			"pipeline_flags_23",
			"pipeline_flags_24",
			"pipeline_flags_25",
			"pipeline_flags_26",
			"pipeline_flags_27",
			"pipeline_flags_28",
			"pipeline_flags_29",
			"pipeline_flags_30",
			"pipeline_flags_31",
			"pipeline_flags_32",
			"pipeline_flags_33",
			"pipeline_flags_34",
			"pipeline_flags_35",
			"pipeline_flags_36",
			"pipeline_flags_37",
			"pipeline_flags_38",
			"pipeline_flags_39",
			"pipeline_flags_40",
			"pipeline_flags_41",
			"pipeline_flags_42",
			"pipeline_flags_43",
			"pipeline_flags_44",
			"pipeline_flags_45",
			"pipeline_flags_46",
			"pipeline_flags_47",
			"pipeline_flags_48",
			"pipeline_flags_49",
			"pipeline_flags_50",
			"pipeline_flags_51",
			"pipeline_flags_52",
			"pipeline_flags_53",
			"pipeline_flags_54",
			"pipeline_flags_55",
			"pipeline_flags_56",
			"pipeline_flags_57",
			"pipeline_flags_58",
			"pipeline_flags_59",
			"pipeline_flags_60",
			"pipeline_flags_61",
			"pipeline_flags_62",
			"pipeline_flags_63",
			"pipeline_flags_64"
		};

		Enum getEnum(const char* name) { return Enum(static_cast<uint64>(powerOf2((indexOf(name, names, count))))); }
		bool setName(const char* name, uint64* const value)
		{
			const char index = indexOf(name, names, count);
			if (index)
			{
				*value |= static_cast<uint64>(powerOf2(index));
				return true;
			}
			return false;
		}
		bool setNames(std::vector<std::string>& new_names, uint64* const value)
		{
			std::vector<char> indices;
			for (std::vector<std::string>::iterator name = new_names.begin(); name != new_names.end(); ++name)
			{
				const char index = indexOf(name->c_str(), names, count);
				if (index) indices.push_back(index);
			}

			if (indices.size() != new_names.size()) return false;

			uint64 new_values = 0;
			std::vector<char>::iterator index = indices.begin();
			for (; index != indices.end(); ++index) new_values |= static_cast<uint64>(powerOf2(*index));
			*value |= new_values;
			return true;
		}
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