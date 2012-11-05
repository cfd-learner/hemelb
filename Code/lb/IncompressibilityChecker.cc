// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#include "lb/lattices/D3Q15.h"
#include "lb/IncompressibilityChecker.hpp"

namespace hemelb
{
  namespace lb
  {
    // Explicit instantiation
    template class IncompressibilityChecker<net::PhasedBroadcastRegular<> > ;
  }
}
