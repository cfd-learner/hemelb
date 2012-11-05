// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#include "mpiInclude.h"
namespace hemelb
{
  namespace util
  {
    // Returns the number of seconds to 6dp elapsed since the Epoch
    double myClock()
    {
      return MPI_Wtime();
    }

  }

}
