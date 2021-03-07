#ifndef BOTURNBASEDCRASHCHALLENGE_H
#define BOTURNBASEDCRASHCHALLENGE_H

#include "BoChallenge.h"

class CBoTurnBasedCrashChallenge : CBoChallenge {
public:
	void Construct();
};

class CBoTurnBasedCrashParty : CBoTurnBasedCrashChallenge {
public:
	void Construct();
};

class CBoTurnBasedCrashTour : CBoTurnBasedCrashChallenge {
public:
	void Construct();
};

#endif // !#define BOTURNBASEDCRASHCHALLENGE_H
