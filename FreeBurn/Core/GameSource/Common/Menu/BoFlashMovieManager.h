#include <rwcore.h>

enum class EBoFlashMode {
	Inactive = 0,
	WhiteOut = 1,
	Polaroid = 2,
	Revenge = 3
};

enum class EFlashMovie {
	LanguageSelect = 0,
	MainMenu = 1,
	MainMenuInGame = 2,
	Test = 3,
	Legal = 4,
	Logo1 = 5,
	Logo2 = 6,
	AttractScreen = 7,
	TitleScreen = 8,
	CitySelect = 9,
	LocationSelect = 10,
	CarSelect = 11,
	TakedownBook = 12,
	ChallengeSheet = 13,
	CrashVideo = 14,
	TrafficVideo = 15,
	DriverDetailsMenu = 16,
	DriverDetailsStats = 17,
	DriverDetailsRecords = 18,
	DriverDetailsSettings = 19,
	DriverDetailsEATrax = 20,
	DriverDetailsExtras = 21,
	ProfileSettingsScreen = 22,
	PostRace = 23,
	PostEventStatistics = 24,
	SplashScreen = 25,
	MPSplashScreen = 26,
	Pause = 27,
	PauseOptions = 28,
	OnlinePause = 29,
	InGameOnlinePostEvent = 30,
	RevengeResults = 31,
	GPAwards = 32,
	GPStandings = 33,
	GPMenu = 34,
	InGameCrashCarSelect = 35,
	CrashTourScore = 36,
	CrashTourResults = 37,
	OnlinePartyRoom = 38,
	OnlinePartyRoomNonHost = 39,
	OnlineMatchMaking = 40,
	OnlineNews = 41,
	OnlinePlayListCategory = 42,
	OnlinePlayListSelect = 43,
	OnlineCustomGame = 44,
	OnlineCustomGameRoom = 45,
	OnlineCustomGameRoomNonHost = 46,
	OnlineOptions = 47,
	OnlineOptimatchSettings = 48,
	OnlineGameOptions = 49,
	OnlineCreateSettings = 50,
	OnlineGamesList = 51,
	OnlineRecords = 52,
	OnlineRecordsSelect = 53,
	OnlineTrackSelect = 54,
	OnlineResults = 55,
	Message = 56,
	DemoMarketingScreen = 57,
	Multiplayer = 58,
	MPRaceOptions = 59,
	MPRoadRageOptions = 60,
	MPTrafficAttackOptions = 61,
	MPCrashBattleOptions = 62,
	MPCrashPartyOptions = 63,
	MPCrashTourOptions = 64,
	MPCrashPartyRounds = 65,
	MPCrashTourRounds = 66,
	MPPostSplitScreen = 67,
	MPPostPartyRound = 68,
	MPPostPartyEvent = 69,
	MPPostTourRound = 70,
	MPPostTourEvent = 71,
	PreviewEvent = 72,
	RankUp = 73,
	CarUnlock = 74,
	SigTakedown = 75,
	ChallengeComplete = 76,
	Video = 77,
	LoadingQuick = 78,
	OnlineOpenInterface = 79,
	OnlineConnectingPersona = 80,
	Num = 81
};

class CBoFlashManager {
public:
	RwReal mrFlashTime;
	RwReal mrFlashLength;
	EBoFlashMode meMode;

	void Construct();
};

class CBoFlashMovieManager {
public:
	void Construct();
	void Destruct();
	void PlayMovie(EFlashMovie leFlashMovie, bool lbPlayThroughMain);
	void Release();
};

extern CBoFlashMovieManager gFlashMovieManager;