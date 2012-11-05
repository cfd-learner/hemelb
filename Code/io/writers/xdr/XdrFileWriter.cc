// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#include <cstdio>
#include "io/writers/xdr/xdr.h"
#include "io/writers/xdr/XdrFileWriter.h"

namespace hemelb
{
  namespace io
  {
    namespace writers
    {
      namespace xdr
      {

        // Implement a constructor that opens the file and creates the Xdr
        // object to write to it.
        XdrFileWriter::XdrFileWriter(const std::string& fileName, const std::string& mode)
        {
          myFile = std::fopen(fileName.c_str(), mode.c_str());
          xdrstdio_create(&mXdr, myFile, XDR_ENCODE);
        }

        // A destructor that ends the work of the Xdr object (including a
        // flush to file, so the order is important here), then frees the
        // memory and closes the file.
        XdrFileWriter::~XdrFileWriter()
        {
          xdr_destroy(&mXdr);
          std::fclose(myFile);
        }

      } // namespace xdr

    } // namespace writers

  }
}
