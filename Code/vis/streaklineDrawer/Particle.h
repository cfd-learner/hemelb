// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELB_VIS_STREAKLINEDRAWER_PARTICLE_H
#define HEMELB_VIS_STREAKLINEDRAWER_PARTICLE_H

#include "util/Vector3D.h"

namespace hemelb
{
  namespace vis
  {
    namespace streaklinedrawer
    {
      struct Particle
      {
        public:
          Particle();

          Particle(float iX, float iY, float iZ, unsigned int iInletId);

          util::Vector3D<float> position;
          util::Vector3D<float> velocity;
          float vel;
          unsigned int inletID;
      };

    }
  }
}

#endif // HEMELB_VIS_STREAKLINEDRAWER_PARTICLE_H
