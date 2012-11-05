// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#include "extraction/GeometrySelector.h"

namespace hemelb
{
  namespace extraction
  {
    bool GeometrySelector::Include(const extraction::IterableDataSource& data,
                                   const util::Vector3D<site_t>& location)
    {
      if (!data.IsValidLatticeSite(location) || !data.IsAvailable(location))
      {
        return false;
      }

      return IsWithinGeometry(data, location);
    }
  }
}
