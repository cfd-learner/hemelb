// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELB_UNITTESTS_NET_PHASED_MOCKCONCERN_H
#define HEMELB_UNITTESTS_NET_PHASED_MOCKCONCERN_H
#include "net/phased/Concern.h"
namespace hemelb
{
  namespace unittests
  {
    namespace net
    {
      namespace phased
      {
        using namespace hemelb::net::phased;
        class MockConcern : public Concern
        {
          public:
            MockConcern(const std::string &name) :
                calls(), name(name)
            {
            }

            bool CallAction(int action)
            {
              // this is where a real concern would switch on the action, and call the appropriate method
              calls.push_back(action);
              return true;
            }

            std::vector<int> const & ActionsCalled() const
            {
              return calls;
            }

          private:
            std::vector<int> calls;
            std::string name;
        };
      }
    }
  }
}
#endif
