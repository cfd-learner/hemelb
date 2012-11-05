// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELB_LB_LATTICES_D3Q15_H
#define HEMELB_LB_LATTICES_D3Q15_H

#include "lb/lattices/Lattice.h"

namespace hemelb
{
  namespace lb
  {
    namespace lattices
    {
      class D3Q15 : public lb::lattices::Lattice<D3Q15>
      {
        public:
          // The number of discrete velocity vectors
          static const Direction NUMVECTORS = 15;

          // The x, y and z components of each of the discrete velocity vectors
          static const int CX[NUMVECTORS];
          static const int CY[NUMVECTORS];
          static const int CZ[NUMVECTORS];
          static const int* discreteVelocityVectors[3];

          static const double EQMWEIGHTS[NUMVECTORS];

          // The index of the inverse direction of each discrete velocity vector
          static const Direction INVERSEDIRECTIONS[NUMVECTORS];
      };
    }
  }
}
#endif /* HEMELB_LB_LATTICES_D3Q15_H */
