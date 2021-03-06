//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
//

#ifndef G4ChannelingMaterialData_h
#define G4ChannelingMaterialData_h 1

#include "G4ios.hh"
#include "globals.hh"

#include "G4VMaterialExtension.hh"
#include "G4ChannelingECHARM.hh"
#include "G4StepPoint.hh"
#include "G4Track.hh"

class G4ChannelingMaterialData : public G4VMaterialExtension{
public:
    
    G4ChannelingMaterialData(const G4String&);
    virtual ~G4ChannelingMaterialData();
    
public:
    void Print() const {G4cout << "Channeling Material Data" << G4endl;};
    void SetFilename(const G4String&);
    
public:
    G4ChannelingECHARM* GetPot() {return fPotential;};
    G4ChannelingECHARM* GetEFX() {return fElectricFieldX;};
    G4ChannelingECHARM* GetEFY() {return fElectricFieldY;};
    G4ChannelingECHARM* GetNuD() {return fNucleiDensity;};
    G4ChannelingECHARM* GetElD() {return fElectronDensity;};
        
private:
    G4ChannelingECHARM* fPotential;
    G4ChannelingECHARM* fElectricFieldX;
    G4ChannelingECHARM* fElectricFieldY;
    G4ChannelingECHARM* fNucleiDensity;
    G4ChannelingECHARM* fElectronDensity;
    
public:
    G4bool IsBent() {
        if(fBR!=G4ThreeVector()){
            return true;
        }
        return false;
    };
    
    G4ThreeVector GetBR(G4ThreeVector&) {
        return fBR;
    };
    void SetBR(G4ThreeVector a3vec) {fBR=a3vec;};
    
private:
    G4ThreeVector fBR;

};

#endif










