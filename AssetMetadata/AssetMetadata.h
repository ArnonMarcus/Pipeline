#ifndef ASSET_METADATA
#define ASSET_METADATA

#include <string>
#include "base.h"
#include "API_Versions.h"
#include "ObjectTypes.h"
#include "ObjectTypeFlags.h"
#include "PartSides.h"
#include "CameraRoles.h"
#include "LightRoles.h"
#include "AssetModes.h"
#include "AssetTypes.h"
#include "BodyParts.h"
#include "FacialParts.h"
#include "RenderSettings.h"
#include "ViewportSettings.h"
#include "CustomParts.h"
#include "CustomFlags.h"
#include "PipelineFlags.h"

namespace Pipeline {

	struct AssetMetadata
	{

	private:

		char* const _buffer;

		uint8* const _apiVersion;
		uint8* const _objectType;
		uint8* const _objectTypeFlags;
		uint8* const _partSides;
		uint8* const _cameraRoles;
		uint8* const _lightRoles;
		uint8* const _assetMode;
		uint8* const _assetType;

		uint16* const _objectID;
		uint16* const _parentID;
		uint16* const _assetID;
		uint16* const _assetVersion;

		uint32* const _bodyParts;
		uint32* const _facialParts;
		uint32* const _renderSettings;
		uint32* const _viewportSettings;

		uint64* const _customParts;
		uint64* const _customFlags;
		uint64* const _pipelineFlags;
		uint64* const _productionID;


	public:

		AssetMetadata() : _buffer(new BUFFER_TYPE),
			_apiVersion((uint8*)(_buffer)),
			_objectType((uint8*)(_buffer + 1)),
			_objectTypeFlags((uint8*)(_buffer + 2)),
			_partSides((uint8*)(_buffer + 3)),
			_cameraRoles((uint8*)(_buffer + 4)),
			_lightRoles((uint8*)(_buffer + 5)),
			_assetMode((uint8*)(_buffer + 6)),
			_assetType((uint8*)(_buffer + 7)),

			_objectID((uint16*)(_buffer + 8)),
			_parentID((uint16*)(_buffer + 8 + 2)),
			_assetID((uint16*)(_buffer + 8 + 4)),
			_assetVersion((uint16*)(_buffer + 8 + 6)),

			_bodyParts((uint32*)(_buffer + 16)),
			_facialParts((uint32*)(_buffer + 16 + 4)),
			_renderSettings((uint32*)(_buffer + 16 + 8)),
			_viewportSettings((uint32*)(_buffer + 16 + 12)),

			_customParts((uint64*)(_buffer + 32)),
			_customFlags((uint64*)(_buffer + 32 + 8)),
			_pipelineFlags((uint64*)(_buffer + 32 + 16)),
			_productionID((uint64*)(_buffer + 32 + 24))
		{
			for (uint8 i = 0; i < BUFFER_LENGTH; i++) _buffer[i] = 0;
			*_apiVersion = (uint8)API_VERSION;
		}

		~AssetMetadata() { delete[] _buffer; }
		AssetMetadata& operator=(const AssetMetadata& other) { setRawBuffer(other._buffer); return *this; }

		char* AssetMetadata::getRawBuffer() { return _buffer; }
		void AssetMetadata::setRawBuffer(const char* buffer) { for (uint8 i = 0; i < BUFFER_LENGTH; i++) _buffer[i] = buffer[i]; };

		// Int Getters
		uint8 getAPIversion() { return *_apiVersion; }
		uint16 getAssetVersion() { return *_assetVersion; }
		uint16 getAssetID() { return *_assetID; }
		uint16 getParentID() { return *_parentID; }
		uint16 getObjectID() { return *_objectID; }
		uint64 getProductionID() { return *_productionID; }

		// Enum Getters
		ObjectTypes::Enum getObjectType() { return (ObjectTypes::Enum)(*_objectType); }
		AssetTypes::Enum getAssetType() { return (AssetTypes::Enum)(*_assetType); }
		AssetModes::Enum getAssetMode() { return (AssetModes::Enum)(*_assetMode); }


		// String Getters
		std::string getObjectType_toString() { return ObjectTypes::getName((ObjectTypes::Enum)*_objectType); }
		std::string getAssetType_toString() { return AssetTypes::getName((AssetTypes::Enum)*_assetType); }
		std::string getAssetMode_toString() { return AssetModes::getName((AssetModes::Enum)*_assetMode); }
		std::string getAssetVersion_toString() { return std::to_string(*_assetVersion); }
		std::string getAssetID_toString() { return std::to_string(*_assetID); }
		std::string getObjectID_toString() { return std::to_string(*_objectID); }
		std::string getParentID_toString() { return std::to_string(*_parentID); }
		std::string getProductionID_toString() { return std::to_string(*_productionID); }

		// Multiple String Getters
		std::vector<std::string> getObjectTypeFlags_toString() { return ObjectTypeFlags::getNames(*_objectTypeFlags); }
		std::vector<std::string> getPartSides_toString() { return PartSides::getNames(*_partSides); }
		std::vector<std::string> getCameraRoles_toString() { return CameraRoles::getNames(*_cameraRoles); }
		std::vector<std::string> getLightRoles_toString() { return LightRoles::getNames(*_lightRoles); }
		std::vector<std::string> getBodyParts_toString() { return BodyParts::getNames(*_bodyParts); }
		std::vector<std::string> getFacialParts_toString() { return FacialParts::getNames(*_facialParts); }
		std::vector<std::string> getRenderSettings_toString() { return RenderSettings::getNames(*_renderSettings); }
		std::vector<std::string> getViewportSettings_toString() { return ViewportSettings::getNames(*_viewportSettings); }
		std::vector<std::string> getCustomParts_toString() { return CustomParts::getNames(*_customParts); }
		std::vector<std::string> getCustomFlags_toString() { return CustomFlags::getNames(*_customFlags); }
		std::vector<std::string> getPipelineFlags_toString() { return PipelineFlags::getNames(*_pipelineFlags); }

		// Setters
		void setObjectType(const ObjectTypes::Enum& objectType) { *_objectType = (uint8)objectType; }
		void setAssetType(const AssetTypes::Enum& assetType) { *_assetType = (uint8)assetType; }
		void setAssetMode(const AssetModes::Enum& assetMode) { *_assetMode = (uint8)assetMode; }
		void setAssetVersion(const uint16& assetVersion) { *_assetVersion = assetVersion; }
		void setAssetID(const uint16& assetID) { *_assetID = assetID; }
		void setParentID(const uint16& parentID) { *_parentID = parentID; }
		void setObjectID(const uint16& objectID) { *_objectID = objectID; }
		void setProductionID(const uint64& productionID) { *_productionID = productionID; }

		// String Setters
		bool setObjectType(const std::string& objectType) { return ObjectTypes::setName(objectType.c_str(), _objectType); }
		bool setObjectTypeFlag(const std::string& objectTypeFlag) { return ObjectTypeFlags::setName(objectTypeFlag.c_str(), _objectTypeFlags); }
		bool setAssetType(const std::string& assetType) { return AssetTypes::setName(assetType.c_str(), _assetType); }
		bool setAssetMode(const std::string& assetMode) { return AssetModes::setName(assetMode.c_str(), _assetMode); }
		bool setPartSide(const std::string& partSide) { return PartSides::setName(partSide.c_str(), _partSides); }
		bool setCameraRole(const std::string& cameraRole) { return CameraRoles::setName(cameraRole.c_str(), _cameraRoles); }
		bool setLightRole(const std::string& lightRole) { return LightRoles::setName(lightRole.c_str(), _lightRoles); }
		bool setBodyPart(const std::string& bodyPart) { return BodyParts::setName(bodyPart.c_str(), _bodyParts); }
		bool setFacialPart(const std::string& facialPart) { return FacialParts::setName(facialPart.c_str(), _facialParts); }
		bool setRenderSetting(const std::string& renderSetting) { return RenderSettings::setName(renderSetting.c_str(), _renderSettings); }
		bool setViewportSetting(const std::string& viewportSetting) { return ViewportSettings::setName(viewportSetting.c_str(), _viewportSettings); }
		bool setCustomPart(const std::string& customPart) { return CustomParts::setName(customPart.c_str(), _customParts); }
		bool setCustomFlag(const std::string& customFlag) { return CustomFlags::setName(customFlag.c_str(), _customFlags); }
		bool setPipelineFlag(const std::string& pipelineFlag) { return PipelineFlags::setName(pipelineFlag.c_str(), _pipelineFlags); }

		// Multi-String Setters
		bool setObjectTypeFlags(std::vector<std::string>& objectTypeFlags) { return ObjectTypeFlags::setNames(objectTypeFlags, _objectTypeFlags); }
		bool setPartSides(std::vector<std::string>& partSides) { return PartSides::setNames(partSides, _partSides); }
		bool setCameraRoles(std::vector<std::string>& cameraRoles) { return CameraRoles::setNames(cameraRoles, _cameraRoles); }
		bool setLightRoles(std::vector<std::string>& lightRoles) { return LightRoles::setNames(lightRoles, _lightRoles); }
		bool setBodyParts(std::vector<std::string>& bodyParts) { return BodyParts::setNames(bodyParts, _bodyParts); }
		bool setFacialParts(std::vector<std::string>& facialParts) { return FacialParts::setNames(facialParts, _facialParts); }
		bool setRenderSettings(std::vector<std::string>& renderSettings) { return RenderSettings::setNames(renderSettings, _renderSettings); }
		bool setViewportSettings(std::vector<std::string>& viewportSettings) { return ViewportSettings::setNames(viewportSettings, _viewportSettings); }
		bool setCustomParts(std::vector<std::string>& customParts) { return CustomParts::setNames(customParts, _customParts); }
		bool setCustomFlags(std::vector<std::string>& customFlags) { return CustomFlags::setNames(customFlags, _customFlags); }
		bool setPipelineFlags(std::vector<std::string>& pipelineFlags) { return PipelineFlags::setNames(pipelineFlags, _pipelineFlags); }

		// Bit-Pattern Single-Bit Setters
		void setObjectTypeFlag(const ObjectTypeFlags::Enum& objectTypeFlag) { *_objectTypeFlags |= (uint8)objectTypeFlag; }
		void setPartSide(const PartSides::Enum& partSide) { *_partSides |= (uint8)partSide; }
		void setCameraRole(const CameraRoles::Enum& cameraRole) { *_cameraRoles |= (uint8)cameraRole; }
		void setLightRole(const LightRoles::Enum& lightRole) { *_lightRoles |= (uint8)lightRole; }

		void setBodyPart(const BodyParts::Enum& bodyPart) { *_bodyParts |= (uint32)bodyPart; }
		void setFacialPart(const FacialParts::Enum& facialPart) { *_facialParts |= (uint32)facialPart; }
		void setRenderSetting(const RenderSettings::Enum& renderSetting) { *_renderSettings |= (uint32)renderSetting; }
		void setViewportSetting(const ViewportSettings::Enum& viewportSetting) { *_viewportSettings |= (uint32)viewportSetting; }

		void setCustomPart(const CustomParts::Enum& customPart) { *_customParts |= (uint64)customPart; }
		void setCustomFlag(const CustomFlags::Enum& customFlag) { *_customFlags |= (uint64)customFlag; }
		void setPipelineFlag(const PipelineFlags::Enum& pipelineFlag) { *_pipelineFlags |= (uint64)pipelineFlag; }

		// Bit-Pattern Multi-Bit Setters
		void setObjectTypeFlags(const uint8& objectTypeFlags) { *_objectTypeFlags |= objectTypeFlags; }
		void setPartSides(const uint8& partSides) { *_partSides |= partSides; }
		void setCameraRoles(const uint8& cameraRoles) { *_cameraRoles |= cameraRoles; }
		void setLightRoles(const uint8& lightRoles) { *_lightRoles |= lightRoles; }

		void setBodyParts(const uint32& bodyParts) { *_bodyParts |= bodyParts; }
		void setFacialParts(const uint32& facialParts) { *_facialParts |= facialParts; }
		void setRenderSettings(const uint32& renderSettings) { *_renderSettings |= renderSettings; }
		void setViewportSettings(const uint32& viewportSettings) { *_viewportSettings |= viewportSettings; }

		void setCustomParts(const uint64& parts) { *_customParts |= parts; }
		void setCustomFlags(const uint64& customFlags) { *_customFlags |= customFlags; }
		void setPipelineFlags(const uint64& pipelineFlags) { *_pipelineFlags |= pipelineFlags; }

		// Bit-Pattern Single-Bit disablers
		void unsetObjectTypeFlag(const ObjectTypeFlags::Enum& objectTypeFlag) { *_objectTypeFlags &= ~(uint8)objectTypeFlag; }
		void unsetPartSide(const PartSides::Enum& partSide) { *_partSides &= ~(uint8)partSide; }
		void unsetCameraRole(const CameraRoles::Enum& cameraRole) { *_cameraRoles &= ~(uint8)cameraRole; }
		void unsetLightRole(const LightRoles::Enum& lightRole) { *_lightRoles &= ~(uint8)lightRole; }

		void unsetBodyPart(const BodyParts::Enum& bodyPart) { *_bodyParts &= ~(uint32)bodyPart; }
		void unsetFacialPart(const FacialParts::Enum& facialPart) { *_facialParts &= ~(uint32)facialPart; }
		void unsetRenderSetting(const RenderSettings::Enum& renderSetting) { *_renderSettings &= ~(uint32)renderSetting; }
		void unsetViewportSetting(const ViewportSettings::Enum& viewportSetting) { *_viewportSettings &= ~(uint32)viewportSetting; }

		void unsetCustomPart(const CustomParts::Enum& customPart) { *_customParts &= ~(uint64)customPart; }
		void unsetCustomFlag(const CustomFlags::Enum& customFlag) { *_customFlags &= ~(uint64)customFlag; }
		void unsetPipelineFlag(const PipelineFlags::Enum& pipelineFlag) { *_pipelineFlags &= ~(uint64)pipelineFlag; }

		// Bit-Pattern Multi-Bit disablers
		void unsetObjectTypeFlags(const uint8& objectTypeFlags) { *_objectTypeFlags &= ~objectTypeFlags; }
		void unsetPartSides(const uint8& partSides) { *_partSides &= ~partSides; }
		void unsetCameraRoles(const uint8& cameraRoles) { *_cameraRoles &= ~cameraRoles; }
		void unsetLightRoles(const uint8& lightRoles) { *_lightRoles &= ~lightRoles; }

		void unsetBodyParts(const uint32& bodyParts) { *_bodyParts &= ~bodyParts; }
		void unsetFacialParts(const uint32& facialParts) { *_facialParts &= ~facialParts; }
		void unsetRenderSettings(const uint32& renderSettings) { *_renderSettings &= ~renderSettings; }
		void unsetViewportSettings(const uint32& viewportSettings) { *_viewportSettings &= ~viewportSettings; }

		void unsetCustomParts(const uint64& customParts) { *_customParts &= ~customParts; }
		void unsetCustomFlags(const uint64& customFlags) { *_customFlags &= ~customFlags; }
		void unsetPipelineFlags(const uint64& pipelineFlags) { *_pipelineFlags &= ~pipelineFlags; }

		// Bit-Pattern Clears
		void clearObjectTypeFlags() { *_objectTypeFlags = 0; }
		void clearPartSides() { *_partSides = 0; }
		void clearCameraRoles() { *_cameraRoles = 0; }
		void clearLightRoles() { *_lightRoles = 0; }

		void clearBodyParts() { *_bodyParts = 0; }
		void clearFacialParts() { *_facialParts = 0; }
		void clearRenderSettings() { *_renderSettings = 0; }
		void clearViewportSettings() { *_viewportSettings = 0; }

		void clearCustomParts() { *_customParts = 0; }
		void clearCustomFlags() { *_customFlags = 0; }
		void clearPipelineFlags() { *_pipelineFlags = 0; }

		// Bit-Pattern Checkers
		bool isObjectTypeFlagSet(const ObjectTypeFlags::Enum& objectTypeFlag) { return (*_objectTypeFlags & (uint8)objectTypeFlag) != 0; }
		bool isPartSideSet(const PartSides::Enum& partSide) { return (*_partSides & (uint8)partSide) != 0; }
		bool isCameraRoleSet(const CameraRoles::Enum& cameraRole) { return (*_cameraRoles & (uint8)cameraRole) != 0; }
		bool isLightRoleSet(const LightRoles::Enum& lightRole) { return (*_lightRoles & (uint8)lightRole) != 0; }

		bool isBodyPartSet(const BodyParts::Enum& bodyPart) { return (*_bodyParts & (uint32)bodyPart) != 0; }
		bool isFacialPartSet(const FacialParts::Enum& facialPart) { return (*_facialParts & (uint32)facialPart) != 0; }
		bool isRenderSettingSet(const RenderSettings::Enum& renderSetting) { return (*_renderSettings & (uint32)renderSetting) != 0; }
		bool isViewportSettingSet(const ViewportSettings::Enum& viewportSetting) { return (*_viewportSettings & (uint32)viewportSetting) != 0; }

		bool isCustomPartSet(const CustomParts::Enum& customPart) { return (*_customParts & (uint64)customPart) != 0; }
		bool isCustomFlagSet(const CustomFlags::Enum& customFlag) { return (*_customFlags & (uint64)customFlag) != 0; }
		bool isPipelineFlagSet(const PipelineFlags::Enum& pipelineFlag) { return (*_pipelineFlags & (uint64)pipelineFlag) != 0; }
	};		  
}

#endif