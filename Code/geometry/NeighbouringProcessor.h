// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELB_GEOMETRY_NEIGHBOURINGPROCESSOR_H
#define HEMELB_GEOMETRY_NEIGHBOURINGPROCESSOR_H

#include "units.h"

namespace hemelb
{
  namespace geometry
  {
    /**
     * Encapsulates data about a processor which has at least 1 site which
     * neighbours at least one site local to this core.
     */
    struct NeighbouringProcessor
    {
      public:
        //! Rank of the neighbouring processor.
        proc_t Rank;

        //! The number of distributions shared between this neighbour and the current processor.
        //! Note that this is not equal to the number of interfacing sites * lattice connectivity
        //! because we only send the distributions that point towards the neighbour.
        site_t SharedDistributionCount;

        //! Index on this processor of the first distribution shared between this
        //! neighbour and the current processor.
        site_t FirstSharedDistribution;
    };
  }
}

#endif /* HEMELB_GEOMETRY_NEIGHBOURINGPROCESSOR_H */
