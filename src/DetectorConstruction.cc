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

#include "DetectorConstruction.hh"

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4Cons.hh"
#include "G4Orb.hh"
#include "G4Sphere.hh"
#include "G4Trd.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4Isotope.hh"
#include "G4Element.hh"


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* DetectorConstruction::Construct()
{
  // Get nist material manager
  G4NistManager* nist = G4NistManager::Instance();

  // Option to switch on/off checking of volumes overlaps
  G4bool checkOverlaps = true;

  // World

  G4double sizeXY = 50*cm, sizeZ = 50*cm;
  G4double world_sizeXY = 1.2*sizeXY;
  G4double world_sizeZ  = 1.2*sizeZ;
  G4Material* world_mat = nist->FindOrBuildMaterial("G4_AIR");

  auto solidWorld = new G4Box("World",                           // its name
    world_sizeXY, world_sizeXY, world_sizeZ);  // its size
  
  auto logicWorld = new G4LogicalVolume(solidWorld,  // its solid
    world_mat,                                       // its material
    "World");                                        // its name
  
  auto physWorld = new G4PVPlacement(nullptr,  // no rotation
    G4ThreeVector(),                           // at (0,0,0)
    logicWorld,                                // its logical volume
    "World",                                   // its name
    nullptr,                                   // its mother  volume
    false,                                     // no boolean operation
    0,                                         // copy number
    checkOverlaps);                            // overlaps checking
  
  //
  // Counter

  G4Material* polyethylene = nist->FindOrBuildMaterial("G4_POLYETHYLENE");
  G4Material* cadmium = nist->FindOrBuildMaterial("G4_Cd");
  
  G4Isotope* he3 = new G4Isotope("he3", 2, 3, 3.016029*gram/mole);
  G4Element* He3 = new G4Element("He3", "He3", 1);
  He3->AddIsotope(he3,100.*perCent);
  G4double density = 12.525e19 * 6.6465e-24 * gram/cm3;
  G4Material* helium = new G4Material("He3_gas", density, 1, kStateGas, 293.15 * kelvin, 5 * atmosphere);
  helium->AddElement(He3, 100.*perCent);
  
  
  G4ThreeVector pos = G4ThreeVector(0, 0, 0);
  
  G4double orbRadius = 2.5*cm;
  G4double sphereRadius = 15*cm;

  auto innerOrb = new G4Orb("Orb", 
    orbRadius);

  auto logicOrb = new G4LogicalVolume(innerOrb,
    helium,
    "Orb");

  auto physOrb = new G4PVPlacement(nullptr,
    pos,
    logicOrb,
    "Orb",
    logicWorld,
    false,
    0,
    checkOverlaps);

  auto outerSphere = new G4Sphere("Sphere",
    orbRadius,
    sphereRadius,
    0*deg,
    360*deg,
    0*deg,
    180*deg);

  auto logicSphere = new G4LogicalVolume(outerSphere,
    polyethylene,
    "Sphere");

  auto physSphere = new G4PVPlacement(nullptr,
    pos,
    logicSphere,
    "Sphere",
    logicWorld,
    false,
    0,
    checkOverlaps);
  // Set Shape as scoring volume

  fScoringVolume = logicOrb;

  //always return the physical World
  return physWorld;

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

