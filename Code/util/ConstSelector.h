// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELB_UTIL_CONSTSELECTOR_H
#define HEMELB_UTIL_CONSTSELECTOR_H

namespace hemelb
{
  namespace util
  {
    template<bool IsConst, class NonConst, class Const>
    struct constSelector
    {
    };

    template<class NonConst, class Const>
    struct constSelector<true, NonConst, Const>
    {
        typedef Const type;
    };

    template<class NonConst, class Const>
    struct constSelector<false, NonConst, Const>
    {
        typedef NonConst type;
    };
  }
}

#endif /* CONSTSELECTOR_H_ */
