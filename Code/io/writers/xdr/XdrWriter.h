// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELB_IO_WRITERS_XDR_XDRWRITER_H
#define HEMELB_IO_WRITERS_XDR_XDRWRITER_H

#include "io/writers/xdr/xdr.h"

#include "io/writers/Writer.h"

namespace hemelb
{
  namespace io
  {
    namespace writers
    {
      namespace xdr
      {

        class XdrWriter : public Writer
        {
          public:
            // Method to get the current position of writing in the stream.
            unsigned int getCurrentStreamPosition() const;

            // Methods for formatting control
            void writeFieldSeparator();
            void writeRecordSeparator();

          protected:
            XDR mXdr;

            // Methods to write basic types to the Xdr object.
            void _write(int16_t const& intToWrite);
            void _write(uint16_t const& uIntToWrite);
            void _write(int32_t const& intToWrite);
            void _write(uint32_t const& uIntToWrite);
            void _write(int64_t const& intToWrite);
            void _write(uint64_t const& uIntToWrite);

            void _write(double const& doubleToWrite);
            void _write(float const& floatToWrite);

            void _write(const std::string& floatToWrite);
        };

      } // namespace xdr
    } // namespace writers
  }
}

#endif //HEMELB_IO_WRITERS_XDR_XDRWRITER_H
