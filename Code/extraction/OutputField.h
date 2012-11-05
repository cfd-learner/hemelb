// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELB_EXTRACTION_OUTPUTFIELD_H
#define HEMELB_EXTRACTION_OUTPUTFIELD_H

namespace hemelb
{
  namespace extraction
  {
    struct OutputField
    {
        enum FieldType
        {
          Pressure,
          Velocity,
          ShearStress,
          VonMisesStress,
          ShearRate,
          StressTensor,
          TractionVector,
          TangentialProjectionTractionVector
        };

        std::string name;
        FieldType type;
    };
  }
}

#endif /* HEMELB_EXTRACTION_OUTPUTFIELD_H */
