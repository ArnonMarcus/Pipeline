#include <string>
#include <maya/MDagPath.h>
#include <maya/MDataHandle.h>
#include <maya/MDGModifier.h>
#include <maya/MDGContext.h>
#include <maya/MStringArray.h>
#include <maya/MStringResource.h>
#include <maya/MStringResourceId.h>
#include <maya/MFnDependencyNode.h>
#include <maya/MFnTypedAttribute.h>
#include <maya/MArgDatabase.h>
#include <maya/MSyntax.h>
#include <maya/MFnDagNode.h>
#include <maya/MItSelectionList.h>
#include <maya/MPlug.h>
#include <maya/MFnPluginData.h>

#include "AssetMetadataCmd.h"
#include "AssetMetadata.h"

using namespace Pipeline;

//- Instantiate static fields
/*static*/ MObject AssetMetadataCmd::_extensionAttribute;
///*static*/ MObject AssetMetadataCmd::_extensionAttributeDefaultValue;
/*static*/ MString AssetMetadataCmd::_extensionAttributeFullName(kExtensionAttributeFullName);
/*static*/ MString AssetMetadataCmd::_extensionAttributeBriefName(kExtensionAttributeShortName);
/*static*/ MNodeClass AssetMetadataCmd::_extensionAttributeAffectedNodeClass(kExtensionAttributeAffectedNodeClassName);

/*static*/ MStatus AssetMetadataCmd::addExtensionAttribute(MObject plugin)
{
	MStatus status;

	//MFnPluginData fnData;
	//AssetMetadataCmd::_extensionAttributeDefaultValue = fnData.create(AssetMetadataMPx::id, &status);
	//CHECK_MSTATUS_AND_RETURN_IT(status);

	MFnTypedAttribute fnAttr;
	AssetMetadataCmd::_extensionAttribute = fnAttr.create(
		AssetMetadataCmd::_extensionAttributeFullName,
		AssetMetadataCmd::_extensionAttributeBriefName,
		AssetMetadataMPx::id,
		MObject::kNullObj, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	fnAttr.setHidden(1);
	fnAttr.setChannelBox(0);
	fnAttr.setConnectable(0);

	status = AssetMetadataCmd::_extensionAttributeAffectedNodeClass.addExtensionAttribute(AssetMetadataCmd::_extensionAttribute);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	return MS::kSuccess;
}

/*static*/ MStatus AssetMetadataCmd::removeExtensionAttribute(MObject plugin)
{
	MStatus status;

	status = AssetMetadataCmd::_extensionAttributeAffectedNodeClass.removeExtensionAttributeIfUnset(AssetMetadataCmd::_extensionAttribute);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	return MS::kSuccess;
}

MSyntax AssetMetadataCmd::cmdSyntax()
{
	MSyntax syntax;

	syntax.enableEdit(true);
	syntax.enableQuery(true);

	syntax.setObjectType(MSyntax::kSelectionList, 1);
	syntax.useSelectionAsDefault(true);

	syntax.addFlag("-h", "-help", MSyntax::kNoArg);
	//syntax.addFlag(kS_AssetName, kL_AssetName, MSyntax::kString);
	syntax.addFlag(kS_AssetType, kL_AssetType, MSyntax::kString);
	syntax.addFlag(kS_AssetMode, kL_AssetMode, MSyntax::kString);
	syntax.addFlag(kS_AssetVersion, kL_AssetVersion, MSyntax::kUnsigned);	
	syntax.addFlag(kS_AssetID, kL_AssetID, MSyntax::kUnsigned);
	syntax.addFlag(kS_ParentID, kL_ParentID, MSyntax::kUnsigned);
	syntax.addFlag(kS_ProductionID, kL_ProductionID, MSyntax::kUnsigned);
	syntax.addFlag(kS_ObjectID, kL_ObjectID, MSyntax::kUnsigned);
	syntax.addFlag(kS_ObjectType, kL_ObjectType, MSyntax::kString);
	syntax.addFlag(kS_ObjectTypeFlags, kL_ObjectTypeFlags, MSyntax::kString);
	syntax.addFlag(kS_CameraRoles, kL_CameraRoles, MSyntax::kString);
	syntax.addFlag(kS_LightRoles, kL_LightRoles, MSyntax::kString);
	syntax.addFlag(kS_PartSides, kL_PartSides, MSyntax::kString);
	syntax.addFlag(kS_BodyParts, kL_BodyParts, MSyntax::kString);
	syntax.addFlag(kS_FacialParts, kL_FacialParts, MSyntax::kString);
	syntax.addFlag(kS_ViewportSettings, kL_ViewportSettings, MSyntax::kString);
	syntax.addFlag(kS_RenderSettings, kL_RenderSettings, MSyntax::kString);
	syntax.addFlag(kS_CustomParts, kL_CustomParts, MSyntax::kString);
	syntax.addFlag(kS_CustomFlags, kL_CustomFlags, MSyntax::kString);
	syntax.addFlag(kS_PipelineFlags, kL_PipelineFlags, MSyntax::kString);


	syntax.makeFlagMultiUse(kS_ObjectTypeFlags);
	syntax.makeFlagMultiUse(kS_CameraRoles);
	syntax.makeFlagMultiUse(kS_LightRoles);
	syntax.makeFlagMultiUse(kS_PartSides);
	syntax.makeFlagMultiUse(kS_BodyParts);
	syntax.makeFlagMultiUse(kS_FacialParts);
	syntax.makeFlagMultiUse(kS_ViewportSettings);
	syntax.makeFlagMultiUse(kS_RenderSettings);
	syntax.makeFlagMultiUse(kS_CustomParts);
	syntax.makeFlagMultiUse(kS_CustomFlags);
	syntax.makeFlagMultiUse(kS_PipelineFlags);

	return syntax;
}

MStatus AssetMetadataCmd::parseArguments(const MArgList& argList)
{
	MStatus status;

	MArgDatabase argData = MArgDatabase(syntax(), argList, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	// If the 'help' flag was used, ignore everything else, and just output the help-message
	if (argData.isFlagSet("help"))
	{
		MString msg = MStringResource::getString(kHelpText, status);
		displayInfo(msg);
		return MS::kSuccess;
	}

	_commandFlagsUsed = 0;

	//  Make sure that either Edit mode is set, or Query mode is set, but not both

	if (argData.isEdit())
	{
		if (argData.isQuery())
		{
			MString msg = MStringResource::getString(kEditQueryFlagErrorMsg, status);
			displayError(msg);
			return MS::kFailure;
		}
		
		_commandFlagsUsed |= kEditMode;
	}

	// Make sure there are objects for the command to work on,
	// provided either within the command string as an argument,
	// or from the currently-selected objects in the current scene
	status = argData.getObjects(_currentSelectionList);
	CHECK_MSTATUS_AND_RETURN_IT(status);
	
	if (!_currentSelectionList.length())
	{
		MString msg = MStringResource::getString(kObjectNotFoundError, status);
		displayError(msg);
		return MS::kFailure;
	}	

	//if (argData.isFlagSet(kS_AssetName)) _commandFlagsUsed |= kAssetName;
	if (argData.isFlagSet(kS_AssetType)) _commandFlagsUsed |= kAssetType;
	if (argData.isFlagSet(kS_AssetMode)) _commandFlagsUsed |= kAssetMode;
	if (argData.isFlagSet(kS_AssetVersion)) _commandFlagsUsed |= kAssetVersion;
	if (argData.isFlagSet(kS_AssetID)) _commandFlagsUsed |= kAssetID;
	if (argData.isFlagSet(kS_ParentID)) _commandFlagsUsed |= kParentID;
	if (argData.isFlagSet(kS_ProductionID)) _commandFlagsUsed |= kProductionID;
	if (argData.isFlagSet(kS_ObjectID)) _commandFlagsUsed |= kObjectID;
	if (argData.isFlagSet(kS_ObjectType)) _commandFlagsUsed |= kObjectType;
	if (argData.isFlagSet(kS_ObjectTypeFlags)) _commandFlagsUsed |= kObjectTypeFlags;
	if (argData.isFlagSet(kS_CameraRoles)) _commandFlagsUsed |= kCameraRoles;
	if (argData.isFlagSet(kS_LightRoles)) _commandFlagsUsed |= kLightRoles;
	if (argData.isFlagSet(kS_PartSides)) _commandFlagsUsed |= kPartSides;
	if (argData.isFlagSet(kS_BodyParts)) _commandFlagsUsed |= kBodyParts;
	if (argData.isFlagSet(kS_FacialParts)) _commandFlagsUsed |= kFacialParts;
	if (argData.isFlagSet(kS_RenderSettings)) _commandFlagsUsed |= kRenderSettings;
	if (argData.isFlagSet(kS_ViewportSettings)) _commandFlagsUsed |= kViewportSettings;
	if (argData.isFlagSet(kS_CustomParts)) _commandFlagsUsed |= kCustomParts;
	if (argData.isFlagSet(kS_CustomFlags)) _commandFlagsUsed |= kCustomFlags;
	if (argData.isFlagSet(kS_PipelineFlags)) _commandFlagsUsed |= kPipelineFlags;

	if (_commandFlagsUsed & kEditMode)
	{
		MArgList mArgs;
		unsigned int pos;
		unsigned int i;

		//if (_commandFlagsUsed & kAssetName) _newAssetMetadata.setAssetName(argData.flagArgumentString(kS_AssetName, 0).asChar());
		if (_commandFlagsUsed & kAssetType) _newAssetMetadata.setAssetType(argData.flagArgumentString(kS_AssetType, 0).asChar());
		if (_commandFlagsUsed & kAssetMode) _newAssetMetadata.setAssetMode(argData.flagArgumentString(kS_AssetMode, 0).asChar());
		if (_commandFlagsUsed & kAssetVersion) _newAssetMetadata.setAssetVersion(argData.flagArgumentString(kS_AssetVersion, 0).asShort());
		if (_commandFlagsUsed & kAssetID) _newAssetMetadata.setAssetID(argData.flagArgumentString(kS_AssetID, 0).asShort());
		if (_commandFlagsUsed & kObjectID) _newAssetMetadata.setObjectID(argData.flagArgumentString(kS_ObjectID, 0).asShort());
		if (_commandFlagsUsed & kParentID) _newAssetMetadata.setParentID(argData.flagArgumentString(kS_ParentID, 0).asShort());
		if (_commandFlagsUsed & kProductionID) _newAssetMetadata.setProductionID(argData.flagArgumentString(kS_ProductionID, 0).asUnsigned());
		if (_commandFlagsUsed & kObjectType) _newAssetMetadata.setObjectType(argData.flagArgumentString(kS_ObjectType, 0).asChar());
		
		if (_commandFlagsUsed & kObjectTypeFlags)
		{
			for (i = 0; i < argData.numberOfFlagUses(kS_ObjectTypeFlags); i++)
			{
				status = argData.getFlagArgumentPosition(kS_ObjectTypeFlags, i, pos);									CHECK_MSTATUS_AND_RETURN_IT(status);
				argData.getFlagArgumentList(kS_ObjectTypeFlags, i, mArgs);
				_newAssetMetadata.setObjectTypeFlag(mArgs.asString(0).asChar());
			}
		}
		
		if (_commandFlagsUsed & kCameraRoles)
		{
			for (i = 0; i < argData.numberOfFlagUses(kS_CameraRoles); i++)
			{
				status = argData.getFlagArgumentPosition(kS_CameraRoles, i, pos);									CHECK_MSTATUS_AND_RETURN_IT(status);
				argData.getFlagArgumentList(kS_CameraRoles, i, mArgs);
				_newAssetMetadata.setCameraRole(mArgs.asString(0).asChar());
			}
		}
		
		if (_commandFlagsUsed & kLightRoles)
		{
			for (i = 0; i < argData.numberOfFlagUses(kS_LightRoles); i++)
			{
				status = argData.getFlagArgumentPosition(kS_LightRoles, i, pos);									CHECK_MSTATUS_AND_RETURN_IT(status);
				argData.getFlagArgumentList(kS_LightRoles, i, mArgs);
				_newAssetMetadata.setLightRole(mArgs.asString(0).asChar());
			}
		}

		if (_commandFlagsUsed & kPartSides)
		{
			for (i = 0; i < argData.numberOfFlagUses(kS_PartSides); i++)
			{
				status = argData.getFlagArgumentPosition(kS_PartSides, i, pos);									CHECK_MSTATUS_AND_RETURN_IT(status);
				argData.getFlagArgumentList(kS_PartSides, i, mArgs);
				_newAssetMetadata.setPartSide(mArgs.asString(0).asChar());
			}
		}

		if (_commandFlagsUsed & kFacialParts)
		{
			for (i = 0; i < argData.numberOfFlagUses(kS_FacialParts); i++)
			{
				status = argData.getFlagArgumentPosition(kS_FacialParts, i, pos);									CHECK_MSTATUS_AND_RETURN_IT(status);
				argData.getFlagArgumentList(kS_FacialParts, i, mArgs);
				_newAssetMetadata.setFacialPart(mArgs.asString(0).asChar());
			}
		}
		
		if (_commandFlagsUsed & kBodyParts)
		{
			for (i = 0; i < argData.numberOfFlagUses(kS_BodyParts); i++)
			{
				status = argData.getFlagArgumentPosition(kS_BodyParts, i, pos);									CHECK_MSTATUS_AND_RETURN_IT(status);
				argData.getFlagArgumentList(kS_BodyParts, i, mArgs);
				_newAssetMetadata.setBodyPart(mArgs.asString(0).asChar());
			}
		}
		
		if (_commandFlagsUsed & kViewportSettings)
		{
			for (i = 0; i < argData.numberOfFlagUses(kS_ViewportSettings); i++)
			{
				status = argData.getFlagArgumentPosition(kS_ViewportSettings, i, pos);									CHECK_MSTATUS_AND_RETURN_IT(status);
				argData.getFlagArgumentList(kS_ViewportSettings, i, mArgs);
				_newAssetMetadata.setViewportSetting(mArgs.asString(0).asChar());
			}			
		}
		
		if (_commandFlagsUsed & kRenderSettings)
		{
			for (i = 0; i < argData.numberOfFlagUses(kS_ViewportSettings); i++)
			{
				status = argData.getFlagArgumentPosition(kS_ViewportSettings, i, pos);									CHECK_MSTATUS_AND_RETURN_IT(status);
				argData.getFlagArgumentList(kS_ViewportSettings, i, mArgs);
				_newAssetMetadata.setViewportSetting(mArgs.asString(0).asChar());
			}
		}
		
		if (_commandFlagsUsed & kCustomParts)
		{
			for (i = 0; i < argData.numberOfFlagUses(kS_CustomParts); i++)
			{
				status = argData.getFlagArgumentPosition(kS_CustomParts, i, pos);									CHECK_MSTATUS_AND_RETURN_IT(status);
				argData.getFlagArgumentList(kS_CustomParts, i, mArgs);
				_newAssetMetadata.setCustomPart(mArgs.asString(0).asChar());
			}
		}

		if (_commandFlagsUsed & kCustomFlags)
		{
			for (i = 0; i < argData.numberOfFlagUses(kS_BodyParts); i++)
			{
				status = argData.getFlagArgumentPosition(kS_BodyParts, i, pos);									CHECK_MSTATUS_AND_RETURN_IT(status);
				argData.getFlagArgumentList(kS_BodyParts, i, mArgs);
				_newAssetMetadata.setCustomFlag(mArgs.asString(0).asChar());
			}
		}

		if (_commandFlagsUsed & kPipelineFlags)
		{
			for (i = 0; i < argData.numberOfFlagUses(kS_PipelineFlags); i++)
			{
				status = argData.getFlagArgumentPosition(kS_PipelineFlags, i, pos);									CHECK_MSTATUS_AND_RETURN_IT(status);
				argData.getFlagArgumentList(kS_PipelineFlags, i, mArgs);
				_newAssetMetadata.setPipelineFlag(mArgs.asString(0).asChar());
			}
		}
	}

	return MS::kSuccess;
}

MStatus AssetMetadataCmd::doCmd(bool undo)
{
	MStatus status;

	MPlug plug;
	MObject node;
	MTypeId typeID;
	MDataHandle dhData;
	MFnPluginData fnData;
	MFnDependencyNode fnNode;
	AssetMetadataMPx* data;
	MItSelectionList iter(_currentSelectionList, MFn::kDagNode, &status);						CHECK_MSTATUS_AND_RETURN_IT(status);

	for (; !iter.isDone(&status); iter.next())
	{
		status = iter.getDependNode(node);														CHECK_MSTATUS_AND_RETURN_IT(status);
		status = fnNode.setObject(node);														CHECK_MSTATUS_AND_RETURN_IT(status);

		bool hasAttr = fnNode.hasAttribute(kExtensionAttributeFullName, &status);				CHECK_MSTATUS_AND_RETURN_IT(status);
		if (!hasAttr)
		{
			MString msg = MStringResource::getString(kAttributeNotFoundError, status);
			displayError(msg);
			return MS::kFailure;
		}

		plug = fnNode.findPlug(kExtensionAttributeFullName, false, &status);					CHECK_MSTATUS_AND_RETURN_IT(status);
		dhData = plug.asMDataHandle(MDGContext::fsNormal, &status);								CHECK_MSTATUS_AND_RETURN_IT(status);
		typeID = dhData.typeId();
		if (typeID.id())
		{
			if (typeID != AssetMetadataMPx::id)
			{
				MString msg = MStringResource::getString(kAttributeWrongType, status);
				displayError(msg);
				return MS::kFailure;
			}

			status = fnData.setObject(dhData.data());												CHECK_MSTATUS_AND_RETURN_IT(status);
			data = (AssetMetadataMPx*)fnData.constData(&status);									CHECK_MSTATUS_AND_RETURN_IT(status);
		}
		else
		{
			data = new AssetMetadataMPx();
		}

		AssetMetadata* assetMetadata = data->assetMetadata;

		if (_commandFlagsUsed & kEditMode)
		{
			if (undo)
			{
				*assetMetadata = _oldAssetMetadata.front();
				_oldAssetMetadata.pop();
			}
			else
			{
				_oldAssetMetadata.push(*assetMetadata);

				//if (_commandFlagsUsed & kAssetName) assetMetadata->setAssetName(_newAssetMetadata.getAssetName().c_str());
				if (_commandFlagsUsed & kAssetType) assetMetadata->setAssetType(_newAssetMetadata.getAssetType());
				if (_commandFlagsUsed & kAssetMode) assetMetadata->setAssetMode(_newAssetMetadata.getAssetMode());
				if (_commandFlagsUsed & kAssetVersion) assetMetadata->setAssetVersion(_newAssetMetadata.getAssetVersion());
				if (_commandFlagsUsed & kAssetID) assetMetadata->setAssetID(_newAssetMetadata.getAssetID());
				if (_commandFlagsUsed & kParentID) assetMetadata->setParentID(_newAssetMetadata.getParentID());
				if (_commandFlagsUsed & kProductionID) assetMetadata->setProductionID(_newAssetMetadata.getProductionID());
				if (_commandFlagsUsed & kObjectID) assetMetadata->setObjectID(_newAssetMetadata.getObjectID());
				if (_commandFlagsUsed & kObjectType) assetMetadata->setObjectType(_newAssetMetadata.getObjectType());
				if (_commandFlagsUsed & kObjectTypeFlags) assetMetadata->setObjectTypeFlags(_newAssetMetadata.getObjectTypeFlags());
				if (_commandFlagsUsed & kPartSides) assetMetadata->setPartSides(_newAssetMetadata.getPartSides());
				if (_commandFlagsUsed & kBodyParts) assetMetadata->setBodyParts(_newAssetMetadata.getBodyParts());
				if (_commandFlagsUsed & kFacialParts) assetMetadata->setFacialParts(_newAssetMetadata.getFacialParts());
				if (_commandFlagsUsed & kCameraRoles) assetMetadata->setCameraRoles(_newAssetMetadata.getCameraRoles());
				if (_commandFlagsUsed & kLightRoles) assetMetadata->setLightRoles(_newAssetMetadata.getLightRoles());
				if (_commandFlagsUsed & kViewportSettings) assetMetadata->setViewportSettings(_newAssetMetadata.getViewportSettings());
				if (_commandFlagsUsed & kRenderSettings) assetMetadata->setRenderSettings(_newAssetMetadata.getRenderSettings());
				if (_commandFlagsUsed & kCustomParts) assetMetadata->setCustomParts(_newAssetMetadata.getCustomParts());
				if (_commandFlagsUsed & kCustomFlags) assetMetadata->setCustomFlags(_newAssetMetadata.getCustomFlags());
				if (_commandFlagsUsed & kPipelineFlags) assetMetadata->setPipelineFlags(_newAssetMetadata.getObjectTypeFlags());
				if (_commandFlagsUsed & kObjectTypeFlags) assetMetadata->setObjectTypeFlags(_newAssetMetadata.getObjectTypeFlags());
			}

			status = plug.setValue(data);														CHECK_MSTATUS_AND_RETURN_IT(status);
		}
		else
		{
			clearResult();
			//if (_commandFlagsUsed & kAssetName) appendToResult(assetMetadata->getAssetName().c_str());
			if (_commandFlagsUsed & kAssetType) appendToResult(assetMetadata->getAssetTypeName().c_str());
			if (_commandFlagsUsed & kAssetMode) appendToResult(assetMetadata->getAssetModeName().c_str());
			if (_commandFlagsUsed & kAssetVersion) appendToResult(assetMetadata->getAssetVersionName().c_str());
			if (_commandFlagsUsed & kAssetID) appendToResult(assetMetadata->getAssetIDName().c_str());
			if (_commandFlagsUsed & kParentID) appendToResult(assetMetadata->getParentIDName().c_str());
			if (_commandFlagsUsed & kProductionID) appendToResult(assetMetadata->getProductionIDName().c_str());
			if (_commandFlagsUsed & kObjectID) appendToResult(assetMetadata->getObjectIDName().c_str());
			if (_commandFlagsUsed & kObjectType) appendToResult(assetMetadata->getObjectTypeName().c_str());
			if (_commandFlagsUsed & kObjectTypeFlags) appendToResult(csv(assetMetadata->getObjectTypeFlagNames()).c_str());
			if (_commandFlagsUsed & kPartSides) appendToResult(csv(assetMetadata->getPartSideNames()).c_str());
			if (_commandFlagsUsed & kBodyParts) appendToResult(csv(assetMetadata->getBodyPartNames()).c_str());
			if (_commandFlagsUsed & kFacialParts) appendToResult(csv(assetMetadata->getFacialPartNames()).c_str());
			if (_commandFlagsUsed & kCameraRoles) appendToResult(csv(assetMetadata->getCameraRoleNames()).c_str());
			if (_commandFlagsUsed & kLightRoles) appendToResult(csv(assetMetadata->getLightRoleNames()).c_str());
			if (_commandFlagsUsed & kViewportSettings) appendToResult(csv(assetMetadata->getViewportSettingNames()).c_str());
			if (_commandFlagsUsed & kRenderSettings) appendToResult(csv(assetMetadata->getRenderSettingNames()).c_str());
			if (_commandFlagsUsed & kCustomParts) appendToResult(csv(assetMetadata->getCustomPartNames()).c_str());
			if (_commandFlagsUsed & kCustomFlags) appendToResult(csv(assetMetadata->getCustomFlagNames()).c_str());
			if (_commandFlagsUsed & kPipelineFlags) appendToResult(csv(assetMetadata->getObjectTypeFlagNames()).c_str());
			if (_commandFlagsUsed & kObjectTypeFlags) appendToResult(csv(assetMetadata->getObjectTypeFlagNames()).c_str());
		}
	}

	return MS::kSuccess;
}

MStatus AssetMetadataCmd::doIt(const MArgList& argList)
{
	MStatus status = parseArguments(argList);													CHECK_MSTATUS_AND_RETURN_IT(status);
	return redoIt();
}

MStatus AssetMetadataCmd::redoIt() { return doCmd(false); }
MStatus AssetMetadataCmd::undoIt() { return doCmd(true); }