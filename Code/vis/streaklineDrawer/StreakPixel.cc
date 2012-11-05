// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#include "vis/streaklineDrawer/StreakPixel.h"

namespace hemelb
{
  template<>
  MPI_Datatype MpiDataTypeTraits<hemelb::vis::streaklinedrawer::StreakPixel>::RegisterMpiDataType()
  {
    MPI_Datatype ret = vis::streaklinedrawer::StreakPixel::GetMPIType();
    MPI_Type_commit(&ret);
    return ret;
  }
}
