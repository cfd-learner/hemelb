// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELB_UNITTESTS_GEOMETRY_LATTICEDATATESTS_H
#define HEMELB_UNITTESTS_GEOMETRY_LATTICEDATATESTS_H

#include "geometry/LatticeData.h"

namespace hemelb
{
  namespace unittests
  {
    namespace geometry
    {

      using namespace hemelb::geometry;
      class NeighbouringLatticeDataTests : public FourCubeBasedTestFixture
      {
          CPPUNIT_TEST_SUITE (NeighbouringLatticeDataTests);
          CPPUNIT_TEST (TestConstruct);
          CPPUNIT_TEST (TestConvertGlobalId);
          CPPUNIT_TEST (TestGetProcFromGlobalId);

          CPPUNIT_TEST_SUITE_END();

        public:
          NeighbouringLatticeDataTests()
          {
          }

          void setUp()
          {
            FourCubeBasedTestFixture::setUp();

          }

          void tearDown()
          {
            FourCubeBasedTestFixture::tearDown();

          }

          void TestConstruct()
          {
            // PASS -- just verify setUp and tearDown
          }

          void TestConvertGlobalId()
          {
            // not really a very good test to use a one-proc geometry
            // we need to create a sixteen-cube lattice data test fixture to test this kind of thing properly
            // but we can at least smoke test things with four cube.
            util::Vector3D<site_t> exampleCoord(1, 2, 3);
            site_t id = latDat->GetGlobalNoncontiguousSiteIdFromGlobalCoords(exampleCoord);
            CPPUNIT_ASSERT_EQUAL(id, static_cast<site_t>(1 * 16 + 2 * 4 + 3)); //43
            util::Vector3D<site_t> resultCoord;
            latDat->GetGlobalCoordsFromGlobalNoncontiguousSiteId(id, resultCoord);
            CPPUNIT_ASSERT_EQUAL(resultCoord, exampleCoord);
          }

          void TestGetProcFromGlobalId()
          {
            // Again, we need to work up a way to mock a multi-processor situation to test this properly.
            CPPUNIT_ASSERT_EQUAL(latDat->ProcProvidingSiteByGlobalNoncontiguousId(43),0);
          }

        private:
      };
      CPPUNIT_TEST_SUITE_REGISTRATION (NeighbouringLatticeDataTests);
    }
  }
}

#endif
