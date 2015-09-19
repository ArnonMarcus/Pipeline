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
/*static*/ MObject AssetMetadataCmd::_extensionAttributeDefaultValue;
/*static*/ MString AssetMetadataCmd::_extensionAttributeFullName(kExtensionAttributeFullName);
/*static*/ MString AssetMetadataCmd::_extensionAttributeBriefName(kExtensionAttributeShortName);
/*static*/ MNodeClass AssetMetadataCmd::_extensionAttributeAffectedNodeClass(kExtensionAttributeAffectedNodeClassName);

/*static*/ MStatus AssetMetadataCmd::addExtensionAttribute(MObject plugin)
{
	MStatus status;

	MFnPluginData fnData;
	AssetMetadataCmd::_extensionAttributeDefaultValue = fnData.create(AssetMetadataMPx::id, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	MFnTypedAttribute fnAttr;
	AssetMetadataCmd::_extensionAttribute = fnAttr.create(
		AssetMetadataCmd::_extensionAttributeFullName,
		AssetMetadataCmd::_extensionAttributeBriefName,
		AssetMetadataMPx::id,
		AssetMetadataCmd::_extensionAttributeDefaultValue, &status);
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

MStatus AssetMetadataCmd::doIt(const MArgList& argList)
{
	MStatus status = parseArguments(argList);
	if (status != MS::kSuccess)
	{
		return status;
	}

	return redoIt();
}

MStatus AssetMetadataCmd::redoIt()
{
	clearResult();

	MStatus status;

	MPlug plug;
	MObject node;
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
		//dhData = plug.asMDataHandle(MDGContext::fsNormal, &status);								CHECK_MSTATUS_AND_RETURN_IT(status);
		//if (dhData.typeId() != AssetMetadataMPx::id)
		//{
		//	MString msg = MStringResource::getString(kAttributeWrongType, status);
		//	displayError(msg);
		//	return MS::kFailure;
		//}

		//status = fnData.setObject(dhData.data());												CHECK_MSTATUS_AND_RETURN_IT(status);
		//data = (AssetMetadataMPx*)fnData.constData(&status);									CHECK_MSTATUS_AND_RETURN_IT(status);

		MObject sData;
		status = plug.getValue(sData);

		if (status != MS::kSuccess)
		{
			cerr << "error getting value off plug" << endl;
			continue;
		}

		status = fnData.setObject(sData);														CHECK_MSTATUS_AND_RETURN_IT(status);

		//MFnPluginData pdFn(sData);

		data = (AssetMetadataMPx*)fnData.constData(&status);									CHECK_MSTATUS_AND_RETURN_IT(status);


		if (_commandFlagsUsed & kEditMode)
		{
			_oldAssetMetadata.push(data->assetMetadata);

			if (_commandFlagsUsed & kAssetName) data->assetMetadata.setAssetName(_newAssetMetadata.getAssetName().c_str());
			if (_commandFlagsUsed & kAssetType) data->assetMetadata.setAssetType(_newAssetMetadata.getAssetType());
			if (_commandFlagsUsed & kObjectType) data->assetMetadata.setObjectType(_newAssetMetadata.getObjectType());
			if (_commandFlagsUsed & kObjectFlags) data->assetMetadata.setObjectFlags(_newAssetMetadata.getObjectFlags());
			if (_commandFlagsUsed & kAssetMode) data->assetMetadata.setAssetMode(_newAssetMetadata.getAssetMode());
			if (_commandFlagsUsed & kAssetModeVersion) data->assetMetadata.setAssetModeVersion(_newAssetMetadata.getAssetModeVersion());
			if (_commandFlagsUsed & kAssetInstanceID) data->assetMetadata.setAssetInstanceID(_newAssetMetadata.getAssetInstanceID());

			status = plug.setValue(data);														CHECK_MSTATUS_AND_RETURN_IT(status);
		}
		else
		{
			if (_commandFlagsUsed & kAssetName) appendToResult(data->assetMetadata.getAssetName().c_str());
			if (_commandFlagsUsed & kAssetType) appendToResult(data->assetMetadata.getAssetTypeString().c_str());
			if (_commandFlagsUsed & kObjectType) appendToResult(data->assetMetadata.getObjectTypeString().c_str());
			if (_commandFlagsUsed & kObjectFlags) appendToResult(data->assetMetadata.getObjectFlagsAsString().c_str());
			if (_commandFlagsUsed & kAssetMode) appendToResult(data->assetMetadata.getAssetModeString().c_str());
			if (_commandFlagsUsed & kAssetModeVersion) appendToResult(data->assetMetadata.getAssetModeVersionString().c_str());
			if (_commandFlagsUsed & kAssetInstanceID) appendToResult(data->assetMetadata.getAssetInstanceIDString().c_str());
		}
	}

	return MS::kSuccess;
}

MStatus AssetMetadataCmd::undoIt()
{

	MStatus status;

	MPlug plug;
	MObject node;
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
		if (dhData.typeId() != AssetMetadataMPx::id)
		{
			MString msg = MStringResource::getString(kAttributeWrongType, status);
			displayError(msg);
			return MS::kFailure;
		}

		status = fnData.setObject(dhData.data());												CHECK_MSTATUS_AND_RETURN_IT(status);
		data = (AssetMetadataMPx*)fnData.constData(&status);								CHECK_MSTATUS_AND_RETURN_IT(status);

		if (_commandFlagsUsed & kEditMode)
		{
			data->assetMetadata.setRawBuffer(_oldAssetMetadata.front().getRawBuffer());
			_oldAssetMetadata.pop();

			status = plug.setValue(data);														CHECK_MSTATUS_AND_RETURN_IT(status);
		}
	}

	return MS::kSuccess;
}