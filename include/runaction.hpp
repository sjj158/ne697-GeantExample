#ifndef RUN_ACTION_HPP
#define RUN_ACTION_HPP
#include "G4UserRunAction.hh"

namespace ne697 {
  class RunAction: public G4UserRunAction {
    public:
      RunAction();
      ~RunAction();

      G4Run* GenerateRun() override final; //G4Run* is pointer to the base class
      void BeginOfRunAction(G4Run const*) override final;
      void EndOfRunAction(G4Run const*) override final;
  }; 
}

#endif