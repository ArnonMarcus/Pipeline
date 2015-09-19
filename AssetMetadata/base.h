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

#define	ASSET_NAME_LENGTH 32
#define BUFFER_LENGTH 64
#define BUFFER_TYPE char[BUFFER_LENGTH]
#define	BUFFER_SIZE (sizeof(char) * BUFFER_LENGTH)

/*

The entire pipeline asset-data block is stored in a single block of memory that is 64-byte-wide.
It is allocated all at once in a single heap-allocation.
The reason is that most modern CPUs have a cache-line that is 64-bytes wide.
This means that (if the bits are aligned), it is a single cache-line read to pull all the data from main memory.
It also means that cache-misses are minimized, as memory is not fragmented.

The data-block is comprised of 2 partitions of 32bytes each:
1. Meta-Data 
2. Asset-Name

The Meta-Data partition holds the following:
1. API version (8 bit number) = the version of the data-format
2. Available 8 bits for future needs
3. Asset-Mode (8 bit enum) = the mode (LOD/representation) of the asset this object belongs to (proxy, shaded, etc.)
4. Asset-Type (8 bit enum) = the type of the asset that this object belongs to (character, prop, etc.)
5. Object-Type (8 bit enum) = the pipeline-related definition of the type of object it is (geometry, rig, camera, etc.)
6. Object-Rig-Parts (8 bit enum) = the pipeline-related definition of the part of the rig this object belongs to (eye, let, etc.)
7. Object-Rig-Sides (8 bit enum) = the pipeline-related definition of the side of the rig this object belongs to (left, right, etc.)
8. Render-Pass ID (8 bit number) = the pipeline-related definition of the render-pass this object belongs to (BG, AO, etc.)
9. Asset Mode-Version (32 bit unsigned integer) = the version of the current mode of the asset, that this object belongs to.
10. Asset Instance-ID (32 bit unsigned integer) = the per-scene unique identifier of the scene-asset-instance this object belongs to.
11. Asset Production-ID (64 bit unsigned integer) = the database primary-key of the asset-record that this object belongs to.
12. Object-Flags (64 bit-pattern) = the pipeline-related flags assigned to this object, each represented as a single-bit.
13. Asset-Name (32 byte c-style string) = the human-readable short-representation of the name of the asset that this object belongs to.

[ API-Version  ][ <available>  ][  Asset-Mode  ][  Asset-Type  ][  Object-Type ][ Obj.RigParts ][ Obj.RigSides ][ rend.pass-ID ]
[ Mode-Version ][ Mode-Version ][ Mode-Version ][ Mode-Version ][ Instance-ID  ][ Instance-ID  ][ Instance-ID  ][ Instance-ID  ]
[ Prod.AssetID ][ Prod.AssetID ][ Prod.AssetID ][ Prod.AssetID ][ Prod.AssetID ][ Prod.AssetID ][ Prod.AssetID ][ Prod.AssetID ]
[ Object-Flags ][ Object-Flags ][ Object-Flags ][ Object-Flags ][ Object-Flags ][ Object-Flags ][ Object-Flags ][ Object-Flags ]

[  Asset Name  ][  Asset Name  ][  Asset Name  ][  Asset Name  ][  Asset Name  ][  Asset Name  ][  Asset Name  ][  Asset Name  ]
[  Asset Name  ][  Asset Name  ][  Asset Name  ][  Asset Name  ][  Asset Name  ][  Asset Name  ][  Asset Name  ][  Asset Name  ]
[  Asset Name  ][  Asset Name  ][  Asset Name  ][  Asset Name  ][  Asset Name  ][  Asset Name  ][  Asset Name  ][  Asset Name  ]
[  Asset Name  ][  Asset Name  ][  Asset Name  ][  Asset Name  ][  Asset Name  ][  Asset Name  ][  Asset Name  ][  Asset Name  ]

*/



namespace Pipeline {
	enum offsets
	{
		kAPIversion = 0x00,
		kAvailable = 0x01,
		kAssetMode = 0x02,
		kAssetType = 0x03,
		kObjectType = 0x04,
		kObjectRigParts = 0x05,
		kObjectRigSides = 0x06,
		kObjectRenderPassID = 0x07,
		kAssetModeVersion = 0x08,
		kAssetInstanceID = 0x0C,
		kAssetProductionID = 0x10,
		kObjectFlags = 0x18,
		kAssetName = 0x20
	};

	char findStringArrayIndex(const char* str, const char* names[], const short& length);
}

#endif