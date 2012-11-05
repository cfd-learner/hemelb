// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELB_REPORTING_REPORTABLE_H
#define HEMELB_REPORTING_REPORTABLE_H

#include "ctemplate/template.h"

namespace hemelb
{
  namespace reporting
  {
    /**
     * Defines the interface for classes that can have entries in reports.
     */
    class Reportable
    {
      public:
        virtual ~Reportable() {}
        virtual void Report(ctemplate::TemplateDictionary& dictionary) = 0;
    };
  }
}


#endif /* HEMELB_REPORTING_REPORTABLE_H */
