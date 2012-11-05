// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELB_NET_PHASED_CONCERN_H
#define HEMELB_NET_PHASED_CONCERN_H
namespace hemelb{
  namespace net{
    namespace phased{
      class Concern{
        public:
          Concern(){}
          virtual ~Concern(){}
          virtual bool CallAction(int action)=0;
      };
    }
  }
}
#endif //ONCE
