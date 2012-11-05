// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#include "extraction/PropertyActor.h"

namespace hemelb
{
  namespace extraction
  {
    PropertyActor::PropertyActor(const lb::SimulationState& simulationState,
                                 const std::vector<PropertyOutputFile*>& propertyOutputs,
                                 IterableDataSource& dataSource) :
        simulationState(simulationState)
    {
      propertyWriter = new PropertyWriter(dataSource, propertyOutputs);
    }

    PropertyActor::~PropertyActor()
    {
      delete propertyWriter;
    }

    void PropertyActor::SetRequiredProperties(lb::MacroscopicPropertyCache& propertyCache)
    {
      const std::vector<LocalPropertyOutput*>& propertyOutputs = propertyWriter->GetPropertyOutputs();

      // Iterate over each property output spec.
      for (unsigned output = 0; output < propertyOutputs.size(); ++output)
      {
        const LocalPropertyOutput* propertyOutput = propertyOutputs[output];

        // Only consider the ones that are being written this iteration.
        if (propertyOutput->ShouldWrite(simulationState.GetTimeStep()))
        {
          const PropertyOutputFile* outputFile = propertyOutput->GetOutputSpec();

          // Iterate over each field.
          for (unsigned outputField = 0; outputField < outputFile->fields.size(); ++outputField)
          {
            // Set the cache to calculate each required field.
            switch (outputFile->fields[outputField].type)
            {
              case (OutputField::Pressure):
                propertyCache.densityCache.SetRefreshFlag();
                break;
              case OutputField::Velocity:
                propertyCache.velocityCache.SetRefreshFlag();
                break;
              case OutputField::ShearStress:
                propertyCache.wallShearStressMagnitudeCache.SetRefreshFlag();
                break;
              case OutputField::VonMisesStress:
                propertyCache.vonMisesStressCache.SetRefreshFlag();
                break;
              case OutputField::ShearRate:
                propertyCache.shearRateCache.SetRefreshFlag();
                break;
              case OutputField::StressTensor:
                propertyCache.stressTensorCache.SetRefreshFlag();
                break;
              case OutputField::TractionVector:
                propertyCache.tractionVectorCache.SetRefreshFlag();
                break;
              case OutputField::TangentialProjectionTractionVector:
                propertyCache.tangentialProjectionTractionVectorCache.SetRefreshFlag();
                break;
              default:
                // This assert should never trip. It only occurs when someone adds a new field to OutputField
                // and forgets adding a new case to the switch
                assert(false);
            }
          }
        }
      }
    }

    void PropertyActor::EndIteration()
    {
      propertyWriter->Write(simulationState.GetTimeStep());
    }

  }
}
