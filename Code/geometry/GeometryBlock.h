// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELB_GEOMETRY_GEOMETRYBLOCK_H
#define HEMELB_GEOMETRY_GEOMETRYBLOCK_H

#include <vector>
#include "geometry/GeometrySite.h"

namespace hemelb
{
  namespace geometry
  {
    /***
     * Model of the information stored for a block in a geometry file.
     * Just gives the array of sites
     */
    struct BlockReadResult
    {
      public:
        std::vector<GeometrySite> Sites;
    };
  }
}

#endif /* HEMELB_GEOMETRY_GEOMETRYBLOCK_H */
