// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELB_NET_MIXINS_POINTPOINT_SEPARATEDPOINTPOINT_H
#define HEMELB_NET_MIXINS_POINTPOINT_SEPARATEDPOINTPOINT_H
#include "net/BaseNet.h"
#include "net/mixins/StoringNet.h"
namespace hemelb
{
  namespace net
  {
    class SeparatedPointPoint : public virtual StoringNet
    {

      public:
      SeparatedPointPoint() :
            sendReceivePrepped(false),count_sends(0),count_receives(0)
        {
        }
        ~SeparatedPointPoint();

        void WaitPointToPoint();

      protected:
        void ReceivePointToPoint();
        void SendPointToPoint();

      private:
        void EnsureEnoughRequests(size_t count);
        void EnsurePreparedToSendReceive();
        bool sendReceivePrepped;

        // Requests and statuses available for general communication within the Net object (both
        // initialisation and during each iteration). Code using these must make sure
        // there are enough available. We do this in a way to minimise the number created
        // on each core, but also to minimise creation / deletion overheads.
        std::vector<MPI_Request> requests;
        std::vector<MPI_Status> statuses;
        unsigned int count_sends;
        unsigned int count_receives;
    };
  }
}

#endif
