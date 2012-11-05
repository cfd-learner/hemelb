// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELB_NET_MIXINS_SEPARATEDGATHERS_H
#define HEMELB_NET_MIXINS_SEPARATEDGATHERS_H

#include "net/mixins/StoringNet.h"

namespace hemelb{
  namespace net{

    class SeparatedGathers : public virtual StoringNet
    {
      void ReceiveGathers(){}
      void SendGathers(){}
      void ReceiveGatherVs(){}
      void SendGatherVs(){}
      void WaitGathers();
      void WaitGatherVs();
    };

  }
}
#endif
