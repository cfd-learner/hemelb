// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELB_EXTRACTION_PROPERTYACTOR_H
#define HEMELB_EXTRACTION_PROPERTYACTOR_H

#include "extraction/PropertyWriter.h"
#include "io/PathManager.h"
#include "lb/MacroscopicPropertyCache.h"
#include "lb/SimulationState.h"
#include "net/IteratedAction.h"

namespace hemelb
{
  namespace extraction
  {
    class PropertyActor : public net::IteratedAction
    {
      public:
        /**
         * Constructor, gets the class ready for reading.
         * @param simulationState
         * @param propertyOutputs
         * @param dataSource
         * @return
         */
        PropertyActor(const lb::SimulationState& simulationState,
                      const std::vector<PropertyOutputFile*>& propertyOutputs,
                      IterableDataSource& dataSource);

        ~PropertyActor();

        /**
         * Set which properties will be required this iteration.
         * @param propertyCache
         */
        void SetRequiredProperties(lb::MacroscopicPropertyCache& propertyCache);

        /**
         * Override the iterated actor end of iteration method to perform writing.
         */
        void EndIteration();

      private:
        const lb::SimulationState& simulationState;
        PropertyWriter* propertyWriter;
    };
  }
}

#endif /* HEMELB_EXTRACTION_PROPERTYACTOR_H */
