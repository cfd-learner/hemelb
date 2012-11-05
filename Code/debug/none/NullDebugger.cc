// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#include <iostream>
#include "debug/none/NullDebugger.h"

namespace hemelb
{
  namespace debug
  {
    // Do nothing!
    void NullDebugger::Attach(void)
    {
    }
    void NullDebugger::BreakHere(void)
    {
    }
    void NullDebugger::Print(const char* iFormat, ...)
    {
    }

    NullDebugger::NullDebugger(const char* const executable) :
      Debugger(executable)
    {
    }

    Debugger* PlatformDebuggerFactory(const char * const executable)
    {
      return new NullDebugger(executable);
    }
  }
}
