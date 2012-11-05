// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELB_UNITTESTS_IO_PATHMANAGERTESTS_H
#define HEMELB_UNITTESTS_IO_PATHMANAGERTESTS_H
#include "io/PathManager.h"
#include "unittests/helpers/FolderTestFixture.h"
namespace hemelb
{
  namespace unittests
  {
    namespace reporting
    {
      using namespace helpers;
      using namespace hemelb::io;

      class PathManagerTests : public FolderTestFixture
      {
          CPPUNIT_TEST_SUITE(PathManagerTests);
          CPPUNIT_TEST(TestCreateLocalConfig);
          CPPUNIT_TEST(TestNameInventionLocalConfig);
          CPPUNIT_TEST(TestCreatePathConfig);
          CPPUNIT_TEST(TestNameInventionPathConfig);
          CPPUNIT_TEST_SUITE_END();
        public:
          void setUp()
          {
            FolderTestFixture::setUp();
            argc = 9;
            processorCount = 5;
            argv[0] = "hemelb";
            argv[2] = "config.xml";
            argv[1] = "-in";
            argv[3] = "-i";
            argv[4] = "1";
            argv[5] = "-s";
            argv[6] = "1";
            argv[7] = "-ss";
            argv[8] = "1111";
          }

          void tearDown()
          {
            FolderTestFixture::tearDown();
            delete fileManager;
          }

          void TestCreateLocalConfig()
          {
            ConstructManager();
            AssertPresent("results");
            AssertPresent("results/Images");
            AssertPresent("results/Snapshots");
          }

          void TestNameInventionLocalConfig()
          {
            ConstructManager();
            CPPUNIT_ASSERT_EQUAL(std::string("./results"),
                                 fileManager->GetReportPath());
          }

          void TestCreatePathConfig()
          {
            ConstructPathConfigManager();
            AssertPresent("results");
            AssertPresent("results/Images");
            AssertPresent("results/Snapshots");
          }

          void TestNameInventionPathConfig()
          {
            ConstructPathConfigManager();
            CPPUNIT_ASSERT_EQUAL(GetTempdir() + "/results",
                                 fileManager->GetReportPath());
          }

        private:

          void ConstructManager()
          {
            configuration::CommandLine cl = configuration::CommandLine(argc, argv);
            fileManager = new PathManager(cl, true, processorCount);
          }

          void ConstructPathConfigManager()
          {
            std::string targetConfig = GetTempdir() + "/config.xml"; // note this resource doesn't exist -- not a problem
            argv[2] = targetConfig.c_str();
            ReturnToOrigin(); // even if we're not in current dir, explicit path should cause the results to be created in the tmpdir
            ConstructManager();
            MoveToTempdir(); // go back to the tempdir and check the files were created in the right place
          }

          int argc;
          int processorCount;
          const char* argv[9];
          PathManager *fileManager;
      };

      CPPUNIT_TEST_SUITE_REGISTRATION(PathManagerTests);
    }
  }
}
#endif // ONCE
