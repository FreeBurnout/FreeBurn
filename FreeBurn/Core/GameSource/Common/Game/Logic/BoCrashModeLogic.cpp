#include <rwcore.h>

#include "BoCrashModeLogic.h"

char kacPlayerDriverOneString[] = "FEMULTIPLAYER";
char kacPlayerDriverTwoString[] = "FEMULTIPLAYER2";
char kacPlayerDriverThreeString[] = "FEMULTIPLAYER3";
char kacPlayerDriverFourString[] = "FEMULTIPLAYER4";
char kacPlayerDriverFiveString[] = "FEMULTIPLAYER5";
char kacPlayerDriverSixString[] = "FEMULTIPLAYER6";

RwReal karCrashbreakerChargeSpeeds[10] = {
	15.0, 15.0, 15.0, 15.0, 22.0, 
	20.5, 18.0, 15.5, 12.0, 11.5
};

void CBoCrashModeLogic::Construct() {

}

void CBoCompCrashModeLogic::Construct() {

}

void CBoPartyCrashModeLogic::Construct() {

}

void CBoTourCrashModeLogic::Construct() {

}

void CBoCrashModeWind::Construct() {
	mbPrepared = false;
}
