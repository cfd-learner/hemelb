// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELB_UNITTESTS_LBTESTS_BOUNDARIES_BOUNDARYTESTS_H
#define HEMELB_UNITTESTS_LBTESTS_BOUNDARIES_BOUNDARYTESTS_H
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "unittests/helpers/FourCubeBasedTestFixture.h"
#include "resources/Resource.h"
#include "lb/boundaries/BoundaryValues.h"

namespace hemelb
{
  namespace unittests
  {
    namespace lbtests
    {
      namespace boundaries
      {
        using namespace hemelb::lb::boundaries;
        using namespace resources;
        /***
         * Class asserting behaviour of boundary-collection objects and the boundaries (in- and out- lets) within them.
         */
        class BoundaryTests : public helpers::FourCubeBasedTestFixture
        {
          CPPUNIT_TEST_SUITE(BoundaryTests);
              CPPUNIT_TEST(TestConstruct);
              CPPUNIT_TEST(TestUpdate);
              CPPUNIT_TEST(TestUpdateFile);
            CPPUNIT_TEST_SUITE_END();
          public:
            void setUp()
            {
              FourCubeBasedTestFixture::setUp();

            }
            void tearDown()
            {

              FourCubeBasedTestFixture::tearDown();
            }
          private:
            void TestConstruct()
            {
              double targetStartDensity = pressureToDensity(80.0 - 1.0);
              inlets = new BoundaryValues(hemelb::geometry::INLET_TYPE,
                                          latDat,
                                          simConfig->GetInlets(),
                                          simState,
                                          unitConverter);
              CPPUNIT_ASSERT_EQUAL(targetStartDensity, inlets->GetBoundaryDensity(0));
              delete inlets;
            }
            void TestUpdate()
            {
              inlets = new BoundaryValues(hemelb::geometry::INLET_TYPE,
                                          latDat,
                                          simConfig->GetInlets(),
                                          simState,
                                          unitConverter);
              CPPUNIT_ASSERT_EQUAL(pressureToDensity(80.0 - 1.0), inlets->GetBoundaryDensity(0));

              while (simState->Get0IndexedTimeStep() < simState->GetTotalTimeSteps() / 20)
              {
                simState->Increment();
              }

              CPPUNIT_ASSERT_EQUAL(pressureToDensity(80.0 + 1.0), inlets->GetBoundaryDensity(0));

              while (simState->Get0IndexedTimeStep() < simState->GetTotalTimeSteps() / 10)
              {
                simState->Increment();
              }

              CPPUNIT_ASSERT_EQUAL(pressureToDensity(80.0 - 1.0), inlets->GetBoundaryDensity(0));
              delete inlets;
            }

            void TestUpdateFile()
            {
              FolderTestFixture::setUp();
              CopyResourceToTempdir("iolet.txt");
              MoveToTempdir();
              configuration::SimConfig *fileInletConfig =
                  configuration::SimConfig::Load(Resource("config_file_inlet.xml").Path().c_str());

              inlets = new BoundaryValues(hemelb::geometry::INLET_TYPE,
                                          latDat,
                                          fileInletConfig->GetInlets(),
                                          simState,
                                          unitConverter);

              CPPUNIT_ASSERT_DOUBLES_EQUAL(pressureToDensity(78.0), inlets->GetBoundaryDensity(0), 1e-6);

              while (simState->Get0IndexedTimeStep() < simState->GetTotalTimeSteps() / 2)
              {
                simState->Increment();
              }

              CPPUNIT_ASSERT_DOUBLES_EQUAL(pressureToDensity(82.0), inlets->GetBoundaryDensity(0), 1e-6);

              while (simState->Get0IndexedTimeStep() < simState->GetTotalTimeSteps())
              {
                simState->Increment();
              }

              CPPUNIT_ASSERT_DOUBLES_EQUAL(pressureToDensity(78.0), inlets->GetBoundaryDensity(0), 1e-6);

              FolderTestFixture::tearDown();
              delete inlets;
            }
            double pressureToDensity(double pressure)
            {
              double inverseVelocity = simState->GetTimeStepLength() / latDat->GetVoxelSize();
              return 1
                  + (pressure - REFERENCE_PRESSURE_mmHg) * mmHg_TO_PASCAL * inverseVelocity * inverseVelocity
                      / (Cs2 * BLOOD_DENSITY_Kg_per_m3);
            }
            BoundaryValues *inlets;
        };
        //BoundaryTests
        CPPUNIT_TEST_SUITE_REGISTRATION(BoundaryTests);
      } // boundaries
    } //lbtests
  } //unittests
} //hemelb
#endif // HEMELB_UNITTESTS_LBTESTS_BOUNDARIES_BOUNDARYTESTS_H
