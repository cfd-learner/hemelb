// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELB_IO_WRITERS_XDR_XDRMEMREADER_H
#define HEMELB_IO_WRITERS_XDR_XDRMEMREADER_H

#include <cstdio>

#include "io/writers/xdr/XdrReader.h"

namespace hemelb
{
  namespace io
  {
    namespace writers
    {
      namespace xdr
      {

        class XdrMemReader : public XdrReader
        {
          public:
            XdrMemReader(char* dataBuffer, unsigned int dataLength);

        };
      } // namespace xdr
    } // namespace writers
  }
}

#endif /* HEMELB_IO_XDRFILEREADER_H */
