// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELB_UNITTESTS_NET_NETMOCK_H
#define HEMELB_UNITTESTS_NET_NETMOCK_H
#include <vector>
#include <map>
#include <cstdlib>
#include <iostream>

#include "constants.h"
#include "mpiInclude.h"
#include "net/net.h"
#include "unittests/net/RecordingNet.h"

namespace hemelb
{
  namespace unittests
  {
    namespace net
    {
      using namespace hemelb::net;

      class NetMock : public InterfaceDelegationNet,public RecordingNet,
                      public GathersViaPointPoint, public AllToAllViaPointPoint
      {
        public:
          NetMock(topology::Communicator & communicator) :
              BaseNet(communicator), RecordingNet()
          {
          }

      };
    }
  }
}
#endif // ONCE
