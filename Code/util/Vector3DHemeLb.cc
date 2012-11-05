// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#include "util/Vector3D.h"
#include "mpiInclude.h"
#include "units.h"
#include <cassert>
#include "log/Logger.h"

namespace hemelb
{
  template<typename vectorType>
  MPI_Datatype GenerateTypeForVector()
  {
    const int typeCount = 1;
    int blocklengths[typeCount] = { 3 };

    MPI_Datatype types[typeCount] = { MpiDataType<vectorType> () };

    MPI_Aint displacements[typeCount] = { 0 };

    MPI_Datatype ret;

    MPI_Type_struct(typeCount, blocklengths, displacements, types, &ret);

    MPI_Type_commit(&ret);
    return ret;
  }

  template<>
  MPI_Datatype MpiDataTypeTraits<hemelb::util::Vector3D<float> >::RegisterMpiDataType()
  {
    return GenerateTypeForVector<float> ();
  }

  template<>
  MPI_Datatype MpiDataTypeTraits<hemelb::util::Vector3D<site_t> >::RegisterMpiDataType()
  {
    return GenerateTypeForVector<site_t> ();
  }

  template<>
   MPI_Datatype MpiDataTypeTraits<hemelb::util::Vector3D<distribn_t> >::RegisterMpiDataType()
   {
     return GenerateTypeForVector<distribn_t> ();
   }
  namespace util
  {
    namespace
    {
      void DefaultHandlerFunction(int direction)
      {
        // TODO need to find a way of handling this case better.
        log::Logger::Log<log::Error, log::OnePerCore>("Failed while accessing a direction in Vector3D.");
        assert(false);
      }
    }
    Vector3DBase::HandlerFunction* Vector3DBase::handler = DefaultHandlerFunction;

  }
}
