#include "AssetMetadataMPx.h"
#include "AssetMetadata.h"

using namespace Pipeline;

const MTypeId AssetMetadataMPx::id(ASSET_METADATA__ID);
const MString AssetMetadataMPx::typeName(ASSET_METADATA__TYPENAME);

void* AssetMetadataMPx::creator()
{
	return new AssetMetadataMPx;
}

void AssetMetadataMPx::copy(const MPxData& other)
{
	if (other.typeId() == AssetMetadataMPx::id)
	{
		AssetMetadataMPx* otherData = (AssetMetadataMPx*)&other;
		assetMetadata = otherData->assetMetadata;
	}
	else
	{
		cerr << "wrong data format!" << endl;
	}
}

MTypeId AssetMetadataMPx::typeId() const
{
	return AssetMetadataMPx::id;
}

MString AssetMetadataMPx::name() const
{
	return AssetMetadataMPx::typeName;
}

MStatus AssetMetadataMPx::readASCII(const MArgList& args, unsigned& lastParsedElement)
{
	MStatus status;

	int argLength = args.length();
	if (argLength > 0)
	{
		MString bufferStr;																											
		status = args.get(lastParsedElement++, bufferStr);
		CHECK_MSTATUS_AND_RETURN_IT(status);
		assetMetadata.setRawBuffer(bufferStr.asChar());
		return MS::kSuccess;
	}
	return MS::kFailure;
}

MStatus AssetMetadataMPx::writeASCII(ostream& out)
{
	MStatus status;

	out << BUFFER_LENGTH << " " << assetMetadata.getRawBuffer();
	
	return out.fail() ? MS::kFailure : MS::kSuccess;
}

MStatus AssetMetadataMPx::writeBinary(ostream& out)
{
	MStatus status;
	out.write(assetMetadata.getRawBuffer(), BUFFER_SIZE);
	return out.fail() ? MS::kFailure : MS::kSuccess;
}

MStatus AssetMetadataMPx::readBinary(istream& in, unsigned length)
{
	MStatus status;
	if (length > 0)
	{
		in.read(assetMetadata.getRawBuffer(), BUFFER_SIZE);
		return in.fail() ? MS::kFailure : MS::kSuccess;
	}
	
	return MS::kFailure;
}