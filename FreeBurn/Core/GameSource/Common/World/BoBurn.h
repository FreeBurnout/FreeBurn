#include <rwcore.h>

enum class EBoShockwaveType {
	Race0 = 0,
	Race1 = 1,
	Race2 = 2,
	Race3 = 3,
	Crash0 = 4,
	Crash1 = 5,
	Crash2 = 6,
	Crash3 = 7,
	Crash4 = 8,
	Crash5 = 9,
	Num = 10
};

class CBoBurn {
public:
	static RwReal gmrMinimumBoostTime;
	static RwReal gmrMinimumBoostRecoveryTime;
	static RwReal gmrPowerBoostDepletionMultiplier;
	static RwReal gmarBoostBarSizes[4];
	static RwReal gmarBurnoutBoostMultipliers[4];
	static RwReal gmarBoostRate[4];

	static void RegisterStaticVariables();
	static void UnregisterStaticVariables();
	static void SetNumExtraBoostBarSegments(RwInt32 lnNumSegments);
	static void AddSegment();
	static void RemoveSegment();
	EBoShockwaveType CalcCrashbreakerType();

private:
	static RwInt32 mnNumExtraSegments;
	static RwReal mrCurrentBoost;
	static RwReal mrMaxBoost;
	static RwReal mrBoostRate;
	static RwReal mrBoostMultiplier;
	static RwReal mrMinimumBoostUsed;
};