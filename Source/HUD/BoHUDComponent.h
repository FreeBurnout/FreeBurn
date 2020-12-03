#include <rwcore.h>

#include "BoHUDManager.h"
#include "../World/Common/BoPlayerCar.h"
#include "../../Shared/Graphical/Common/2D/Gt2dScene.h"
#include "../../Shared/Graphical/PC/GtTexturePC.h"
#include "../../Shared/Graphical/Common/2D/Gt2dObject.h"
#include "../../Shared/System/Common/Unicode/GtUnicode.h"

enum EBoHUDString {
	eBoHUDStringSplitTime = 0,
	eBoHUDStringDRIFT = 1,
	eBoHUDStringONCOMING = 2,
	eBoHUDStringNEARMISS = 3,
	eBoHUDStringAIR = 4,
	eBoHUDStringTAILGATING = 5,
	eBoHUDStringGRINDING = 6,
	eBoHUDStringRUBBING = 7,
	eBoHUDStringCHECKEDTRAFFIC = 8,
	eBoHUDStringIMPACTTIME = 9,
	eBoHUDStringAFTERTOUCH = 10,
	eBoHUDStringPOS = 11,
	eBoHUDStringLAP = 12,
	eBoHUDStringKPH = 13,
	eBoHUDStringMPH = 14,
	eBoHUDStringTIME = 15,
	eBoHUDStringBoostBarSegments = 16,
	eBoHUDStringTrafficAttackWarning = 17,
	eBoHUDStringEventStartGetReady = 18,
	eBoHUDStringEventStartGo = 19,
	eBoHUDStringCrashBreaker = 20,
	eBoHUDStringTimeBonusTitle = 21,
	eBoHUDStringTimeBonusValue = 22,
	eBoHUDStringGoldAt = 23,
	eBoHUDStringSilverAt = 24,
	eBoHUDStringBronzeAt = 25,
	eBoHUDStringTakedowns = 26,
	eBoHUDStringBoostPromptPart1 = 27,
	eBoHUDStringBoostPromptPart2 = 28,
	eBoHUDStringSecondsCountdownFormat = 29,
	eBoHUDStringRoadrageTripleScoring = 30,
	eBoHUDStringRacersEscapingPrompt = 31,
	eBoHUDStringRacersBehindYouPrompt = 32,
	eBoHUDStringRacerDistToFinish = 33,
	eBoHUDStringCheckTrafficToScore = 34,
	eBoHUDStringSheetChallengeCompleted = 35,
	eBoHUDStringRoadRage1TakedownToGold = 36,
	eBoHUDStringRoadRageTakedownsToGold = 37,
	eBoHUDStringRoadRage1TakedownToSilver = 38,
	eBoHUDStringRoadRageTakedownsToSilver = 39,
	eBoHUDStringRoadRage1TakedownToBronze = 40,
	eBoHUDStringRoadRageTakedownsToBronze = 41,
	eBoHUDStringRoadRage1WaveToGold = 42,
	eBoHUDStringRoadRageWavesToGold = 43,
	eBoHUDStringRoadRage1WaveToSilver = 44,
	eBoHUDStringRoadRageWavesToSilver = 45,
	eBoHUDStringRoadRage1WaveToBronze = 46,
	eBoHUDStringRoadRageWavesToBronze = 47,
	eBoHUDStringRoadRageCurrentWave = 48,
	eBoHUDStringRoadRageTimeExtendedAt1Takedown = 49,
	eBoHUDStringRoadRageTimeExtendedAtNTakedowns = 50,
	eBoHUDStringSplitTimeSecondsBehind = 51,
	eBoHUDStringSplitTimeSecondBehind = 52,
	eBoHUDStringSplitTimeSecondsAhead = 53,
	eBoHUDStringSplitTimeSecondAhead = 54,
	eBoHUDStringOnlineCableDisconnect = 55,
	eBoHUDStringHitCount = 56,
	eBoHUDStringPressButtonToStartPart1 = 57,
	eBoHUDStringPressButtonToStartPart2 = 58,
	eBoHUDStringWindTitle = 59,
	eBoHUDStringRatingTitle = 60,
	eBoHUDStringRating1 = 61,
	eBoHUDStringRating2 = 62,
	eBoHUDStringRating3 = 63,
	eBoHUDStringRating4 = 64,
	eBoHUDStringCrashTourParTitle = 65,
	eBoHUDStringCrashTourTurnTitle = 66,
	eBoHUDStringCrashTourTargetTitle = 67,
	eBoHUDStringRoadRageRedTeam = 68,
	eBoHUDStringRoadRageBlueTeam = 69,
	eBoHUDStringRoadRageEliminated = 70,
	eBoHUDStringRoadRageTargetTitleGold = 71,
	eBoHUDStringRoadRageTargetTitleSilver = 72,
	eBoHUDStringRoadRageTargetTitleBronze = 73,
	eBoHUDStringNum = 74
};

enum EOutlineDropShadow {
	eODSSmallText = 0,
	eODSMediumText = 1,
	eODSLargeText = 2,
	eODSNum = 3
};

enum EHUDTexture {
	eHUDTextureSignAgressiveNeg = 0,
	eHUDTextureSignAgressivePos = 1,
	eHUDTextureSignTakeDownNeg = 2,
	eHUDTextureSignTakeDownPos = 3,
	eHUDTextureSignRatingDown = 4,
	eHUDTextureSignRatingUp = 5,
	eHUDTextureSignCrash = 6,
	eHUDTextureSignCrashBreaker = 7,
	eHUDTextureHeartbreaker = 8,
	eHUDTextureSmallScore = 9,
	eHUDTextureMediumScore = 10,
	eHUDTextureLargeScore = 11,
	eHUDTextureImpactTimeDPad = 12,
	eHUDTextureImpactTimeStick = 13,
	eHUDTextureImpactController = 14,
	eHUDTextureSmallPanelTile = 15,
	eHUDTextureSmallPanelChevron = 16,
	eHUDTextureBorderRoad = 17,
	eHUDTextureBorderChevron = 18,
	eHUDTextureMessageBoxEnd = 19,
	eHUDTextureMessageBoxTile = 20,
	eHUDTextureGoldMedal = 21,
	eHUDTextureSilverMedal = 22,
	eHUDTextureBronzeMedal = 23,
	eHUDTextureTrafficAttackBGEnd = 24,
	eHUDTextureTrafficAttackBGTile = 25,
	eHUDTextureTrafficAttackFuseGlow = 26,
	eHUDTextureTrafficAttackFuseTile = 27,
	eHUDTextureMessageStar = 28,
	eHUDTextureMessageStarCorona = 29,
	eHUDTextureBoostGlowBits = 30,
	eHUDTextureCrashBar = 31,
	eHUDTextureTalkIcon = 32,
	eHUDTextureCrossIcon = 33,
	eHUDTextureStarEmpty = 34,
	eHUDTextureStarFull = 35,
	eHUDTextureButtonL1 = 36,
	eHUDTextureButtonL2 = 37,
	eHUDTextureButtonR1 = 38,
	eHUDTextureButtonR2 = 39,
	eHUDTextureButtonCross = 40,
	eHUDTextureNum = 41,
	eHUDTextureButtonBoost = 38,
	eHUDTextureButtonAftertouch = 38,
	eHUDTextureButtonCrashbreaker = 39,
	eHUDTextureButtonCrashBar = 40,
	eHUDTextureButtonConfirm = 40,
	eHUDTextureBad = 6,
	eHUDTextureAwardPositive = 6,
	eHUDTextureAwardNegative = 6,
	eHUDTextureAwardStar = 6,
	eHUDTextureAwardTakedown = 6,
	eHUDTextureBoost = 6,
	eHUDTextureSmallMultiplier = 6,
	eHUDTextureLargeMultiplier = 6,
	eHUDTextureCrashbreaker = 6,
	eHUDTextureScoreStealer = 6,
	eHUDTextureSignTimeBonus = 6
};

struct BoHUDParticleParamsTag {

};

class CBoHUDComponent {
public:
    void Construct();
    bool Prepare();
    void Update();
    void Construct(CBoHUDManager *);
    bool Prepare(int, int, int, EPlayerCarIndex, EHUDAlign, int);
    void UpdateTransition(float, bool, EHUDMode, EHUDMode);
    void SetAllLayerVisible(bool);
    void StartTransition(bool, EHUDMode, EHUDMode);
    void AdjustScalingForSplitScreen();
	void UseClipFrame();
	CGt2dScene* GetScene();

	COutlineDropShadow* GetOutlineDropShadow(CBoHUDComponent, EOutlineDropShadow);
	CGtTexture* GetHUDTexture();
    CGtTexture* GetBoostFireCoreTexture();
    CGtTexture* GetBoostFireEdgeTexture();
    CGtTexture* GetBoostFireOverTexture();
    CGtTexture* GetBoostBitsTexture();
    CGtTexture* GetBoostBlueFlameTexture();
	CGtTexture* GetHUDTexture(CBoHUDComponent, EHUDTexture);
    RwInt32 GetFlags();
	EHUDAlign GetAlign();
	CGtTexture* GetBoostStarsTexture();
	GtUTF16* GetHUDString(EBoHUDString leHUDString);
    EPlayerCarIndex GetPlayerCarIndex();
};