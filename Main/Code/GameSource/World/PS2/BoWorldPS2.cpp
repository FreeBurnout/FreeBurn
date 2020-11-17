#include "../../Common/World/BoPlayerCar.h"
#include "../../Common/World/BoRaceCar.h"
#include "../../Common/World/BoWorld.h"
#include "../../../../GameShared/Common/Graphical/GtColour.h"
#include "../../../../GameShared/Common/Numeric/Math/Generic/GtV2dGeneric.h"
#include "../../../../GameShared/PC/Numeric/GtMathPC.h"

char kacAIDriverOneString[]   = "DRIVER1";
char kacAIDriverTwoString[]   = "DRIVER2";
char kacAIDriverThreeString[] = "DRIVER3";
char kacAIDriverFourString[]  = "DRIVER4";
char kacAIDriverFiveString[]  = "DRIVER5";

char * kacpAIDriverString[5] = {
	kacAIDriverOneString,
	kacAIDriverTwoString,
	kacAIDriverThreeString,
	kacAIDriverFourString,
	kacAIDriverFiveString
};

CGtRGBA kCarUnlockColour;
CGtRGBA kCarSelectColour;
GtMathPC::CGtV2d kPolyPos;
GtMathPC::CGtV2d kPolyHandle;
CGtRGBA kRedPolyColour;
CGtRGBA kRedPolyColour1;
CGtRGBA kOrangePolyColour;
CGtRGBA kOrangePolyColour1;
CGtRGBA kWhitePolyColour;
CGtRGBA kBluePolyColour;

void CBoWorld::RenderOnePlayer() {

}

void CBoWorld::Render(EPlayerCarIndex) {

}

void CBoWorld::RenderTwoPlayer() {

}

void CBoWorld::RenderFrontEnd(ERaceCarIndex) {

}

void CBoWorld::NetworkCatchupUpdate() {

}

void CBoWorld::PauseForNetworkSync(bool) {

}

void CBoWorld::PauseForStreamSync(bool) {

}

bool CBoWorld::WeArePausedForNetworkOrStreamSync() {
	return false;
}

void CBoWorld::SetReplayRequestStatus(bool) {

}

bool CBoWorld::GetReplayRequestStatus() {
	return false;
}

bool CBoWorld::IsReplaying() {
	return false;
}
