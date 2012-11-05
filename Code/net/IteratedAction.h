// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELB_NET_ITERATEDACTION_H
#define HEMELB_NET_ITERATEDACTION_H
#include "net/phased/Concern.h"
namespace hemelb
{
  namespace net
  {
    class IteratedAction : public phased::Concern
    {
      public:
        bool CallAction(int action);
        virtual ~IteratedAction();
        virtual void RequestComms();
        virtual void PreSend();
        virtual void PreReceive();
        virtual void PostReceive();
        virtual void EndIteration();
        virtual void Reset();
    };
  }
}

#endif /* HEMELB_NET_ITERATEDACTION_H */
