// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELB_DEBUG_NONE_NULLDEBUGGER_H
#define HEMELB_DEBUG_NONE_NULLDEBUGGER_H

#include "debug/Debugger.h"

namespace hemelb
{
  namespace debug
  {
    class NullDebugger : public Debugger
    {
      public:
        void BreakHere(void);
        void Print(const char* iFormat, ...);

      protected:
        void Attach(void);
        NullDebugger(const char* const executable);
        friend Debugger* PlatformDebuggerFactory(const char* const executable);
    };

    Debugger* PlatformDebuggerFactory(const char* const executable);
  }
}

#endif // HEMELB_DEBUG_NONE_DEBUGGER_H
