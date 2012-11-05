// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#include "net/ProcComms.h"
namespace hemelb
{
  namespace net
  {
    void ProcComms::CreateMPIType()
    {
      std::vector<MPI_Aint> displacements(size());
      std::vector<int> lengths;
      std::vector<MPI_Datatype> types;

      int location = 0;

      MPI_Aint offset;
      MPI_Get_address(front().Pointer, &offset);

      for (iterator it = begin(); it != end(); ++it)
      {
        MPI_Get_address(it->Pointer, &displacements[location]);
        displacements[location] -= offset;

        ++location;
        lengths.push_back(it->Count);
        types.push_back(it->Type);
      }
      // Create the type and commit it.
      MPI_Type_create_struct(this->size(), &lengths.front(), &displacements.front(), &types.front(), &Type);
      MPI_Type_commit(&Type);
    }
  }
}
