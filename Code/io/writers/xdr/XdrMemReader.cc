// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

/*
 * XdrFileReader.cc
 *
 *  Created on: Oct 25, 2010
 *      Author: rupert
 */

#include "io/writers/xdr/XdrMemReader.h"

namespace hemelb
{
  namespace io
  {
    namespace writers
    {
      namespace xdr
      {
        // Constructor to create an Xdr object based on a memory buffer
        XdrMemReader::XdrMemReader(char* dataBuffer, unsigned int dataLength)
        {
          xdrmem_create(&mXdr, dataBuffer, dataLength, XDR_DECODE);
        }

      } // namespace xdr
    } // namespace writers
  }
}
