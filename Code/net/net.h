// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELB_NET_NET_H
#define HEMELB_NET_NET_H

#include "net/BaseNet.h"
#include "net/mixins/mixins.h"
namespace hemelb
{
  namespace net
  {
    class Net : public SeparatedPointPoint,
                public InterfaceDelegationNet,
                public SeparatedGathers,
                public SeparatedAllToAll
    {
      public:
        Net() :
            BaseNet(), StoringNet()
        {

        }
        Net(topology::Communicator &communicator) :
            BaseNet(communicator), StoringNet()
        {
        }
    };
  }
}
#endif

