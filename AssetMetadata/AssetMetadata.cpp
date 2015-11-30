//#include <string>
//#include "base.h"
//#include "AssetMetadata.h"
//
//
//
//uint16* const _objectID;
//uint16* const _parentID;
//uint16* const _assetID;
//uint16* const _assetVersion;
//
//uint32* const _bodyParts;
//uint32* const _facialParts;
//uint32* const _renderSettings;
//uint32* const _viewportSettingss;
//
//uint64* const _rigParts;
//uint64* const _customFlags;
//uint64* const _pipelineFlags;
//uint64* const _productionID;
//
//namespace Pipeline {
//	AssetMetadata::AssetMetadata() : _buffer(new BUFFER_TYPE),
//		_apiVersion((uint8*)(_buffer)),
//		_objectType((uint8*)(_buffer + 1)),
//		_objectTypeFlags((uint8*)(_buffer + 2)),
//		_rigPartSides((uint8*)(_buffer + 3)),
//		_cameraRoles((uint8*)(_buffer + 4)),
//		_lightRoles((uint8*)(_buffer + 5)),
//		_assetMode((uint8*)(_buffer + 6)),
//		_assetType((uint8*)(_buffer + 7)),
//
//		_objectID((uint16*)(_buffer + 8)),
//		_parentID((uint16*)(_buffer + 8 + 2)),
//		_assetID((uint16*)(_buffer + 8 + 4)),
//		_assetVersion((uint16*)(_buffer + 8 + 6)),
//
//		_bodyParts((uint32*)(_buffer + 16)),
//		_facialParts((uint32*)(_buffer + 16 + 4)),
//		_renderSettings((uint32*)(_buffer + 16 + 8)),
//		_viewportSettings((uint32*)(_buffer + 16 + 12)),
//
//		_rigParts((uint64*)(_buffer + 32)),
//		_customFlags((uint64*)(_buffer + 32 + 8)),
//		_pipelineFlags((uint64*)(_buffer + 32 + 16)),
//		_productionID((uint64*)(_buffer + 32 + 24))
//	{
//		for (uint8 i = 0; i < BUFFER_LENGTH; i++) _buffer[i] = 0;		
//		*_apiVersion = (uint8)API_VERSION;
//	}
//
//	AssetMetadata::~AssetMetadata() { delete[] _buffer; }
//	AssetMetadata& AssetMetadata::operator=(const AssetMetadata& other) { setRawBuffer(other._buffer); return *this; }
//
//	char* AssetMetadata::getRawBuffer() { return _buffer; }
//	void AssetMetadata::setRawBuffer(const char* buffer) { for (uint8 i = 0; i < BUFFER_LENGTH; i++) _buffer[i] = buffer[i]; };
//
//	// Int Getters
//	uint8 AssetMetadata::getAPIversion() { return *_apiVersion; }
//	uint16 AssetMetadata::getAssetVersion() { return *_assetVersion; }
//	uint16 AssetMetadata::setAssetID() { return *_assetID; }
//	uint16 AssetMetadata::setParentID() { return *_parentID; }
//	uint16 AssetMetadata::setObjectID() { return *_objectID; }
//	uint64 AssetMetadata::setProductionID() { return *_productionID; }
//
//	// Enum Getters
//	ObjectTypes::Enum AssetMetadata::getObjectType() { return (ObjectTypes::Enum)(*_objectType); }
//	AssetTypes::Enum AssetMetadata::getAssetType() { return (AssetTypes::Enum)(*_assetType); }
//	AssetModes::Enum AssetMetadata::getAssetMode() { return (AssetModes::Enum)(*_assetMode); }
//
//	// String Getters
//	std::string AssetMetadata::getObjectType_toString() { return ObjectTypes::getName((ObjectTypes::Enum)*_objectType); }
//	std::string AssetMetadata::getAssetType_toString() { return AssetTypes::getName((AssetTypes::Enum)*_assetType); }
//	std::string AssetMetadata::getAssetMode_toString() { return AssetModes::getName((AssetModes::Enum)*_assetMode); }
//	std::string AssetMetadata::getAssetVersion_toString() { return std::to_string(*_assetVersion); }
//	std::string AssetMetadata::getAssetID_toString() { return std::to_string(*_assetID); }
//	std::string AssetMetadata::getParentID_toString() { return std::to_string(*_parentID); }
//	std::string AssetMetadata::getProductionID_toString() { return std::to_string(*_productionID); }
//
//	// Setters
//	void AssetMetadata::setObjectType(const ObjectTypes::Enum& objectType)	{ *_objectType = (uint8)objectType; }
//	void AssetMetadata::setAssetType(const AssetTypes::Enum& assetType)		{ *_assetType = (uint8)assetType; }
//	void AssetMetadata::setAssetMode(const AssetModes::Enum& assetMode)		{ *_assetMode = (uint8)assetMode; }
//	void AssetMetadata::setAssetVersion(const uint16& assetVersion)			{ *_assetVersion = assetVersion; }
//	void AssetMetadata::setAssetID(const uint16& assetID)					{ *_assetID = assetID; }
//	void AssetMetadata::setParentID(const uint16& parentID)					{ *_parentID = parentID; }
//	void AssetMetadata::setObjectID(const uint16& objectID)					{ *_objectID = objectID; }
//	void AssetMetadata::setProductionID(const uint64& productionID)			{ *_productionID = productionID; }
//
//	// Bit-Pattern Single-Bit Setters
//	void AssetMetadata::setObjectTypeFlag(const ObjectTypeFlags::Enum& objectTypeFlag)		{ *_objectTypeFlags		|= (uint8)objectTypeFlag; }
//	void AssetMetadata::setRigPartSide(const RigPartSides::Enum& rigPartSide)				{ *_rigPartSides		|= (uint8)rigPartSide; }
//	void AssetMetadata::setCameraRole(const CameraRoles::Enum& cameraRole)					{ *_cameraRoles			|= (uint8)cameraRole; }
//	void AssetMetadata::setLightRole(const LightRoles::Enum& lightRole)						{ *_lightRoles			|= (uint8)lightRole; }
//
//	void AssetMetadata::setBodyPart(const BodyParts::Enum& bodyPart)						{ *_bodyParts			|= (uint32)bodyPart; }
//	void AssetMetadata::setFacialPart(const FacialParts::Enum& facialPart)					{ *_facialParts			|= (uint32)facialPart; }
//	void AssetMetadata::setRenderSetting(const RenderSettings::Enum& renderSetting)			{ *_renderSettings		|= (uint32)renderSetting; }
//	void AssetMetadata::setViewportSetting(const ViewportSettings::Enum& viewportSetting)	{ *_viewportSettings	|= (uint32)viewportSetting; }
//
//	void AssetMetadata::setRigPart(const RigParts::Enum& rigPart)							{ *_rigParts			|= (uint64)rigPart; }
//	void AssetMetadata::setCustomFlag(const CustomFlags::Enum& customFlag)					{ *_customFlags			|= (uint64)customFlag; }
//	void AssetMetadata::setPipelineFlag(const PipelineFlag::Enum& pipelineFlag)				{ *_pipelineFlags		|= (uint64)pipelineFlag; }
//
//	// Bit-Pattern Multi-Bit Setters
//	void AssetMetadata::setObjectTypeFlags(const uint8& objectTypeFlags)					{ *_objectTypeFlags		|= objectTypeFlags; }
//	void AssetMetadata::setRigPartSides(const uint8& rigPartSides)							{ *_rigPartSides		|= rigPartSides; }
//	void AssetMetadata::setCameraRoles(const uint8& cameraRoles)							{ *_cameraRoles			|= cameraRoles; }
//	void AssetMetadata::setLightRoles(const uint8& lightRoles)								{ *_lightRoles			|= lightRoles; }
//
//	void AssetMetadata::setBodyParts(const uint32& bodyParts)								{ *_bodyParts			|= bodyParts; }
//	void AssetMetadata::setFacialParts(const uint32& facialParts)							{ *_facialParts			|= facialParts; }
//	void AssetMetadata::setRenderSettings(const uint32& renderSettings)						{ *_renderSettings		|= renderSettings; }
//	void AssetMetadata::setViewportSettings(const uint32& viewportSettings)					{ *_viewportSettings	|= viewportSettings; }
//
//	void AssetMetadata::setRigParts(const uint64& rigParts)									{ *_rigParts			|= rigParts; }
//	void AssetMetadata::setCustomFlags(const uint64& customFlags)							{ *_customFlags			|= customFlags; }
//	void AssetMetadata::setPipelineFlags(const uint64& pipelineFlags)						{ *_pipelineFlags		|= pipelineFlags; }
//
//	// Bit-Pattern Single-Bit Un-Setters
//	void AssetMetadata::unsetObjectTypeFlag(const ObjectTypeFlags::Enum& objectTypeFlag) { *_objectTypeFlags &= ~(uint8)objectTypeFlag; }
//	void AssetMetadata::unsetRigPartSide(const RigPartSides::Enum& rigPartSide) { *_rigPartSides &= ~(uint8)rigPartSide; }
//	void AssetMetadata::unsetCameraRole(const CameraRoles::Enum& cameraRole) { *_cameraRoles &= ~(uint8)cameraRole; }
//	void AssetMetadata::unsetLightRole(const LightRoles::Enum& lightRole) { *_lightRoles &= ~(uint8)lightRole; }
//						
//	void AssetMetadata::unsetBodyPart(const BodyParts::Enum& bodyPart) { *_bodyParts &= ~(uint32)bodyPart; }
//	void AssetMetadata::unsetFacialPart(const FacialParts::Enum& facialPart) { *_facialParts &= ~(uint32)facialPart; }
//	void AssetMetadata::unsetRenderSetting(const RenderSettings::Enum& renderSetting) { *_renderSettings &= ~(uint32)renderSetting; }
//	void AssetMetadata::unsetViewportSetting(const ViewportSettings::Enum& viewportSetting) { *_viewportSettings &= ~(uint32)viewportSetting; }
//						
//	void AssetMetadata::unsetRigPart(const RigParts::Enum& rigPart) { *_rigParts &= ~(uint64)rigPart; }
//	void AssetMetadata::unsetCustomFlag(const CustomFlags::Enum& customFlag) { *_customFlags &= ~(uint64)customFlag; }
//	void AssetMetadata::unsetPipelineFlag(const PipelineFlag::Enum& pipelineFlag) { *_pipelineFlags &= ~(uint64)pipelineFlag; }
//
//	// Bit-Pattern Multi-Bit Un-Setters
//	void AssetMetadata::unsetObjectTypeFlags(const uint8& objectTypeFlags) { *_objectTypeFlags &= ~objectTypeFlags; }
//	void AssetMetadata::unsetRigPartSides(const uint8& rigPartSides) { *_rigPartSides &= ~rigPartSides; }
//	void AssetMetadata::unsetCameraRoles(const uint8& cameraRoles) { *_cameraRoles &= ~cameraRoles; }
//	void AssetMetadata::unsetLightRoles(const uint8& lightRoles) { *_lightRoles &= ~lightRoles; }
//						
//	void AssetMetadata::unsetBodyParts(const uint32& bodyParts) { *_bodyParts &= ~bodyParts; }
//	void AssetMetadata::unsetFacialParts(const uint32& facialParts) { *_facialParts &= ~facialParts; }
//	void AssetMetadata::unsetRenderSettings(const uint32& renderSettings) { *_renderSettings &= ~renderSettings; }
//	void AssetMetadata::unsetViewportSettings(const uint32& viewportSettings) { *_viewportSettings &= ~viewportSettings; }
//						
//	void AssetMetadata::unsetRigParts(const uint64& rigParts) { *_rigParts &= ~rigParts; }
//	void AssetMetadata::unsetCustomFlags(const uint64& customFlags) { *_customFlags &= ~customFlags; }
//	void AssetMetadata::unsetPipelineFlags(const uint64& pipelineFlags) { *_pipelineFlags &= ~pipelineFlags; }
//
//	// Bit-Pattern Clears
//	void AssetMetadata::clearObjectTypeFlags() { *_objectTypeFlags = 0; }
//	void AssetMetadata::clearRigPartSides() { *_rigPartSides = 0; }
//	void AssetMetadata::clearCameraRoles() { *_cameraRoles = 0; }
//	void AssetMetadata::clearLightRoles() { *_lightRoles = 0; }
//						
//	void AssetMetadata::clearBodyParts() { *_bodyParts = 0; }
//	void AssetMetadata::clearFacialParts() { *_facialParts = 0; }
//	void AssetMetadata::clearRenderSettings() { *_renderSettings = 0; }
//	void AssetMetadata::clearViewportSettings() { *_viewportSettings = 0; }
//						
//	void AssetMetadata::clearRigParts() { *_rigParts = 0; }
//	void AssetMetadata::clearCustomFlags() { *_customFlags = 0; }
//	void AssetMetadata::clearPipelineFlags() { *_pipelineFlags = 0; }
//
//	// Bit-Pattern Checkers
//	bool AssetMetadata::isObjectTypeFlagSet(const ObjectTypeFlags::Enum& objectTypeFlag) { return (*_objectTypeFlags & (uint8)objectTypeFlag) != 0; }
//	bool AssetMetadata::isRigPartSideSet(const RigPartSides::Enum& rigPartSide) { return (*_rigPartSides & (uint8)rigPartSide) != 0; }
//	bool AssetMetadata::isCameraRoleSet(const CameraRoles::Enum& cameraRole) { return (*_cameraRoles & (uint8)cameraRole) != 0; }
//	bool AssetMetadata::isLightRoleSet(const LightRoles::Enum& lightRole) { return (*_lightRoles & (uint8)cameraRole) != 0; }
//
//	bool AssetMetadata::isBodyPartSet(const BodyParts::Enum& bodyPart) { return (*_bodyParts & (uint32)bodyPart) != 0; }
//	bool AssetMetadata::isFacialPartSet(const FacialParts::Enum& facialPart) { return (*_facialParts & (uint32)facialPart) != 0; }
//	bool AssetMetadata::isRenderSettingSet(const RenderSettings::Enum& renderSetting) { return (*_renderSettings & (uint32)renderSetting) != 0; }
//	bool AssetMetadata::isViewportSettingSet(const ViewportSettings::Enum& viewportSetting) { return (*_viewportSettings & (uint32)viewportSetting) != 0; }
//
//	bool AssetMetadata::isRigPartSet(const RigParts::Enum& rigPart) { return (*_rigParts & (uint64)rigPart) != 0; }
//	bool AssetMetadata::isCustomFlagSet(const CustomFlags::Enum& customFlag) { return (*_customFlags & (uint64)customFlag) != 0; }
//	bool AssetMetadata::isPipelineFlagSet(const PipelineFlag::Enum& pipelineFlag) { return (*_pipelineFlags & (uint64)pipelineFlag) != 0; }
//}
//
//
