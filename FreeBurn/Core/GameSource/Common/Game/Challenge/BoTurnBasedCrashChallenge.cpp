#include "BoTurnBasedCrashChallenge.h"

void CBoTurnBasedCrashChallenge::Construct() {
	
}

void CBoTurnBasedCrashParty::Construct() {

}

void CBoTurnBasedCrashTour::Construct() {
	((CBoTurnBasedCrashChallenge *)this)->Construct();
}

