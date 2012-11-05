// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELB_VIS_RAYTRACER_SITEDATA_H
#define HEMELB_VIS_RAYTRACER_SITEDATA_H

namespace hemelb
{
  namespace vis
  {
    namespace raytracer
    {
      //Stores the data about an individual voxel 
      struct SiteData_t
      {
        public:
          float density;
          float velocity;
          float stress;
      };
    }
  }
}

#endif // HEMELB_VIS_RAYTRACER_SITEDATA_H
