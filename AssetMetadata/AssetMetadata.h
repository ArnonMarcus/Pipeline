#ifndef ASSET_METADATA
#define ASSET_METADATA

#include "API_Versions.h"
#include "AssetModes.h"
#include "AssetTypes.h"
#include "ObjectTypes.h"
#include "ObjectFlags.h"
#include "ObjectRigParts.h"
#include "ObjectRigSides.h"

namespace Pipeline {

	struct AssetMetadata
	{
		AssetMetadata();
		~AssetMetadata();

		// Setters
		void setObjectType(const char* objectType);
		void setObjectType(const ObjectTypes::Enum& objectType);
		void setAssetType(const char* assetType);
		void setAssetType(const AssetTypes::Enum& assetType);
		void setAssetMode(const char* assetMode);
		void setAssetMode(const AssetModes::Enum& assetMode);
		void setObjectRigPart(const char* objectRigPart);
		void setObjectRigPart(const ObjectRigParts::Enum& objectRigPart);
		void setObjectRigSide(const char* objectRigSide);
		void setObjectRigSide(const ObjectRigSides::Enum& objectRigSide);
		void setObjectFlag(const char* objectFlag);
		void setObjectFlag(const ObjectFlags::Enum& objectFlag);
		void setObjectFlags(const uint64& objectFlags);
		void unsetObjectFlag(const char* objectFlag);
		void unsetObjectFlag(const ObjectFlags::Enum& objectFlag);
		void unsetObjectFlags(const uint64& objectFlags);
		void clearObjectFlags();
		void setAssetModeVersion(const uint32& assetModeVersion);
		void setAssetInstanceID(const uint32& assetInstanceID);
		void setAssetProductionID(const uint64& assetProductionID);
		bool setAssetName(const char* assetName);

		// Getters
		AssetModes::Enum getAssetMode();
		AssetTypes::Enum getAssetType();
		ObjectTypes::Enum getObjectType();
		ObjectRigParts::Enum getObjectRigPart();
		ObjectRigSides::Enum getObjectRigSide();

		uint8 getAPIversion();
		uint8 getAssetModeChar();
		uint8 getAssetTypeChar();
		uint8 getObjectTypeChar();
		uint8 getObjectRigPartChar();
		uint8 getObjectRigSideChar();
		
		std::string getAssetName();
		std::string getAssetModeString();
		std::string getAssetTypeString();
		std::string getObjectTypeString();
		std::string getObjectRigPartString();
		std::string getObjectRigSideString();
		std::string getAssetModeVersionString();
		std::string getAssetInstanceIDString();
		std::string getAssetProductionIDString();
		std::string getObjectFlagsAsString();

		uint64 getObjectFlags();
		uint64 getAssetProductionID();
		uint32 getAssetInstanceID();
		uint32 getAssetModeVersion();
		bool isObjectFlagSet(ObjectFlags::Enum objectFlag);

		void setRawBuffer(const char* buffer);
		char* getRawBuffer();


	private:
		char* const _buffer;
		uint8* const _apiVersion;
		uint8* const _available;
		char* const _assetName;
		uint8* const _assetMode;
		uint8* const _assetType;
		uint8* const _objectType;
		uint8* const _objectRigPart;
		uint8* const _objectRigSide;
		uint8* const _objectRenderPassID;
		uint64* const _objectFlags;
		uint64* const _assetProductionID;
		uint32* const _assetInstanceID;
		uint32* const _assetModeVersion;
	};		  
}

#endif