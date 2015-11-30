#ifndef BASE
#define BASE

#if ULONG_MAX >= 0xFFFFFFFFFFFFFFFFULL
typedef unsigned long uint64;
#else
typedef unsigned long long uint64;
#endif
typedef unsigned char uint8;
typedef unsigned long uint32;
typedef unsigned short uint16;

#define API_VERSION 2

#define BUFFER_LENGTH 64
#define BUFFER_TYPE char[BUFFER_LENGTH]
#define	BUFFER_SIZE (sizeof(char) * BUFFER_LENGTH)

/*

The entire pipeline asset-data block is stored in a single block of memory that is 64-byte-wide.
It is allocated all at once in a single heap-allocation.
The reason is that most modern CPUs have a cache-line that is 64-bytes wide.
This means that (if the bits are aligned), it is a single cache-line read to pull all the data from main memory.
It also means that cache-misses are minimized, as memory is not fragmented.

The data-block holds the following:
1. API version (8 bit number) = the version of the data-format
2. Asset-Mode (8 bit enum) = the mode (LOD/representation) of the asset this object belongs to (proxy, shaded, etc.)
3. Asset-Type (8 bit enum) = the type of the asset that this object belongs to (character, prop, etc.)
4. Object-Type (8 bit enum) = the pipeline-related definition of the type of object it is (geometry, rig, camera, etc.)
5. Object-Rig-Parts (8 bit enum) = the pipeline-related definition of the part of the rig this object belongs to (eye, let, etc.)
6. Object-Rig-Sides (8 bit enum) = the pipeline-related definition of the side of the rig this object belongs to (left, right, etc.)
9. Asset Mode-Version (32 bit unsigned integer) = the version of the current mode of the asset, that this object belongs to.
10. Asset Instance-ID (32 bit unsigned integer) = the per-scene unique identifier of the scene-asset-instance this object belongs to.
11. Asset Production-ID (64 bit unsigned integer) = the database primary-key of the asset-record that this object belongs to.
12. Object-Flags (64 bit-pattern) = the pipeline-related flags assigned to this object, each represented as a single-bit.

[ API-Version  ][  Asset-Mode  ][  Asset-Type  ][  Object-Type ][ Obj.RigParts ][ Obj.RigSides ][]
[ Mode-Version ][ Mode-Version ][ Mode-Version ][ Mode-Version ][ Instance-ID  ][ Instance-ID  ][ Instance-ID  ][ Instance-ID  ]
[ Prod.AssetID ][ Prod.AssetID ][ Prod.AssetID ][ Prod.AssetID ][ Prod.AssetID ][ Prod.AssetID ][ Prod.AssetID ][ Prod.AssetID ]
[ Object-Flags ][ Object-Flags ][ Object-Flags ][ Object-Flags ][ Object-Flags ][ Object-Flags ][ Object-Flags ][ Object-Flags ]




*/

namespace Pipeline {
	namespace bits {
		namespace for_8bit {
			const uint8 bit_00 = 0x00;
			const uint8 bit_01 = 0x01;
			const uint8 bit_02 = 0x02;
			const uint8 bit_03 = 0x04;
			const uint8 bit_04 = 0x08;
			const uint8 bit_05 = 0x10;
			const uint8 bit_06 = 0x20;
			const uint8 bit_07 = 0x40;
			const uint8 bit_08 = 0x80;
		}
		namespace for_16bit {
			const uint16 bit_00 = 0x0000;
			const uint16 bit_01 = 0x0001;
			const uint16 bit_02 = 0x0002;
			const uint16 bit_03 = 0x0004;
			const uint16 bit_04 = 0x0008;
			const uint16 bit_05 = 0x0010;
			const uint16 bit_06 = 0x0020;
			const uint16 bit_07 = 0x0040;
			const uint16 bit_08 = 0x0080;
			const uint16 bit_09 = 0x0100;
			const uint16 bit_10 = 0x0200;
			const uint16 bit_11 = 0x0400;
			const uint16 bit_12 = 0x0800;
			const uint16 bit_13 = 0x1000;
			const uint16 bit_14 = 0x2000;
			const uint16 bit_15 = 0x4000;
			const uint16 bit_16 = 0x8000;
		}
		namespace for_32bit {
			const uint32 bit_00 = 0x00000000;
			const uint32 bit_01 = 0x00000001;
			const uint32 bit_02 = 0x00000002;
			const uint32 bit_03 = 0x00000004;
			const uint32 bit_04 = 0x00000008;
			const uint32 bit_05 = 0x00000010;
			const uint32 bit_06 = 0x00000020;
			const uint32 bit_07 = 0x00000040;
			const uint32 bit_08 = 0x00000080;
			const uint32 bit_09 = 0x00000100;
			const uint32 bit_10 = 0x00000200;
			const uint32 bit_11 = 0x00000400;
			const uint32 bit_12 = 0x00000800;
			const uint32 bit_13 = 0x00001000;
			const uint32 bit_14 = 0x00002000;
			const uint32 bit_15 = 0x00004000;
			const uint32 bit_16 = 0x00008000;
			const uint32 bit_17 = 0x00010000;
			const uint32 bit_18 = 0x00020000;
			const uint32 bit_19 = 0x00040000;
			const uint32 bit_20 = 0x00080000;
			const uint32 bit_21 = 0x00100000;
			const uint32 bit_22 = 0x00200000;
			const uint32 bit_23 = 0x00400000;
			const uint32 bit_24 = 0x00800000;
			const uint32 bit_25 = 0x01000000;
			const uint32 bit_26 = 0x02000000;
			const uint32 bit_27 = 0x04000000;
			const uint32 bit_28 = 0x08000000;
			const uint32 bit_29 = 0x10000000;
			const uint32 bit_30 = 0x20000000;
			const uint32 bit_31 = 0x40000000;
			const uint32 bit_32 = 0x80000000;
		}
		namespace for_64bit {
			const uint64 bit_00 = 0x0000000000000000ULL;
			const uint64 bit_01 = 0x0000000000000001ULL;
			const uint64 bit_02 = 0x0000000000000002ULL;
			const uint64 bit_03 = 0x0000000000000004ULL;
			const uint64 bit_04 = 0x0000000000000008ULL;
			const uint64 bit_05 = 0x0000000000000010ULL;
			const uint64 bit_06 = 0x0000000000000020ULL;
			const uint64 bit_07 = 0x0000000000000040ULL;
			const uint64 bit_08 = 0x0000000000000080ULL;
			const uint64 bit_09 = 0x0000000000000100ULL;
			const uint64 bit_10 = 0x0000000000000200ULL;
			const uint64 bit_11 = 0x0000000000000400ULL;
			const uint64 bit_12 = 0x0000000000000800ULL;
			const uint64 bit_13 = 0x0000000000001000ULL;
			const uint64 bit_14 = 0x0000000000002000ULL;
			const uint64 bit_15 = 0x0000000000004000ULL;
			const uint64 bit_16 = 0x0000000000008000ULL;
			const uint64 bit_17 = 0x0000000000010000ULL;
			const uint64 bit_18 = 0x0000000000020000ULL;
			const uint64 bit_19 = 0x0000000000040000ULL;
			const uint64 bit_20 = 0x0000000000080000ULL;
			const uint64 bit_21 = 0x0000000000100000ULL;
			const uint64 bit_22 = 0x0000000000200000ULL;
			const uint64 bit_23 = 0x0000000000400000ULL;
			const uint64 bit_24 = 0x0000000000800000ULL;
			const uint64 bit_25 = 0x0000000001000000ULL;
			const uint64 bit_26 = 0x0000000002000000ULL;
			const uint64 bit_27 = 0x0000000004000000ULL;
			const uint64 bit_28 = 0x0000000008000000ULL;
			const uint64 bit_29 = 0x0000000010000000ULL;
			const uint64 bit_30 = 0x0000000020000000ULL;
			const uint64 bit_31 = 0x0000000040000000ULL;
			const uint64 bit_32 = 0x0000000080000000ULL;
			const uint64 bit_33 = 0x0000000100000000ULL;
			const uint64 bit_34 = 0x0000000200000000ULL;
			const uint64 bit_35 = 0x0000000400000000ULL;
			const uint64 bit_36 = 0x0000000800000000ULL;
			const uint64 bit_37 = 0x0000001000000000ULL;
			const uint64 bit_38 = 0x0000002000000000ULL;
			const uint64 bit_39 = 0x0000004000000000ULL;
			const uint64 bit_40 = 0x0000008000000000ULL;
			const uint64 bit_41 = 0x0000010000000000ULL;
			const uint64 bit_42 = 0x0000020000000000ULL;
			const uint64 bit_43 = 0x0000040000000000ULL;
			const uint64 bit_44 = 0x0000080000000000ULL;
			const uint64 bit_45 = 0x0000100000000000ULL;
			const uint64 bit_46 = 0x0000200000000000ULL;
			const uint64 bit_47 = 0x0000400000000000ULL;
			const uint64 bit_48 = 0x0000800000000000ULL;
			const uint64 bit_49 = 0x0001000000000000ULL;
			const uint64 bit_50 = 0x0002000000000000ULL;
			const uint64 bit_51 = 0x0004000000000000ULL;
			const uint64 bit_52 = 0x0008000000000000ULL;
			const uint64 bit_53 = 0x0010000000000000ULL;
			const uint64 bit_54 = 0x0020000000000000ULL;
			const uint64 bit_55 = 0x0040000000000000ULL;
			const uint64 bit_56 = 0x0080000000000000ULL;
			const uint64 bit_57 = 0x0100000000000000ULL;
			const uint64 bit_58 = 0x0200000000000000ULL;
			const uint64 bit_59 = 0x0400000000000000ULL;
			const uint64 bit_60 = 0x0000000000000000ULL;
			const uint64 bit_61 = 0x1000000000000000ULL;
			const uint64 bit_62 = 0x2000000000000000ULL;
			const uint64 bit_63 = 0x4000000000000000ULL;
			const uint64 bit_64 = 0x8000000000000000ULL;
		}
	}

	uint64 powerOf2(const uint8 value);
	uint8 log2(const uint64 value);
	char indexOf(const char* str, const char* names[], const short& length);
}

#endif