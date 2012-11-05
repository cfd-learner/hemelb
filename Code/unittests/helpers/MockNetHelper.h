// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELB_UNITTESTS_HELPERS_MOCKNETHELPER_H
#define HEMELB_UNITTESTS_HELPERS_MOCKNETHELPER_H

#include "unittests/net/NetMock.h"
namespace hemelb
{
  namespace unittests
  {
    namespace helpers
    {
      class MockNetHelper
      {
        protected:
          MockNetHelper():communicatorMock(NULL),netMock(NULL){}
          void setUp(const proc_t core_count, const proc_t current_core)
          {
            communicatorMock = new topology::Communicator(current_core, core_count);
            netMock = new net::NetMock(*communicatorMock);
          }
          void tearDown(){
            delete communicatorMock;
            delete netMock;
          }

          topology::Communicator *communicatorMock;
          net::NetMock *netMock;
      };

    }
  }
}

#endif // HEMELB_UNITTESTS_HELPERS_RANDOMSOURCE_H
