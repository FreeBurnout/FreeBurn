#ifndef BOSTAGELOGIC_H
#define BOSTAGELOGIC_H

#include "BoTakedownManager.h"
#include "../Persistence/BoProfileProgression.h"
#include "../../../World/Common/BoRaceCar.h"
#include "../../../World/Common/BoPlayerCar.h"
#include "../../../World/Common/BoOffensiveDrivingManager.h"
#include "../../../Shared/System/Common/Unicode/GtUnicode.h"
#include "../../../Physics/BoCheckedTrafficPhysics.h"
#include "../../../World/Common/Traffic/BoTrafficVehicle.h"
#include "../../../Physics/BoVehiclePhysics.h"
#include "../../../Physics/BoRaceCarPhysics.h"
#include "../../../Physics/BoTrafficPhysics.h"
#include "../../../World/Common/BoPropType.h"
#include "../../../Network/Common/BoNetworkPlayer.h"
#include "../../../World/Common/BoCrashCombo.h"

enum EAIMode {
    eAIModeNormal = 0,
    eAIModeRoadRage = 1,
    eAIModeCount = 2
};
enum EBurnoutPointsType {
    eBurnoutPointsTypeRevenge = 0,
    eBurnoutPointsTypeAggressiveDriving = 1,
    eBurnoutPointsTypeDrivingSkills = 2,
    eBurnoutPointsTypeDestruction = 3,
    eBurnoutPointsTypeNum = 4
};
enum EChallengeInfoType {
    eChallengeInfoChampionshipRace = 0,
    eChallengeInfoChampionshipBurningLap = 1,
    eChallengeInfoChampionshipRoadRage = 2,
    eChallengeInfoChampionshipFaceOff = 3,
    eChallengeInfoChampionshipEliminator = 4,
    eChallengeInfoChampionshipGrandPrix = 5,
    eChallengeInfoChampionshipCrash = 6,
    eChallengeInfoChampionshipRevenge = 7,
    eChallengeInfoSingleRace = 8,
    eChallengeInfoSingleTimeAttack = 9,
    eChallengeInfoSingleRoadRage = 10,
    eChallengeInfoSingleCrash = 11,
    eChallengeInfoMultiRace = 12,
    eChallengeInfoMultiRoadRage = 13,
    eChallengeInfoMultiTeamCrush = 14,
    eChallengeInfoMultiDoubleImpact = 15,
    eChallengeInfoMultiPartyCrash = 16,
    eChallengeInfoOnlineRace = 17,
    eChallengeInfoOnlineRoadRage = 18,
    eChallengeInfoOnlineTeamCrush = 19,
    eChallengeInfoOnlineDoubleImpact = 20,
    eChallengeInfoOnlinePartyCrash = 21,
    eChallengeInfoCount = 22
};
enum EChallengeMedal {
    eEventMedalNeverRaced = -1,
    eEventMedalNone = 0,
    eEventMedalBronze = 1,
    eEventMedalSilver = 2,
    eEventMedalGold = 3,
    eEventMedalNumber = 4
};
enum ECrashbreakerPower {
    eCrashbreakerPowerHalf = 0,
    eCrashbreakerPowerFull = 1,
    eCrashbreakerPowerDouble = 2,
    eCrashbreakerPowerPickup = 3,
    eCrashbreakerPowerCount = 4
};
enum ECrashModePickupType {
    eCrashModePickupBoost = 0,
    eCrashModePickupScoreSmall = 1,
    eCrashModePickupScoreMedium = 2,
    eCrashModePickupScoreLarge = 3,
    eCrashModePickupNegativeMultiplier = 4,
    eCrashModePickupMultiplierSmall = 5,
    eCrashModePickupMultiplierLarge = 6,
    eCrashModePickupCrashbreaker = 7,
    eCrashModePickupScoreStealer = 8,
    eCrashModePickupBoostSegment = 9,
    eCrashModePickupNumber = 10
};
enum EFrameRateModifier {
    eFrameRateNormal = 0,
    eFrameRateHalf = 1,
    eFrameRateCount = 2
};
enum EHUDType {
    eHUDTypeNone = 0,
    eHUDTypeRace = 1,
    eHUDTypeRace2P = 2,
    eHUDTypeBurningLap = 3,
    eHUDTypeTimeAttack = 4,
    eHUDTypeLapEliminator = 5,
    eHUDTypeRoadRage = 6,
    eHUDTypeRoadRage2P = 7,
    eHUDTypeTrafficAttack = 8,
    eHUDTypeCrash = 9,
    eHUDTypeCount = 10
};
enum EIntroMessage {
    eIntroMessage_PressStartToSkip = 0,
    eIntroMessage_PressToSelect = 1,
    eIntroMessage_PressToBegin = 2,
    eIntroMessage_Num = 3
};
enum ERacePositionType {
    eRacePositionTypeNone = 0,
    eRacePositionTypeNormal = 1,
    eRacePositionTypeRace = 2,
    eRacePositionTypeBattle = 3,
    eRacePositionTypeOnlineRace = 4,
    eRacePositionTypeOnlineRoadRage = 5,
    eRacePositionTypeOnlineRevenge = 6,
    eRacePositionTypeTargetVehicle = 7,
    eRacePositionTypeCount = 8
};
enum EResultsPageType {
    eResultsPageCrash = 0,
    eResultsPageRace = 1,
    eResultsPageBurningLap = 2,
    eResultsPageRoadRage = 3,
    eResultsPageLapEliminator = 4,
    eResultsPageRevenge = 5,
    eResultsPageCount = 6
};
enum EResultsMenuType {
    eResultsMenuRace = 0,
    eResultsMenuRoadRage = 1,
    eResultsMenu2PRace = 2,
    eResultsMenuCrash = 3,
    eResultsMenuCrashParty = 4,
    eResultsMenuCrashBattle = 5,
    eResultsMenuCrashCoop = 6,
    eResultsMenuCount = 7
};
enum ERevengeState {
    eRevengeState1 = 0,
    eRevengeState2 = 1,
    eRevengeState3 = 2,
    eRevengeStateCount = 3
};
enum ERoadRageRevengeState {
    eRoadRageRevengeStateNone = 0,
    eRoadRageRevengeStateR = 1,
    eRoadRageRevengeStateE = 2,
    eRoadRageRevengeStateV = 3,
    eRoadRageRevengeState2ndE = 4,
    eRoadRageRevengeStateN = 5,
    eRoadRageRevengeStateG = 6,
    eRoadRageRevengeState3rdE = 7,
    eRoadRageRevengeStateCount = 8
};
enum ESoundBankType {
    eSoundBankSingle = 0,
    eSoundBankRoadRage = 1,
    eSoundBankCrash = 2,
    eSoundBankEliminator = 3,
    eSoundBankRevenge = 4,
    eSoundBankCount = 5
};
enum EStageLogicRenderType {
    eStageLogicRenderTypeFullScreen = 0,
    eStageLogicRenderTypeCount = 1
};
enum EStageLogicSplashScreenStage {
    eStageLogicSplashStart = 0,
    eStageLogicSplashDoCall = 1,
    eStageLogicSplashWait = 2,
    eStageLogicSplashDone = 3
};
enum ETakedownType {
    eTakedownTypeNormal = 0,
    eTakedownTypePsycheOut = 1,
    eTakedownTypeCheckedTraffic = 2,
    eTakedownTypeAfterTouch = 3,
    eTakedownTypeCrashBreaker = 4,
    eTakedownTypeSignature = 5,
    eTakedownTypeAerial = 6,
    eTakedownTypeTBone = 7,
    eTakedownTypeCount = 8
};
enum ETrafficVehicleCategories {
    eVehicleCategoryNull = 0,
    eVehicleCategoryCar = 1,
    eVehicleCategoryVan = 2,
    eVehicleCategoryLorry = 3,
    eVehicleCategoryArticulatedCab = 4,
    eVehicleCategoryBus = 5,
    eVehicleCategorySpecialHelicopter = 6,
    eVehicleCategorySpecialLTrain = 7,
    eVehicleCategorySpecialTram = 8,
    eVehicleCategorySpecialMonoRail = 9,
    eVehicleCategorySpecialPlane = 10,
    eVehicleCategoryArticulatedTrailer = 11,
    eVehicleCategoriesNumber = 12
};
enum EBoScoreMedalType {
    eScoreMedalBronze = 0,
    eScoreMedalSilver = 1,
    eScoreMedalGold = 2,
    eScoreMedalCount = 3,
    eScoreMedalNone = 4,
    eScoreMedalFirst = 0,
    eScoreMedalLast = 2
};

class CBoCrashModeWind {

};

class CBoStageLogicGameParams {
    RwReal mrAwardedBurnValueScaling;
    RwReal mrAwardedRatingValueScaling;
    RwReal mrMinimumFatalTrafficImpact;
    RwReal mrTimeToDelayBeforeShowingResultsPage;
    EFrameRateModifier meFrameRateModifier;
    ESoundBankType meSoundBankType;
    EResultsMenuType meResultsMenuType;
    RwReal mrAftertouchForceFactor;
    RwReal mrAftertouchRollFactor;
    RwReal mrInAirAftertouchForceFactor;
    RwReal mrInAirAftertouchRollFactor;
    RwReal mrCrashStartOnlineTimeout;
    bool mbAllowProps;
    bool mbWantRollingStart;
    bool mbEnableAftermath;
    bool mbAllowPlayerControlledCamera;
    bool mbAllowAftertouch;
    bool mbAllowCrashbreaker;
    bool mbRaceCarPicksUpCrashIndex;
    bool mbCarsBecomeFragileAfterBeingSlammed;
    bool mbAllowSlowMo;
    bool mbDoAfterTouchWithoutSlowMo;
    bool mbRaceCarsHaveCrashingPartsWhenDriving;
    bool mbDoSlowMoInAir;
    bool mbSlowMoOnlyForPlayerPlayerCollisions;
    bool mbPickupsAreEasierToGet;
    bool mbCrashBattleScoring;
    bool mbAudioFadesOutInOutro;
    bool mbAudioBlipsOnTimer;
    bool mbAudioOnNetworkPlayersJoinOrLeave;
    bool mbAudioOnExtraTakedowns;
    bool mbDisplayTeamName;
    bool mbOnlineRevenge;
    bool mbNetworkClientQuitEndsGame;
    bool mbSlamsAreSuperStrength;
    bool mbDisplayCheckTrafficPrompt;
    bool mbDisplayPressR1ToBoostPrompt;
    bool mbDisplayOnlineRoadRagePrompts;
    bool mbSendHealth;
    bool mbSendScoreSeparately;
    bool mbIsRoadRage;
    bool mbSendMoreTrafficOnline;
    bool mbDoCrashCarSelect;
    bool mbAIAllowedToResetOnPatches;
    bool mbDoCrashCountdownStart;
    bool mbDoCrashWaitButtonToStart;
    bool mbRatingUseGoldMedalThreshold;
    ERaceCarIndex meAssignStartPositionIndex[6];
};

using namespace GtMathPC;

class CBoStageLogic {
public:
    bool mbStageFinished;
    bool mbIsInDetourZone;
    bool mabPlayerResultsNeedResending[2];
    CBoStageLogicGameParams mGameParams;
    EIntroMessage meCurrentIntroMessage;
    RwReal mrLaunchTime;
    RwReal mrRaceStartTime;
    RwReal mrResultsDisplayFinishTime;
    CBoTakedownManager maTakedownManagers[2];
    int mganBurnPickupByClass[12];
    bool mbRunEventSummary;
    EStageLogicSplashScreenStage meSplashScreenStage;

    void AddBurnoutPoints(EPlayerCarIndex, ERaceCarIndex, int, int, EBurnoutPointsType);
    bool CanAdjustCameras();
    void CheckForResendResults();
    void Construct();
    bool CrashShouldBeClearedUp(char);
    void Destruct();
    bool DisplayCrashWindHUD(EPlayerCarIndex);
    bool DoneEventSummary();
    bool EventSummaryAptCall(const char*, const char*, unsigned const short*, unsigned const short*, unsigned const short*, bool);
    void FillOutResultsStructureForRaceCar(CBoRaceCar*);
    void FinaliseResultsStructures();
    EAIMode GetAIMode();
    RwInt32 GetBurnPickup(ETrafficVehicleCategories);
    EChallengeInfoType GetChallengeInfoType();
    RwInt32 GetCheckpointMarkerFlags();
    CBoCrashModeWind* GetCrashWind(ERaceCarIndex);
    EIntroMessage GetCurrentIntroMessage();
    RwInt32 GetCurrentScore(int) const;
    RwReal GetFakeProportionOfMaxSpeed(EPlayerCarIndex);
    RwReal GetForcedAcceleration(EPlayerCarIndex);
    bool GetForcedBoost(EPlayerCarIndex);
    RwReal GetForcedSteering(EPlayerCarIndex);
    CBoStageLogicGameParams GetGameControlParams();
    EHUDType GetHUDType();
    RwInt32 GetNumCrashBreakerVehicles();
    RwInt32 GetNumInitialBoostBarSegments();
    RwInt32 GetNumLaps();
    RwInt32 GetNumPlayers();
    RwUInt8 GetPickupTypeToDisplay();
    RwInt32 GetRacePosition(CBoRaceCar*);
    ERacePositionType GetRacePositionType();
    RwReal GetResultsCountdown();
    GtUTF16* GetResultsPageString();
    EResultsPageType GetResultsPageType();
    RwInt32 GetRevengePoints(EPlayerCarIndex);
    ERevengeState GetRevengeState(EPlayerCarIndex, ERaceCarIndex) const;
    ERoadRageRevengeState GetRoadRageRevengeState(EPlayerCarIndex) const;
    RwInt32 GetScoreModeFlags();
    CBoTakedownManager GetTakedownManager(EPlayerCarIndex);
    RwReal GetTimeRemaining();
    bool HasStageFinished();
    bool IsGameCountingDownToForcedExit();
    bool IsGameOver();
    bool IsInCrashBoostStartState();
    bool IsInDetourZone();
    bool IsIntroPlaying();
    bool IsUsingTakedownCamera(int);
    void MenuExit(bool);
    bool OfferEndSessionRatherThanQuit();

#pragma region Events
    virtual void OnAir(CBoScoreCategory*, EPlayerCarIndex);
    virtual void OnBoostStart(EPlayerCarIndex);
    virtual void OnBurnoutLap(EPlayerCarIndex);
    virtual void OnChallengeInfoFinish();
    virtual void OnCheckedTraffic(CBoCheckedTrafficPhysics*, CBoTrafficVehicle*, ERaceCarIndex);
    virtual void OnCheckedTrafficBonus(EPlayerCarIndex, CBoScoreCategory*);
    virtual void OnCheckedTrafficSwerve(CBoCheckedTrafficPhysics*, float);
    virtual void OnCheckpoint(CBoRaceCar*);
    virtual void OnComeIntoRangeOfCrashbreaker(EPlayerCarIndex, CGtV3d);
    virtual void OnCrashbreaker(EPlayerCarIndex, ECrashbreakerPower);
    virtual void OnCrashComboItem(EComboEntryType);
    virtual void OnCrashEscape(EPlayerCarIndex, char);
    virtual void OnCrashingVehicleExploded(CBoVehiclePhysics*);
    virtual void OnCrashStart(CBoVehiclePhysics*, CBoCrashStartInfo*);
    virtual void OnDetectedAerialTakeDown(CBoRaceCar*, CBoRaceCar*);
    virtual void OnDetectedTBoneTakeDown(CBoRaceCar*, CBoRaceCar*);
    virtual void OnDrift(CBoScoreCategory*, EPlayerCarIndex);
    virtual void OnGoneOutOfRangeOfCrashbreaker(EPlayerCarIndex);
    virtual void OnGrinding(EPlayerCarIndex, CBoRaceCar*, CBoScoreCategory*);
    virtual void OnHostMigration(int, int);
    virtual void OnInitialVehicleImpact(CBoVehiclePhysics*, CBoRaceCarPhysics*);
    virtual void OnIntroCameraFinished();
    virtual void OnIntroFinish();
    virtual void OnLargeVehicleImpact(CBoVehiclePhysics*, bool);
    virtual void OnLastCutOfTakedownSequence();
    virtual void OnLeaveLobby();
    virtual void OnMedalAwarded(EBoScoreMedalType, EPlayerCarIndex);
    virtual void OnMovingAwayFromCrashbreaker(EPlayerCarIndex);
    virtual void OnNearMiss(CBoScoreCategory*, EPlayerCarIndex);
    virtual void OnNewBestRacePosition(EPlayerCarIndex, int);
    virtual void OnNonFatalTrafficCollision(CBoRaceCarPhysics*, CBoTrafficVehicle*);
    virtual void OnOncoming(CBoScoreCategory*, EPlayerCarIndex);
    virtual void OnPause();
    virtual void OnPayloadReleased(CBoVehiclePhysics*);
    virtual void OnPerfectLap(EPlayerCarIndex);
    virtual void OnPickupPickedUp(ECrashModePickupType, EPlayerCarIndex);
    virtual void OnPlayerResultsFailedToSend(int);
    virtual void OnPostCrashReset(CBoRaceCarPhysics*);
    virtual void OnPreCrashbreakerFinish(EPlayerCarIndex, ECrashbreakerPower);
    virtual void OnPreCrashbreakerStart(EPlayerCarIndex, ECrashbreakerPower);
    virtual void OnPreCrashReset(CBoRaceCarPhysics*);
    virtual void OnPropHit(EPlayerCarIndex, bool, const CBoPropType*, float, CGtV3d);
    virtual void OnRaceCarCrash(CBoRaceCarPhysics*, CBoCrashStartInfo*);
    virtual void OnRaceCarFinish(CBoRaceCar*, EBoScoreFinishState);
    virtual void OnRaceCarRaceCarCollision(CBoRaceCarPhysics*, CBoRaceCarPhysics*);
    virtual void OnRaceCarStartNewLap(CBoRaceCar*);
    virtual void OnResultArrived(CBoNetworkPlayer*);
    virtual void OnResume();
    virtual void OnRetry();
    virtual void OnRub(EPlayerCarIndex, CBoRaceCar*, CBoScoreCategory*);
    virtual void OnSlam(CBoRaceCar*, CBoRaceCar*, EBoScoreSlamType, bool);
    virtual void OnSplashScreenFinished();
    virtual void OnStartBoosting();
    virtual void OnStopBoosting();
    virtual void OnTailgating(EPlayerCarIndex, CBoRaceCar*, CBoScoreCategory*);
    virtual void OnTakedownDenied(EPlayerCarIndex);
    virtual void OnTakedownFinish(CBoRaceCar*, CBoRaceCar*);
    virtual void OnTakedownSequenceFinished();
    virtual void OnTakedownStart(CBoRaceCar*, CBoRaceCar*, CBoCrashStartInfo*, ETakedownType);
    virtual void OnTimeExtension(EPlayerCarIndex);
    virtual void OnTimeout();
    virtual void OnTradePaint(EPlayerCarIndex, CBoRaceCar*, bool);
    virtual void OnTrafficCarCrash(CBoTrafficPhysics*, CBoTrafficVehicle*, ERaceCarIndex, bool);
    virtual void OnWorldPrepared();
    virtual void OnYouWereLucky(EPlayerCarIndex, CBoRaceCar*);

#pragma endregion

    bool Prepare();
    void PrepareRacing();
    void PrepareStartPositions();
    void PrepareSyncTimeClient();
    void PrepareWaitInitCountdownHost();
    void PrepareWaitWhileResultsAreDisplayed(int);
    bool ReceivedAllResults();
    void RegisterStaticVariables();
    void Release();
    virtual void Render(EStageLogicRenderType); const
    bool RunEventSummary(const char*, const char*, unsigned const short*, unsigned const short*, unsigned const short*, bool, bool);
    void SetCurrentScore(int, int, int);
    void SetUpDefaultGameParams();
    void StartOnlineResultsPage();
    void StartOnlineTime();
    bool StartReplay();
    void StopOnlineTime();
    void TestForPausing();
    void UnRegisterStaticVariables();
    void Update();
    void UpdateCameras();
    void UpdateProfile(EBoProgressionRating, EChallengeMedal);
    bool UpdateRacing();
    bool UpdateSendResults();
    bool UpdateSyncTimeClient(float);
    bool UpdateWaitCountdown();
    bool UpdateWaitInitCountdownClient();
    bool UpdateWaitInitCountdownHost(float, float);
    bool UpdateWaitWhileResultsAreDisplayed();
    bool UseTakedownCamera(CBoRaceCar*, CBoRaceCar*, ETakedownType);
};

#endif // !BOSTAGELOGIC_H