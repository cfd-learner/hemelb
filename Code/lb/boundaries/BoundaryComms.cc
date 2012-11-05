// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#include "lb/boundaries/BoundaryComms.h"
#include "lb/boundaries/BoundaryValues.h"
#include "topology/NetworkTopology.h"
#include "util/utilityFunctions.h"

namespace hemelb
{
  namespace lb
  {
    namespace boundaries
    {

      BoundaryComms::BoundaryComms(SimulationState* iSimState,
                                   std::vector<int> &iProcsList,
                                   bool iHasBoundary) :
        hasBoundary(iHasBoundary), nProcs((int) iProcsList.size()), procsList(iProcsList)
      {
        // Only BC proc sends
        if (BoundaryValues::IsCurrentProcTheBCProc())
        {
          sendRequest = new MPI_Request[nProcs];
          sendStatus = new MPI_Status[nProcs];
        }
        else
        {
          sendRequest = NULL;
          sendStatus = NULL;
        }
      }

      BoundaryComms::~BoundaryComms()
      {

        if (BoundaryValues::IsCurrentProcTheBCProc())
        {
          delete[] sendRequest;
          delete[] sendStatus;
        }
      }

      void BoundaryComms::Wait()
      {
        if (hasBoundary)
        {
          MPI_Wait(&receiveRequest, &receiveStatus);
        }
      }

      void BoundaryComms::WaitAllComms()
      {
        // Now wait for all to complete
        if (BoundaryValues::IsCurrentProcTheBCProc())
        {
          MPI_Waitall(nProcs, sendRequest, sendStatus);

          if (hasBoundary)
            MPI_Wait(&receiveRequest, &receiveStatus);
        }
        else
        {
          MPI_Wait(&receiveRequest, &receiveStatus);
        }

      }

      // It is up to the caller to make sure only BCproc calls send
      void BoundaryComms::Send(distribn_t* density)
      {
        for (int proc = 0; proc < nProcs; proc++)
        {
          MPI_Isend(density,
                    1,
                    hemelb::MpiDataType(*density),
                    procsList[proc],
                    100,
                    MPI_COMM_WORLD,
                    &sendRequest[proc]);
        }
      }

      void BoundaryComms::Receive(distribn_t* density)
      {
        if (hasBoundary)
        {
          MPI_Irecv(density,
                    1,
                    hemelb::MpiDataType(*density),
                    BoundaryValues::GetBCProcRank(),
                    100,
                    MPI_COMM_WORLD,
                    &receiveRequest);
        }
      }

      void BoundaryComms::FinishSend()
      {
        // Don't move on to next step with BC proc until all messages have been sent
        // Precautionary measure to make sure proc doesn't overwrite, before message is sent
        if (BoundaryValues::IsCurrentProcTheBCProc())
        {
          MPI_Waitall(nProcs, sendRequest, sendStatus);
        }
      }

    }
  }
}
