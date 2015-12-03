#ifndef CAMERA_ROLES
#define CAMERA_ROLES

#include <vector>
#include <string>
#include "base.h"

namespace Pipeline {
	namespace CameraRoles {
		using namespace Pipeline::bits::for_8bit;

		enum Enum
		{
			kEmpty = bit_00,

			kRender = bit_01,
			kProjection = bit_02,
			kUI = bit_03,
			
			kCameraRole_04 = bit_04,
			kCameraRole_05 = bit_05,
			kCameraRole_06 = bit_06,
			kCameraRole_07 = bit_07,
			kCameraRole_08 = bit_08
		};

		Enum getEnum(const char* name);
		bool setName(const char* name, uint8* const value);
		bool setNames(std::vector<std::string>& new_names, uint8* const value);
		std::string getName(const Enum& value);
		std::vector<std::string> getNames(const uint8& value);
	}
}

#endif