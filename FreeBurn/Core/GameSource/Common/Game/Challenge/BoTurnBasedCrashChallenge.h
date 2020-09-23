#include "BoChallenge.h"

class CBoTurnBasedCrashChallenge : CBoChallenge {

};

class CBoTurnBasedCrashParty : CBoTurnBasedCrashChallenge {
public:
	void Construct();
};

class CBoTurnBasedCrashTour : CBoTurnBasedCrashChallenge {
public:
	void Construct();
};