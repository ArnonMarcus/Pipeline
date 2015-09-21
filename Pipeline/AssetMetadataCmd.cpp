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
	syntax.addFlag(kS_AssetName, kL_AssetName, MSyntax::kString);
	syntax.addFlag(kS_AssetType, kL_AssetType, MSyntax::kString);
	syntax.addFlag(kS_AssetMode, kL_AssetMode, MSyntax::kString);
	syntax.addFlag(kS_ObjectType, kL_ObjectType, MSyntax::kString);
	syntax.addFlag(kS_AssetVersion, kL_AssetVersion, MSyntax::kUnsigned);
	syntax.addFlag(kS_AssetID, kL_AssetID, MSyntax::kUnsigned);
	syntax.addFlag(kS_ObjectFlag, kL_ObjectFlags, MSyntax::kString);
	syntax.makeFlagMultiUse(kL_ObjectFlags);

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

	if (argData.isFlagSet(kS_AssetName)) _commandFlagsUsed |= kAssetName;
	if (argData.isFlagSet(kS_AssetType)) _commandFlagsUsed |= kAssetType;
	if (argData.isFlagSet(kS_AssetMode)) _commandFlagsUsed |= kAssetMode;
	if (argData.isFlagSet(kS_AssetVersion)) _commandFlagsUsed |= kAssetModeVersion;
	if (argData.isFlagSet(kS_AssetID)) _commandFlagsUsed |= kAssetInstanceID;
	if (argData.isFlagSet(kS_ObjectType)) _commandFlagsUsed |= kObjectType;
	if (argData.isFlagSet(kS_ObjectFlag)) _commandFlagsUsed |= kObjectFlags;

	if (_commandFlagsUsed & kEditMode)
	{
		if (_commandFlagsUsed & kAssetName) _newAssetMetadata.setAssetName(argData.flagArgumentString(kS_AssetName, 0).asChar());
		if (_commandFlagsUsed & kAssetType) _newAssetMetadata.setAssetType(AssetTypes::getEnum(argData.flagArgumentString(kS_AssetType, 0).asChar()));
		if (_commandFlagsUsed & kAssetMode) _newAssetMetadata.setAssetMode(AssetModes::getEnum(argData.flagArgumentString(kS_AssetMode, 0).asChar()));
		if (_commandFlagsUsed & kAssetModeVersion) _newAssetMetadata.setAssetModeVersion(argData.flagArgumentString(kS_AssetVersion, 0).asShort());
		if (_commandFlagsUsed & kAssetInstanceID) _newAssetMetadata.setAssetInstanceID(argData.flagArgumentString(kS_AssetID, 0).asShort());
		if (_commandFlagsUsed & kObjectType) _newAssetMetadata.setObjectType(ObjectTypes::getEnum(argData.flagArgumentString(kS_ObjectType, 0).asChar()));
		if (_commandFlagsUsed & kObjectFlags)
		{
			_newAssetMetadata.clearObjectFlags();
			unsigned int numFlags = argData.numberOfFlagUses(kS_ObjectFlag);
			for (unsigned int i = 0; i < numFlags; i++)
			{
				_newAssetMetadata.setObjectFlag(ObjectFlags::getEnum(argData.flagArgumentString(kS_ObjectFlag, i).asChar()));
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

				if (_commandFlagsUsed & kAssetName) assetMetadata->setAssetName(_newAssetMetadata.getAssetName().c_str());
				if (_commandFlagsUsed & kAssetType) assetMetadata->setAssetType(_newAssetMetadata.getAssetType());
				if (_commandFlagsUsed & kObjectType) assetMetadata->setObjectType(_newAssetMetadata.getObjectType());
				if (_commandFlagsUsed & kObjectFlags) assetMetadata->setObjectFlags(_newAssetMetadata.getObjectFlags());
				if (_commandFlagsUsed & kAssetMode) assetMetadata->setAssetMode(_newAssetMetadata.getAssetMode());
				if (_commandFlagsUsed & kAssetModeVersion) assetMetadata->setAssetModeVersion(_newAssetMetadata.getAssetModeVersion());
				if (_commandFlagsUsed & kAssetInstanceID) assetMetadata->setAssetInstanceID(_newAssetMetadata.getAssetInstanceID());
			}

			status = plug.setValue(data);														CHECK_MSTATUS_AND_RETURN_IT(status);
		}
		else
		{
			clearResult();
			if (_commandFlagsUsed & kAssetName) appendToResult(assetMetadata->getAssetName().c_str());
			if (_commandFlagsUsed & kAssetType) appendToResult(assetMetadata->getAssetTypeString().c_str());
			if (_commandFlagsUsed & kObjectType) appendToResult(assetMetadata->getObjectTypeString().c_str());
			if (_commandFlagsUsed & kObjectFlags) appendToResult(assetMetadata->getObjectFlagsAsString().c_str());
			if (_commandFlagsUsed & kAssetMode) appendToResult(assetMetadata->getAssetModeString().c_str());
			if (_commandFlagsUsed & kAssetModeVersion) appendToResult(assetMetadata->getAssetModeVersionString().c_str());
			if (_commandFlagsUsed & kAssetInstanceID) appendToResult(assetMetadata->getAssetInstanceIDString().c_str());
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