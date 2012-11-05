// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELB_UTIL_REFRESHABLECACHE_HPP
#define HEMELB_UTIL_REFRESHABLECACHE_HPP

#include "util/RefreshableCache.h"
#include "util/CheckingCache.hpp"

namespace hemelb
{
  namespace util
  {
    /**
     * NOTE: We initialise the checking cache to size 0, then expand it if needed.
     * @param simulationState
     * @param size
     */
    template<typename CacheType>
    RefreshableCache<CacheType>::RefreshableCache(const lb::SimulationState& simulationState, unsigned long size) :
        CheckingCache<CacheType>(simulationState, 0), requiresRefreshing(false), cacheSize(size)
    {

    }

    template<typename CacheType>
    void RefreshableCache<CacheType>::SetRefreshFlag()
    {
      CheckingCache<CacheType>::Reserve(cacheSize);
      requiresRefreshing = true;
    }

    template<typename CacheType>
    void RefreshableCache<CacheType>::UnsetRefreshFlag()
    {
      requiresRefreshing = false;
    }

    template<typename CacheType>
    bool RefreshableCache<CacheType>::RequiresRefresh() const
    {
      return requiresRefreshing;
    }
  }
}

#endif /* HEMELB_UTIL_REFRESHABLECACHE_HPP */
