// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELB_NET_MIXINS_SEPARATEDALLTOALL_H
#define HEMELB_NET_MIXINS_SEPARATEDALLTOALL_H

#include "net/mixins/StoringNet.h"

namespace hemelb{
  namespace net{

    class SeparatedAllToAll : public virtual StoringNet
    {
      void ReceiveAllToAll(){}
      void SendAllToAll(){}
      void WaitAllToAll();
    };
  }
}
#endif
