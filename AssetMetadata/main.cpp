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
	string objectIDName = to_string(objectID);
	string parentIDName = to_string(parentID);
	string assetIDName = to_string(assetID);
	string assetVersionName = to_string(assetVersion);
	string bodyPartName = BodyParts::getName(bodyPart);
	string facialPartName = FacialParts::getName(facialPart);
	string renderSettingName = RenderSettings::getName(renderSetting);
	string viewportSettingName = ViewportSettings::getName(viewportSetting);
	string customPartName = CustomParts::getName(customPart);
	string customFlagName = CustomFlags::getName(customFlag);
	string pipelineFlagName = PipelineFlags::getName(pipelineFlag);
	string productionIDName = to_string(productionID);

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

	string objectTypeName_stored = assetMetadata.getObjectTypeName();
	string assetTypeName_stored = assetMetadata.getAssetTypeName();
	string assetModeName_stored = assetMetadata.getAssetModeName();
	string objectIDName_stored = assetMetadata.getObjectIDName();
	string parentIDName_stored = assetMetadata.getParentIDName();
	string assetIDName_stored = assetMetadata.getAssetIDName();
	string assetVersionName_stored = assetMetadata.getAssetVersionName();
	string productionIDName_stored = assetMetadata.getProductionIDName();

	bool objectType_Tested = objectType == objectType_stored;
	bool assetType_Tested = assetType == assetType_stored;
	bool assetMode_Tested = assetMode == assetMode_stored;
	bool objectID_Tested = objectID == objectID_stored;
	bool parentID_Tested = parentID == parentID_stored;
	bool assetID_Tested = assetID == assetID_stored;
	bool assetVersion_Tested = assetVersion == assetVersion_stored;
	bool productionID_Tested = productionID == productionID_stored;

	if (!objectType_Tested) cout << "Given Object-Type: " << objectTypeName << " is different from: " << objectType_stored << endl;
	if (!assetType_Tested) cout << "Given Asset-Type: " << assetType << " is different from: " << assetType_stored << endl;
	if (!assetMode_Tested) cout << "Given Asset-Mode: " << assetMode << " is different from: " << assetMode_stored << endl;
	if (!objectID_Tested) cout << "Given Object-ID: " << objectID << " is different from: " << objectID_stored << endl;
	if (!parentID_Tested) cout << "Given Parent-ID: " << parentID << " is different from: " << parentID_stored << endl;
	if (!assetID_Tested) cout << "Given Asset-ID: " << assetID << " is different from: " << assetID_stored << endl;
	if (!assetVersion_Tested) cout << "Given Asset-Version: " << assetMode << " is different from: " << assetVersion_stored << endl;
	if (!productionID_Tested) cout << "Given Production-ID: " << productionID << " is different from: " << productionID_stored << endl;

	if (objectType_Tested && assetType_Tested && assetMode_Tested && objectID_Tested && parentID_Tested && assetID_Tested && assetVersion_Tested && productionID_Tested)
		cout << "All Single-Value Tests Passed!" << endl;


	bool objectTypeName_Tested = objectTypeName.compare(objectTypeName_stored) == 0;
	bool assetModeName_Tested = assetModeName.compare(assetModeName_stored) == 0;
	bool assetTypeName_Tested = assetTypeName.compare(assetTypeName_stored) == 0;
	bool objectIDName_Tested = objectIDName.compare(objectIDName_stored) == 0;
	bool parentIDName_Tested = parentIDName.compare(parentIDName_stored) == 0;
	bool assetIDName_Tested = assetIDName.compare(assetIDName_stored) == 0;
	bool assetVersionName_Tested = assetVersionName.compare(assetVersionName_stored) == 0;
	bool productionIDName_Tested = productionIDName.compare(productionIDName_stored) == 0;

	if (!objectTypeName_Tested) cout << "Given Object-Type Name: " << objectTypeName << " is different from: " << objectTypeName_stored << endl;
	if (!assetModeName_Tested) cout << "Given Asset-Type Name: " << assetTypeName << " is different from: " << assetTypeName_stored << endl;
	if (!assetModeName_Tested) cout << "Given Asset-Mode Name: " << assetModeName << " is different from: " << assetModeName_stored << endl;
	if (!objectIDName_Tested) cout << "Given Object-ID Name: " << objectIDName << " is different from: " << objectIDName_stored << endl;
	if (!parentIDName_Tested) cout << "Given Parent-ID Name: " << parentIDName << " is different from: " << parentIDName_stored << endl;
	if (!assetIDName_Tested) cout << "Given Asset-ID Name: " << assetID << " is different from: " << assetIDName_stored << endl;
	if (!assetVersionName_Tested) cout << "Given Asset-Version Name: " << assetModeName << " is different from: " << assetVersionName_stored << endl;
	if (!productionIDName_Tested) cout << "Given Production-ID Name: " << productionIDName << " is different from: " << productionIDName_stored << endl;

	if (objectTypeName_Tested && assetModeName_Tested && assetTypeName_Tested && objectIDName_Tested && parentIDName_Tested && assetIDName_Tested && assetVersionName_Tested && productionIDName_Tested)
		cout << "All Single-Value Name Tests Passed!" << endl;

	bool objectTypeFlag_Tested = assetMetadata.isObjectTypeFlagSet(objectTypeFlag);
	bool partSide_Tested = assetMetadata.isPartSideSet(partSide);
	bool cameraRole_Tested = assetMetadata.isCameraRoleSet(cameraRole);
	bool lightRole_Tested = assetMetadata.isLightRoleSet(lightRole);
	bool bodyPart_Tested = assetMetadata.isBodyPartSet(bodyPart);
	bool facialPart_Tested = assetMetadata.isFacialPartSet(facialPart);
	bool renderSetting_Tested = assetMetadata.isRenderSettingSet(renderSetting);
	bool viewportSetting_Tested = assetMetadata.isViewportSettingSet(viewportSetting);
	bool customPart_Tested = assetMetadata.isCustomPartSet(customPart);
	bool customFlag_Tested = assetMetadata.isCustomFlagSet(customFlag);
	bool pipelineFlag_Tested = assetMetadata.isPipelineFlagSet(pipelineFlag);

	if (!objectTypeFlag_Tested) cout << "Given Type-Flag:" << objectTypeFlagName << "(" << objectTypeFlag << ")" << " failed to be set" << endl;
	if (!partSide_Tested) cout << "Given Part-Side:" << partSideName << "(" << partSide << ")" << " failed to be set" << endl;
	if (!cameraRole_Tested) cout << "Given Camera-Role:" << cameraRoleName << "(" << cameraRole << ")" << " failed to be set" << endl;
	if (!lightRole_Tested) cout << "Given Light-Role:" << lightRoleName << "(" << lightRole << ")" << " failed to be set" << endl;
	if (!bodyPart_Tested) cout << "Given Body-Part:" << bodyPartName << "(" << bodyPart << ")" << " failed to be set" << endl;
	if (!facialPart_Tested) cout << "Given Facial - Part:" << facialPartName << "(" << facialPart << ")" << " failed to be set" << endl;
	if (!renderSetting_Tested) cout << "Given Render-Setting:" << renderSettingName << "(" << renderSetting << ")" << " failed to be set" << endl;
	if (!viewportSetting_Tested) cout << "Given Viewport-Setting:" << viewportSettingName << "(" << viewportSetting << ")" << " failed to be set" << endl;
	if (!customPart_Tested) cout << "Given Custom-Part:" << customPartName << "(" << customPart << ")" << " failed to be set" << endl;
	if (!customFlag_Tested) cout << "Given Custom-Flag:" << customFlagName << "(" << customFlag << ")" << " failed to be set" << endl;
	if (!pipelineFlag_Tested) cout << "Given Pipeline-Flag:" << pipelineFlagName << "(" << pipelineFlag << ")" << " failed to be set" << endl;

	if (objectTypeFlag_Tested && partSide_Tested && cameraRole_Tested && lightRole_Tested && bodyPart_Tested && facialPart_Tested && renderSetting_Tested && viewportSetting_Tested && customPart_Tested && customFlag_Tested && pipelineFlag_Tested)
		cout << "All Single-Flag Setting Tests Passed!" << endl;


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

	objectTypeFlag_Tested = assetMetadata.isObjectTypeFlagSet(objectTypeFlag);
	partSide_Tested = assetMetadata.isPartSideSet(partSide);
	cameraRole_Tested = assetMetadata.isCameraRoleSet(cameraRole);
	lightRole_Tested = assetMetadata.isLightRoleSet(lightRole);
	bodyPart_Tested = assetMetadata.isBodyPartSet(bodyPart);
	facialPart_Tested = assetMetadata.isFacialPartSet(facialPart);
	renderSetting_Tested = assetMetadata.isRenderSettingSet(renderSetting);
	viewportSetting_Tested = assetMetadata.isViewportSettingSet(viewportSetting);
	customPart_Tested = assetMetadata.isCustomPartSet(customPart);
	customFlag_Tested = assetMetadata.isCustomFlagSet(customFlag);
	pipelineFlag_Tested = assetMetadata.isPipelineFlagSet(pipelineFlag);

	if (objectTypeFlag_Tested) cout << "Given Type-Flag:" << objectTypeFlagName << "(" << objectTypeFlag << ")" << " failed to be un-set" << endl;
	if (partSide_Tested) cout << "Given Part-Side:" << partSideName << "(" << partSide << ")" << " failed to be un-set" << endl;
	if (cameraRole_Tested) cout << "Given Camera-Role:" << cameraRoleName << "(" << cameraRole << ")" << " failed to be un-set" << endl;
	if (lightRole_Tested) cout << "Given Light-Role:" << lightRoleName << "(" << lightRole << ")" << " failed to be un-set" << endl;
	if (bodyPart_Tested) cout << "Given Body-Part:" << bodyPartName << "(" << bodyPart << ")" << " failed to be un-set" << endl;
	if (facialPart_Tested) cout << "Given Facial - Part:" << facialPartName << "(" << facialPart << ")" << " failed to be un-set" << endl;
	if (renderSetting_Tested) cout << "Given Render-Setting:" << renderSettingName << "(" << renderSetting << ")" << " failed to be un-set" << endl;
	if (viewportSetting_Tested) cout << "Given Viewport-Setting:" << viewportSettingName << "(" << viewportSetting << ")" << " failed to be un-set" << endl;
	if (customPart_Tested) cout << "Given Custom-Part:" << customPartName << "(" << customPart << ")" << " failed to be un-set" << endl;
	if (customFlag_Tested) cout << "Given Custom-Flag:" << customFlagName << "(" << customFlag << ")" << " failed to be un-set" << endl;
	if (pipelineFlag_Tested) cout << "Given Pipeline-Flag:" << pipelineFlagName << "(" << pipelineFlag << ")" << " failed to be un-set" << endl;

	if (objectTypeName_Tested && assetModeName_Tested && assetTypeName_Tested && objectIDName_Tested && parentIDName_Tested && assetIDName_Tested && assetVersionName_Tested && productionIDName_Tested)
		cout << "All Single-Flag Un-Setting Tests Passed!" << endl;


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
	vector<string> facialPartNames = FacialParts::getNames(facialParts);
	vector<string> renderSettingNames = RenderSettings::getNames(renderSettings);
	vector<string> viewportSettingNames = ViewportSettings::getNames(viewportSettings);
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
	
	vector<string> objectTypeFlagNames_stored = assetMetadata.getObjectTypeFlagNames();
	vector<string> partSideNames_stored = assetMetadata.getPartSideNames();
	vector<string> cameraRoleNames_stored = assetMetadata.getCameraRoleNames();
	vector<string> lightRoleNames_stored = assetMetadata.getLightRoleNames();
	vector<string> bodyPartNames_stored = assetMetadata.getBodyPartNames();
	vector<string> facialPartsNames_stored = assetMetadata.getFacialPartNames();
	vector<string> renderSettingNames_stored = assetMetadata.getRenderSettingNames();
	vector<string> viewportSettingsNames_stored = assetMetadata.getViewportSettingNames();
	vector<string> customPartNames_stored = assetMetadata.getCustomPartNames();
	vector<string> customFlagNames_stored = assetMetadata.getCustomFlagNames();
	vector<string> pipelineFlagNames_stored = assetMetadata.getPipelineFlagNames();

	for (int i = 0; i <= 1; i++)
	{
		objectTypeFlag_Tested = assetMetadata.isObjectTypeFlagSet(objectTypeFlagArray[i]);
		partSide_Tested = assetMetadata.isPartSideSet(partSideArray[i]);
		cameraRole_Tested = assetMetadata.isCameraRoleSet(cameraRoleArray[i]);
		lightRole_Tested = assetMetadata.isLightRoleSet(lightRoleArray[i]);
		bodyPart_Tested = assetMetadata.isBodyPartSet(bodyPartArray[i]);
		facialPart_Tested = assetMetadata.isFacialPartSet(facialPartArray[i]);
		renderSetting_Tested = assetMetadata.isRenderSettingSet(renderSettingArray[i]);
		viewportSetting_Tested = assetMetadata.isViewportSettingSet(viewportSettingArray[i]);
		customPart_Tested = assetMetadata.isCustomPartSet(customPartArray[i]);
		customFlag_Tested = assetMetadata.isCustomFlagSet(customFlagArray[i]);
		pipelineFlag_Tested = assetMetadata.isPipelineFlagSet(pipelineFlagArray[i]);

		if (!objectTypeFlag_Tested) cout << "Given Type-Flag (" << i << "):" << objectTypeFlagNames.at(i) << "(" << objectTypeFlagArray[i] << ")" << " failed to be set" << endl;
		if (!partSide_Tested) cout << "Given Part-Side (" << i << "):" << partSideNames.at(i) << "(" << partSideArray[i] << ")" << " failed to be set" << endl;
		if (!cameraRole_Tested) cout << "Given Camera-Role (" << i << "):" << cameraRoleNames.at(i) << "(" << cameraRoleArray[i] << ")" << " failed to be set" << endl;
		if (!lightRole_Tested) cout << "Given Light-Role (" << i << "):" << lightRoleNames.at(i) << "(" << lightRoleArray[i] << ")" << " failed to be set" << endl;
		if (!bodyPart_Tested) cout << "Given Body-Part (" << i << "):" << bodyPartNames.at(i) << "(" << bodyPartArray[i] << ")" << " failed to be set" << endl;
		if (!facialPart_Tested) cout << "Given Facial-Part (" << i << "):" << facialPartNames.at(i) << "(" << facialPartArray[i] << ")" << " failed to be set" << endl;
		if (!renderSetting_Tested) cout << "Given Render-Setting (" << i << "):" << renderSettingNames.at(i) << "(" << renderSettingArray[i] << ")" << " failed to be set" << endl;
		if (!viewportSetting_Tested) cout << "Given Viewport-Setting (" << i << "):" << viewportSettingNames.at(i) << "(" << viewportSettingArray[i] << ")" << " failed to be set" << endl;
		if (!customPart_Tested) cout << "Given Custom-Part (" << i << "):" << customPartNames.at(i) << "(" << customPartArray[i] << ")" << " failed to be set" << endl;
		if (!customFlag_Tested) cout << "Given Custom-Flag (" << i << "):" << customFlagNames.at(i) << "(" << customFlagArray[i] << ")" << " failed to be set" << endl;
		if (!pipelineFlag_Tested) cout << "Given Pipeline-Flag (" << i << "):" << pipelineFlagNames.at(i) << "(" << pipelineFlagArray[i] << ")" << " failed to be set" << endl;

		if (objectTypeFlag_Tested && partSide_Tested && cameraRole_Tested && lightRole_Tested && bodyPart_Tested && facialPart_Tested && renderSetting_Tested && viewportSetting_Tested && customPart_Tested && customFlag_Tested && pipelineFlag_Tested)
			cout << "All Multiple-Flag Setting Tests " << i << " Passed!" << endl;
	}

	for (int i = 0; i <= 1; i++)
	{
		objectTypeFlag_Tested = objectTypeFlagNames.at(i).compare(objectTypeFlagNames_stored.at(i)) == 0;
		partSide_Tested = partSideNames.at(i).compare(partSideNames_stored.at(i)) == 0;
		cameraRole_Tested = cameraRoleNames.at(i).compare(cameraRoleNames_stored.at(i)) == 0;
		lightRole_Tested = lightRoleNames.at(i).compare(lightRoleNames_stored.at(i)) == 0;
		bodyPart_Tested = bodyPartNames.at(i).compare(bodyPartNames_stored.at(i)) == 0;
		facialPart_Tested = facialPartNames.at(i).compare(facialPartsNames_stored.at(i)) == 0;
		renderSetting_Tested = renderSettingNames.at(i).compare(renderSettingNames_stored.at(i)) == 0;
		viewportSetting_Tested = viewportSettingNames.at(i).compare(viewportSettingsNames_stored.at(i)) == 0;
		customPart_Tested = customPartNames.at(i).compare(customPartNames_stored.at(i)) == 0;
		customFlag_Tested = customFlagNames.at(i).compare(customFlagNames_stored.at(i)) == 0;
		pipelineFlag_Tested = pipelineFlagNames.at(i).compare(pipelineFlagNames_stored.at(i)) == 0;

		if (!objectTypeFlag_Tested) cout << "Given Type-Flag Name (" << i << "):" << objectTypeFlagNames.at(i) << " is different from: " << objectTypeFlagNames_stored.at(i) << endl;
		if (!partSide_Tested) cout << "Given Part-Side Name (" << i << "):" << partSideNames.at(i) << " is different from: " << partSideNames_stored.at(i) << endl;
		if (!cameraRole_Tested) cout << "Given Camera-Role Name (" << i << "):" << cameraRoleNames.at(i) << " is different from: " << cameraRoleNames_stored.at(i) << endl;
		if (!lightRole_Tested) cout << "Given Light-Role Name (" << i << "):" << lightRoleNames.at(i) << " is different from: " << lightRoleNames_stored.at(i) << endl;
		if (!bodyPart_Tested) cout << "Given Body-Part Name (" << i << "):" << bodyPartNames.at(i) << " is different from: " << bodyPartNames_stored.at(i) << endl;
		if (!facialPart_Tested) cout << "Given Facial-Part Name (" << i << "):" << facialPartNames.at(i) << " is different from: " << facialPartsNames_stored.at(i) << endl;
		if (!renderSetting_Tested) cout << "Given Render-Setting Name (" << i << "):" << renderSettingNames.at(i) << " is different from: " << renderSettingNames_stored.at(i) << endl;
		if (!viewportSetting_Tested) cout << "Given Viewport-Setting Name (" << i << "):" << viewportSettingNames.at(i) << " is different from: " << viewportSettingsNames_stored.at(i) << endl;
		if (!customPart_Tested) cout << "Given Custom-Part Name (" << i << "):" << customPartNames.at(i) << " is different from: " << customPartNames_stored.at(i) << endl;
		if (!customFlag_Tested) cout << "Given Custom-Flag Name (" << i << "):" << customFlagNames.at(i) << " is different from: " << customFlagNames_stored.at(i) << endl;
		if (!pipelineFlag_Tested) cout << "Given Pipeline-Flag Name (" << i << "):" << pipelineFlagNames.at(i) << " is different from: " << pipelineFlagNames_stored.at(i) << endl;

		if (objectTypeFlag_Tested && partSide_Tested && cameraRole_Tested && lightRole_Tested && bodyPart_Tested && facialPart_Tested && renderSetting_Tested && viewportSetting_Tested && customPart_Tested && customFlag_Tested && pipelineFlag_Tested)
			cout << "All Multiple-Flag Setting Name Tests " << i << " Passed!" << endl;
	}

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

	for (int i = 0; i <= 1; i++)
	{
		objectTypeFlag_Tested = assetMetadata.isObjectTypeFlagSet(objectTypeFlagArray[i]);
		partSide_Tested = assetMetadata.isPartSideSet(partSideArray[i]);
		cameraRole_Tested = assetMetadata.isCameraRoleSet(cameraRoleArray[i]);
		lightRole_Tested = assetMetadata.isLightRoleSet(lightRoleArray[i]);
		bodyPart_Tested = assetMetadata.isBodyPartSet(bodyPartArray[i]);
		facialPart_Tested = assetMetadata.isFacialPartSet(facialPartArray[i]);
		renderSetting_Tested = assetMetadata.isRenderSettingSet(renderSettingArray[i]);
		viewportSetting_Tested = assetMetadata.isViewportSettingSet(viewportSettingArray[i]);
		customPart_Tested = assetMetadata.isCustomPartSet(customPartArray[i]);
		customFlag_Tested = assetMetadata.isCustomFlagSet(customFlagArray[i]);
		pipelineFlag_Tested = assetMetadata.isPipelineFlagSet(pipelineFlagArray[i]);

		if (objectTypeFlag_Tested) cout << "Given Type-Flag (" << i << "):" << objectTypeFlagNames.at(i) << "(" << objectTypeFlagArray[i] << ")" << " failed to be cleared" << endl;
		if (partSide_Tested) cout << "Given Part-Side (" << i << "):" << partSideNames.at(i) << "(" << partSideArray[i] << ")" << " failed to be cleared" << endl;
		if (cameraRole_Tested) cout << "Given Camera-Role (" << i << "):" << cameraRoleNames.at(i) << "(" << cameraRoleArray[i] << ")" << " failed to be cleared" << endl;
		if (lightRole_Tested) cout << "Given Light-Role (" << i << "):" << lightRoleNames.at(i) << "(" << lightRoleArray[i] << ")" << " failed to be cleared" << endl;
		if (bodyPart_Tested) cout << "Given Body-Part (" << i << "):" << bodyPartNames.at(i) << "(" << bodyPartArray[i] << ")" << " failed to be cleared" << endl;
		if (facialPart_Tested) cout << "Given Facial-Part (" << i << "):" << facialPartNames.at(i) << "(" << facialPartArray[i] << ")" << " failed to be cleared" << endl;
		if (renderSetting_Tested) cout << "Given Render-Setting (" << i << "):" << renderSettingNames.at(i) << "(" << renderSettingArray[i] << ")" << " failed to be cleared" << endl;
		if (viewportSetting_Tested) cout << "Given Viewport-Setting (" << i << "):" << viewportSettingNames.at(i) << "(" << viewportSettingArray[i] << ")" << " failed to be cleared" << endl;
		if (customPart_Tested) cout << "Given Custom-Part (" << i << "):" << customPartNames.at(i) << "(" << customPartArray[i] << ")" << " failed to be cleared" << endl;
		if (customFlag_Tested) cout << "Given Custom-Flag (" << i << "):" << customFlagNames.at(i) << "(" << customFlagArray[i] << ")" << " failed to be cleared" << endl;
		if (pipelineFlag_Tested) cout << "Given Pipeline-Flag (" << i << "):" << pipelineFlagNames.at(i) << "(" << pipelineFlagArray[i] << ")" << " failed to be cleared" << endl;

		if (objectTypeFlag_Tested && partSide_Tested && cameraRole_Tested && lightRole_Tested && bodyPart_Tested && facialPart_Tested && renderSetting_Tested && viewportSetting_Tested && customPart_Tested && customFlag_Tested && pipelineFlag_Tested)
			cout << "All Multiple-Flag Un-Setting Tests " << i << " Passed!" << endl;
	}

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

	for (int i = 0; i <= 1; i++)
	{
		objectTypeFlag_Tested = assetMetadata.isObjectTypeFlagSet(objectTypeFlagArray[i]);
		partSide_Tested = assetMetadata.isPartSideSet(partSideArray[i]);
		cameraRole_Tested = assetMetadata.isCameraRoleSet(cameraRoleArray[i]);
		lightRole_Tested = assetMetadata.isLightRoleSet(lightRoleArray[i]);
		bodyPart_Tested = assetMetadata.isBodyPartSet(bodyPartArray[i]);
		facialPart_Tested = assetMetadata.isFacialPartSet(facialPartArray[i]);
		renderSetting_Tested = assetMetadata.isRenderSettingSet(renderSettingArray[i]);
		viewportSetting_Tested = assetMetadata.isViewportSettingSet(viewportSettingArray[i]);
		customPart_Tested = assetMetadata.isCustomPartSet(customPartArray[i]);
		customFlag_Tested = assetMetadata.isCustomFlagSet(customFlagArray[i]);
		pipelineFlag_Tested = assetMetadata.isPipelineFlagSet(pipelineFlagArray[i]);

		if (objectTypeFlag_Tested) cout << "Given Type-Flag (" << i << "):" << objectTypeFlagNames.at(i) << "(" << objectTypeFlagArray[i] << ")" << " failed to be un-set" << endl;
		if (partSide_Tested) cout << "Given Part-Side (" << i << "):" << partSideNames.at(i) << "(" << partSideArray[i] << ")" << " failed to be un-set" << endl;
		if (cameraRole_Tested) cout << "Given Camera-Role (" << i << "):" << cameraRoleNames.at(i) << "(" << cameraRoleArray[i] << ")" << " failed to be un-set" << endl;
		if (lightRole_Tested) cout << "Given Light-Role (" << i << "):" << lightRoleNames.at(i) << "(" << lightRoleArray[i] << ")" << " failed to be un-set" << endl;
		if (bodyPart_Tested) cout << "Given Body-Part (" << i << "):" << bodyPartNames.at(i) << "(" << bodyPartArray[i] << ")" << " failed to be un-set" << endl;
		if (facialPart_Tested) cout << "Given Facial-Part (" << i << "):" << facialPartNames.at(i) << "(" << facialPartArray[i] << ")" << " failed to be un-set" << endl;
		if (renderSetting_Tested) cout << "Given Render-Setting (" << i << "):" << renderSettingNames.at(i) << "(" << renderSettingArray[i] << ")" << " failed to be un-set" << endl;
		if (viewportSetting_Tested) cout << "Given Viewport-Setting (" << i << "):" << viewportSettingNames.at(i) << "(" << viewportSettingArray[i] << ")" << " failed to be un-set" << endl;
		if (customPart_Tested) cout << "Given Custom-Part (" << i << "):" << customPartNames.at(i) << "(" << customPartArray[i] << ")" << " failed to be un-set" << endl;
		if (customFlag_Tested) cout << "Given Custom-Flag (" << i << "):" << customFlagNames.at(i) << "(" << customFlagArray[i] << ")" << " failed to be un-set" << endl;
		if (pipelineFlag_Tested) cout << "Given Pipeline-Flag (" << i << "):" << pipelineFlagNames.at(i) << "(" << pipelineFlagArray[i] << ")" << " failed to be un-set" << endl;

		if (objectTypeFlag_Tested && partSide_Tested && cameraRole_Tested && lightRole_Tested && bodyPart_Tested && facialPart_Tested && renderSetting_Tested && viewportSetting_Tested && customPart_Tested && customFlag_Tested && pipelineFlag_Tested)
			cout << "All Clear-Flags Tests " << i << " Passed!" << endl;
	}

	assetMetadata.setAssetMode(assetModeName);
	assetMetadata.setAssetType(assetTypeName);
	assetMetadata.setObjectType(objectTypeName);
	assetMetadata.setObjectTypeFlag(objectTypeFlagName);
	assetMetadata.setPartSide(partSideName);
	assetMetadata.setCameraRole(cameraRoleName);
	assetMetadata.setLightRole(lightRoleName);
	assetMetadata.setBodyPart(bodyPartName);
	assetMetadata.setFacialPart(facialPartName);
	assetMetadata.setRenderSetting(renderSettingName);
	assetMetadata.setViewportSetting(viewportSettingName);
	assetMetadata.setCustomPart(customPartName);
	assetMetadata.setCustomFlag(customFlagName);
	assetMetadata.setPipelineFlag(pipelineFlagName);

	assetModeName_stored = assetMetadata.getAssetModeName();
	assetTypeName_stored = assetMetadata.getAssetTypeName();
	objectTypeName_stored = assetMetadata.getObjectTypeName();
	objectTypeFlagNames_stored = assetMetadata.getObjectTypeFlagNames();
	partSideNames_stored = assetMetadata.getPartSideNames();
	cameraRoleNames_stored = assetMetadata.getCameraRoleNames();
	lightRoleNames_stored = assetMetadata.getLightRoleNames();
	bodyPartNames_stored = assetMetadata.getBodyPartNames();
	facialPartsNames_stored = assetMetadata.getFacialPartNames();
	renderSettingNames_stored = assetMetadata.getRenderSettingNames();
	viewportSettingsNames_stored = assetMetadata.getViewportSettingNames();
	customPartNames_stored = assetMetadata.getCustomPartNames();
	customFlagNames_stored = assetMetadata.getCustomFlagNames();
	pipelineFlagNames_stored = assetMetadata.getPipelineFlagNames();

	assetModeName_Tested = assetModeName.compare(assetModeName_stored) == 0;
	assetTypeName_Tested = assetTypeName.compare(assetTypeName_stored) == 0;
	objectTypeName_Tested = objectTypeName.compare(objectTypeName_stored) == 0;
	objectTypeFlag_Tested = objectTypeFlagNames_stored.size() == 1 && objectTypeFlagName.compare(objectTypeFlagNames_stored.at(0)) == 0;
	partSide_Tested = partSideNames_stored.size() == 1 && partSideName.compare(partSideNames_stored.at(0)) == 0;
	cameraRole_Tested = cameraRoleNames_stored.size() == 1 && cameraRoleName.compare(cameraRoleNames_stored.at(0)) == 0;
	lightRole_Tested = lightRoleNames_stored.size() == 1 && lightRoleName.compare(lightRoleNames_stored.at(0)) == 0;
	bodyPart_Tested = bodyPartNames_stored.size() == 1 && bodyPartName.compare(bodyPartNames_stored.at(0)) == 0;
	facialPart_Tested = facialPartsNames_stored.size() == 1 && facialPartName.compare(facialPartsNames_stored.at(0)) == 0;
	renderSetting_Tested = renderSettingNames_stored.size() == 1 && renderSettingName.compare(renderSettingNames_stored.at(0)) == 0;
	viewportSetting_Tested = viewportSettingsNames_stored.size() == 1 && viewportSettingName.compare(viewportSettingsNames_stored.at(0)) == 0;
	customPart_Tested = customPartNames_stored.size() == 1 && customPartName.compare(customPartNames_stored.at(0)) == 0;
	customFlag_Tested = customFlagNames_stored.size() == 1 && customFlagName.compare(customFlagNames_stored.at(0)) == 0;
	pipelineFlag_Tested = pipelineFlagNames_stored.size() == 1 && pipelineFlagName.compare(pipelineFlagNames_stored.at(0)) == 0;

	if (!assetModeName_Tested) cout << "Given Asset-Mode Name:" << assetModeName << " failed to be set by name" << endl;
	if (!assetTypeName_Tested) cout << "Given Asset-Type Name:" << assetTypeName << " failed to be set by name" << endl;
	if (!objectTypeName_Tested) cout << "Given Object-Type Name:" << objectTypeName << " failed to be set by name" << endl;
	if (!objectTypeFlag_Tested) cout << "Given Object-Type-Flag Name:" << objectTypeFlagName << " failed to be set by name" << endl;
	if (!partSide_Tested) cout << "Given Part-Side Name:" << partSideName << " failed to be set by name" << endl;
	if (!cameraRole_Tested) cout << "Given Camera-Role Name:" << cameraRoleName << " failed to be set by name" << endl;
	if (!lightRole_Tested) cout << "Given Light-Role Name:" << lightRoleName << " failed to be set by name" << endl;
	if (!bodyPart_Tested) cout << "Given Body-Part Name:" << bodyPartName << " failed to be set by name" << endl;
	if (!facialPart_Tested) cout << "Given Facial-Part Name:" << facialPartName << " failed to be set by name" << endl;
	if (!renderSetting_Tested) cout << "Given Render-Setting Name:" << renderSettingName << " failed to be set by name" << endl;
	if (!viewportSetting_Tested) cout << "Given Viewport-Setting Name:" << viewportSettingName << " failed to be set by name" << endl;
	if (!customPart_Tested) cout << "Given Custom-Part Name:" << customPartName << " failed to be set by name" << endl;
	if (!customFlag_Tested) cout << "Given Custom-Flag Name:" << customFlagName << " failed to be set by name" << endl;
	if (!pipelineFlag_Tested) cout << "Given Pipeline-Flag Name:" << pipelineFlagName << "(" << pipelineFlag << ")" << " failed to be set" << endl;

	if (assetModeName_Tested && assetTypeName_Tested && objectTypeName_Tested && objectTypeFlag_Tested && partSide_Tested &&
		cameraRole_Tested && lightRole_Tested && bodyPart_Tested && facialPart_Tested && renderSetting_Tested &&
		viewportSetting_Tested && customPart_Tested && customFlag_Tested && pipelineFlag_Tested)
		cout << "All Single-Name Setting Tests Passed!" << endl;


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

	assetMetadata.setObjectTypeFlags(objectTypeFlagNames);
	assetMetadata.setPartSides(partSideNames);
	assetMetadata.setCameraRoles(cameraRoleNames);
	assetMetadata.setLightRoles(lightRoleNames);
	assetMetadata.setBodyParts(bodyPartNames);
	assetMetadata.setFacialParts(facialPartNames);
	assetMetadata.setRenderSettings(renderSettingNames);
	assetMetadata.setViewportSettings(viewportSettingNames);
	assetMetadata.setCustomParts(customPartNames);
	assetMetadata.setCustomFlags(customFlagNames);
	assetMetadata.setPipelineFlags(pipelineFlagNames);

	objectTypeFlagNames_stored = assetMetadata.getObjectTypeFlagNames();
	partSideNames_stored = assetMetadata.getPartSideNames();
	cameraRoleNames_stored = assetMetadata.getCameraRoleNames();
	lightRoleNames_stored = assetMetadata.getLightRoleNames();
	bodyPartNames_stored = assetMetadata.getBodyPartNames();
	facialPartsNames_stored = assetMetadata.getFacialPartNames();
	renderSettingNames_stored = assetMetadata.getRenderSettingNames();
	viewportSettingsNames_stored = assetMetadata.getViewportSettingNames();
	customPartNames_stored = assetMetadata.getCustomPartNames();
	customFlagNames_stored = assetMetadata.getCustomFlagNames();
	pipelineFlagNames_stored = assetMetadata.getPipelineFlagNames();

	for (int i = 0; i <= 1; i++)
	{
		objectTypeFlag_Tested = objectTypeFlagNames.at(i).compare(objectTypeFlagNames_stored.at(i)) == 0;
		partSide_Tested = partSideNames.at(i).compare(partSideNames_stored.at(i)) == 0;
		cameraRole_Tested = cameraRoleNames.at(i).compare(cameraRoleNames_stored.at(i)) == 0;
		lightRole_Tested = lightRoleNames.at(i).compare(lightRoleNames_stored.at(i)) == 0;
		bodyPart_Tested = bodyPartNames.at(i).compare(bodyPartNames_stored.at(i)) == 0;
		facialPart_Tested = facialPartNames.at(i).compare(facialPartsNames_stored.at(i)) == 0;
		renderSetting_Tested = renderSettingNames.at(i).compare(renderSettingNames_stored.at(i)) == 0;
		viewportSetting_Tested = viewportSettingNames.at(i).compare(viewportSettingsNames_stored.at(i)) == 0;
		customPart_Tested = customPartNames.at(i).compare(customPartNames_stored.at(i)) == 0;
		customFlag_Tested = customFlagNames.at(i).compare(customFlagNames_stored.at(i)) == 0;
		pipelineFlag_Tested = pipelineFlagNames.at(i).compare(pipelineFlagNames_stored.at(i)) == 0;

		if (!objectTypeFlag_Tested) cout << "Given Type-Flag Name (" << i << "):" << objectTypeFlagNames.at(i) << " is different from: " << objectTypeFlagNames_stored.at(i) << endl;
		if (!partSide_Tested) cout << "Given Part-Side Name (" << i << "):" << partSideNames.at(i) << " is different from: " << partSideNames_stored.at(i) << endl;
		if (!cameraRole_Tested) cout << "Given Camera-Role Name (" << i << "):" << cameraRoleNames.at(i) << " is different from: " << cameraRoleNames_stored.at(i) << endl;
		if (!lightRole_Tested) cout << "Given Light-Role Name (" << i << "):" << lightRoleNames.at(i) << " is different from: " << lightRoleNames_stored.at(i) << endl;
		if (!bodyPart_Tested) cout << "Given Body-Part Name (" << i << "):" << bodyPartNames.at(i) << " is different from: " << bodyPartNames_stored.at(i) << endl;
		if (!facialPart_Tested) cout << "Given Facial-Part Name (" << i << "):" << facialPartNames.at(i) << " is different from: " << facialPartsNames_stored.at(i) << endl;
		if (!renderSetting_Tested) cout << "Given Render-Setting Name (" << i << "):" << renderSettingNames.at(i) << " is different from: " << renderSettingNames_stored.at(i) << endl;
		if (!viewportSetting_Tested) cout << "Given Viewport-Setting Name (" << i << "):" << viewportSettingNames.at(i) << " is different from: " << viewportSettingsNames_stored.at(i) << endl;
		if (!customPart_Tested) cout << "Given Custom-Part Name (" << i << "):" << customPartNames.at(i) << " is different from: " << customPartNames_stored.at(i) << endl;
		if (!customFlag_Tested) cout << "Given Custom-Flag Name (" << i << "):" << customFlagNames.at(i) << " is different from: " << customFlagNames_stored.at(i) << endl;
		if (!pipelineFlag_Tested) cout << "Given Pipeline-Flag Name (" << i << "):" << pipelineFlagNames.at(i) << " is different from: " << pipelineFlagNames_stored.at(i) << endl;

		if (objectTypeFlag_Tested && partSide_Tested && cameraRole_Tested && lightRole_Tested && bodyPart_Tested && facialPart_Tested && renderSetting_Tested && viewportSetting_Tested && customPart_Tested && customFlag_Tested && pipelineFlag_Tested)
			cout << "All Multiple-Flag-Names Setting Name Tests " << i << " Passed!" << endl;
	}

	cin.get();
	return 0;
}