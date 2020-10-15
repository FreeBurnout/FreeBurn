#include <rwcore.h>

class CBoBurn {
public:
	RwReal gmrMinimumBoostTime = 1.0;
	RwReal gmrMinimumBoostRecoveryTime = 0.5;
	RwReal gmrPowerBoostDepletionMultiplier = 1.4;
	RwReal gmarBoostBarSizes[4] = {
		100.0, 200.0, 300.0, 400.0
	};
	RwReal gmarBurnoutBoostMultipliers[4] = {
		1.0, 2.0, 3.0, 4.0
	};
	RwReal gmarBoostRate[4] = {
		10.0, 10.0, 10.0, 10.0
	};
};