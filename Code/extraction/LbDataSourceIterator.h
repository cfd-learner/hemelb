// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELB_EXTRACTION_LBDATASOURCEITERATOR_H
#define HEMELB_EXTRACTION_LBDATASOURCEITERATOR_H

#include "extraction/IterableDataSource.h"
#include "geometry/LatticeData.h"
#include "lb/MacroscopicPropertyCache.h"
#include "util/UnitConverter.h"

namespace hemelb
{
  namespace extraction
  {
    class LbDataSourceIterator : public IterableDataSource
    {
      public:
        /**
         * Constructs an iterator using the LBM as a source.
         * @param propertyCache
         * @param data
         * @return
         */
        LbDataSourceIterator(const lb::MacroscopicPropertyCache& propertyCache,
                             const geometry::LatticeData& data,
                             const util::UnitConverter& converter);

        /**
         * Reads the next fluid site from the data source. Returns true if values could
         * be obtained.
         *
         * @return
         */
        bool ReadNext();

        /**
         * Returns the coordinates of the site.
         * @return
         */
        util::Vector3D<site_t> GetPosition() const;

        /**
         * Returns the pressure at the site.
         * @return
         */
        FloatingType GetPressure() const;

        /**
         * Returns the velocity at the site.
         * @return
         */
        util::Vector3D<FloatingType> GetVelocity() const;

        /**
         * Returns the shear stress at the site.
         * @return
         */
        FloatingType GetShearStress() const;

        /**
         * Returns the Von Mises stress at the site.
         * @return
         */
        FloatingType GetVonMisesStress() const;

        /**
         * Returns the shear rate at the site.
         * @return shear rate
         */
        FloatingType GetShearRate() const;

        /**
         * Returns the full stress tensor at the site.
         * @return stress tensor
         */
        util::Matrix3D GetStressTensor() const;

        /**
         * Returns the traction vector at an edge site (i.e. stress tensor times surface normal).
         * @return traction vector
         */
        util::Vector3D<PhysicalStress> GetTractionVector() const;

        /**
         * Returns the projection of the traction vector on the tangential plane of an edge site.
         * @return projected traction vector
         */
        util::Vector3D<PhysicalStress> GetTangentialProjectionTractionVector() const;

        /**
         * Resets the iterator to the beginning again.
         */
        void Reset();

        /**
         * Returns true iff the passed location is within the lattice.
         *
         * @param
         * @return
         */
        bool IsValidLatticeSite(const util::Vector3D<site_t>& location) const;

        /**
         * Returns true iff the given location is available on this core (i.e. if the data
         * lives on this core).
         * @return
         */
        bool IsAvailable(const util::Vector3D<site_t>& location) const;

        /**
         * Returns the real-world size of a single lattice unit.
         * @return
         */
        distribn_t GetVoxelSize() const;

        /**
         * Returns the origin of the geometry in real, spatial units.
         *
         * @return
         */
        const util::Vector3D<distribn_t>& GetOrigin() const;

        /**
         * Returns true if the site at the given location is marked as an edge site
         * (i.e. one of its links intersects a wall)
         *
         * @param location coordinates of interest
         * @return whether there is a boundary site at location
         */
        bool IsEdgeSite(const util::Vector3D<site_t>& location) const;


      private:
        /**
         * The cache of properties for each site, which we iterate through.
         */
        const lb::MacroscopicPropertyCache& propertyCache;
        /**
         * The object containing information about the lattice.
         */
        const geometry::LatticeData& data;
        /**
         * Object capable of converting from physical to lattice units and vice versa.
         */
        const util::UnitConverter& converter;
        /**
         * Iteration variable for tracking progress through all the local fluid sites.
         */
        site_t position;
        /**
         * The origin of the geometry.
         */
        const util::Vector3D<distribn_t> origin;
    };
  }
}

#endif /* HEMELB_EXTRACTION_LBDATASOURCEITERATOR_H */
