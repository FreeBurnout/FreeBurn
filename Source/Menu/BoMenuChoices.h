#ifndef BOMENUCHOICES_H
#define BOMENUCHOICES_H

enum EBoLoadingScreenTypes {
	eBoLoadingScreenTypeBootup = 0,
	eBoLoadingScreenTypeSimple = 1,
	eBoLoadingScreenTypeTip = 2,
	eBoLoadingScreenTypeReplay = 3,
	eBoLoadingScreenTypeNum = 4
};
enum EBoMenuCarClasses {
	eBoMenuCarClassCompact = 0,
	eBoMenuCarClassMuscle = 1,
	eBoMenuCarClassCoupe = 2,
	eBoMenuCarClassSport = 3,
	eBoMenuCarClassSuper = 4,
	eBoMenuCarClassRaceSpecial = 5,
	eBoMenuCarClassHeavyweight = 6,
	eBoMenuCarClassTraffic = 7,
	eBoMenuCarClassTrafficSpecial = 8,
	eBoMenuCarClassNumber = 9
};
enum EBoRaceCarRank {
	eRaceCarRank0 = 0,
	eRaceCarRank1 = 1,
	eRaceCarRank2 = 2,
	eRaceCarRank3 = 3,
	eRaceCarRank4 = 4,
	eRaceCarRank5 = 5,
	eRaceCarRank6 = 6,
	eRaceCarRank7 = 7,
	eRaceCarRank8 = 8,
	eRaceCarRank9 = 9,
	eRaceCarRankSpecial = 10,
	eRaceCarRankNone = 11,
	eRaceCarRankCount = 12
};

static char kacBoGameModeStringIDs[6][25] = {
	"GameModeRace",
	"GameModeRoadRage",
	"GameModeCrashGolf",
	"GameModeCrashBattle",
	"GameModeCrashParty",
	"GameModeRevenge"
};
static char kacBoGameModeStringIDsWithDollar[6][25] = {
	"$GameModeRace",
	"$GameModeRoadRage",
	"$GameModeCrashGolf",
	"$GameModeCrashBattle",
	"$GameModeCrashParty",
	"$GameModeRevenge"
};
static int kanNumberOfRanksInOneRace[11] = {
	2, 3, 3, 3, 3, 3, 2, 2, 3, 3, 3,
};
static EBoRaceCarRank kaaeRaceCarRanksInOneRace[11][3] = {
	{ eRaceCarRank1,       eRaceCarRank0, eRaceCarRankNone },
	{ eRaceCarRank2,       eRaceCarRank1, eRaceCarRank0    },
	{ eRaceCarRank3,       eRaceCarRank2, eRaceCarRank1    },
	{ eRaceCarRank4,       eRaceCarRank3, eRaceCarRank2    },
	{ eRaceCarRank4,       eRaceCarRank4, eRaceCarRank3    },
	{ eRaceCarRank6,       eRaceCarRank5, eRaceCarRank4    },
	{ eRaceCarRank7,       eRaceCarRank6, eRaceCarRankNone },
	{ eRaceCarRank8,       eRaceCarRank7, eRaceCarRankNone },
	{ eRaceCarRankSpecial, eRaceCarRank9, eRaceCarRank8    },
	{ eRaceCarRankSpecial, eRaceCarRank9, eRaceCarRank8    },
	{ eRaceCarRankSpecial, eRaceCarRank9, eRaceCarRank8    }
};

class CBoMenuChoices {
public:
	static char* maCarClassIDs[9];
	static char* maTrackRegionIDs[3];
	EBoLoadingScreenTypes meBoLoadingScreenType;
};

extern CBoMenuChoices gMenuChoices;

#endif // !#define BOMENUCHOICES_H
