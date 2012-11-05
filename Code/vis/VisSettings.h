// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELB_VIS_VISSETTINGS_H
#define HEMELB_VIS_VISSETTINGS_H

#include "lb/LbmParameters.h"

namespace hemelb
{
  namespace vis
  {
    struct VisSettings
    {
        enum Mode
        {
          // 0 - Only display the isosurfaces (wall pressure and stress)
          ISOSURFACES = 0,
          // 1 - Isosurface and glyphs
          ISOSURFACESANDGLYPHS = 1,
          // 2 - Wall pattern streak lines
          WALLANDSTREAKLINES = 2
        };

        // better public member vars than globals!
        Mode mode;

        float ctr_x, ctr_y, ctr_z;
        float streaklines_per_simulation, streakline_length;
        double mouse_pressure, mouse_stress;
        float brightness;
        float glyphLength;

        //Maximum distance - used in the enhanced ray tracer to handle
        //dept cuing
        float maximumDrawDistance;

        lb::StressTypes mStressType;

        int mouse_x, mouse_y;
    };
  }
}

#endif /* HEMELB_VIS_VISSETTINGS_H */
