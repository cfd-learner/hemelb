// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELB_SIMULATIONMASTER_H
#define HEMELB_SIMULATIONMASTER_H
#include "lb/lattices/D3Q15.h"
#include "extraction/PropertyActor.h"
#include "lb/lb.hpp"
#include "lb/StabilityTester.h"
#include "net/net.h"
#include "steering/ImageSendComponent.h"
#include "steering/SteeringComponent.h"
#include "lb/EntropyTester.h"
#include "lb/boundaries/BoundaryValues.h"
#include "util/UnitConverter.h"
#include "configuration/CommandLine.h"
#include "io/PathManager.h"
#include "reporting/Reporter.h"
#include "reporting/Timers.h"
#include "reporting/BuildInfo.h"
#include "lb/IncompressibilityChecker.hpp"
#include "net/phased/StepManager.h"
#include "net/phased/NetConcern.h"
#include "geometry/neighbouring/NeighbouringDataManager.h"

class SimulationMaster
{
  public:
    SimulationMaster(hemelb::configuration::CommandLine &options);
    virtual ~SimulationMaster();

    void Abort();

    bool IsCurrentProcTheIOProc();

    int GetProcessorCount();

    void RunSimulation();
    hemelb::lb::SimulationState const * GetState() const {
      return simulationState;
    }
    void Finalise();
  protected:
    hemelb::lb::boundaries::BoundaryValues* inletValues;
    hemelb::lb::boundaries::BoundaryValues* outletValues;
    virtual void DoTimeStep();

  private:
    // Set the lattice type via a build parameter
    typedef hemelb::lb::lattices:: HEMELB_LATTICE latticeType;
    void Initialise();
    void SetupReporting(); // set up the reporting file
    unsigned int OutputPeriod(unsigned int frequency);
    void HandleActors();
    void ResetUnstableSimulation();
    void WriteLocalImages();
    void GenerateNetworkImages();
    /**
     * Updates the property caches record of which properties need to be calculated
     * and cached on this iteration.
     */
    void RecalculatePropertyRequirements();

    /**
     * True if we are to create a snapshot on this iteration.
     * @return
     */
    bool ShouldWriteSnapshot();

    /**
     * Helper method to log simulation parameters related to stability and accuracy
     */
    void LogStabilityReport();

    hemelb::configuration::SimConfig *simConfig;
    hemelb::geometry::LatticeData* latticeData;
    hemelb::io::PathManager* fileManager;
    hemelb::reporting::Timers timings;
    hemelb::reporting::Reporter* reporter;
    hemelb::reporting::BuildInfo build_info;
    typedef std::multimap<unsigned long, unsigned long> MapType;

    MapType snapshotsCompleted;
    MapType networkImagesCompleted;

    hemelb::steering::Network* network;
    hemelb::steering::ImageSendComponent *imageSendCpt;
    hemelb::steering::SteeringComponent* steeringCpt;

    hemelb::lb::SimulationState* simulationState;
    hemelb::lb::StabilityTester<latticeType>* stabilityTester;
    hemelb::lb::EntropyTester<latticeType>* entropyTester;

    /** Actor in charge of checking the maximum density difference across the domain */
    hemelb::lb::IncompressibilityChecker<hemelb::net::PhasedBroadcastRegular<> >* incompressibilityChecker;

    hemelb::lb::LBM<latticeType>* latticeBoltzmannModel;
    hemelb::net::Net communicationNet;

    hemelb::util::UnitConverter* unitConvertor;

    hemelb::vis::Control* visualisationControl;
    hemelb::extraction::IterableDataSource* propertyDataSource;
    hemelb::extraction::PropertyActor* propertyExtractor;

    hemelb::net::phased::StepManager* stepManager;
    hemelb::net::phased::NetConcern* netConcern;

    hemelb::geometry::neighbouring::NeighbouringDataManager *neighbouringDataManager;

    unsigned int snapshotsPerSimulation;
    unsigned int imagesPerSimulation;
    int steeringSessionId;
    unsigned int imagesPeriod;
    static const hemelb::LatticeTime FORCE_FLUSH_PERIOD=1000;
};

#endif /* HEMELB_SIMULATIONMASTER_H */
