// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#include "io/writers/Writer.h"

namespace hemelb
{
  namespace io
  {
    namespace writers
    {

      Writer::Writer()
      {
      }

      Writer::~Writer()
      {
        // Pure virtual destructor
      }

      Writer& Writer::operator<<(enum Writer::Separator const & value)
      {
        writeRecordSeparator();
        return *this;
      }

    } // namespace writer
  }
}
