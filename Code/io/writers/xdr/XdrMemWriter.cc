// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#include "io/writers/xdr/xdr.h"
#include "io/writers/xdr/XdrMemWriter.h"

namespace hemelb
{
  namespace io
  {
    namespace writers
    {
      namespace xdr
      {

        // Constructor for a Xdr writer held in a memory buffer.
        XdrMemWriter::XdrMemWriter(char* dataBuffer, unsigned int dataLength)
        {
          xdrmem_create(&mXdr, dataBuffer, dataLength, XDR_ENCODE);
        }

        // Destructor for the class.
        XdrMemWriter::~XdrMemWriter()
        {
          xdr_destroy(&mXdr);
        }

      } // namespace xdr
    } // namespace writers
  }
}
