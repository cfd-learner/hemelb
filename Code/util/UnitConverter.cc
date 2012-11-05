// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#include "util/UnitConverter.h"
#include "constants.h"

namespace hemelb
{
  namespace util
  {

    UnitConverter::UnitConverter(lb::LbmParameters* params, lb::SimulationState* state, double voxelSize) :
        lbmParameters(params), simulationState(state), voxelSize(voxelSize), latticeSpeed(voxelSize
            / simulationState->GetTimeStepLength())
    {

    }

    LatticeDensity UnitConverter::ConvertPressureToLatticeUnits(PhysicalPressure pressure) const
    {
      return Cs2 + ConvertPressureDifferenceToLatticeUnits(pressure - REFERENCE_PRESSURE_mmHg);
    }

    PhysicalPressure UnitConverter::ConvertPressureToPhysicalUnits(LatticePressure pressure) const
    {
      return REFERENCE_PRESSURE_mmHg + ConvertPressureDifferenceToPhysicalUnits(pressure - Cs2);
    }

    LatticeDensity UnitConverter::ConvertPressureDifferenceToLatticeUnits(double pressure_grad) const
    {
      return pressure_grad * mmHg_TO_PASCAL / (latticeSpeed * latticeSpeed * BLOOD_DENSITY_Kg_per_m3);
    }

    double UnitConverter::ConvertPressureDifferenceToPhysicalUnits(LatticePressure pressure_grad) const
    {
      return pressure_grad * BLOOD_DENSITY_Kg_per_m3 * latticeSpeed * latticeSpeed / mmHg_TO_PASCAL;
    }

    LatticeVelocity UnitConverter::ConvertVelocityToLatticeUnits(PhysicalVelocity velocity) const
    {
      return velocity / latticeSpeed;
    }

    LatticeStress UnitConverter::ConvertStressToLatticeUnits(PhysicalStress stress) const
    {
      return stress / (latticeSpeed * latticeSpeed * BLOOD_DENSITY_Kg_per_m3);
    }

    PhysicalStress UnitConverter::ConvertStressToPhysicalUnits(PhysicalStress stress) const
    {
      // convert stress from lattice units to physical units (Pa)
      return stress * (latticeSpeed * latticeSpeed * BLOOD_DENSITY_Kg_per_m3);
      // stress=Force per unit area=mass * length / time^2 / length^2=mass / length * time^2
      // = mass * (length/time)^2 / length^3
    }

    util::Matrix3D UnitConverter::ConvertStressToPhysicalUnits(const util::Matrix3D& stress) const
    {
      return stress * (latticeSpeed * latticeSpeed * BLOOD_DENSITY_Kg_per_m3);
    }

    util::Vector3D<PhysicalStress> UnitConverter::ConvertStressToPhysicalUnits(const util::Vector3D<LatticeStress>& stress) const
    {
      return stress * (latticeSpeed * latticeSpeed * BLOOD_DENSITY_Kg_per_m3);
    }

    PhysicalReciprocalTime UnitConverter::ConvertShearRateToPhysicalUnits(LatticeReciprocalTime shearRate) const
    {
      return shearRate / simulationState->GetTimeStepLength();
    }
  }
}
