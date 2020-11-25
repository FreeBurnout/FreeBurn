#include <rwcore.h>

#include "BoNetworkCar.h"
#include "../../Common/Graphics/VehicleRenderer/BoVehicleRenderer.h"
#include "../../Common/Physics/BoVehiclePhysics.h"
#include "../../Common/World/AI/BoAICar.h"
#include "../../../../GameShared/Common/Core/GtID.h"
#include "../../../../GameShared/PC/Numeric/GtMathPC.h"

using namespace GtMathPC;

class CBoWorld {
public:
    CBoWorld();
    void Construct();
    bool Prepare(bool lbQuickPrepare);
    bool LoadRaceCarData(GtID lnID, RwInt32 lnBufferIndex);
    CBoVehicleData GetRaceCarData(GtID lnID, RwInt32 lnBufferIndex);
    CBoVehiclePhysics GetRaceCar(ERaceCarIndex);
    void SetUpTrackExtents();
    void Update();
    void UpdateTrack();
    void Release();
    void SetTrackID(GtID lnID);
    void UnLoadRaceCarData(GtID lnID, RwInt32 lnBufferIndex);
    void Destruct();
    void SetCarNumbers(RwInt32 lnNumPlayerCars, RwInt32 lnNumAICars, RwInt32 lnNumNetworkCars, RwInt32 lnNumAdjustedAICars);
    void UpdateSound();
    void RenderRaceCars(EPlayerCarIndex, EPlayerCarIndex);
    void RenderFullScreenPoly(EPlayerCarIndex);
    void RenderCarUnlockEffects();
    void RenderOnePlayer();
    void Render(EPlayerCarIndex);
    void RenderTwoPlayer();
    void RenderFrontEnd(ERaceCarIndex);

private:
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
    CBoAILaneStruct * mpAILaneData;
    CBoAICornerStruct * mpAICornersArray;
    CBoAIDriverStruct mpAIDriversArray;
    CBoAIRungStruct * mpAINodesArray; // TODO: confirm type.
    RwInt32 mnAILaneCount;
    RwInt32 mnAICornerCount;
    RwInt32 mnAIDriverCount;
    CBoSliceStruct * mpSlicesArray;
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
    
    void NetworkCatchupUpdate();
    void PauseForNetworkSync(bool);
    void PauseForStreamSync(bool);
    bool WeArePausedForNetworkOrStreamSync();
    void SetReplayRequestStatus(bool);
    bool GetReplayRequestStatus();
    bool IsReplaying();
    GtID GetTrackID();
    ERaceCarIndex GetNumRaceCars();
    RwInt32 GetNumActiveRaceCars();
    EPlayerCarIndex GetNumPlayerCars();
    EPlayerCarIndex GetNumAICars();
    EPlayerCarIndex GetNumNetworkCars();
    RwInt32 GetNumAdjustedAICars();
    void DecrementNumAdjustedAICars();
    RwInt32 GetLeadingAdjustedAICar();
    void IncrementLeadingAdjustedAICar();
    void DecrementLeadingAdjustedAICar();
    void SetNumLeadingCars(int);
    CBoPlayerCar * GetPlayerCar(EPlayerCarIndex);
    CBoAICar * GetAICar(EAICarIndex);
    CBoNetworkCar * GetNetworkCar(ENetworkCarIndex);
    bool IsPointToPoint();
    bool IsMarathon();
    bool IsRightHandDrive();
    CGtV3d GetTrackCentre();
    void GetTrackExtents(CGtV3d *, CGtV3d *);
    void SetNumActiveRaceCars(int);
    void DecrementNumActiveRaceCars();
    bool IsCrashIntro() const;
    void SetCrashIntro(bool);
    bool IsCrashAftermath() const;
    void SetCrashAftermath(bool);
    RwReal GetTimeBeforeAutomaticTimeout();
    RwInt32 GetInitialWorldFrame();
    RwInt32 GetMaxRaceCarStreams() const;
    bool IsMultiPlayer();
    bool IsSinglePlayer();

};

extern CBoWorld gWorld;