#ifndef RUN_HPP
#define RUN_HPP
#include "G4Run.hh"
#include "hit.hpp"

namespace ne697 {
  class Run: public G4Run {
    public:
      Run();
      ~Run();

      //After we have already called EndOfEventAction
      void RecordEvent(G4Event const* event) override final;
      void Merge(G4Run const* from_run) override final; //pass in run that is going to get merged
    
      std::vector<Hit> getHits() const;

    private:
      std::vector<Hit> m_hits;
  }; 
}

#endif