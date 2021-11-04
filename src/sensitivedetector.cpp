#include "sensitivedetector.hpp"
#include "G4UnitsTable.hh"
#include "G4VProcess.hh"

namespace ne697 {
  SensitiveDetector::SensitiveDetector(G4String const& name):
  G4VSensitiveDetector(name),
  m_id(-1),
  m_hitsCollection(nullptr)
  {
    G4String hc_name = name + "_hits";
    collectionName.insert(hc_name);   
  }

  void SensitiveDetector::Initialize(G4HCofThisEvent* hc) {
    if (m_id < 0) {
      m_id = GetCollectionID(0);
    }
    //Create a hits collection for this sensitive detector (SD)
    m_hitsCollection=new HitsCollection(SensitiveDetectorName, collectionName[0]);
    //Give the collection to the g4Event so we can get it at the end in Run::RecordEvent()
    hc->AddHitsCollection(m_id, m_hitsCollection);
    return;
  }

  bool SensitiveDetector::ProcessHits(G4Step* step, G4TouchableHistory*) {
    auto track = step->GetTrack(); //auto=Hit*
    //must use the class tag since G4VSensitiveDetector has a Hit member and we do not want that
    auto hit = new ne697::Hit(
      track->GetTrackID(),
      track->GetParentID(),
      track->GetVolume()->GetName(),
      track->GetDefinition()->GetParticleName(),
      (track->GetCreatorProcess() ? track->GetCreatorProcess()->GetProcessName()
                                        : "generator"),
      track->GetPosition(), step->GetTotalEnergyDeposit(),
      track->GetGlobalTime());
    m_hitsCollection->insert(hit);
    // DEBUG: Just prints outputs
    G4cout << "Got a hit!" << G4endl;
    G4cout << "Volume: " << hit->getVolume() << "\n";
    G4cout << "Particle: " << hit->getParticle() << "\n";
    G4cout << "Creator process: " << hit->getProcess() << "\n";
    G4cout << "Position: " << G4BestUnit(hit->getPosition(), "Length") << "\n";
    G4cout << "Energy deposited: " << G4BestUnit(hit->getEnergy(), "Energy")
          << "\n";
    G4cout << "Time: " << G4BestUnit(hit->getTime(), "Time") << "\n" << G4endl;
    // DEBUG
    return true;
  }
}