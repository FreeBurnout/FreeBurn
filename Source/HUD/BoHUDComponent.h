#include <rwcore.h>

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

private:
    GetScene();
    GetOutlineDropShadow(CBoHUDComponent, EOutlineDropShadow);
    GetHUDTexture();
    GetBoostFireCoreTexture();
    GetBoostFireEdgeTexture();
    GetBoostFireOverTexture();
    GetBoostBitsTexture();
    GetBoostBlueFlameTexture();
    GetHUDTexture(CBoHUDComponent, EHUDTexture);
    RwInt32 GetFlags();
    GetAlign();
    GetBoostStarsTexture();
    GetHUDString(EBoHUDString leHUDString);
    GetPlayerCarIndex();
};