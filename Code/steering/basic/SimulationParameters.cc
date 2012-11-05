// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#include "io/writers/xdr/XdrMemWriter.h"

#include "vis/Control.h"
#include "steering/basic/SimulationParameters.h"

namespace hemelb
{
  namespace steering
  {

    SimulationParameters::SimulationParameters()
    {
      // C'tor initialises to the following defaults.

      timeStep = 0;
      time = 0.0;
      nInlets = 3;
      mousePressure = -1.0;
      mouseStress = -1.0;
    }

    SimulationParameters::~SimulationParameters()
    {
    }

    void SimulationParameters::pack(io::writers::xdr::XdrWriter* writer)
    {
      writer->operator <<(timeStep);

      writer->operator <<(time);

      writer->operator <<(0); // Cycle is always zero, leave this in to stop steering clients breaking.
      writer->operator <<(nInlets);

      writer->operator <<(mousePressure);
      writer->operator <<(mouseStress);
    }

  }
}
