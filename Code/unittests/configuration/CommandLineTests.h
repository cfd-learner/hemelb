// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELB_UNITTESTS_CONFIGURATION_COMMANDLINETESTS_H
#define HEMELB_UNITTESTS_CONFIGURATION_COMMANDLINETESTS_H

#include <cppunit/TestFixture.h>
#include "configuration/CommandLine.h"
#include "resources/Resource.h"
#include "unittests/helpers/FolderTestFixture.h"

namespace hemelb
{
  namespace unittests
  {
    /**
     * Class to test the simulation master.
     */
    using namespace hemelb::configuration;
    using namespace resources;
    using namespace helpers;
    class CommandLineTests : public FolderTestFixture
    {
        CPPUNIT_TEST_SUITE(CommandLineTests);
        CPPUNIT_TEST(TestConstruct);
        CPPUNIT_TEST_SUITE_END();
      public:
        void setUp()
        {
          configFile = Resource("four_cube.xml").Path();
          argc = 9;
          argv[0] = "hemelb";
          argv[2] = configFile.c_str();
          argv[1] = "-in";
          argv[3] = "-i";
          argv[4] = "1";
          argv[5] = "-s";
          argv[6] = "1";
          argv[7] = "-ss";
          argv[8] = "1111";
          FolderTestFixture::setUp();
          options = new hemelb::configuration::CommandLine(argc, argv);
        }

        void tearDown()
        {
          FolderTestFixture::tearDown();
          delete options;
        }

        void TestConstruct()
        {
          CPPUNIT_ASSERT(options);
        }

      private:
        int argc;
        std::string configFile;
        hemelb::configuration::CommandLine *options;
        const char* argv[9];

    };
    CPPUNIT_TEST_SUITE_REGISTRATION(CommandLineTests);
  }
}

#endif // ONCE
