// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELB_UNITS_H
#define HEMELB_UNITS_H

#include <stdint.h>

namespace hemelb
{
  // Basic types for use in HemeLB.

  namespace util { template<typename T> class Vector3D; } // forward declaration of Vector3D

  // ------ OLD POLICY:  ---------
  //Any variable which scales as a function of the number of sites
  // can have type site_t, processors proc_t.
  // Any variable whose precision should roughly match that of the lattice sites' velocity
  // distributions can have type distribn_t.
  typedef int64_t site_t;
  typedef int proc_t;
  typedef double distribn_t;
  typedef unsigned Direction;
  typedef uint64_t sitedata_t;

  // ------- NEW POLICY -------------
  // Types should reflect the meaning of a quantity as well as the precision
  // the type name should reflect the dimensionality and the base of the units

  typedef double PhysicalDensity;
  typedef distribn_t LatticeDensity;
  typedef float ScreenDensity;

  typedef double PhysicalPressure;
  typedef distribn_t LatticePressure;

  typedef double PhysicalStress;
  typedef distribn_t LatticeStress;
  typedef float ScreenStress;

  typedef unsigned long LatticeTime; // lattice time steps.
  typedef double PhysicalTime; // seconds

  typedef distribn_t LatticeReciprocalTime; ///< 1/timestep
  typedef double PhysicalReciprocalTime; ///< 1/seconds

  typedef double RadianAngle;

  // TODO: deprecated, use PhysicalDistance instead - should be fixed as part of ticket #437
  typedef double PhysicalLength;

  typedef double PhysicalDistance; // continuous distance in physical units
  typedef double LatticeDistance; // continuous distance in lattice units
  typedef int64_t LatticeCoordinate; // discrete distance in lattice units

  typedef util::Vector3D<LatticeDistance> LatticePosition; // origin of lattice is at {0.0,0.0,0.0}
  typedef util::Vector3D<LatticeCoordinate> LatticeVector; // origin of lattice is at {0,0,0}

  // TODO: xxxVelocity is a Vector3D<xxxSpeed> not a scalar - should be fixed as part of ticket #437
  typedef double PhysicalVelocity;
  typedef distribn_t LatticeVelocity;

  typedef double DimensionlessQuantity;
}
#endif //HEMELB_UNITS_H
