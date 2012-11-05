// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELB_EXTRACTION_PROPERTYOUTPUTFILE_H
#define HEMELB_EXTRACTION_PROPERTYOUTPUTFILE_H

#include <string>
#include <vector>
#include "extraction/GeometrySelector.h"
#include "extraction/OutputField.h"

namespace hemelb
{
  namespace extraction
  {
    struct PropertyOutputFile
    {
        PropertyOutputFile()
        {
          geometry = NULL;
        }

        ~PropertyOutputFile()
        {
          delete geometry;
        }

        std::string filename;
        unsigned long frequency;
        GeometrySelector* geometry;
        std::vector<OutputField> fields;
    };
  }
}

#endif /* HEMELB_EXTRACTION_PROPERTYOUTPUTFILE_H */
