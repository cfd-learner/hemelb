// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#include "lb/kernels/rheologyModels/TruncatedPowerLawRheologyModel.h"
#include "util/utilityFunctions.h"

namespace hemelb
{
  namespace lb
  {
    namespace kernels
    {
      namespace rheologyModels
      {
        double TruncatedPowerLawRheologyModel::CalculateViscosityForShearRate(const double &iShearRate,
                                                                              const distribn_t &iDensity)
        {
          // Don't allow shear rates outside [GAMMA_ZERO, GAMMA_INF]
          double gamma = util::NumericalFunctions::enforceBounds(iShearRate, GAMMA_ZERO, GAMMA_INF);
          double eta = M_CONSTANT * pow(gamma, N_CONSTANT - 1);

          // TODO Investigate whether we should be using BLOOD_DENSITY_Kg_per_m3*iDensity
          double nu = eta / BLOOD_DENSITY_Kg_per_m3;

          return nu;
        }
      }
    }
  }
}

