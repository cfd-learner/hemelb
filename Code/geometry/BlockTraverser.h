// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELB_GEOMETRY_BLOCKTRAVERSER_H
#define HEMELB_GEOMETRY_BLOCKTRAVERSER_H

#include "lb/lattices/D3Q27.h"
#include "geometry/Block.h"
#include "geometry/VolumeTraverser.h"
#include "geometry/SiteTraverser.h"

namespace hemelb
{
  namespace geometry
  {
    /**
     *BlockTraverser is used to traverse the blocks in a lattice sequentially.
     */
    class BlockTraverser : public VolumeTraverser
    {
      public:
        BlockTraverser(const LatticeData& iLatDat);

        /**
         * @override Of the default destructor in VolumeTraverser.
         */
        ~BlockTraverser();

        site_t CurrentBlockNumber() const;

        util::Vector3D<site_t> GetSiteCoordinatesOfLowestSiteInCurrentBlock();

        const Block& GetCurrentBlockData();

        const Block& GetBlockDataForLocation(const util::Vector3D<site_t>& iLocation);

        site_t GetBlockSize();

        SiteTraverser GetSiteTraverser();

        /**
         * Gets the number of blocks in the x direction.
         * @override of the abstract function in VolumeTraverser.
         * @return
         */
        site_t GetXCount() const;

        /**
         * Gets the number of blocks in the y direction.
         * @override of the abstract function in VolumeTraverser.
         * @return
         */
        site_t GetYCount() const;

        /**
         * Gets the number of blocks in the z direction.
         * @override of the abstract function in VolumeTraverser.
         * @return
         */
        site_t GetZCount() const;

        bool IsValidLocation(util::Vector3D<site_t> block);

      protected:
        bool GoToNextBlock();

        const LatticeData & mLatticeData;
    };
  }
}

#endif // HEMELB_GEOMETRY_BLOCKTRAVERSER_H
