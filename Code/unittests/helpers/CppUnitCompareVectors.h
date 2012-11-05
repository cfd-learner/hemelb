// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELB_UNITTESTS_HELPERS_CPPUNITCOMPAREVECTORS_H
#define HEMELB_UNITTESTS_HELPERS_CPPUNITCOMPAREVECTORS_H
#include <cppunit/TestFixture.h>

namespace CPPUNIT_NS
{
  template<class T> struct assertion_traits<std::vector<T> >
  {
      static bool equal(const std::vector<T>& x, const std::vector<T>& y)
      {
        return x == y;
      }

      // Note this vector print doesn't visually distinguish between ("1" "2" "3") and("1, 2" "3").
      static std::string toString(const std::vector<T>& values)
      {
        std::stringstream output;
        output << "[ " << std::flush;
        for (typename std::vector<T>::const_iterator value = values.begin(); value != values.end(); value++)
        {
          output << *value << ", " << std::flush;
        }
        output << "]" << std::flush;
        return output.str();
      }
  };
}
#endif
