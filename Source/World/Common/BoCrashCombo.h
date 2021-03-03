#ifndef BOCRASHCOMBO_H
#define BOCRASHCOMBO_H

#include <rwcore.h>

#include "BoPlayerCar.h"
#include "../../Physics/BoRaceCarPhysics.h"
#include "../../Physics/BoVehiclePhysics.h"
#include "../../../Shared/Numeric/Math/PC/GtMathPC.h"

using namespace GtMathPC;

enum ECrashComboCollisionType {
	eComboEntryCollisionTypeUnknown = 0,
	eComboEntryCollisionTypeHeadOn = 1,
	eComboEntryCollisionTypeRearEnded = 2,
	eComboEntryCollisionTypeTBoned = 3,
	eComboEntryCollisionTypeCount = 4
};
enum EComboEntryType {
	eComboEntryIntoWall = 0,
	eComboEntryIntoVehicle = 1,
	eComboEntryIntoRamp = 2,
	eComboEntryRollOver = 3,
	eComboEntryRightSided = 4,
	eComboEntryBarrelRoll = 5,
	eComboEntryFrontFlip = 6,
	eComboEntryBackFlip = 7,
	eComboEntryHelicopter = 8,
	eComboEntryCartwheel = 9,
	eComboEntryRodeo = 10,
	eComboEntryAlleyOop = 11,
	eComboEntryCrazyStyle = 12,
	eComboEntryHeadSpin = 13,
	eComboEntrySunroofSkid = 14,
	eComboEntrySkid = 15,
	eComboEntrySidePanelSkid = 16,
	eComboEntryNoseGrind = 17,
	eComboEntryTailGrind = 18,
	eComboEntryRoofWreck = 19,
	eComboEntryNoseDive = 20,
	eComboEntryExhaustStand = 21,
	eComboEntryWingMirrorCrush = 22,
	eComboEntrySoftLanding = 23,
	eComboEntryPayload = 24,
	eComboEntryAir = 25,
	eComboEntryBurstIntoFlames = 26,
	eComboEntryExploded = 27,
	eComboEntryOverVehicle = 28,
	eComboEntryCrashbreaker = 29,
	eComboEntryPickup = 30,
	eComboEntryCarExploded = 31,
	eComboEntryVanExploded = 32,
	eComboEntryTruckExploded = 33,
	eComboEntryBusExploded = 34,
	eComboEntryTramExploded = 35,
	eComboEntryBigRigExploded = 36,
	eComboEntryTrailerExploded = 37,
	eComboEntryCarImpact = 38,
	eComboEntryCarSmashed = 39,
	eComboEntryVanImpact = 40,
	eComboEntryVanSmashed = 41,
	eComboEntryTruckImpact = 42,
	eComboEntryTruckSmashed = 43,
	eComboEntryBusImpact = 44,
	eComboEntryBusSmashed = 45,
	eComboEntryTramImpact = 46,
	eComboEntryTramSmashed = 47,
	eComboEntryBigRigImpact = 48,
	eComboEntryBigRigSmashed = 49,
	eComboEntryTrailerImpact = 50,
	eComboEntryTrailerSmashed = 51,
	eComboEntryTypeCount = 52,
	eComboEntryTypeNone = 53
};
enum ECrashComboSideUp {
	eComboSideUpNone = 0,
	eComboSideRightWayUp = 1,
	eComboSideUpsideDown = 2,
	eComboSideNoseUp = 3,
	eComboSideTailUp = 4,
	eComboSideLeftUp = 5,
	eComboSideRightUp = 6,
	eComboSideUpCount = 7
};
enum ESlamShuntComboState {
	eSlamShuntComboStateNeutral = 0,
	eSlamShuntComboStateLevelOne = 1,
	eSlamShuntComboStateLevelTwo = 2,
	eSlamShuntCombeStateCount = 3
};
enum EBoPlayerVehicleClass {
	eBoPlayerVehicleClassNone = 0,
	eBoPlayerVehicleClassRace = 1,
	eBoPlayerVehicleClassMuscle = 2,
	eBoPlayerVehicleClassCrash = 3,
	eBoPlayerVehicleClassSuper = 4,
	eBoPlayerVehicleClassCount = 5
};

struct CBoCrashComboItem {
	CBoVehiclePhysics* mpVehicle;
	EComboEntryType meType;
	RwInt32 mnValue;
	RwReal mrValue;
};

struct CBoCrashStartInfo {

};

class CBoCrashCombo {
	CBoCrashComboItem maCombo[16];
	RwInt32 mnComboQueueSize;
	RwInt32 mnComboQueueHead;
	RwInt32 mnComboQueueTail;
	CBoCrashComboItem* mpNewComboItem;
	CBoCrashComboItem* mpLastSkidComboEntry;
	CBoCrashComboItem* mpLastAirComboEntry;
	bool mbAddedItemThisFrame;
	bool mbFinishingCombo;
	bool mbCrashing;
	bool mbCrashCausedByWall;
	RwReal mrCrashStartTime;
	RwReal mrCrashFinishTime;
	RwReal mrRampSkidIgnoreTime;
	EBoPlayerVehicleClass meVehicleClass;
	CGtV3d mCrashStartPos;
	CGtV3d mLastPosition;
	CGtV3d mRotationDelta;
	bool mabSpinsFinished[3];
	int manCurrentSpins[3];
	int manTotalSpins[3];
	RwInt32 mnAllTotalSpins;
	RwReal marTotalSpinTime[3];
	RwReal marSpins[3];
	ECrashComboSideUp meSideUp;
	int manTotalAxisSpins[7];
	RwInt32 mnTotalBackFlips;
	bool mbLanded;
	bool mbLandedThisFrame;
	bool mbInAir;
	RwReal mrAirTime;
	RwReal mrGroundTime;
	RwReal mrTotalAirTime;
	RwReal mrCurrentAirTime;
	ECrashComboSideUp meHardestLanding;
	RwReal mrHardestLandingVelocity;
	RwReal mrLastLandingVelocity;
	CGtV3d mSkidStartPos;
	bool mbStoppedThisFrame;
	bool mbSkidFinished;
	bool mbSkidding;
	bool mbExploded;
	bool mbOnFire;
	RwReal mrSkidDistance;
	RwReal mrTotalSkidTime;
	RwReal mrTotalSkidDistance;
	RwReal marSkidDistance[7];
	ECrashComboSideUp mePrevSideUp;
	RwReal mrLastExternalItemTime;
	EComboEntryType meLatestItemType;
	bool mbNewItemType;
	CBoPlayerCar* mpPlayerCar;
	CBoRaceCarPhysics* mpCarPhysics;
	RwInt16 mn16CurrentComboIndex;
	bool mbReverse;
	CBoVehiclePhysics* mapVehiclesInCrash[64];
	RwInt32 mnVehiclesInCrash;
	RwInt32 mnNewVehiclesThisFrame;
	RwInt32 mnTotalVehiclesInCrash;
	RwInt32 mnBusCount;
	RwInt32 mnCarCount;
	RwInt32 mnTruckCount;
	RwInt32 mnRivalCount;

	void Construct();
	void Destruct();
	void Prepare(CBoPlayerCar*);
	void Release();
	void Update();
	void UpdateCollidingPairs();
	void OnCrashStart(const CBoCrashStartInfo*);
	void OnCrashStop();
	void OnCrashFinishing();
	CBoCrashComboItem* GetFirstItem(bool);
	EComboEntryType GetFirstItemType();
	CBoCrashComboItem* GetNextItem();
	RwInt32 GetComboSize() const;
	RwInt32 GetNumVehiclesInCrash() const;
	void AddPickupToCombo();
	void AddExternalItemToCombo(EComboEntryType);
	EBoPlayerVehicleClass GetVehicleClass();
	bool IsNewItemAvailable();
	void DetectAirAndGround();
	void DetectSkid();
	void UpdateCurrentCombo();
	void UpdateVehicles();
	void UpdateSpins();
	void UpdateSkids();
	void UpdateAir();
	void UpdateExtras();
	CBoCrashComboItem* AddUninitialisedItemToCombo();
	void AddVehicleToCombo(CBoVehiclePhysics*, EComboEntryType, ECrashComboCollisionType);
	void AddItemToCombo(EComboEntryType, int, CBoVehiclePhysics*);
	void AddItemToCombo(EComboEntryType, float, CBoVehiclePhysics*);
	void AddLanding();
	ECrashComboCollisionType GetVehicleCollisionType(CBoVehiclePhysics);
	ECrashComboSideUp GetSideFacingUp(const CGtMatrix3x4&);
	void AddVehicle(CBoVehiclePhysics*);
	void ResetData();
};

#endif // !#define BOCRASHCOMBO_H
