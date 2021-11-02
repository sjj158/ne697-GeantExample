#ifndef Event_Action_HPP
#define Event_Action_HPP
#include "G4UserEventAction.hh"

namespace ne697 {
  class EventAction: public G4UserEventAction {
    public:
      EventAction();
      ~EventAction();

    //  void BeginOfEventAction(G4Event const* event) override final;
      void EndOfEventAction(G4Event const* event) override final;
  }; 
}

#endif