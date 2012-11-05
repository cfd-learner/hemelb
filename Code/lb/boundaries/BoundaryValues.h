// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELB_LB_BOUNDARIES_BOUNDARYVALUES_H
#define HEMELB_LB_BOUNDARIES_BOUNDARYVALUES_H

#include "topology/NetworkTopology.h"
#include "net/IteratedAction.h"
#include "lb/boundaries/iolets/InOutLet.h"
#include "geometry/LatticeData.h"

namespace hemelb
{
  namespace lb
  {
    namespace boundaries
    {

      class BoundaryValues : public net::IteratedAction
      {
        public:
          BoundaryValues(geometry::SiteType ioletType,
                         geometry::LatticeData* latticeData,
                         const std::vector<iolets::InOutLet*> &iolets,
                         SimulationState* simulationState,
                         util::UnitConverter* units);
          ~BoundaryValues();

          void RequestComms();
          void EndIteration();
          void Reset();

          void FinishReceive();

          distribn_t GetBoundaryDensity(const int index);

          distribn_t GetDensityMin(int boundaryId);
          distribn_t GetDensityMax(int boundaryId);

          static bool IsCurrentProcTheBCProc();
          static proc_t GetBCProcRank();
          iolets::InOutLet* GetLocalIolet(unsigned int index)
          {
            return iolets[localIoletIDs[index]];
          }
          unsigned int GetLocalIoletCount()
          {
            return localIoletCount;
          }
        private:
          bool IsIOletOnThisProc(geometry::SiteType ioletType, geometry::LatticeData* latticeData, int boundaryId);
          std::vector<int> GatherProcList(bool hasBoundary);
          void HandleComms(iolets::InOutLet* iolet);
          int totalIoletCount;
          // Number of IOlets and vector of their indices for communication purposes
          int localIoletCount;
          std::vector<int> localIoletIDs;
          // Has to be a vector of pointers for InOutLet polymorphism
          std::vector<iolets::InOutLet*> iolets;

          SimulationState* state;
          util::UnitConverter* unitConverter;
      }
      ;
    }
  }
}

#endif /* HEMELB_LB_BOUNDARIES_BOUNDARYVALUES_H */
