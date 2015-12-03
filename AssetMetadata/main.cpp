#include <iostream>
#include "AssetMetadata.h"

using namespace std;
using namespace Pipeline;

int main(int argc, char* argv[])
{
	AssetMetadata assetMetadata;

	ObjectTypes::Enum objectType = ObjectTypes::kRig;
	ObjectTypeFlags::Enum objectTypeFlag = ObjectTypeFlags::kRoot;
	PartSides::Enum partSide = PartSides::kInner;
	CameraRoles::Enum cameraRole = CameraRoles::kProjection;
	LightRoles::Enum lightRole = LightRoles::kRim;
	AssetTypes::Enum assetType = AssetTypes::kProp;
	AssetModes::Enum assetMode = AssetModes::kProxy;
	uint16 objectID = 12345;
	uint16 parentID = 54321;
	uint16 assetID = 33333;
	uint16 assetVersion = 2222;
	BodyParts::Enum bodyPart = BodyParts::kArm;
	FacialParts::Enum facialPart = FacialParts::kEye;
	RenderSettings::Enum renderSetting = RenderSettings::kVisibleToRefractions;
	ViewportSettings::Enum viewportSetting = ViewportSettings::kLocked;
	CustomParts::Enum customPart = CustomParts::kCustomPart_01;
	CustomFlags::Enum customFlag = CustomFlags::kCustomFlag_01;
	PipelineFlags::Enum pipelineFlag = PipelineFlags::kSimulate;
	uint64 productionID = 123456789;

	string objectTypeName = ObjectTypes::getName(objectType);
	string objectTypeFlagName = ObjectTypeFlags::getName(objectTypeFlag);
	string partSideName = PartSides::getName(partSide);
	string cameraRoleName = CameraRoles::getName(cameraRole);
	string lightRoleName = LightRoles::getName(lightRole);
	string assetTypeName = AssetTypes::getName(assetType);
	string assetModeName = AssetModes::getName(assetMode);
	string objectIdName = to_string(objectID);
	string parentIdName = to_string(parentID);
	string assetIdName = to_string(assetID);
	string assetVersionName = to_string(assetVersion);
	string bodyPartName = BodyParts::getName(bodyPart);
	string facialPartName = FacialParts::getName(facialPart);
	string renderSettingName = RenderSettings::getName(renderSetting);
	string viewportSettingName = ViewportSettings::getName(viewportSetting);
	string customPartName = CustomParts::getName(customPart);
	string customFlagName = CustomFlags::getName(customFlag);
	string pipelineFlagName = PipelineFlags::getName(pipelineFlag);
	string productionIdName = to_string(productionID);

	assetMetadata.setObjectType(objectType);
	assetMetadata.setObjectTypeFlag(objectTypeFlag);
	assetMetadata.setPartSide(partSide);
	assetMetadata.setCameraRole(cameraRole);
	assetMetadata.setLightRole(lightRole);
	assetMetadata.setAssetMode(assetMode);
	assetMetadata.setAssetType(assetType);
	assetMetadata.setObjectID(objectID);
	assetMetadata.setParentID(parentID);
	assetMetadata.setAssetID(assetID);
	assetMetadata.setAssetVersion(assetVersion);
	assetMetadata.setBodyPart(bodyPart);
	assetMetadata.setFacialPart(facialPart);
	assetMetadata.setRenderSetting(renderSetting);
	assetMetadata.setViewportSetting(viewportSetting);
	assetMetadata.setCustomPart(customPart);
	assetMetadata.setCustomFlag(customFlag);
	assetMetadata.setPipelineFlag(pipelineFlag);
	assetMetadata.setProductionID(productionID);

	ObjectTypes::Enum objectType_stored = assetMetadata.getObjectType();
	AssetTypes::Enum assetType_stored = assetMetadata.getAssetType();
	AssetModes::Enum assetMode_stored = assetMetadata.getAssetMode();
	uint16 objectID_stored = assetMetadata.getObjectID();
	uint16 parentID_stored = assetMetadata.getParentID();
	uint16 assetID_stored = assetMetadata.getAssetID();
	uint16 assetVersion_stored = assetMetadata.getAssetVersion();
	uint64 productionID_stored = assetMetadata.getProductionID();

	string objectTypeName_stored = assetMetadata.getObjectType_toString();
	string assetTypeName_stored = assetMetadata.getAssetType_toString();
	string assetModeName_stored = assetMetadata.getAssetMode_toString();
	string objectIdName_stored = assetMetadata.getObjectID_toString();
	string parentIdName_stored = assetMetadata.getParentID_toString();
	string assetIdName_stored = assetMetadata.getAssetID_toString();
	string assetVersionName_stored = assetMetadata.getAssetVersion_toString();
	string productionIdName_stored = assetMetadata.getProductionID_toString();

	if (objectType != objectType_stored || objectTypeName.compare(objectTypeName_stored) != 0) cout <<
		"Given Object-Type: " << objectTypeName << "(" << objectType << ")" <<
		" is different from: " << objectTypeName << "(" << objectType_stored << ")" << endl;

	if (assetType != assetType_stored || assetTypeName.compare(assetTypeName_stored) != 0) cout <<
		"Given Asset-Type: " << assetTypeName << "(" << assetType << ")" <<
		" is different from: " << assetTypeName_stored << "(" << assetType_stored << ")" << endl;

	if (assetMode != assetMode_stored || assetModeName.compare(assetModeName_stored) != 0) cout <<
		"Given Asset-Mode: " << assetModeName << "(" << assetMode << ")" <<
		" is different from: " << assetModeName_stored << "(" << assetMode_stored << ")" << endl;

	if (objectID != objectID_stored || objectIdName.compare(objectIdName_stored) != 0) cout <<
		"Given Object-ID: " << objectIdName << "(" << objectID << ")" <<
		" is different from: " << objectIdName_stored << "(" << objectID_stored << ")" << endl;

	if (parentID != parentID_stored || parentIdName.compare(parentIdName_stored) != 0) cout <<
		"Given Parent-ID: " << parentIdName << "(" << parentID << ")" <<
		" is different from: " << parentIdName_stored << "(" << parentID_stored << ")" << endl;

	if (assetID != assetID_stored || assetIdName.compare(assetIdName_stored) != 0) cout <<
		"Given Asset-ID: " << assetIdName << "(" << assetID << ")" <<
		" is different from: " << assetIdName_stored << "(" << assetID_stored << ")" << endl;

	if (assetVersion != assetVersion_stored || assetVersionName.compare(assetVersionName_stored) != 0) cout <<
		"Given Asset-Version: " << assetVersionName << "(" << assetVersion << ")" <<
		" is different from: " << assetVersionName_stored << "(" << assetVersion_stored << ")" << endl;

	if (productionID != productionID_stored || productionIdName.compare(productionIdName_stored) != 0) cout <<
		"Given Production-ID: " << productionIdName << "(" << productionID << ")" <<
		" is different from: " << productionIdName_stored << "(" << productionID_stored << ")" << endl;

	if (!assetMetadata.isObjectTypeFlagSet(objectTypeFlag)) cout <<
		"Given Object-Type-Flag:" << ObjectTypeFlags::getName(objectTypeFlag) << "(" << objectTypeFlag << ")" <<
		" failed to be set" << endl;

	if (!assetMetadata.isPartSideSet(partSide)) cout <<
		"Given Part-Side:" << PartSides::getName(partSide) << "(" << partSide << ")" <<
		" failed to be set" << endl;

	if (!assetMetadata.isCameraRoleSet(cameraRole)) cout <<
		"Given Camera-Role:" << CameraRoles::getName(cameraRole) << "(" << cameraRole << ")" <<
		" failed to be set" << endl;

	if (!assetMetadata.isLightRoleSet(lightRole)) cout <<
		"Given Light-Role:" << LightRoles::getName(lightRole) << "(" << lightRole << ")" <<
		" failed to be set" << endl;

	if (!assetMetadata.isBodyPartSet(bodyPart)) cout <<
		"Given Body-Part:" << BodyParts::getName(bodyPart) << "(" << bodyPart << ")" <<
		" failed to be set" << endl;
	
	if (!assetMetadata.isFacialPartSet(facialPart)) cout <<
		"Given Facial-Part:" << FacialParts::getName(facialPart) << "(" << facialPart << ")" <<
		" failed to be set" << endl;

	if (!assetMetadata.isRenderSettingSet(renderSetting)) cout <<
		"Given Render-Setting:" << RenderSettings::getName(renderSetting) << "(" << renderSetting << ")" <<
		" failed to be set" << endl;

	if (!assetMetadata.isViewportSettingSet(viewportSetting)) cout <<
		"Given Viewport-Setting:" << ViewportSettings::getName(viewportSetting) << "(" << viewportSetting << ")" <<
		" failed to be set" << endl;

	if (!assetMetadata.isCustomPartSet(customPart)) cout <<
		"Given Custom-Part:" << CustomParts::getName(customPart) << "(" << customPart << ")" <<
		" failed to be set" << endl;

	if (!assetMetadata.isCustomFlagSet(customFlag)) cout <<
		"Given Custom-Flag:" << CustomFlags::getName(customFlag) << "(" << customFlag << ")" <<
		" failed to be set" << endl;

	if (!assetMetadata.isPipelineFlagSet(pipelineFlag)) cout <<
		"Given Pipeline-Flag:" << PipelineFlags::getName(pipelineFlag) << "(" << pipelineFlag << ")" <<
		" failed to be set" << endl;


	assetMetadata.unsetObjectTypeFlag(objectTypeFlag);
	assetMetadata.unsetPartSide(partSide);
	assetMetadata.unsetCameraRole(cameraRole);
	assetMetadata.unsetLightRole(lightRole);
	assetMetadata.unsetBodyPart(bodyPart);
	assetMetadata.unsetFacialPart(facialPart);
	assetMetadata.unsetRenderSetting(renderSetting);
	assetMetadata.unsetViewportSetting(viewportSetting);
	assetMetadata.unsetCustomPart(customPart);
	assetMetadata.unsetCustomFlag(customFlag);
	assetMetadata.unsetPipelineFlag(pipelineFlag);


	if (assetMetadata.isObjectTypeFlagSet(objectTypeFlag)) cout <<
		"Given Object-Type-Flag:" << ObjectTypeFlags::getName(objectTypeFlag) << "(" << objectTypeFlag << ")" <<
		" failed to be unset" << endl;

	if (assetMetadata.isPartSideSet(partSide)) cout <<
		"Given Part-Side:" << PartSides::getName(partSide) << "(" << partSide << ")" <<
		" failed to be unset" << endl;

	if (assetMetadata.isCameraRoleSet(cameraRole)) cout <<
		"Given Camera-Role:" << CameraRoles::getName(cameraRole) << "(" << cameraRole << ")" <<
		" failed to be unset" << endl;

	if (assetMetadata.isLightRoleSet(lightRole)) cout <<
		"Given Light-Role:" << LightRoles::getName(lightRole) << "(" << lightRole << ")" <<
		" failed to be unset" << endl;

	if (assetMetadata.isBodyPartSet(bodyPart)) cout <<
		"Given Body-Part:" << BodyParts::getName(bodyPart) << "(" << bodyPart << ")" <<
		" failed to be unset" << endl;

	if (assetMetadata.isFacialPartSet(facialPart)) cout <<
		"Given Facial-Part:" << FacialParts::getName(facialPart) << "(" << facialPart << ")" <<
		" failed to be unset" << endl;

	if (assetMetadata.isRenderSettingSet(renderSetting)) cout <<
		"Given Render-Setting:" << RenderSettings::getName(renderSetting) << "(" << renderSetting << ")" <<
		" failed to be unset" << endl;

	if (assetMetadata.isViewportSettingSet(viewportSetting)) cout <<
		"Given Viewport-Setting:" << ViewportSettings::getName(viewportSetting) << "(" << viewportSetting << ")" <<
		" failed to be unset" << endl;

	if (assetMetadata.isCustomPartSet(customPart)) cout <<
		"Given Custom-Part:" << CustomParts::getName(customPart) << "(" << customPart << ")" <<
		" failed to be unset" << endl;

	if (assetMetadata.isCustomFlagSet(customFlag)) cout <<
		"Given Custom-Flag:" << CustomFlags::getName(customFlag) << "(" << customFlag << ")" <<
		" failed to be unset" << endl;

	if (assetMetadata.isPipelineFlagSet(pipelineFlag)) cout <<
		"Given Pipeline-Flag:" << PipelineFlags::getName(pipelineFlag) << "(" << pipelineFlag << ")" <<
		" failed to be unset" << endl;

	//objectType;
	//objectTypeFlags;
	//partSides;
	//cameraRoles;
	//lightRoles;
	//assetMode;
	//assetType;

	//objectID;
	//parentID;
	//assetID;
	//assetVersion;

	//bodyParts;
	//facialParts;
	//renderSettings;
	//viewportSettings;

	//customParts;
	//customFlags;
	//pipelineFlags;
	//productionID;



	ObjectTypeFlags::Enum objectTypeFlagArray[2] = {ObjectTypeFlags::kFK, ObjectTypeFlags::kIK};
	PartSides::Enum partSideArray[2] = {PartSides::kLower, PartSides::kLeft};
	CameraRoles::Enum cameraRoleArray[2] = {CameraRoles::kRender, CameraRoles::kUI};
	LightRoles::Enum lightRoleArray[2] = {LightRoles::kKey, LightRoles::kFill};
	BodyParts::Enum bodyPartArray[2] = {BodyParts::kLeg, BodyParts::kAnkle};
	FacialParts::Enum facialPartArray[2] = {FacialParts::kCheek, FacialParts::kChin};
	RenderSettings::Enum renderSettingArray[2] = {RenderSettings::kRenderable, RenderSettings::kVisibleToCamera};
	ViewportSettings::Enum viewportSettingArray[2] = {ViewportSettings::kHidden, ViewportSettings::kTemplate};
	CustomParts::Enum customPartArray[2] = {CustomParts::kCustomPart_29, CustomParts::kCustomPart_04};
	CustomFlags::Enum customFlagArray[2] = {CustomFlags::kCustomFlag_07, CustomFlags::kCustomFlag_24};
	PipelineFlags::Enum pipelineFlagArray[2] = {PipelineFlags::kCache, PipelineFlags::kBake};

	uint8 objectTypeFlags = objectTypeFlagArray[0] | objectTypeFlagArray[1];
	uint8 partSides = partSideArray[0] | partSideArray[1];
	uint8 cameraRoles = cameraRoleArray[0] | cameraRoleArray[1];
	uint8 lightRoles = lightRoleArray[0] | lightRoleArray[1];
	uint32 bodyParts = bodyPartArray[0] | bodyPartArray[1];
	uint32 facialParts = facialPartArray[0] | facialPartArray[1];
	uint32 renderSettings = renderSettingArray[0] | renderSettingArray[1];
	uint32 viewportSettings = viewportSettingArray[0] | viewportSettingArray[1];
	uint64 customParts = customPartArray[0] | customPartArray[1];
	uint64 customFlags = customFlagArray[0] | customFlagArray[1];
	uint64 pipelineFlags = pipelineFlagArray[0] | pipelineFlagArray[1];

	vector<string> objectTypeFlagNames = ObjectTypeFlags::getNames(objectTypeFlags);
	vector<string> partSideNames = PartSides::getNames(partSides);
	vector<string> cameraRoleNames = CameraRoles::getNames(cameraRoles);
	vector<string> lightRoleNames = LightRoles::getNames(lightRoles);
	vector<string> bodyPartNames = BodyParts::getNames(bodyParts);
	vector<string> facialPartsNames = FacialParts::getNames(facialParts);
	vector<string> renderSettingNames = RenderSettings::getNames(renderSettings);
	vector<string> viewportSettingsNames = ViewportSettings::getNames(viewportSettings);
	vector<string> customPartNames = CustomParts::getNames(customParts);
	vector<string> customFlagNames = CustomFlags::getNames(customFlags);
	vector<string> pipelineFlagNames = PipelineFlags::getNames(pipelineFlags);


	assetMetadata.setObjectTypeFlags(objectTypeFlags);
	assetMetadata.setPartSides(partSides);
	assetMetadata.setCameraRoles(cameraRoles);
	assetMetadata.setLightRoles(lightRoles);
	assetMetadata.setBodyParts(bodyParts);
	assetMetadata.setFacialParts(facialParts);
	assetMetadata.setRenderSettings(renderSettings);
	assetMetadata.setViewportSettings(viewportSettings);
	assetMetadata.setCustomParts(customParts);
	assetMetadata.setCustomFlags(customFlags);
	assetMetadata.setPipelineFlags(pipelineFlags);

	vector<string> objectTypeFlagNames_stored = assetMetadata.getObjectTypeFlags_toString();
	vector<string> partSideNames_stored = assetMetadata.getPartSides_toString();
	vector<string> cameraRoleNames_stored = assetMetadata.getCameraRoles_toString();
	vector<string> lightRoleNames_stored = assetMetadata.getLightRoles_toString();
	vector<string> bodyPartNames_stored = assetMetadata.getBodyParts_toString();
	vector<string> facialPartsNames_stored = assetMetadata.getFacialParts_toString();
	vector<string> renderSettingNames_stored = assetMetadata.getRenderSettings_toString();
	vector<string> viewportSettingsNames_stored = assetMetadata.getViewportSettings_toString();
	vector<string> customPartNames_stored = assetMetadata.getCustomParts_toString();
	vector<string> customFlagNames_stored = assetMetadata.getCustomFlags_toString();
	vector<string> pipelineFlagNames_stored = assetMetadata.getPipelineFlags_toString();

	if (
		!assetMetadata.isObjectTypeFlagSet(objectTypeFlagArray[0]) ||
		!assetMetadata.isObjectTypeFlagSet(objectTypeFlagArray[1]) ||
		objectTypeFlagNames[0].compare(objectTypeFlagNames_stored[0]) != 0 ||
		objectTypeFlagNames[1].compare(objectTypeFlagNames_stored[1]) != 0
		) cout << "Given Object-Type-Flags:" << endl <<
		"  1: " << objectTypeFlagNames[0] << "(" << objectTypeFlagArray[0] << ") [" << objectTypeFlagNames_stored[0] << "]" << endl <<
		"  2: " << objectTypeFlagNames[1] << "(" << objectTypeFlagArray[1] << ") [" << objectTypeFlagNames_stored[1] << "]" << endl;

	if (
		!assetMetadata.isPartSideSet(partSideArray[0]) ||
		!assetMetadata.isPartSideSet(partSideArray[1]) ||
		partSideNames[0].compare(partSideNames_stored[0]) != 0 ||
		partSideNames[1].compare(partSideNames_stored[1]) != 0
		) cout << "Given Part-Sides:" << endl <<
		"  1: " << partSideNames[0] << "(" << partSideArray[0] << ") [" << partSideNames_stored[0] << "]" << endl <<
		"  2: " << partSideNames[1] << "(" << partSideArray[1] << ") [" << partSideNames_stored[1] << "]" << endl;

	if (
		!assetMetadata.isCameraRoleSet(cameraRoleArray[0]) ||
		!assetMetadata.isCameraRoleSet(cameraRoleArray[1]) ||
		cameraRoleNames[0].compare(cameraRoleNames_stored[0]) != 0 ||
		cameraRoleNames[1].compare(cameraRoleNames_stored[1]) != 0
		) cout << "Given Camera-Roles:" << endl <<
		"  1: " << cameraRoleNames[0] << "(" << cameraRoleArray[0] << ") [" << cameraRoleNames_stored[0] << "]" << endl <<
		"  2: " << cameraRoleNames[1] << "(" << cameraRoleArray[1] << ") [" << cameraRoleNames_stored[1] << "]" << endl;

	if (
		!assetMetadata.isLightRoleSet(lightRoleArray[0]) ||
		!assetMetadata.isLightRoleSet(lightRoleArray[1]) ||
		lightRoleNames[0].compare(lightRoleNames_stored[0]) != 0 ||
		lightRoleNames[1].compare(lightRoleNames_stored[1]) != 0
		) cout << "Given Light-Roles:" << endl <<
		"  1: " << lightRoleNames[0] << "(" << lightRoleArray[0] << ") [" << lightRoleNames_stored[0] << "]" << endl <<
		"  2: " << lightRoleNames[1] << "(" << lightRoleArray[1] << ") [" << lightRoleNames_stored[1] << "]" << endl;

	if (
		!assetMetadata.isBodyPartSet(bodyPartArray[0]) ||
		!assetMetadata.isBodyPartSet(bodyPartArray[1]) ||
		bodyPartNames[0].compare(bodyPartNames_stored[0]) != 0 ||
		bodyPartNames[1].compare(bodyPartNames_stored[1]) != 0
		) cout << "Given Body-Parts:" << endl <<
		"  1: " << bodyPartNames[0] << "(" << bodyPartArray[0] << ") [" << bodyPartNames_stored[0] << "]" << endl <<
		"  2: " << bodyPartNames[1] << "(" << bodyPartArray[1] << ") [" << bodyPartNames_stored[1] << "]" << endl;

	if (
		!assetMetadata.isFacialPartSet(facialPartArray[0]) ||
		!assetMetadata.isFacialPartSet(facialPartArray[1]) ||
		facialPartsNames[0].compare(facialPartsNames_stored[0]) != 0 ||
		facialPartsNames[1].compare(facialPartsNames_stored[1]) != 0
		) cout << "Given Facial-Parts:" << endl <<
		"  1: " << facialPartsNames[0] << "(" << facialPartArray[0] << ") [" << facialPartsNames_stored[0] << "]" << endl <<
		"  2: " << facialPartsNames[1] << "(" << facialPartArray[1] << ") [" << facialPartsNames_stored[1] << "]" << endl;

	if (
		!assetMetadata.isRenderSettingSet(renderSettingArray[0]) ||
		!assetMetadata.isRenderSettingSet(renderSettingArray[1]) ||
		renderSettingNames[0].compare(renderSettingNames_stored[0]) != 0 ||
		renderSettingNames[1].compare(renderSettingNames_stored[1]) != 0
		) cout << "Given Render-Settings:" << endl <<
		"  1: " << renderSettingNames[0] << "(" << renderSettingArray[0] << ") [" << renderSettingNames_stored[0] << "]" << endl <<
		"  2: " << renderSettingNames[1] << "(" << renderSettingArray[1] << ") [" << renderSettingNames_stored[1] << "]" << endl;

	if (
		!assetMetadata.isViewportSettingSet(viewportSettingArray[0]) ||
		!assetMetadata.isViewportSettingSet(viewportSettingArray[1]) ||
		viewportSettingsNames[0].compare(viewportSettingsNames_stored[0]) != 0 ||
		viewportSettingsNames[1].compare(viewportSettingsNames_stored[1]) != 0
		) cout << "Given Viewport-Settings:" << endl <<
		"  1: " << viewportSettingsNames[0] << "(" << viewportSettingArray[0] << ") [" << viewportSettingsNames_stored[0] << "]" << endl <<
		"  2: " << viewportSettingsNames[1] << "(" << viewportSettingArray[1] << ") [" << viewportSettingsNames_stored[1] << "]" << endl;

	if (
		!assetMetadata.isCustomPartSet(customPartArray[0]) ||
		!assetMetadata.isCustomPartSet(customPartArray[1]) ||
		customPartNames[0].compare(customPartNames_stored[0]) != 0 ||
		customPartNames[1].compare(customPartNames_stored[1]) != 0
		) cout << "Given Custom-Parts:" << endl <<
		"  1: " << customPartNames[0] << "(" << customPartArray[0] << ") [" << customPartNames_stored[0] << "]" << endl <<
		"  2: " << customPartNames[1] << "(" << customPartArray[1] << ") [" << customPartNames_stored[1] << "]" << endl;

	if (
		!assetMetadata.isCustomFlagSet(customFlagArray[0]) ||
		!assetMetadata.isCustomFlagSet(customFlagArray[1]) ||
		customFlagNames[0].compare(customFlagNames_stored[0]) != 0 ||
		customFlagNames[1].compare(customFlagNames_stored[1]) != 0
		) cout << "Given Custom-Flags:" << endl <<
		"  1: " << customFlagNames[0] << "(" << customFlagArray[0] << ") [" << customFlagNames_stored[0] << "]" << endl <<
		"  2: " << customFlagNames[1] << "(" << customFlagArray[1] << ") [" << customFlagNames_stored[1] << "]" << endl;

	if (
		!assetMetadata.isPipelineFlagSet(pipelineFlagArray[0]) ||
		!assetMetadata.isPipelineFlagSet(pipelineFlagArray[1]) ||
		pipelineFlagNames[0].compare(pipelineFlagNames_stored[0]) != 0 ||
		pipelineFlagNames[1].compare(pipelineFlagNames_stored[1]) != 0
		) cout << "Given Pipeline-Flags:" << endl <<
		"  1: " << pipelineFlagNames[0] << "(" << pipelineFlagArray[0] << ") [" << pipelineFlagNames_stored[0] << "]" << endl <<
		"  2: " << pipelineFlagNames[1] << "(" << pipelineFlagArray[1] << ") [" << pipelineFlagNames_stored[1] << "]" << endl;


	assetMetadata.unsetObjectTypeFlags(objectTypeFlags);
	assetMetadata.unsetPartSides(partSides);
	assetMetadata.unsetCameraRoles(cameraRoles);
	assetMetadata.unsetLightRoles(lightRoles);
	assetMetadata.unsetBodyParts(bodyParts);
	assetMetadata.unsetFacialParts(facialParts);
	assetMetadata.unsetRenderSettings(renderSettings);
	assetMetadata.unsetViewportSettings(viewportSettings);
	assetMetadata.unsetCustomParts(customParts);
	assetMetadata.unsetCustomFlags(customFlags);
	assetMetadata.unsetPipelineFlags(pipelineFlags);


	if (
		assetMetadata.isObjectTypeFlagSet(objectTypeFlagArray[0]) ||
		assetMetadata.isObjectTypeFlagSet(objectTypeFlagArray[1])
		) cout << "Failed to un-set Object-Type-Flags:" << endl <<
		"  1: " << objectTypeFlagNames[0] << "(" << objectTypeFlagArray[0] << ") [" << objectTypeFlagNames_stored[0] << "]" << endl <<
		"  2: " << objectTypeFlagNames[1] << "(" << objectTypeFlagArray[1] << ") [" << objectTypeFlagNames_stored[1] << "]" << endl;

	if (
		assetMetadata.isPartSideSet(partSideArray[0]) ||
		assetMetadata.isPartSideSet(partSideArray[1])
		) cout << "Failed to un-set Part-Sides:" << endl <<
		"  1: " << partSideNames[0] << "(" << partSideArray[0] << ") [" << partSideNames_stored[0] << "]" << endl <<
		"  2: " << partSideNames[1] << "(" << partSideArray[1] << ") [" << partSideNames_stored[1] << "]" << endl;

	if (
		assetMetadata.isCameraRoleSet(cameraRoleArray[0]) ||
		assetMetadata.isCameraRoleSet(cameraRoleArray[1])
		) cout << "Failed to un-set Camera-Roles:" << endl <<
		"  1: " << cameraRoleNames[0] << "(" << cameraRoleArray[0] << ") [" << cameraRoleNames_stored[0] << "]" << endl <<
		"  2: " << cameraRoleNames[1] << "(" << cameraRoleArray[1] << ") [" << cameraRoleNames_stored[1] << "]" << endl;

	if (
		assetMetadata.isLightRoleSet(lightRoleArray[0]) ||
		assetMetadata.isLightRoleSet(lightRoleArray[1])
		) cout << "Failed to un-set Light-Roles:" << endl <<
		"  1: " << lightRoleNames[0] << "(" << lightRoleArray[0] << ") [" << lightRoleNames_stored[0] << "]" << endl <<
		"  2: " << lightRoleNames[1] << "(" << lightRoleArray[1] << ") [" << lightRoleNames_stored[1] << "]" << endl;

	if (
		assetMetadata.isBodyPartSet(bodyPartArray[0]) ||
		assetMetadata.isBodyPartSet(bodyPartArray[1])
		) cout << "Failed to un-set Body-Parts:" << endl <<
		"  1: " << bodyPartNames[0] << "(" << bodyPartArray[0] << ") [" << bodyPartNames_stored[0] << "]" << endl <<
		"  2: " << bodyPartNames[1] << "(" << bodyPartArray[1] << ") [" << bodyPartNames_stored[1] << "]" << endl;

	if (
		assetMetadata.isFacialPartSet(facialPartArray[0]) ||
		assetMetadata.isFacialPartSet(facialPartArray[1])
		) cout << "Failed to un-set Facial-Parts:" << endl <<
		"  1: " << facialPartsNames[0] << "(" << facialPartArray[0] << ") [" << facialPartsNames_stored[0] << "]" << endl <<
		"  2: " << facialPartsNames[1] << "(" << facialPartArray[1] << ") [" << facialPartsNames_stored[1] << "]" << endl;

	if (
		assetMetadata.isRenderSettingSet(renderSettingArray[0]) ||
		assetMetadata.isRenderSettingSet(renderSettingArray[1])
		) cout << "Failed to un-set Render-Settings:" << endl <<
		"  1: " << renderSettingNames[0] << "(" << renderSettingArray[0] << ") [" << renderSettingNames_stored[0] << "]" << endl <<
		"  2: " << renderSettingNames[1] << "(" << renderSettingArray[1] << ") [" << renderSettingNames_stored[1] << "]" << endl;

	if (
		assetMetadata.isViewportSettingSet(viewportSettingArray[0]) ||
		assetMetadata.isViewportSettingSet(viewportSettingArray[1])
		) cout << "Failed to un-set Viewport-Settings:" << endl <<
		"  1: " << viewportSettingsNames[0] << "(" << viewportSettingArray[0] << ") [" << viewportSettingsNames_stored[0] << "]" << endl <<
		"  2: " << viewportSettingsNames[1] << "(" << viewportSettingArray[1] << ") [" << viewportSettingsNames_stored[1] << "]" << endl;

	if (
		assetMetadata.isCustomPartSet(customPartArray[0]) ||
		assetMetadata.isCustomPartSet(customPartArray[1])
		) cout << "Failed to un-set Custom-Parts:" << endl <<
		"  1: " << customPartNames[0] << "(" << customPartArray[0] << ") [" << customPartNames_stored[0] << "]" << endl <<
		"  2: " << customPartNames[1] << "(" << customPartArray[1] << ") [" << customPartNames_stored[1] << "]" << endl;

	if (
		assetMetadata.isCustomFlagSet(customFlagArray[0]) ||
		assetMetadata.isCustomFlagSet(customFlagArray[1])
		) cout << "Failed to un-set Custom-Flags:" << endl <<
		"  1: " << customFlagNames[0] << "(" << customFlagArray[0] << ") [" << customFlagNames_stored[0] << "]" << endl <<
		"  2: " << customFlagNames[1] << "(" << customFlagArray[1] << ") [" << customFlagNames_stored[1] << "]" << endl;

	if (
		assetMetadata.isPipelineFlagSet(pipelineFlagArray[0]) ||
		assetMetadata.isPipelineFlagSet(pipelineFlagArray[1])
		) cout << "Failed to un-set Pipeline-Flags:" << endl <<
		"  1: " << pipelineFlagNames[0] << "(" << pipelineFlagArray[0] << ") [" << pipelineFlagNames_stored[0] << "]" << endl <<
		"  2: " << pipelineFlagNames[1] << "(" << pipelineFlagArray[1] << ") [" << pipelineFlagNames_stored[1] << "]" << endl;

	assetMetadata.setObjectTypeFlags(objectTypeFlags);
	assetMetadata.setPartSides(partSides);
	assetMetadata.setCameraRoles(cameraRoles);
	assetMetadata.setLightRoles(lightRoles);
	assetMetadata.setBodyParts(bodyParts);
	assetMetadata.setFacialParts(facialParts);
	assetMetadata.setRenderSettings(renderSettings);
	assetMetadata.setViewportSettings(viewportSettings);
	assetMetadata.setCustomParts(customParts);
	assetMetadata.setCustomFlags(customFlags);
	assetMetadata.setPipelineFlags(pipelineFlags);

	assetMetadata.clearObjectTypeFlags();
	assetMetadata.clearPartSides();
	assetMetadata.clearCameraRoles();
	assetMetadata.clearLightRoles();
	assetMetadata.clearBodyParts();
	assetMetadata.clearFacialParts();
	assetMetadata.clearRenderSettings();
	assetMetadata.clearViewportSettings();
	assetMetadata.clearCustomParts();
	assetMetadata.clearCustomFlags();
	assetMetadata.clearPipelineFlags();
	if (
		assetMetadata.isObjectTypeFlagSet(objectTypeFlagArray[0]) ||
		assetMetadata.isObjectTypeFlagSet(objectTypeFlagArray[1])
		) cout << "Failed to clear Object-Type-Flags:" << endl <<
		"  1: " << objectTypeFlagNames[0] << "(" << objectTypeFlagArray[0] << ") [" << objectTypeFlagNames_stored[0] << "]" << endl <<
		"  2: " << objectTypeFlagNames[1] << "(" << objectTypeFlagArray[1] << ") [" << objectTypeFlagNames_stored[1] << "]" << endl;

	if (
		assetMetadata.isPartSideSet(partSideArray[0]) ||
		assetMetadata.isPartSideSet(partSideArray[1])
		) cout << "Failed to clear Part-Sides:" << endl <<
		"  1: " << partSideNames[0] << "(" << partSideArray[0] << ") [" << partSideNames_stored[0] << "]" << endl <<
		"  2: " << partSideNames[1] << "(" << partSideArray[1] << ") [" << partSideNames_stored[1] << "]" << endl;

	if (
		assetMetadata.isCameraRoleSet(cameraRoleArray[0]) ||
		assetMetadata.isCameraRoleSet(cameraRoleArray[1])
		) cout << "Failed to clear Camera-Roles:" << endl <<
		"  1: " << cameraRoleNames[0] << "(" << cameraRoleArray[0] << ") [" << cameraRoleNames_stored[0] << "]" << endl <<
		"  2: " << cameraRoleNames[1] << "(" << cameraRoleArray[1] << ") [" << cameraRoleNames_stored[1] << "]" << endl;

	if (
		assetMetadata.isLightRoleSet(lightRoleArray[0]) ||
		assetMetadata.isLightRoleSet(lightRoleArray[1])
		) cout << "Failed to clear Light-Roles:" << endl <<
		"  1: " << lightRoleNames[0] << "(" << lightRoleArray[0] << ") [" << lightRoleNames_stored[0] << "]" << endl <<
		"  2: " << lightRoleNames[1] << "(" << lightRoleArray[1] << ") [" << lightRoleNames_stored[1] << "]" << endl;

	if (
		assetMetadata.isBodyPartSet(bodyPartArray[0]) ||
		assetMetadata.isBodyPartSet(bodyPartArray[1])
		) cout << "Failed to clear Body-Parts:" << endl <<
		"  1: " << bodyPartNames[0] << "(" << bodyPartArray[0] << ") [" << bodyPartNames_stored[0] << "]" << endl <<
		"  2: " << bodyPartNames[1] << "(" << bodyPartArray[1] << ") [" << bodyPartNames_stored[1] << "]" << endl;

	if (
		assetMetadata.isFacialPartSet(facialPartArray[0]) ||
		assetMetadata.isFacialPartSet(facialPartArray[1])
		) cout << "Failed to clear Facial-Parts:" << endl <<
		"  1: " << facialPartsNames[0] << "(" << facialPartArray[0] << ") [" << facialPartsNames_stored[0] << "]" << endl <<
		"  2: " << facialPartsNames[1] << "(" << facialPartArray[1] << ") [" << facialPartsNames_stored[1] << "]" << endl;

	if (
		assetMetadata.isRenderSettingSet(renderSettingArray[0]) ||
		assetMetadata.isRenderSettingSet(renderSettingArray[1])
		) cout << "Failed to clear Render-Settings:" << endl <<
		"  1: " << renderSettingNames[0] << "(" << renderSettingArray[0] << ") [" << renderSettingNames_stored[0] << "]" << endl <<
		"  2: " << renderSettingNames[1] << "(" << renderSettingArray[1] << ") [" << renderSettingNames_stored[1] << "]" << endl;

	if (
		assetMetadata.isViewportSettingSet(viewportSettingArray[0]) ||
		assetMetadata.isViewportSettingSet(viewportSettingArray[1])
		) cout << "Failed to clear Viewport-Settings:" << endl <<
		"  1: " << viewportSettingsNames[0] << "(" << viewportSettingArray[0] << ") [" << viewportSettingsNames_stored[0] << "]" << endl <<
		"  2: " << viewportSettingsNames[1] << "(" << viewportSettingArray[1] << ") [" << viewportSettingsNames_stored[1] << "]" << endl;

	if (
		assetMetadata.isCustomPartSet(customPartArray[0]) ||
		assetMetadata.isCustomPartSet(customPartArray[1])
		) cout << "Failed to clear Custom-Parts:" << endl <<
		"  1: " << customPartNames[0] << "(" << customPartArray[0] << ") [" << customPartNames_stored[0] << "]" << endl <<
		"  2: " << customPartNames[1] << "(" << customPartArray[1] << ") [" << customPartNames_stored[1] << "]" << endl;

	if (
		assetMetadata.isCustomFlagSet(customFlagArray[0]) ||
		assetMetadata.isCustomFlagSet(customFlagArray[1])
		) cout << "Failed to clear Custom-Flags:" << endl <<
		"  1: " << customFlagNames[0] << "(" << customFlagArray[0] << ") [" << customFlagNames_stored[0] << "]" << endl <<
		"  2: " << customFlagNames[1] << "(" << customFlagArray[1] << ") [" << customFlagNames_stored[1] << "]" << endl;

	if (
		assetMetadata.isPipelineFlagSet(pipelineFlagArray[0]) ||
		assetMetadata.isPipelineFlagSet(pipelineFlagArray[1])
		) cout << "Failed to clear Pipeline-Flags:" << endl <<
		"  1: " << pipelineFlagNames[0] << "(" << pipelineFlagArray[0] << ") [" << pipelineFlagNames_stored[0] << "]" << endl <<
		"  2: " << pipelineFlagNames[1] << "(" << pipelineFlagArray[1] << ") [" << pipelineFlagNames_stored[1] << "]" << endl;



	cin.get();
	return 0;
}