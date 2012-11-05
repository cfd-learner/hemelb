// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELB_LB_BOUNDARIES_IOLETS_INOUTLETFILE_H
#define HEMELB_LB_BOUNDARIES_IOLETS_INOUTLETFILE_H

#include "lb/boundaries/iolets/InOutLet.h"

namespace hemelb
{
  namespace lb
  {
    namespace boundaries
    {
      namespace iolets
      {

        /*
         * Template values are chosen to be tUpdatePeriod = 0 and tComms = false
         * If a trace is read from a file it should be done once and then stored
         * on each relevant proc. If memory is a concern tComms can be set to true
         * and then only the BCproc will keep the entire trace in memory
         * WARNING: - be cautious of setting tUpdatePeriod to something else other than
         * zero, because it may not be what you expect - see comments on CalculateCycle in
         * cc file.
         */
        class InOutLetFile : public InOutLet
        {
          public:
            InOutLetFile();
            virtual ~InOutLetFile();
            virtual void DoIO(TiXmlElement *parent, bool isLoading, configuration::SimConfig* simConfig);
            virtual InOutLet* Clone() const;
            virtual void Reset(SimulationState &state)
            {
              CalculateTable(state.GetTotalTimeSteps());
            }
            std::string & GetFilePath()
            {
              return pressureFilePath;
            }
            PhysicalPressure GetPressureMin() const
            {
              return pressureMinPhysical;
            }
            PhysicalPressure GetPressureMax() const
            {
              return pressureMaxPhysical;
            }
            LatticeDensity GetDensity(LatticeTime timeStep) const
            {
              return densityTable[timeStep];
            }
          private:
            void CalculateTable(LatticeTime totalTimeSteps);
            std::vector<LatticeDensity> densityTable;
            PhysicalPressure pressureMinPhysical;
            PhysicalPressure pressureMaxPhysical;
            std::string pressureFilePath;
        };

      }
    }
  }
}

#endif /* HEMELB_LB_BOUNDARIES_IOLETS_INOUTLETFILE_H */
