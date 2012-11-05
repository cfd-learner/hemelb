// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELB_UTIL_UNITCONVERTER_H
#define HEMELB_UTIL_UNITCONVERTER_H

#include "lb/LbmParameters.h"
#include "lb/SimulationState.h"
#include "constants.h"
#include "util/Matrix3D.h"

namespace hemelb
{
  namespace util
  {

    class UnitConverter
    {
      public:
        UnitConverter(lb::LbmParameters* params, lb::SimulationState* state, double voxelSize);

        LatticePressure ConvertPressureToLatticeUnits(PhysicalPressure pressure) const;
        LatticeVelocity ConvertVelocityToLatticeUnits(PhysicalVelocity velocity) const;
        LatticeStress ConvertStressToLatticeUnits(PhysicalStress stress) const;
        LatticeStress ConvertPressureDifferenceToLatticeUnits(PhysicalStress pressure_grad) const;
        PhysicalPressure ConvertPressureToPhysicalUnits(LatticePressure pressure) const;

        //! @todo: #510 It should be possible to have a single ConvertStressToPhysicalUnits method using template metaprogramming. Implementations are identical.
        PhysicalStress ConvertStressToPhysicalUnits(LatticeStress stress) const;
        //! @todo: #510 template util::Matrix3D so we can enforce PhysicalStress and LatticeStress
        util::Matrix3D ConvertStressToPhysicalUnits(const util::Matrix3D& stress) const;
        util::Vector3D<PhysicalStress> ConvertStressToPhysicalUnits(const util::Vector3D<LatticeStress>& stress) const;

        /**
         * Templated to handle both absolute and directional velocity.
         * @param velocity
         * @return
         */
        template<class InputType>
        InputType ConvertVelocityToPhysicalUnits(InputType velocity) const
        {
          // convert velocity from lattice units to physical units (m/s)
          return velocity * latticeSpeed;
        }
        double ConvertPressureDifferenceToPhysicalUnits(distribn_t pressure_grad) const;

        PhysicalTime ConvertTimeStepToPhysicalUnits(LatticeTime time_step) const
        {
          return static_cast<double>(time_step) * simulationState->GetTimeStepLength();
        }

        /**
         * Converts a shear rate in lattice units into physical units
         * @param shearRate shear rate in lattice units (1/time_step_length)
         * @return shear rate in physical units (1/s)
         */
        PhysicalReciprocalTime ConvertShearRateToPhysicalUnits(LatticeReciprocalTime shearRate) const;

      private:
        lb::LbmParameters* lbmParameters;
        lb::SimulationState* simulationState;
        PhysicalLength voxelSize; //!< Lattice displacement in physical units.
        PhysicalVelocity latticeSpeed; //!< Lattice displacement length divided by time step.
    };

  }
}

#endif /* HEMELB_UTIL_UNITCONVERTER_H */
