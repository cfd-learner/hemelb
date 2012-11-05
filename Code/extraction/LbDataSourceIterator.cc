// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#include "extraction/LbDataSourceIterator.h"

namespace hemelb
{
  namespace extraction
  {
    LbDataSourceIterator::LbDataSourceIterator(const lb::MacroscopicPropertyCache& propertyCache,
                                               const geometry::LatticeData& data,
                                               const util::UnitConverter& converter) :
        propertyCache(propertyCache), data(data), converter(converter), position(-1), origin(data.GetOrigin())
    {

    }

    bool LbDataSourceIterator::ReadNext()
    {
      ++position;

      if (position >= data.GetLocalFluidSiteCount())
      {
        return false;
      }

      return true;
    }

    util::Vector3D<site_t> LbDataSourceIterator::GetPosition() const
    {
      return data.GetSite(position).GetGlobalSiteCoords();
    }

    FloatingType LbDataSourceIterator::GetPressure() const
    {
      return converter.ConvertPressureToPhysicalUnits(propertyCache.densityCache.Get(position) * Cs2);
    }

    util::Vector3D<FloatingType> LbDataSourceIterator::GetVelocity() const
    {
      return converter.ConvertVelocityToPhysicalUnits(propertyCache.velocityCache.Get(position));
    }

    FloatingType LbDataSourceIterator::GetShearStress() const
    {
      return converter.ConvertStressToPhysicalUnits(propertyCache.wallShearStressMagnitudeCache.Get(position));
    }

    FloatingType LbDataSourceIterator::GetVonMisesStress() const
    {
      return converter.ConvertStressToPhysicalUnits(propertyCache.vonMisesStressCache.Get(position));
    }

    FloatingType LbDataSourceIterator::GetShearRate() const
    {
      return converter.ConvertShearRateToPhysicalUnits(propertyCache.shearRateCache.Get(position));
    }

    util::Matrix3D LbDataSourceIterator::GetStressTensor() const
    {
      return converter.ConvertStressToPhysicalUnits(propertyCache.stressTensorCache.Get(position));
    }

    util::Vector3D<PhysicalStress> LbDataSourceIterator::GetTractionVector() const
    {
      return converter.ConvertStressToPhysicalUnits(propertyCache.tractionVectorCache.Get(position));
    }

    util::Vector3D<PhysicalStress> LbDataSourceIterator::GetTangentialProjectionTractionVector() const
    {
      return converter.ConvertStressToPhysicalUnits(propertyCache.tangentialProjectionTractionVectorCache.Get(position));
    }

    void LbDataSourceIterator::Reset()
    {
      position = -1;
    }

    bool LbDataSourceIterator::IsValidLatticeSite(const util::Vector3D<site_t>& location) const
    {
      return data.IsValidLatticeSite(location);
    }

    bool LbDataSourceIterator::IsAvailable(const util::Vector3D<site_t>& location) const
    {
      return data.GetProcIdFromGlobalCoords(location) == topology::NetworkTopology::Instance()->GetLocalRank();
    }

    distribn_t LbDataSourceIterator::GetVoxelSize() const
    {
      return data.GetVoxelSize();
    }

    const util::Vector3D<distribn_t>& LbDataSourceIterator::GetOrigin() const
    {
      return origin;
    }

    bool LbDataSourceIterator::IsEdgeSite(const util::Vector3D<site_t>& location) const
    {
      site_t localSiteId = data.GetContiguousSiteId(location);

      return data.GetSite(localSiteId).IsEdge();
    }
  }
}
