#ifndef B1ActionInitialization_h
#define B1ActionInitialization_h 1

#include "G4VUserActionInitialization.hh"
#include "globals.hh"
#include "B1RunAction.hh"
#include <vector>

/// Action initialization class.

class B1ActionInitialization : public G4VUserActionInitialization
{
public:
	B1ActionInitialization(G4double BeamEnergy, G4bool CalibMuonBeamFlag, G4bool ProdMuonBeamFlag ,G4bool ElectronBeamFlag, G4bool SimpleFlag, G4bool StoreCaloEnDepFlag, G4bool ExtSourceFlagBha, G4bool ExtSourceFlagMu, G4double EThr, std::vector<G4int> & ChannelMap);
	virtual ~B1ActionInitialization();
	
	virtual void BuildForMaster() const;
	virtual void Build() const;
	
	//	virtual B1RunAction* GetRunAction() {return frunAction;};
	
private:
	G4double fBeamEnergy;
	G4bool fCalibMuonBeamFlag;
	G4bool fProdMuonBeamFlag;
	G4bool fElectronBeamFlag;
	G4bool fSimpleFlag;
	G4bool fStoreCaloEnDepFlag;
	
	G4bool fExtSourceFlagBha;
	G4bool fExtSourceFlagMu;
	G4double fEThr;
	
	
public:
	std::vector<G4int> fChannelMap;

};


#endif


