// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELB_DEBUG_PLATFORM_H
#define HEMELB_DEBUG_PLATFORM_H

/* This file hides the various platform differences.  Need to
 * cross-check definitions of the various macros against the Rules.mk
 * file.
 */

#ifdef HEMELB_DEBUG_LIBRARY_OSX
#include "debug/OSX/OsxDebugger.h"

#elif defined(HEMELB_DEBUG_LIBRARY_LINUX)
#include "debug/linux/LinuxDebugger.h"

#else
#include "debug/none/NullDebugger.h"

#endif

#endif // HEMELB_DEBUG_PLATFORM_H
