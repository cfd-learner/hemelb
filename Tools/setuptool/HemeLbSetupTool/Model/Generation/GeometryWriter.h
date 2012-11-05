// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELBSETUPTOOL_GEOMETRYWRITER_H
#define HEMELBSETUPTOOL_GEOMETRYWRITER_H

#include <string>
#include <cstdio>

#include "Index.h"

#include "io/writers/xdr/XdrWriter.h"
using hemelb::io::writers::xdr::XdrWriter;

class BlockWriter;

class GeometryWriter {
public:
	GeometryWriter(const std::string& OutputGeometryFile,
			int BlockSize, Index BlockCounts, double VoxelSizeMetres, Vector OriginMetres);

	~GeometryWriter();

	void Close();
	BlockWriter* StartNextBlock();

protected:
	std::string OutputGeometryFile;
	int BlockSize;
	Index BlockCounts;
	double VoxelSizeMetres;
	Vector OriginMetres;

	int headerStart;
	XdrWriter* headerEncoder;
	unsigned int headerBufferLength;
	char *headerBuffer;

	int bodyStart;
	FILE* bodyFile;
	friend class BlockWriter;
};

#endif // HEMELBSETUPTOOL_GEOMETRYWRITER_H
