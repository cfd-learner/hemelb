#include "GeometryWriter.h"
#include "BlockWriter.h"

#include "io/formats/formats.h"
#include "io/formats/geometry.h"
#include "io/writers/xdr/XdrFileWriter.h"
#include "io/writers/xdr/XdrMemWriter.h"


GeometryWriter::GeometryWriter(const std::string& OutputGeometryFile,
		int BlockSize, Index BlockCounts, double VoxelSizeMetres, Vector OriginMetres) :
	OutputGeometryFile(OutputGeometryFile) {

	// Copy in key data
	this->BlockSize = BlockSize;
	this->VoxelSizeMetres = VoxelSizeMetres;

	for (unsigned int i = 0; i < 3; ++i) {
		this->BlockCounts[i] = BlockCounts[i];
		this->OriginMetres[i] = OriginMetres[i];
	}

	{
		hemelb::io::writers::xdr::XdrFileWriter encoder(this->OutputGeometryFile);

		// Write the preamble

		// General magic
		encoder << static_cast<unsigned int>(hemelb::io::formats::HemeLbMagicNumber);
		// Geometry magic
		encoder << static_cast<unsigned int>(hemelb::io::formats::geometry::MagicNumber);
		// Geometry file format version number
		encoder << static_cast<unsigned int>(hemelb::io::formats::geometry::VersionNumber);

		// Blocks in each dimension
		for (unsigned int i = 0; i < 3; ++i)
			encoder << this->BlockCounts[i];

		// Sites along 1 dimension of a block
		encoder << this->BlockSize;

		// Voxel Size, in metres
		encoder << this->VoxelSizeMetres;

		// Position of site index (0,0,0) in block index (0,0,0), in
		// metres in the STL file's coordinate system
		for (unsigned int i = 0; i < 3; ++i)
			encoder << this->OriginMetres[i];

		// padding
		encoder << 0U;
		// TODO: Check that buffer length is 64 bytes

		// (Dummy) Header

		// Note the start of the header
		this->headerStart = encoder.getCurrentStreamPosition();
		unsigned int nBlocks = this->BlockCounts[0] * this->BlockCounts[1]
				* this->BlockCounts[2];

		// The XDR writer interface doesn't let us at the file underneath.
		// We need to write HeaderRecordLength * nBlocks worth of junk bytes.
		// The smallest unit XDR will write is 32 bits, so divide by 4 and
		// write that many zeros
		unsigned int headerLengthInXdrWords = hemelb::io::formats::geometry::HeaderRecordLength * nBlocks / 4;
		// Write a dummy header
		for (unsigned int i = 0; i < headerLengthInXdrWords; ++i) {
			encoder << 0;
		}

		this->bodyStart = encoder.getCurrentStreamPosition();

		// Setup the encoder for the header
		this->headerBufferLength = this->bodyStart - this->headerStart;
		this->headerBuffer = new char[this->headerBufferLength];
		this->headerEncoder = new hemelb::io::writers::xdr::XdrMemWriter(this->headerBuffer,
				this->headerBufferLength);
	}
	// "encoder" declared in the block above will now have been destructed, thereby closing the file.
	// Reopen it for writing the blocks we're about to generate.
	this->bodyFile = std::fopen(this->OutputGeometryFile.c_str(), "a");
}

GeometryWriter::~GeometryWriter() {
	delete this->headerEncoder;
	delete[] this->headerBuffer;
	// Check this is still here as Close() will delete this
	if (this->bodyFile != NULL)
		std::fclose(this->bodyFile);
}

void GeometryWriter::Close() {
	// Close the geometry file
	std::fclose(this->bodyFile);
	this->bodyFile= NULL;

	// Reopen it, write the header buffer, close it.
	std::FILE* cfg = std::fopen(this->OutputGeometryFile.c_str(), "r+");
	std::fseek(cfg, this->headerStart, SEEK_SET);
	std::fwrite(this->headerBuffer, 1, this->headerBufferLength, cfg);
	std::fclose(cfg);

}

BlockWriter* GeometryWriter::StartNextBlock() {
	return new BlockWriter(this->BlockSize);
}

