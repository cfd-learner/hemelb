// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#include "constants.h"
#include "geometry/Block.h"

namespace hemelb
{
  namespace geometry
  {
    Block::Block()
    {
    }

    Block::Block(site_t sitesPerBlock) :
        processorRankForEachBlockSite(sitesPerBlock, BIG_NUMBER2), localContiguousIndex(sitesPerBlock, SOLID_SITE_ID)
    {
    }

    Block::~Block()
    {
    }

    bool Block::IsEmpty() const
    {
      return localContiguousIndex.empty();
    }

    proc_t Block::GetProcessorRankForSite(site_t localSiteIndex) const
    {
      return processorRankForEachBlockSite[localSiteIndex];
    }

    site_t Block::GetLocalContiguousIndexForSite(site_t localSiteIndex) const
    {
      return localContiguousIndex[localSiteIndex];
    }

    bool Block::SiteIsSolid(site_t localSiteIndex) const
    {
      return localContiguousIndex[localSiteIndex] == SOLID_SITE_ID;
    }

    void Block::SetProcessorRankForSite(site_t localSiteIndex, proc_t rank)
    {
      processorRankForEachBlockSite[localSiteIndex] = rank;
    }

    void Block::SetLocalContiguousIndexForSite(site_t localSiteIndex, site_t contiguousIndex)
    {
      localContiguousIndex[localSiteIndex] = contiguousIndex;
    }

  }
}
