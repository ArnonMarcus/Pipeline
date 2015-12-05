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
//#define kL_AssetName	"-assetName"
//#define kS_AssetName	"-nam"

#define kL_AssetType	"-assetType"
#define kS_AssetType	"-at"

#define kL_AssetMode	"-assetMode"
#define kS_AssetMode	"-mod"

#define kL_AssetVersion	"-assetVersion"
#define kS_AssetVersion	"-ver"

#define kL_ParentID		"-parentID"
#define kS_ParentID		"-pnt"

#define kL_ProductionID	"-productionID"
#define kS_ProductionID	"-prd"

#define kL_AssetID		"-assetID"
#define kS_AssetID		"-ast"

#define kL_ObjectID		"-ObjectID"
#define kS_ObjectID		"-obj"

#define kL_ObjectType	"-objectType"
#define	kS_ObjectType	"-ot"

#define kL_ObjectTypeFlags	"-objectTypeFlag"
#define	kS_ObjectTypeFlags	"-otf"

#define kL_LightRoles "-lightRoles"
#define	kS_LightRoles "-lrl"

#define kL_LightRoles "-lightRoles"
#define	kS_LightRoles "-lrl"

#define kL_CameraRoles "-cameraRoles"
#define	kS_CameraRoles "-crl"

#define kL_PartSides "-partSides"
#define	kS_PartSides "-psd"

#define kL_BodyParts "-bodyParts"
#define	kS_BodyParts "-bpt"

#define kL_FacialParts "-facialParts"
#define	kS_FacialParts "-fpt"

#define kL_RenderSettings "-renderSettings"
#define	kS_RenderSettings "-rst"

#define kL_ViewportSettings	"-viewportSettings"
#define	kS_ViewportSettings "-vst"

#define kL_CustomParts	"-customParts"
#define	kS_CustomParts	"-cpt"

#define kL_CustomFlags	"-customFlags"
#define	kS_CustomFlags	"-cfg"

#define kL_PipelineFlags "-pipelineFlags"
#define	kS_PipelineFlags "-pfg"

using namespace Pipeline::bits::for_32bit;

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
	//static MObject _extensionAttributeDefaultValue;
	static MString _extensionAttributeFullName;
	static MString _extensionAttributeBriefName;
	static MNodeClass _extensionAttributeAffectedNodeClass;

	uint32 _commandFlagsUsed;
	enum _commandFlag
	{
		kEditMode = bit_01,
		kAssetType = bit_02,
		kAssetMode = bit_03,
		kAssetVersion = bit_04,
		kAssetID = bit_05,
		kParentID = bit_06,
		kProductionID = bit_07,
		kObjectID = bit_08,
		kObjectType = bit_09,
		kObjectTypeFlags = bit_10,
		kPartSides = bit_11,
		kBodyParts = bit_12,
		kFacialParts = bit_13,
		kCameraRoles = bit_14,
		kLightRoles = bit_15,
		kRenderSettings = bit_16,
		kViewportSettings = bit_17,
		kCustomFlags = bit_18,
		kCustomParts = bit_19,
		kPipelineFlags = bit_20
	};

	MSelectionList _currentSelectionList;
	
	AssetMetadata _newAssetMetadata;
	std::queue<AssetMetadata> _oldAssetMetadata;

	MStatus parseArguments(const MArgList& argList);
	MStatus doCmd(bool undo);
};

#endif