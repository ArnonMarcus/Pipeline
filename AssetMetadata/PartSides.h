#ifndef OBJECT_RIG_SIDES
#define OBJECT_RIG_SIDES

#include <vector>
#include <string>
#include "base.h"

namespace Pipeline {
	namespace PartSides {
		using namespace Pipeline::bits::for_8bit;

		enum Enum
		{
			kCenter = bit_00, // [ 0000 0000 ]
			kRight = bit_01,  // [ 0001 0000 ]
			kLeft = bit_02,   // [ 0001 0001 ]
			kUpper = bit_03,  // [ 0010 0000 ]
			kLower = bit_04,  // [ 0010 0010 ]
			kBack = bit_05,   // [ 0100 0000 ]
			kFront = bit_06,  // [ 0100 0100 ]
			kInner = bit_07,  // [ 1000 0000 ]
			kOuter = bit_08   // [ 1000 1000 ]
		};

		//Rig - Part Side bit - pattern encoding :
		//      [  0  ][  1  ]

		// 1st: Right / Left
		// 2nd: Upper / Lower
		// 3rd: Back  / Front
		// 4th: Inner / Outer
		
		// 5th: cent. / sided 
		// 6th: no-UL / UL matters
		// 7th: no-BF / BF matters
		// 8th: no-IO / IO matters

		// Example:
		// Upper (Center) [ 0010 0010 ] = kUpper 
		// Upper-Right	  [ 0011 0010 ] = kUpper | kRight 
		// Upper-Left     [ 0011 0011 ] = kUpper | kLeft
		// Outer-Back-Lower-Left [ 1111 1011 ] = kOuter | kBack | kLower | kLeft

		Enum getEnum(const char* name);
		bool setName(const char* name, uint8* const value);
		bool setNames(std::vector<std::string>& new_names, uint8* const value);
		std::string getName(const Enum& value);
		std::vector<std::string> getNames(const uint8& value);
	}
}

#endif