// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#include "extraction/WholeGeometrySelector.h"

namespace hemelb
{
  namespace extraction
  {
    bool WholeGeometrySelector::IsWithinGeometry(const extraction::IterableDataSource& data,
                                                 const util::Vector3D<site_t>& location)
    {
      return true;
    }
  }
}
