// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELB_IO_WRITERS_XDR_XDRFILEWRITER_H
#define HEMELB_IO_WRITERS_XDR_XDRFILEWRITER_H

#include <cstdio>
#include <string>

#include "io/writers/xdr/XdrWriter.h"

namespace hemelb
{
  namespace io
  {
    namespace writers
    {
      namespace xdr
      {

        // Class to write Xdr to a file. The actual write functions are implemented in the base class, XdrWriter.
        class XdrFileWriter : public XdrWriter
        {

            // Implement the constructor and destructor to deal with the FILE
            // and XDR objects.
          public:
            XdrFileWriter(const std::string& fileName, const std::string& mode = "w");
            ~XdrFileWriter();

          private:
            std::FILE *myFile;

        };

      } // namespace xdr
    } // namespace writers
  }
}
#endif // HEMELB_IO_WRITERS_XDR_XDRFILEWRITER_H
