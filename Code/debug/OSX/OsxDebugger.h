// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELB_DEBUG_OSX_OSXDEBUGGER_H
#define HEMELB_DEBUG_OSX_OSXDEBUGGER_H

#include <debug/common/ActiveDebugger.h>

namespace hemelb
{
  namespace debug
  {
    
    class OsxDebugger : public ActiveDebugger {
    protected:
      // Platform specific getters
      const std::string GetPlatformInterpreter(void) const;
      const std::string GetPlatformScript(void) const;
      const std::string GetPlatformGdbScript(void) const;
      
      // C'tor...
      OsxDebugger(const char* const executable);
      // ... which the factory function needs to be able to get at.
      friend Debugger* PlatformDebuggerFactory(const char* const executable);
      
    };
    
    // Factory. Don't be calling this.
    Debugger* PlatformDebuggerFactory(const char* const executable);
  }
}

#endif // HEMELB_DEBUG_OSX_OSXDEBUGGER_H
