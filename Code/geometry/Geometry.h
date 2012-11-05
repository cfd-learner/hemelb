// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELB_GEOMETRY_GEOMETRY_H
#define HEMELB_GEOMETRY_GEOMETRY_H

#include <vector>
#include "units.h"
#include "constants.h"
#include "geometry/GeometryBlock.h"
#include "util/utilityFunctions.h"
#include "util/Vector3D.h"

namespace hemelb
{
  namespace geometry
  {
    /***
     * Model of the information in a geometry file
     */
    class Geometry
    {
      public:
        /**
         * Default constructor initialises internal variables
         */
        Geometry(const util::Vector3D<site_t>& dimensionsInBlocks,
                 site_t blockSize,
                 PhysicalLength voxelSize,
                 const util::Vector3D<PhysicalLength>& origin) :
            dimensionsInBlocks(dimensionsInBlocks), blockSize(blockSize), voxelSize(voxelSize), origin(origin), blockCount(dimensionsInBlocks.x
                * dimensionsInBlocks.y * dimensionsInBlocks.z), sitesPerBlock(util::NumericalFunctions::IntegerPower(blockSize,
                                                                                                                     3)), Blocks(blockCount)
        {

        }

        /***
         * Returns the total count of blocks in the bounding box of the geometry.
         * @return count of blocks in the geometry.
         */
        site_t GetBlockCount() const
        {
          return blockCount;
        }

        /**
         * Returns the number of sites in each cubic block.
         * @return Number of sites in each block of the geometry.
         */
        site_t GetSitesPerBlock() const
        {
          return sitesPerBlock;
        }

        /***
         * Get the i.d. of a block, i.e. the one-d coordinate, from the three-d coordinate.
         * @todo Use this to replace LatticeData::GetBlockIdFromBlockCoords
         */
        site_t GetBlockIdFromBlockCoordinates(site_t blockI, site_t blockJ, site_t blockK) const
        {
          return (blockI * dimensionsInBlocks.y + blockJ) * dimensionsInBlocks.z + blockK;
        }

        /***
         * Get the coordinates of a block from a block id.
         */
        util::Vector3D<site_t> GetBlockCoordinatesFromBlockId(site_t blockId) const
        {
          site_t blockZ = blockId % dimensionsInBlocks.z;
          site_t remainder = blockId / dimensionsInBlocks.z;
          site_t blockY = remainder % dimensionsInBlocks.y;
          site_t blockX = remainder / dimensionsInBlocks.y;
          return util::Vector3D<site_t>(blockX, blockY, blockZ);
        }

        /***
         * Get the i.d. of a site, i.e. the one-d coordinate, from the three-d coordinate.
         */
        site_t GetSiteIdFromSiteCoordinates(site_t siteI, site_t siteJ, site_t siteK) const
        {
          return (siteI * blockSize + siteJ) * blockSize + siteK;
        }

        /**
         * True if the given block coordinates are within the geometry bounding-box.
         */
        bool AreBlockCoordinatesValid(const util::Vector3D<site_t>& blockCoords) const
        {
          return blockCoords.x >= 0 && blockCoords.y >= 0 && blockCoords.z >= 0 && blockCoords.x < dimensionsInBlocks.x
              && blockCoords.y < dimensionsInBlocks.y && blockCoords.z < dimensionsInBlocks.z;
        }

        /**
         * Get the dimensions of the bounding box in terms of blocks.
         * @return Dimensions of the bounding box in blocks.
         */
        const util::Vector3D<site_t>& GetBlockDimensions() const
        {
          return dimensionsInBlocks;
        }

        /**
         * Get the number of sites along one edge of a block.
         * @return Number of sites that make up one block-length.
         */
        site_t GetBlockSize() const
        {
          return blockSize;
        }

        /**
         * Get voxel size (real-life length of one site length)
         * @return Voxel size.
         */
        PhysicalLength GetVoxelSize() const
        {
          return voxelSize;
        }

        /**
         * Get the origin of the geometry in real-world coordinates.
         * @return Origin of the geometry.
         */
        const util::Vector3D<PhysicalLength>& GetOrigin() const
        {
          return origin;
        }

      private:
        const util::Vector3D<site_t> dimensionsInBlocks; //! The count of blocks in each direction
        const site_t blockSize; //! Size of a block, in sites.
        const PhysicalLength voxelSize; //! Size of a block, in real-world units.
        const util::Vector3D<PhysicalLength> origin;

        const site_t blockCount;
        const site_t sitesPerBlock;

      public:
        std::vector<BlockReadResult> Blocks; //! Array of Block models

    };

  }
}
#endif // HEMELB_GEOMETRY_GEOMETRYREADRESULT_H
