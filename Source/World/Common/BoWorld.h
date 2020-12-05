#ifndef GTWORLD_H
#define GTWORLD_H

#include <rwcore.h>

#include "BoCrashScore.h"
#include "BoEnvironmentManager.h"
#include "BoGameData.h"
#include "BoLapManager.h"
#include "BoNetworkCar.h"
#include "BoPropManager.h"
#include "BoRevengeScore.h"
#include "BoVehicleDataStream.h"
#include "AI/BoAICar.h"
#include "AI/BoAILaneSegmentManager.h"
#include "Track/BoStaticTrack.h"
#include "Track/BoStreamedTrack.h"
#include "Traffic/BoTrafficSystem.h"
#include "../../Physics/BoVehiclePhysics.h"
#include "../../Physics/BoPhysicsManager.h"
#include "../../Physics/BoCrashActionDirector.h"
#include "../../Physics/BoConvexHull.h"
#include "../../Graphics/Common/BoVehicleRenderer.h"
#include "../../Game/Common/BoAIDebug.h"
#include "../../Camera/Crash/BoCrashAnalyser.h"
#include "../../../Shared/System/Common/GtTimer.h"
#include "../../../Shared/Numeric/Math/PC/GtV3dPC.h"
#include "../../../Shared/Numeric/GtRandom.h"
#include "../../../Shared/Core/GtID.h"

using namespace GtMathPC;

class CBoCrashPresentationDirector {

};

class CBoReplaySystem {

};

class CBoStreamManager {

};

class CBoWorld {
public:
	CGtTimer mTimer;
	CBoAILane maAILanes[128];
	CBoTrafficLane maTrafficLanes[255];
	CBoTrafficSystem mTrafficSystem;
	CBoCrashPresentationDirector mCrashPresentationDirector;
	CBoCrashActionDirector mCrashActionDirector;
	CBoReplaySystem mReplaySystem;
	CBoPhysicsManager mPhysicsManager;
	CBoGameData mGameData;
	CBoRacePosition mRacePositions;
	CBoPropManager mPropManager;
	CBoPayloadPropManager mPayloadPropManager;
	CBoCrashAnalyser maPlayerCrashAnalysers[2];
	CBoStaticTrack mStaticTrack;
	CBoStreamedTrack mStreamedTrack[2];
	CBoStreamManager mStreamManager;
	CBoConvexHullPlane manStreamStartHull;
	CBoCrashScore mCrashScore;
	CBoRevengeScore mRevengeScore;
	RwInt32 mnNumTrafficLanes;
	CBoAISegmentStruct mpAIData;
	CBoAILaneStruct* mpAILaneData;
	CBoAICornerStruct* mpAICornersArray;
	CBoAIDriverStruct mpAIDriversArray;
	CBoAIRungStruct* mpAINodesArray; // TODO: confirm type.
	RwInt32 mnAILaneCount;
	RwInt32 mnAICornerCount;
	RwInt32 mnAIDriverCount;
	CBoSliceStruct* mpSlicesArray;
	RwInt32 mnSliceCount;
	RwInt32 mnNumCarsCrossedLine;
	CGtRandom mRaceCarRand;
	GtID mTrackID;
	bool mbIsPointToPoint;
	bool mbIsMarathon;
	bool mbIsRightHandDrive;
	RwInt32 mnNumRaceCars;
	RwInt32 mnNumRaceCarsPrepared;
	RwInt32 mnNumActiveRaceCars;
	CBoRaceCar* mapRaceCars[6];
	RwInt32 mnNumPlayerCars;
	RwInt32 mnNumAICars;
	RwInt32 mnNumNetworkCars;
	RwInt32 mnBaseNumAdjustedAICars;
	RwInt32 mnCurrentNumAdjustedAICars;
	RwInt32 mnLeadingAdjustedAICar;
	CBoPlayerCar maPlayerCars[2];
	CBoAICar maAICars[5];
	CBoNetworkCar maNetworkCars[5];
	RwInt32 mnMaxRaceCarStreams;
	CBoVehicleDataStream maRaceCarStreams[6];
	bool mbPausedForNetworkSync;
	bool mbPausedForStreamSync;
	bool mbRequestReplay;
	bool mbIsReplaying;
	RwInt32 mnInitialWorldFrame;
	RwInt32 mnSkyRenderMonitorID;
	RwInt32 mnTrackRenderMonitorID;
	RwInt32 mnTrafficRenderMonitorID;
	RwInt32 mnRaceCarRenderMonitorID;
	RwInt32 mnShadowRenderMonitorID;
	RwReal mrPulseTime;
	RwReal mrPulseDirection;
	CGtV3d mTrackCentre;
	CGtV3d mMinTrackPos;
	CGtV3d mMaxTrackPos;
	bool mbIsCrashIntro;
	bool mbIsCrashAftermath;
	EGtPrepareState mePrepareState;

	CBoWorld();
	void Construct();
	void DecrementLeadingAdjustedAICar();
	void DecrementNumActiveRaceCars();
	void DecrementNumAdjustedAICars();
	void Destruct();
	CBoAICar* GetAICar(EAICarIndex);
	RwInt32	GetInitialWorldFrame();
	RwInt32	GetLeadingAdjustedAICar();
	RwInt32	GetMaxRaceCarStreams() const;
	CBoNetworkCar* GetNetworkCar(ENetworkCarIndex);
	RwInt32	GetNumActiveRaceCars();
	RwInt32	GetNumAdjustedAICars();
	EPlayerCarIndex	GetNumAICars();
	EPlayerCarIndex	GetNumNetworkCars();
	EPlayerCarIndex	GetNumPlayerCars();
	ERaceCarIndex GetNumRaceCars();
	CBoPlayerCar* GetPlayerCar(EPlayerCarIndex);
	CBoVehiclePhysics GetRaceCar(ERaceCarIndex);
	CBoVehicleData GetRaceCarData(GtID lnID, RwInt32 lnBufferIndex);
	bool GetReplayRequestStatus();
	RwReal GetTimeBeforeAutomaticTimeout();
	CGtV3d GetTrackCentre();
	void GetTrackExtents(CGtV3d*, CGtV3d*);
	GtID GetTrackID();
	void IncrementLeadingAdjustedAICar();
	bool IsCrashAftermath() const;
	bool IsCrashIntro() const;
	bool IsMarathon();
	bool IsMultiPlayer();
	bool IsPointToPoint();
	bool IsReplaying();
	bool IsRightHandDrive();
	bool IsSinglePlayer();
	bool LoadRaceCarData(GtID lnID, RwInt32 lnBufferIndex);
	void NetworkCatchupUpdate();
	void PauseForNetworkSync(bool);
	void PauseForStreamSync(bool);
	bool Prepare(bool lbQuickPrepare);
	void Release();
	void Render(EPlayerCarIndex);
	void RenderCarUnlockEffects();
	void RenderFrontEnd(ERaceCarIndex);
	void RenderFullScreenPoly(EPlayerCarIndex);
	void RenderOnePlayer();
	void RenderRaceCars(EPlayerCarIndex, EPlayerCarIndex);
	void RenderTwoPlayer();
	void SetCarNumbers(RwInt32 lnNumPlayerCars, RwInt32 lnNumAICars, RwInt32 lnNumNetworkCars, RwInt32 lnNumAdjustedAICars);
	void SetCrashAftermath(bool);
	void SetCrashIntro(bool);
	void SetNumActiveRaceCars(int);
	void SetNumLeadingCars(int);
	void SetReplayRequestStatus(bool);
	void SetTrackID(GtID lnID);
	void SetUpTrackExtents();
	void UnLoadRaceCarData(GtID lnID, RwInt32 lnBufferIndex);
	void Update();
	void UpdateSound();
	void UpdateTrack();
	bool WeArePausedForNetworkOrStreamSync();
};

extern CBoWorld gWorld;

#endif // !#define GTWORLD_H
