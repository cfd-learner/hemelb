// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELB_STEERING_BASIC_SIMULATIONPARAMETERS_H
#define HEMELB_STEERING_BASIC_SIMULATIONPARAMETERS_H

#include "io/writers/xdr/XdrMemWriter.h"
#include "lb/SimulationState.h"

namespace hemelb
{
  namespace steering
  {

    class SimulationParameters
    {

      public:

        int timeStep;
        double time;
        int nInlets;
        double mousePressure;
        double mouseStress;

        static const u_int paramsSizeB = 3 * sizeof(int) + 3 * sizeof(double);

        SimulationParameters();
        ~SimulationParameters();
        void pack(io::writers::xdr::XdrWriter* writer);

      private:

    };

  }
}

#endif // HEMELB_STEERING_BASIC_SIMULATIONPARAMETERS_H
