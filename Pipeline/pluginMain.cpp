#include <maya/MFnPlugin.h>
#include "AssetMetadataCmd.h"

#define PLUGIN_VENDOR "Arnon Marcus"
#define PLUGIN_VERSION "PreAlpha"

#define ASSET_METADATA__COMMAND_NAME "assetMetadata"


MStatus initializePlugin(MObject obj)
{
	MStatus	  status;
	MFnPlugin plugin(obj, PLUGIN_VENDOR, PLUGIN_VERSION, "Any", &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	status = plugin.registerData(ASSET_METADATA__TYPENAME,
		AssetMetadataMPx::id,
		AssetMetadataMPx::creator);

	if (!status)
	{
		status.perror("registerData");
		return status;
	}

	status = plugin.registerCommand(ASSET_METADATA__COMMAND_NAME,
		AssetMetadataCmd::creator,
		AssetMetadataCmd::cmdSyntax);

	if (!status)
	{
		plugin.deregisterData(AssetMetadataMPx::id);
		status.perror("registerCommand");
		return status;
	}

	status = AssetMetadataCmd::addExtensionAttribute(obj);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	return status;
}

MStatus uninitializePlugin(MObject obj)
{
	MStatus	  status, status1, status2;
	MFnPlugin plugin(obj);

	status = AssetMetadataCmd::removeExtensionAttribute(obj);
	CHECK_MSTATUS_AND_RETURN_IT(status);


	status1 = plugin.deregisterCommand(ASSET_METADATA__COMMAND_NAME);
	if (!status1)
	{
		status1.perror("deregisterCommand");
	}
	status2 = plugin.deregisterData(AssetMetadataMPx::id);
	if (!status2)
	{
		status2.perror("deregisterData");
	}

	if (!status1)
		return status1;
	return status2;
}