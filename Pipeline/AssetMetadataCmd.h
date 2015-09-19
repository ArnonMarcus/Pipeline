#ifndef ASSET_METADATA__CMD
#define ASSET_METADATA__CMD

#include <queue>
#include <string>
#include <maya/MNodeClass.h>
#include <maya/MSelectionList.h>
#include <maya/MPxCommand.h>

#include "AssetMetadataMPx.h"

// Extension Attribute
#define kExtensionAttributeFullName "blindPipelineAssetData"
#define kExtensionAttributeShortName "bPAD"
#define kExtensionAttributeAffectedNodeClassName "dagNode"

// Text-message resources for this plug-in:
#define kPluginId 				"AssetMetadata"
#define kHelpText			    MStringResourceId   (kPluginId, "kObjectNotFoundError",     "Edit or Query Pipeline-Asset-Data on specified or selected DAG-objects:\n-help             [-h]   = print this help\n-assetName        [-nam] = Asset-Name\n-assetType        [-atp] = Asset-Type\n-assetMode        [-mod] = Asset-LOD-Mode\n-assetVersion     [-ver] = Asset's verion in that Asset-Mode\n-assetID          [-aID] = Asset's Instance-ID in the current scene\n-objectType       [-otp] = node's Asset-Object-Type\n-objectFlags      [-flg] = node's Asset-Object-Flag(s) [can exist multiple times]\n\n")
#define kEditQueryFlagErrorMsg  MStringResourceId	(kPluginId, "kEditQueryFlagErrorMsg",   "Can't specify edit and query flags simultanously.")
#define kObjectNotFoundError    MStringResourceId   (kPluginId, "kObjectNotFoundError",     "Object not found. No object(s) were specified, and no objects are currently selected in the scene(!)")
#define kAttributeNotFoundError MStringResourceId   (kPluginId, "kAttributeNotFoundError",  "Object does not have a PipelineAssetData attribute attached to it - Query mode failed(!)")
#define kAttributeWrongType     MStringResourceId   (kPluginId, "kAttributeWrongType",      "PipelineAssetData attribute holds a wrong dataType(!)")

// All flags in both 'short' and 'long' form
#define kL_AssetName	"-assetName"
#define kS_AssetName	"-nam"

#define kL_AssetType	"-assetType"
#define kS_AssetType	"-atp"

#define kL_AssetMode	"-assetMode"
#define kS_AssetMode	"-mod"

#define kL_AssetVersion	"-assetVersion"
#define kS_AssetVersion	"-ver"

#define kL_AssetID		"-assetID"
#define kS_AssetID		"-aID"

#define kL_ObjectType	"-objectType"
#define	kS_ObjectType	"-otp"

#define kL_ObjectFlags	"-objectFlag"
#define	kS_ObjectFlag	"-flg"

class AssetMetadataCmd : public MPxCommand
{
public:
	static void* creator() { return new AssetMetadataCmd(); }

	static MSyntax cmdSyntax();
	virtual MStatus redoIt();
	virtual MStatus undoIt();
	virtual MStatus	doIt(const MArgList& args);
	static MStatus removeExtensionAttribute(MObject plugin);
	static MStatus addExtensionAttribute(MObject plugin);
	virtual bool isUndoable() const { return true; }
	virtual	bool hasSyntax() { return true;	}
private:
	static MObject _extensionAttribute;
	static MObject _extensionAttributeDefaultValue;
	static MString _extensionAttributeFullName;
	static MString _extensionAttributeBriefName;
	static MNodeClass _extensionAttributeAffectedNodeClass;

	char _commandFlagsUsed;
	enum _commandFlag
	{
		kEditMode			= 0x01,
		kAssetName			= 0x02,
		kAssetType			= 0x04,
		kObjectType			= 0x08,
		kObjectFlags		= 0x10,
		kAssetMode			= 0x20,
		kAssetModeVersion	= 0x40,
		kAssetInstanceID	= 0x80
	};

	MSelectionList _currentSelectionList;
	
	AssetMetadata _newAssetMetadata;
	std::queue<AssetMetadata> _oldAssetMetadata;

	MStatus parseArguments(const MArgList& argList);
};

#endif