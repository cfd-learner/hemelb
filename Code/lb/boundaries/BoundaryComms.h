// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELB_LB_BOUNDARIES_BOUNDARYCOMMS_H
#define HEMELB_LB_BOUNDARIES_BOUNDARYCOMMS_H

#include "geometry/LatticeData.h"
#include "lb/SimulationState.h"
#include "util/UnitConverter.h"

namespace hemelb
{
  namespace lb
  {
    namespace boundaries
    {

      class BoundaryComms
      {
        public:
          BoundaryComms(SimulationState* iSimState,
                        std::vector<int> &iProcsList,
                        bool iHasBoundary);
          ~BoundaryComms();

          void Wait();

          // It is up to the caller to make sure only BCproc calls send
          void Send(distribn_t* density);
          void Receive(distribn_t* density);
          void WaitAllComms();
          void FinishSend();

        private:
          // This is necessary to support BC proc having fluid sites
          bool hasBoundary;

          // These are only assigned on the BC proc as it is the only one that needs to know
          // which proc has which IOlet
          int nProcs;
          std::vector<int> procsList;

          MPI_Request *sendRequest;
          MPI_Status *sendStatus;

          MPI_Request receiveRequest;
          MPI_Status receiveStatus;

          SimulationState* mState;
      };

    }
  }
}

#endif /* HEMELB_LB_BOUNDARIES_BOUNDARYCOMMS_H */
