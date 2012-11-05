// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELB_LB_COLLISIONS_BASECOLLISION_H
#define HEMELB_LB_COLLISIONS_BASECOLLISION_H

#include "constants.h"
#include "lb/LbmParameters.h"
#include "geometry/LatticeData.h"

namespace hemelb
{
  namespace lb
  {
    namespace collisions
    {
      /**
       * BaseCollision: inheritable base class for the collision operator. The public interface
       * here defines the complete interface usable by streaming operators:
       *  - CalculatePreCollision(CHydroVars&, site_t)
       *  - Collide(const LbmParameters*, unsigned int, CHydroVars&)
       *  - Reset(InitParams*)
       *
       * The following must be implemented must be collisions (which derive from this class
       * using the CRTP).
       *  - CKernel, the type of the kernel to be used.
       *  - DoCalculatePreCollision(CHydroVars&, site_t)
       *  - DoCollide(const LbmParameters*, unsigned int, CHydroVars&) returns distribn_t
       *  - DoReset(InitParams*)
       */
      template<typename CollisionImpl, typename KernelImpl>
      class BaseCollision
      {
        public:
          typedef KernelImpl CKernel;

          inline void CalculatePreCollision(kernels::HydroVars<KernelImpl>& hydroVars,
                                            const geometry::Site& site)
          {
            static_cast<CollisionImpl*>(this)->DoCalculatePreCollision(hydroVars, site);
          }

          inline void Collide(const LbmParameters* lbmParams,
                              kernels::HydroVars<KernelImpl>& hydroVars)
          {
            static_cast<CollisionImpl*>(this)->DoCollide(lbmParams, hydroVars);
          }

          inline void Reset(kernels::InitParams* init)
          {
            static_cast<CollisionImpl*>(this)->DoReset(init);
          }
      };

    }
  }
}

#endif /* HEMELB_LB_COLLISIONS_BASECOLLISION_H */
