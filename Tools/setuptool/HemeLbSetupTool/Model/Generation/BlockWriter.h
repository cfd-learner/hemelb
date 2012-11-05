// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELBSETUPTOOL_BLOCKWRITER_H
#define HEMELBSETUPTOOL_BLOCKWRITER_H

#include <stddef.h>
#include <string>
#include "io/writers/xdr/XdrMemWriter.h"

class GeometryWriter;
/*
 * Extension of a hemelb::io::XdrWriter that notes how many fluid sites, in how
 * much space, have been written. It then pushes this to the GeometryWriter's
 * headerEncoder and writes to the GeometryWriter's body
 */

class BlockWriter {
public:
	BlockWriter(int blocksize);
	void Reset();

	~BlockWriter();

	void IncrementFluidSitesCount();

	void Finish();
	void Write(GeometryWriter& gw);

	// Overload << to delegate to the XdrMemWriter
	template<typename T>
	BlockWriter& operator<<(T const & value) {
		(*this->writer) << value;
		return *this;
	}

protected:
	unsigned int maxBufferSize;
	char* buffer;
	hemelb::io::writers::xdr::XdrMemWriter* writer;
	unsigned int nFluidSites;
	unsigned int CompressedBlockLength;
	unsigned int UncompressedBlockLength;
	bool IsFinished;
};

#endif // HEMELBSETUPTOOL_BLOCKWRITER_H
