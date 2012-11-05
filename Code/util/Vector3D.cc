// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#include <cstdlib>
#include <iostream>
#include "util/Vector3D.h"

namespace hemelb
{
  namespace util
  {

    void Vector3DBase::SetIndexErrorHandler(Vector3DBase::HandlerFunction* func)
    {
      Vector3DBase::handler = func;
    }

    void Vector3DBase::HandleIndexError(int direction)
    {
      if (Vector3DBase::handler == NULL)
      {
        std::cout << "Vector3D index error handler not set when index error "
          "occurred" << std::endl;
        std::exit(1);
      }
      else
      {
        Vector3DBase::handler(direction);
      }
    }

  }
}
