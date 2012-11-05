// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#include "lb/kernels/rheologyModels/CarreauYasudaRheologyModel.h"
#include <cmath>

namespace hemelb
{
  namespace lb
  {
    namespace kernels
    {
      namespace rheologyModels
      {
        double CarreauYasudaRheologyModel::CalculateViscosityForShearRate(const double &iShearRate,
                                                                          const distribn_t &iDensity)
        {
          double eta = ETA_INF + (ETA_ZERO - ETA_INF) * pow( (1.0 + pow(LAMBDA * iShearRate, A)),
                                                             (N - 1.0) / A);

          // TODO Investigate whether we should be using BLOOD_DENSITY_Kg_per_m3*iDensity
          double nu = eta / BLOOD_DENSITY_Kg_per_m3;

          return nu;
        }
      }
    }
  }
}
