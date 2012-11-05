// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELB_VIS_DOMAINSTATS_H
#define HEMELB_VIS_DOMAINSTATS_H

#include "constants.h"

namespace hemelb
{
  namespace vis
  {
    struct DomainStats
    {
      public:
        distribn_t velocity_threshold_max_inv;
        distribn_t stress_threshold_max_inv;
        distribn_t density_threshold_min;
        distribn_t density_threshold_minmax_inv;
        float physical_pressure_threshold_min;
        float physical_pressure_threshold_max;
        float physical_velocity_threshold_max;
        float physical_stress_threshold_max;
    };
  }
}

#endif /* HEMELB_VIS_DOMAINSTATS_H */

