// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELB_IO_WRITERS_ASCII_ASCIIFILEWRITER_H
#define HEMELB_IO_WRITERS_ASCII_ASCIIFILEWRITER_H

#include <iostream>

#include "io/writers/ascii/AsciiStreamWriter.h"

namespace hemelb
{
  namespace io
  {
    namespace writers
    {
      namespace ascii
      {
        // Class to write a file. The actual write functions are implemented
        // in the base class.
        class AsciiFileWriter : public AsciiStreamWriter
        {

          public:
            AsciiFileWriter(std::string fileName);
            ~AsciiFileWriter();

        };
      } // namespace ascii
    } // namespace writers
  }
}
#endif // HEMELB_IO_WRITERS_ASCII_ASCIIFILEWRITER_H
