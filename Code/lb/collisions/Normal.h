// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELB_LB_COLLISIONS_NORMAL_H
#define HEMELB_LB_COLLISIONS_NORMAL_H

#include "lb/collisions/BaseCollision.h"
#include "lb/kernels/BaseKernel.h"

namespace hemelb
{
  namespace lb
  {
    namespace collisions
    {
      /**
       * Normal collisions - use a formula to relax the distribution towards equilibrium.
       */
      template<typename KernelType>
      class Normal : public BaseCollision<Normal<KernelType>, KernelType>
      {
        public:
          typedef KernelType CKernel;

          Normal(kernels::InitParams& initParams) :
              kernel(initParams)
          {
          }

          inline void DoCalculatePreCollision(kernels::HydroVars<KernelType>& hydroVars,
                                              const geometry::Site& site)
          {
            kernel.CalculateDensityMomentumFeq(hydroVars, site.GetIndex());
          }

          inline void DoCollide(const LbmParameters* lbmParams,
                                kernels::HydroVars<KernelType>& iHydroVars)
          {
            kernel.Collide(lbmParams, iHydroVars);
          }

          inline void DoReset(kernels::InitParams* init)
          {
            kernel.Reset(init);
          }

          KernelType kernel;

      };

    }
  }
}

#endif /* HEMELB_LB_COLLISIONS_NORMAL_H */
