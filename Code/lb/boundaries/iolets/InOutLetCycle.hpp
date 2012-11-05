// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELB_LB_BOUNDARIES_IOLETS_INOUTLETCYCLE_HPP
#define HEMELB_LB_BOUNDARIES_IOLETS_INOUTLETCYCLE_HPP
#include "lb/boundaries/iolets/InOutLetCycle.h"
#include "lb/boundaries/BoundaryComms.h"

namespace hemelb
{
  namespace lb
  {
    namespace boundaries
    {
      namespace iolets
      {
        template<unsigned long updatePeriod, bool comms> void InOutLetCycle<updatePeriod, comms>::DoComms(bool is_io_proc,
                                                                                                                   LatticeTime time_step)
        {
          if (is_io_proc)
          {
            UpdateCycle(time_step);
            comms->Send(&densityBuffer[time_step]);
          }
          else
          {
            double incoming_density;
            comms->Receive(&incoming_density);
            densityBuffer[time_step] = incoming_density;
          }
        }
      }
    }
  }
}
#endif /* HEMELB_LB_BOUNDARIES_INOUTLETCYCLE_H */
