// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#include "geometry/LatticeData.h"
#include "geometry/SiteTraverser.h"

namespace hemelb
{
  namespace geometry
  {
    SiteTraverser::SiteTraverser(const geometry::LatticeData& iLatticeData) :
      mLatticeData(iLatticeData)

    {
    }

    SiteTraverser::~SiteTraverser()
    {
    }

    site_t SiteTraverser::GetXCount() const
    {
      return GetBlockSize();
    }

    site_t SiteTraverser::GetYCount() const
    {
      return GetBlockSize();
    }

    site_t SiteTraverser::GetZCount() const
    {
      return GetBlockSize();
    }

    site_t SiteTraverser::GetBlockSize() const
    {
      return mLatticeData.GetBlockSize();
    }
  }
}
