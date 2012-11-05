// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELB_IO_FORMATS_FORMATS_H
#define HEMELB_IO_FORMATS_FORMATS_H

namespace hemelb
{
  namespace io
  {
    namespace formats
    {
      // This is the generic HemeLB binary file identifier. It should be the
      // first 4 bytes of every (binary) file used for IO. It should be then
      // followed by another 4 bytes identifying the particular type/version,
      // that number being terminated by the EOF character (0x04)
      enum
      {
        // ASCII for hlb!
        HemeLbMagicNumber = 0x686c6221
      };
    }
  }

}
#endif // HEMELB_IO_FORMATS_H
