#ifndef BOSTAGELOGIC_H
#define BOSTAGELOGIC_H

#include "../../../World/Common/BoRaceCar.h"
#include "../../../World/Common/BoPlayerCar.h"

enum class EAIMode {
	eAIModeNormal = 0,
	eAIModeRoadRage = 1,
	eAIModeCount = 2
};

enum class EHUDType {
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

enum class ERacePositionType {
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

enum class EResultsPageType {
	eResultsPageCrash = 0, 
	eResultsPageRace = 1, 
	eResultsPageBurningLap = 2, 
	eResultsPageRoadRage = 3, 
	eResultsPageLapEliminator = 4, 
	eResultsPageRevenge = 5, 
	eResultsPageCount = 6
};

enum class EResultsMenuType {
	eResultsMenuRace = 0,
	eResultsMenuRoadRage = 1,
	eResultsMenu2PRace = 2,
	eResultsMenuCrash = 3,
	eResultsMenuCrashParty = 4,
	eResultsMenuCrashBattle = 5,
	eResultsMenuCrashCoop = 6,
	eResultsMenuCount = 7
};

enum class ERevengeState {
	eRevengeState1 = 0, 
	eRevengeState2 = 1, 
	eRevengeState3 = 2, 
	eRevengeStateCount = 3
};

enum class EBurnoutPointsType {
	eBurnoutPointsTypeRevenge = 0, 
	eBurnoutPointsTypeAggressiveDriving = 1, 
	eBurnoutPointsTypeDrivingSkills = 2, 
	eBurnoutPointsTypeDestruction = 3, 
	eBurnoutPointsTypeNum = 4
};

enum class EIntroMessage {
	eIntroMessage_PressStartToSkip = 0,
	eIntroMessage_PressToSelect = 1,
	eIntroMessage_PressToBegin = 2,
	eIntroMessage_Num = 3
};

enum class EChallengeInfoType {
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
	
enum class EStageLogicSplashScreenStage {
	eStageLogicSplashStart = 0, 
	eStageLogicSplashDoCall = 1, 
	eStageLogicSplashWait = 2, 
	eStageLogicSplashDone = 3
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

using namespace GtMathPS2;

class CBoStageLogic {
public:
	void AddBurnoutPoints(EPlayerCarIndex, ERaceCarIndex, int, int, EBurnoutPointsType);
	void CheckForResendResults();
	void Construct();
	bool CrashShouldBeClearedUp(unsigned char);
	void Destruct();
	bool DisplayCrashWindHUD(EPlayerCarIndex);
	bool EventSummaryAptCall(const char *, const char *, unsigned const short *, unsigned const short *, unsigned const short *, bool);
	void FillOutResultsStructureForRaceCar(CBoRaceCar *);
	void FinaliseResultsStructures();
	EAIMode GetAIMode();
	RwInt32 GetBurnPickup(ETrafficVehicleCategories);
	EChallengeInfoType GetChallengeInfoType();
	RwInt32 GetCheckpointMarkerFlags();
	EIntroMessage GetCurrentIntroMessage();
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
	RwInt32 GetRacePosition(CBoRaceCar *);
	ERacePositionType GetRacePositionType();
	RwReal GetResultsCountdown();
	GtUTF16 * GetResultsPageString();
	EResultsPageType GetResultsPageType();
	RwInt32 GetRevengePoints(EPlayerCarIndex);
	ERevengeState GetRevengeState(EPlayerCarIndex, ERaceCarIndex); const
	RwInt32 GetScoreModeFlags();
	RwReal GetTimeRemaining();
	bool IsGameCountingDownToForcedExit();
	bool IsGameOver();
	bool IsIntroPlaying();
	bool IsUsingTakedownCamera(int);
	void MenuExit(bool);
	bool OfferEndSessionRatherThanQuit();
	void OnBurnoutLap(EPlayerCarIndex);
	void OnChallengeInfoFinish();
	void OnCheckedTraffic(CBoCheckedTrafficPhysics *, CBoTrafficVehicle *, ERaceCarIndex);
	void OnCheckedTrafficBonus(EPlayerCarIndex, CBoScoreCategory *);
	void OnCheckedTrafficSwerve(CBoCheckedTrafficPhysics *, float);
	void OnCheckpoint(CBoRaceCar *);
	void OnComeIntoRangeOfCrashbreaker(EPlayerCarIndex, CGtV3d);
	void OnCrashbreaker(EPlayerCarIndex, ECrashbreakerPower);
	void OnCrashComboItem(EComboEntryType);
	void OnCrashEscape(EPlayerCarIndex, unsigned char);
	void OnCrashingVehicleExploded(CBoVehiclePhysics *);
	void OnCrashStart(CBoVehiclePhysics *, CBoCrashStartInfo *);
	void OnDetectedAerialTakeDown(CBoRaceCar *, CBoRaceCar *);
	void OnDetectedTBoneTakeDown(CBoRaceCar *, CBoRaceCar *);
	void OnGoneOutOfRangeOfCrashbreaker(EPlayerCarIndex);
	void OnGrinding(EPlayerCarIndex, CBoRaceCar *, CBoScoreCategory *);
	void OnHostMigration(int, int);
	void OnInitialVehicleImpact(CBoVehiclePhysics *, CBoRaceCarPhysics *);
	void OnIntroCameraFinished();
	void OnIntroFinish();
	void OnLargeVehicleImpact(CBoVehiclePhysics *, bool);
	void OnLastCutOfTakedownSequence();
	void OnLeaveLobby();
	void OnMedalAwarded(EBoScoreMedalType, EPlayerCarIndex);
	void OnMovingAwayFromCrashbreaker(EPlayerCarIndex);
	void OnNewBestRacePosition(EPlayerCarIndex, int);
	void OnNonFatalTrafficCollision(CBoRaceCarPhysics *, CBoTrafficVehicle *);
	void OnPause();
	void OnPayloadReleased(CBoVehiclePhysics *);
	void OnPerfectLap(EPlayerCarIndex);
	void OnPickupPickedUp(ECrashModePickupType, EPlayerCarIndex);
	void OnPreCrashbreakerFinish(EPlayerCarIndex, ECrashbreakerPower);
	void OnPreCrashbreakerStart(EPlayerCarIndex, ECrashbreakerPower);
	void OnPreCrashReset(CBoRaceCarPhysics *);
	void OnRaceCarFinish(CBoRaceCar *, EBoScoreFinishState);
	void OnRaceCarRaceCarCollision(CBoRaceCarPhysics *, CBoRaceCarPhysics *);
	void OnRaceCarStartNewLap(CBoRaceCar *);
	void OnResultArrived(CBoNetworkPlayer *);
	void OnResume();
	void OnRetry();
	void OnRub(EPlayerCarIndex, CBoRaceCar *, CBoScoreCategory *);
	void OnSlam(CBoRaceCar *, CBoRaceCar *, EBoScoreSlamType, bool);
	void OnSplashScreenFinished();
	void OnStartBoosting();
	void OnStopBoosting();
	void OnTailgating(EPlayerCarIndex, CBoRaceCar *, CBoScoreCategory *);
	void OnTakedownDenied(EPlayerCarIndex);
	void OnTakedownFinish(CBoRaceCar *, CBoRaceCar *);
	void OnTakedownSequenceFinished();
	void OnTakedownStart(CBoRaceCar *, CBoRaceCar *, CBoCrashStartInfo *, ETakedownType);
	void OnTimeExtension(EPlayerCarIndex);
	void OnTimeout();
	void OnTradePaint(EPlayerCarIndex, CBoRaceCar *, bool);
	void OnTrafficCarCrash(CBoTrafficPhysics *, CBoTrafficVehicle *, ERaceCarIndex, bool);
	void OnWorldPrepared();
	void OnYouWereLucky(EPlayerCarIndex, CBoRaceCar *);
	bool Prepare();
	void PrepareRacing();
	void PrepareSyncTimeClient();
	void PrepareWaitInitCountdownHost();
	void PrepareWaitWhileResultsAreDisplayed(int);
	bool ReceivedAllResults();
	void RegisterStaticVariables();
	void Release();
	void Render(EStageLogicRenderType); const
	bool RunEventSummary(const char *, const char *, unsigned const short *, unsigned const short *, unsigned const short *, bool, bool);
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

private:
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

	bool CanAdjustCameras();
	bool DoneEventSummary();
	CBoCrashModeWind* GetCrashWind(ERaceCarIndex);
	RwInt32 GetCurrentScore(int); const
	GetRoadRageRevengeState(EPlayerCarIndex);
	CBoTakedownManager GetTakedownManager(EPlayerCarIndex);
	bool HasStageFinished();
	bool IsInCrashBoostStartState();
	bool IsInDetourZone();
	void OnAir(CBoScoreCategory*, EPlayerCarIndex);
	void OnBoostStart(EPlayerCarIndex);
	void OnDrift(CBoScoreCategory*, EPlayerCarIndex);
	void OnNearMiss(CBoScoreCategory*, EPlayerCarIndex);
	void OnOncoming(CBoScoreCategory*, EPlayerCarIndex);
	void OnPostCrashReset(CBoRaceCarPhysics*);
	void OnPropHit(EPlayerCarIndex, bool, const CBoPropType*, float, CGtV3d);
	void OnRaceCarCrash(CBoRaceCarPhysics*, CBoCrashStartInfo*);
	void PrepareStartPositions();
	void SetCurrentScore(int, int, int);
	bool UseTakedownCamera(CBoRaceCar*, CBoRaceCar*, ETakedownType);
	void OnPlayerResultsFailedToSend(int);
};

#endif // !BOSTAGELOGIC_H