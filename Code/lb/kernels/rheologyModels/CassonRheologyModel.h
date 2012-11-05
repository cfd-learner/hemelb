// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELB_LB_KERNELS_RHEOLOGYMODELS_CASSONRHEOLOGYMODEL_H
#define HEMELB_LB_KERNELS_RHEOLOGYMODELS_CASSONRHEOLOGYMODEL_H

#include "lb/kernels/rheologyModels/AbstractRheologyModel.h"

namespace hemelb
{
  namespace lb
  {
    namespace kernels
    {
      namespace rheologyModels
      {
        // Casson model constants
        static const double K0 = 0.1937; // Pa^{1/2}
        static const double K1 = 0.055; // (Pa*s)^{1/2}

        static const double CASSON_MAX_VISCOSITY = 0.16; // Pa*s

        class CassonRheologyModel : public AbstractRheologyModel<CassonRheologyModel>
        {
          public:
            /*
             *  Compute nu for a given shear rate according to the Casson model:
             *
             *  eta = (K0 + K1*sqrt(iShearRate))^2 / iShearRate
             *  nu = eta / density
             *
             *  @param iShearRate local shear rate value (s^{-1}).
             *  @param iDensity local density. TODO at the moment this value is not used
             *         in any subclass.
             *
             *  @return kinematic viscosity (m^2/s).
             */
            static double CalculateViscosityForShearRate(const double &iShearRate,
                                                         const distribn_t &iDensity);
        };
      }
    }
  }
}

#endif /* HEMELB_LB_KERNELS_RHEOLOGYMODELS_CASSONRHEOLOGYMODEL_H */
