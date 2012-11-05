// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELB_NET_PHASED_STEPS_H
#define HEMELB_NET_PHASED_STEPS_H

namespace hemelb
{
  namespace net
  {
    namespace phased
    {
      namespace steps
      {
        enum Step
        {
          BeginAll = -1, // Called only before first phase
          BeginPhase = 0,
          Receive = 1,
          PreSend = 2,
          Send = 3,
          PreWait = 4,
          Wait = 5,
          EndPhase = 6,
          EndAll = 7, // Called only after final phase
          Reset = 8 // Special step, called if simulation must reinitialise
        };
      }
    }
  }
}
#endif
