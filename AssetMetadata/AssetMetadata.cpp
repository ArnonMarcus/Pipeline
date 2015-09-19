#include <string>
#include "base.h"
#include "AssetMetadata.h"

namespace Pipeline {
	AssetMetadata::AssetMetadata() : _buffer(new BUFFER_TYPE),
		_apiVersion((uint8*)(_buffer + offsets::kAPIversion)),
		_available((uint8*)(_buffer + offsets::kAvailable)),
		_assetName((char*)(_buffer + offsets::kAssetName)),
		_assetMode((uint8*)(_buffer + offsets::kAssetMode)),
		_assetType((uint8*)(_buffer + offsets::kAssetType)),
		_objectType((uint8*)(_buffer + offsets::kObjectType)),
		_objectRigPart((uint8*)(_buffer + offsets::kObjectRigParts)),
		_objectRigSide((uint8*)(_buffer + offsets::kObjectRigSides)),
		_objectRenderPassID((uint8*)(_buffer + offsets::kObjectRenderPassID)),
		_objectFlags((uint64*)(_buffer + offsets::kObjectFlags)),
		_assetProductionID((uint64*)(_buffer + offsets::kAssetProductionID)),
		_assetInstanceID((uint32*)(_buffer + offsets::kAssetInstanceID)),
		_assetModeVersion((uint32*)(_buffer + offsets::kAssetModeVersion))
	{
		for (uint8 i = 0; i < BUFFER_LENGTH; i++) _buffer[i] = 0;		
		*_apiVersion = (uint8)API_VERSION;
	}

	AssetMetadata::~AssetMetadata()	{ delete[] _buffer;	}
	AssetMetadata& AssetMetadata::operator=(const AssetMetadata& other) { setRawBuffer(other._buffer); return *this; }

	void AssetMetadata::setAssetMode(const AssetModes::Enum& assetMode)				{ *_assetMode = (uint8)assetMode; }
	void AssetMetadata::setAssetType(const AssetTypes::Enum& assetType)				{ *_assetType = (uint8)assetType; }
	void AssetMetadata::setObjectType(const ObjectTypes::Enum& objectType)			{ *_objectType = (uint8)objectType; }
	void AssetMetadata::setObjectRigPart(const ObjectRigParts::Enum& objectRigPart) { *_objectRigPart = (uint8)objectRigPart; }
	void AssetMetadata::setObjectRigSide(const ObjectRigSides::Enum& objectSide)	{ *_objectRigSide = (uint8)objectSide; }
	void AssetMetadata::setObjectFlag(const ObjectFlags::Enum& objectFlag)			{ *_objectFlags |= (uint64)objectFlag; }
	void AssetMetadata::setObjectFlags(const uint64& objectFlags)					{ *_objectFlags |= objectFlags; }
	void AssetMetadata::unsetObjectFlag(const ObjectFlags::Enum& objectFlag)		{ *_objectFlags &= ~(uint64)objectFlag; }
	void AssetMetadata::unsetObjectFlags(const uint64& objectFlags)					{ *_objectFlags &= ~objectFlags; }
	void AssetMetadata::clearObjectFlags()											{ *_objectFlags = 0; }
	void AssetMetadata::setAssetModeVersion(const uint32& assetModeVersion)			{ *_assetModeVersion = assetModeVersion; }
	void AssetMetadata::setAssetInstanceID(const uint32& assetInstanceID)			{ *_assetInstanceID = assetInstanceID; }
	void AssetMetadata::setAssetProductionID(const uint64& assetProductionID)		{ *_assetProductionID = assetProductionID; }

	void AssetMetadata::setAssetMode(const char* name) { setAssetMode(AssetModes::getEnum(name)); }
	void AssetMetadata::setAssetType(const char* name) { setAssetType(AssetTypes::getEnum(name)); }
	void AssetMetadata::setObjectType(const char* name) { setObjectType(ObjectTypes::getEnum(name)); }
	void AssetMetadata::setObjectRigPart(const char* name) { setObjectRigPart(ObjectRigParts::getEnum(name)); }
	void AssetMetadata::setObjectRigSide(const char* name) { setObjectRigSide(ObjectRigSides::getEnum(name)); }
	void AssetMetadata::setObjectFlag(const char* name) { setObjectFlag(ObjectFlags::getEnum(name)); }
	void AssetMetadata::unsetObjectFlag(const char* name) { unsetObjectFlag(ObjectFlags::getEnum(name)); }
	// Getters

	AssetModes::Enum AssetMetadata::getAssetMode() { return (AssetModes::Enum)(*_assetMode); }
	AssetTypes::Enum AssetMetadata::getAssetType() { return (AssetTypes::Enum)(*_assetType); }
	ObjectTypes::Enum AssetMetadata::getObjectType() { return (ObjectTypes::Enum)(*_objectType); }
	ObjectRigParts::Enum AssetMetadata::getObjectRigPart() { return (ObjectRigParts::Enum)(*_objectRigPart); }
	ObjectRigSides::Enum AssetMetadata::getObjectRigSide() { return (ObjectRigSides::Enum)(*_objectRigSide); }

	uint64 AssetMetadata::getObjectFlags() { return *_objectFlags; }
	uint64 AssetMetadata::getAssetProductionID() { return *_assetProductionID; }
	uint32 AssetMetadata::getAssetInstanceID() { return *_assetInstanceID; }
	uint32 AssetMetadata::getAssetModeVersion() { return *_assetModeVersion; }
	uint8 AssetMetadata::getAssetModeChar() { return *_assetMode; }
	uint8 AssetMetadata::getAssetTypeChar() { return *_assetType; }
	uint8 AssetMetadata::getObjectTypeChar() { return *_objectType; }
	uint8 AssetMetadata::getObjectRigPartChar() { return *_objectRigPart; }
	uint8 AssetMetadata::getObjectRigSideChar() { return *_objectRigSide; }

	std::string AssetMetadata::getAssetName() { return _assetName; }
	std::string AssetMetadata::getAssetProductionIDString() { return std::to_string(*_assetProductionID); }
	std::string AssetMetadata::getAssetInstanceIDString() { return std::to_string(*_assetInstanceID); }
	std::string AssetMetadata::getAssetModeVersionString() { return std::to_string(*_assetModeVersion); }
	std::string AssetMetadata::getAssetModeString() { return AssetModes::getName((AssetModes::Enum)*_assetMode); }
	std::string AssetMetadata::getAssetTypeString() { return AssetTypes::getName((AssetTypes::Enum)*_assetType); }
	std::string AssetMetadata::getObjectTypeString() { return ObjectTypes::getName((ObjectTypes::Enum)*_objectType); }
	std::string AssetMetadata::getObjectRigPartString() { return ObjectRigParts::getName((ObjectRigParts::Enum)*_objectRigPart); }
	std::string AssetMetadata::getObjectRigSideString() { return ObjectRigSides::getName((ObjectRigSides::Enum)*_objectRigSide); }
	std::string AssetMetadata::getObjectFlagsAsString() { return ObjectFlags::getString(*_objectFlags); }

	bool AssetMetadata::isObjectFlagSet(ObjectFlags::Enum objectFlag) { return (*_objectFlags & (uint64)objectFlag) != 0; }
	bool AssetMetadata::setAssetName(const char* assetName)
	{
		strcpy_s(_assetName, ASSET_NAME_LENGTH, "");
		strcat_s(_assetName, ASSET_NAME_LENGTH, assetName);
		return true;
	}

	uint8 AssetMetadata::getAPIversion() { return *_apiVersion; }
	char* AssetMetadata::getRawBuffer() { return _buffer; }
	void AssetMetadata::setRawBuffer(const char* buffer) { for (uint8 i = 0; i < BUFFER_LENGTH; i++) _buffer[i] = buffer[i]; };
}


