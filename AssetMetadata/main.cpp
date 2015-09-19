#include <iostream>
#include "AssetMetadata.h"

using namespace std;
using namespace Pipeline;

int main(int argc, char* argv[])
{
	AssetMetadata assetMetadata;

	char* assetName = "Test";
	char* assetType = "prop";
	char* assetMode = "proxy";

	char* objectType = "rig";
	char* objectFlags[2] = { "hidden", "frozen" };
	char* objectRigPart = "leg";
	char* objectRigSide = "left";
	
	int assetModeVersion = 99;
	int assetInstanceID = 2000;
	int assetProductionID = 1000000;

	assetMetadata.setAssetName(assetName);
	assetMetadata.setAssetType(assetType);
	assetMetadata.setAssetMode(assetMode);

	assetMetadata.setAssetModeVersion(assetModeVersion);
	assetMetadata.setAssetInstanceID(assetInstanceID);
	assetMetadata.setAssetProductionID(assetProductionID);

	assetMetadata.setObjectType(objectType);
	assetMetadata.setObjectFlag(objectFlags[0]);
	assetMetadata.setObjectFlag(objectFlags[1]);
	assetMetadata.setObjectRigPart(objectRigPart);
	assetMetadata.setObjectRigSide(objectRigSide);

	bool assetName_Failed = assetMetadata.getAssetName().compare(assetName);
	bool assetType_Failed = assetMetadata.getAssetTypeString().compare(assetType);
	bool assetMode_Failed = assetMetadata.getAssetModeString().compare(assetMode);
	bool objectType_Failed = assetMetadata.getObjectTypeString().compare(objectType);
	bool objectRigPart_Failed = assetMetadata.getObjectRigPartString().compare(objectRigPart);
	bool objectRigSide_Failed = assetMetadata.getObjectRigSideString().compare(objectRigSide);
	bool assetModeVersion_Failed = assetMetadata.getAssetModeVersion() != assetModeVersion;
	bool assetInstanceID_Failed = assetMetadata.getAssetInstanceID() != assetInstanceID;
	bool assetProductionID_Failed = assetMetadata.getAssetProductionID() != assetProductionID;

	if (assetName_Failed) cout << "Asset Name: Given=" << assetName << " stored=" << assetMetadata.getAssetName() << endl;
	if (assetType_Failed) cout << "Asset Type: Given=" << assetType << " stored=" << assetMetadata.getAssetTypeString() << endl;
	if (assetMode_Failed) cout << "Asset Mode: Given=" << assetMode << " stored=" << assetMetadata.getAssetModeString() << endl;
	if (objectType_Failed) cout << "Object Type: Given=" << objectType << " stored=" << assetMetadata.getObjectTypeString() << endl;
	if (objectRigPart_Failed) cout << "Object Rig-Part: Given=" << objectRigPart << " stored=" << assetMetadata.getObjectRigPartString() << endl;
	if (objectRigSide_Failed) cout << "Object Rig-Side: Given=" << objectRigSide << " stored=" << assetMetadata.getObjectRigSideString() << endl;
	if (assetModeVersion_Failed) cout << "Asset Mode-Version: Given=" << assetModeVersion << " stored=" << assetMetadata.getAssetModeVersion() << endl;
	if (assetInstanceID_Failed) cout << "Asset Instance-ID: Given=" << assetInstanceID << " stored=" << assetMetadata.getAssetInstanceID() << endl;
	if (assetProductionID_Failed) cout << "Asset Production-ID: Given=" << assetProductionID << " stored=" << assetMetadata.getAssetProductionID() << endl;

	//cout << "Asset Name: ";
	//cin >> assetName;
	//cout << endl << "Asset Mode: ";
	//cin >> assetMode;
	//cout << endl << "Asset Mode-Version: ";
	//cin >> assetModeVersion;
	//cout << endl << "Asset Instance-ID: ";
	//cin >> assetInstanceID;
	//cout << endl << "Asset Production-ID: ";
	//cin >> assetProductionID;
	//cout << endl << "Asset Type: ";
	//cin >> assetType;
	//cout << endl << "Object Type: ";
	//cin >> objectType;
	//cout << endl << "Object Flag (1): ";
	//cin >> objectFlags[0];
	//cout << endl << "Object Flag (2): ";
	//cin >> objectFlags[1];
	//cout << endl << "Object Rig-Part: ";
	//cin >> objectRigPart;
	//cout << endl << "Object Rig-Side: ";
	//cin >> objectRigSide;

	//cout << "Asset Name: " << assetName << endl;
	//cout << "Asset Mode: " << assetMode << endl;
	//cout << "Asset Mode-Version: " << assetModeVersion << endl;
	//cout << "Asset Instance-ID: " << assetInstanceID << endl;
	//cout << "Asset Production-ID: " << assetProductionID << endl;
	//cout << "Asset Type: " << assetType << endl;
	//cout << "Object Type: " << objectType << endl;
	//cout << "Object Flags: " << objectFlags << endl;
	//cout << "Object Rig-Part: " << objectRigPart << endl;
	//cout << "Object Rig-Side: " << objectRigSide << endl;

	cin.get();
	return 0;
}