// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#include "topology/NetworkTopology.h"
#include "mpiInclude.h"

namespace hemelb
{
  namespace topology
  {
    NetworkTopology NetworkTopology::instance;
    bool NetworkTopology::initialised = false;

    // Must be specified to prevent the default constructor being public.
    NetworkTopology::NetworkTopology()
    {

    }

    NetworkTopology* NetworkTopology::Instance()
    {
      return &instance;
    }

    void NetworkTopology::Init(int argCount, char ** argList, bool* oSuccess)
    {
      if (!initialised)
      {
        initialised = true;
        MPI_Init(&argCount, &argList);

        comms = Communicator(MPI_COMM_WORLD);

        *oSuccess = InitialiseMachineInfo();
      }
    }

    NetworkTopology::~NetworkTopology()
    {
      if (initialised)
      {
        MPI_Finalize();

        delete[] ProcCountOnEachMachine;
        delete[] MachineIdOfEachProc;
      }
    }

    bool NetworkTopology::IsCurrentProcTheIOProc() const
    {
      return GetLocalRank() == 0;
    }

    proc_t NetworkTopology::GetLocalRank() const
    {
      return comms.GetRank();
    }

    proc_t NetworkTopology::GetProcessorCount() const
    {
      return comms.GetSize();
    }

    int NetworkTopology::GetDepths() const
    {
      return depths;
    }

    unsigned int NetworkTopology::GetMachineCount() const
    {
      return machineCount;
    }

  }
}
