// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELB_LB_LBMPARAMETERS_H
#define HEMELB_LB_LBMPARAMETERS_H

#include <cmath>
#include "constants.h"
#include <vector>
#include <cassert>

namespace hemelb
{
  namespace lb
  {
    enum StressTypes
    {
      VonMises = 0,
      ShearStress = 1,
      IgnoreStress = 2
    };

    struct LbmParameters
    {
      public:
        LbmParameters(distribn_t timeStepLength, distribn_t voxelSize)
        {
          Update(timeStepLength, voxelSize);
        }

        void Update(distribn_t timeStepLength, distribn_t voxelSize)
        {
          timestep = timeStepLength;
          tau = 0.5
              + (timeStepLength * BLOOD_VISCOSITY_Pa_s / BLOOD_DENSITY_Kg_per_m3)
                  / (Cs2 * voxelSize * voxelSize);

          omega = -1.0 / tau;
          stressParameter = (1.0 - 1.0 / (2.0 * tau)) / sqrt(2.0);
          beta = -1.0 / (2.0 * tau);
        }

        distribn_t GetTimeStep() const
        {
          return timestep;
        }

        distribn_t GetOmega() const
        {
          return omega;
        }

        distribn_t GetTau() const
        {
          return tau;
        }

        distribn_t GetStressParameter() const
        {
          return stressParameter;
        }

        distribn_t GetBeta() const
        {
          return beta;
        }

        StressTypes StressType;

      private:
        distribn_t timestep;
        distribn_t omega;
        distribn_t tau;
        distribn_t stressParameter;
        distribn_t beta; ///< Viscous dissipation in ELBM
    };
  }
}

#endif //HEMELB_LB_LBMPARAMETERS_H
