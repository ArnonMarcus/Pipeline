#ifndef ASSET_METADATA__MPX
#define ASSET_METADATA__MPX
#define	ASSET_METADATA__TYPENAME "assetMetadataType"
#define ASSET_METADATA__ID 0x80002

#include <maya/MArgList.h>
#include <maya/MString.h>
#include <maya/MTypeId.h>
#include <maya/MIOStream.h>
#include <maya/MPxData.h>
#include <maya/MGlobal.h>

#include <assert.h>

#include "AssetMetadata.h"

using namespace Pipeline;

class AssetMetadataMPx : public MPxData
{
public:
	AssetMetadataMPx() { assetMetadata = new AssetMetadata; };
	virtual ~AssetMetadataMPx() { delete assetMetadata; };

	virtual MStatus         readASCII(const MArgList&, unsigned& lastElement);
	virtual MStatus         readBinary(istream& in, unsigned length);
	virtual MStatus         writeASCII(ostream& out);
	virtual MStatus         writeBinary(ostream& out);

	virtual void			copy(const MPxData&);

	MTypeId                 typeId() const;
	MString					name() const;

	static const MString    typeName;
	static const MTypeId    id;
	static void*            creator();

	AssetMetadata*			assetMetadata;
};

#endif;