// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELB_IO_WRITERS_XDR_XDRREADER_H
#define HEMELB_IO_WRITERS_XDR_XDRREADER_H
#include <stdint.h>

#include <io/writers/xdr/xdr.h>

namespace hemelb
{
  namespace io
  {
    namespace writers
    {
      namespace xdr
      {
        // Class to read an Xdr-style file from disk.
        class XdrReader
        {
          public:
            // destructor.
            virtual ~XdrReader();

            // Functions for reading the next bit of the stream.
            bool readDouble(double& outDouble);
            bool readFloat(float& outDouble);
            bool readInt(int& outInt);
            bool readUnsignedInt(unsigned int& outUInt);
            bool readUnsignedLong(uint64_t& outULong);

            // Get the position in the stream.
            unsigned int GetPosition();
            bool SetPosition(unsigned int iPosition);

          protected:
            XdrReader();
            XDR mXdr;

        };

      } // namespace xdr
    } // namespace writers
  }
}

#endif // HEMELB_IO_WRITERS_XDR_XDRREADER_H
