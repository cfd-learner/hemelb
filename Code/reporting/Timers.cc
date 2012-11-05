// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#include "reporting/Timers.hpp"
namespace hemelb
{
  namespace reporting
  {
    template class TimersBase<HemeLBClockPolicy, MPICommsPolicy>; // explicit instantiate
  }
}
