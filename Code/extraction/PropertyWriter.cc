// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#include "extraction/PropertyWriter.h"

namespace hemelb
{
  namespace extraction
  {
    PropertyWriter::PropertyWriter(IterableDataSource& dataSource,
                                   const std::vector<PropertyOutputFile*>& propertyOutputs)
    {
      for (unsigned outputNumber = 0; outputNumber < propertyOutputs.size(); ++outputNumber)
      {
        localPropertyOutputs.push_back(new LocalPropertyOutput(dataSource, propertyOutputs[outputNumber]));
      }
    }

    PropertyWriter::~PropertyWriter()
    {
      for (unsigned outputNumber = 0; outputNumber < localPropertyOutputs.size(); ++outputNumber)
      {
        delete localPropertyOutputs[outputNumber];
      }
    }

    const std::vector<LocalPropertyOutput*>& PropertyWriter::GetPropertyOutputs() const
    {
      return localPropertyOutputs;
    }

    void PropertyWriter::Write(unsigned long iterationNumber) const
    {
      for (unsigned outputNumber = 0; outputNumber < localPropertyOutputs.size(); ++outputNumber)
      {
        localPropertyOutputs[outputNumber]->Write((uint64_t) iterationNumber);
      }
    }
  }
}
