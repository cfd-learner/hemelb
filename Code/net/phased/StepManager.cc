// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#include "net/phased/StepManager.h"

namespace hemelb
{
  namespace net
  {
    namespace phased
    {

      StepManager::StepManager(Phase phases) :
          registry(phases)
      {
      }

      void StepManager::Register(Phase phase, steps::Step step, Concern & concern, MethodLabel method)
      {
        if (step == steps::BeginAll || step == steps::EndAll || step == steps::Reset)
        {
          phase = 0; // special actions are always recorded in the phase zero registry
        }
        registry[phase][step].push_back(Action(concern, method));
      }

      void StepManager::RegisterIteratedActorSteps(Concern &concern, Phase phase)
      {
        for (int step = steps::BeginPhase; step <= steps::Reset; step++)
        {
          if (step == steps::Receive || step == steps::Send || step == steps::Wait)
          {
            continue;
          }
          // C++ makes it completely annoying to iterate over values in an enum
          Register(phase, static_cast<steps::Step>(step), concern, step);
        }
      }

      void StepManager::RegisterCommsSteps(Concern &concern, Phase phase)
      {
        Register(phase, steps::Send, concern, steps::Send);
        Register(phase, steps::Receive, concern, steps::Receive);
        Register(phase, steps::Wait, concern, steps::Wait);
      }

      void StepManager::RegisterCommsForAllPhases(Concern &concern)
      {
        for (Phase phase = 0; phase < registry.size(); phase++)
        {
          RegisterCommsSteps(concern, phase);
        }
      }

      unsigned int StepManager::ConcernCount() const
      {
        std::set<Concern *> concerns;
        for (std::vector<Registry>::const_iterator phase = registry.begin(); phase < registry.end(); phase++)
        {
          for (Registry::const_iterator step = phase->begin(); step != phase->end(); step++)
          {
            for (std::vector<Action>::const_iterator action = step->second.begin(); action != step->second.end();
                action++)
            {
              concerns.insert(action->concern);
            }
          }
        }
        return concerns.size();
      }

      unsigned int StepManager::ActionCount() const
      {
        unsigned int total = 0;
        for (std::vector<Registry>::const_iterator phase = registry.begin(); phase < registry.end(); phase++)
        {
          for (Registry::const_iterator step = phase->begin(); step != phase->end(); step++)
          {
            for (std::vector<Action>::const_iterator action = step->second.begin(); action != step->second.end();
                action++)
            {
              total++;
            }
          }
        }
        return total;
      }

      void StepManager::CallActionsForPhase(Phase phase)
      {
        for (int step = steps::BeginPhase; step <= steps::EndPhase; step++)
        {
          CallActionsForStep(static_cast<steps::Step>(step), phase);
        }
      }

      void StepManager::CallSpecialAction(steps::Step step)
      {
        // special actions are always recorded in the phase zero registry
        CallActionsForStep(static_cast<steps::Step>(step), 0);
      }

      void StepManager::CallActions()
      {
        CallSpecialAction(steps::BeginAll);
        for (Phase phase = 0; phase < registry.size(); phase++)
        {
          CallActionsForPhase(phase);
        }
        CallSpecialAction(steps::EndAll);
      }

      void StepManager::CallActionsForStep(steps::Step step, Phase phase)
      {

        std::vector<Action> &actionsForStep = registry[phase][step];
        for (std::vector<Action>::iterator action = actionsForStep.begin(); action != actionsForStep.end(); action++)
        {
          action->Call();
        }
      }
    }
  }
}
