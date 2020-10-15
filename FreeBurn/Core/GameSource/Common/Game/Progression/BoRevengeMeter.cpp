#include "BoRevengeMeter.h"
#include "../BoGame.h"

RwInt32 CBoRevengeMeter::GetPointsTotal(void) const {
	return mnRevengePoints;
}

void CBoRevengeMeter::SetPointsTotal(RwInt32 lnRevengePoints) {
	int last = mnRevengePoints;
	mnRevengePoints = lnRevengePoints;
	mnLastRevengePoints = last;
	Update(false);
}

RwInt32 CBoRevengeMeter::GetPreviousPointsTotal(void) const {
	return RwInt32();
}

RwInt32 CBoRevengeMeter::GetRankID(void) const {
	return RwInt32();
}

RwInt32 CBoRevengeMeter::GetPreviousRankID(void) const {
	return RwInt32();
}

RwInt32 CBoRevengeMeter::GetPreviousThresholdUnlockIndex(int, EChallengeUnlockType) const {
	return RwInt32();
}

RwInt32 CBoRevengeMeter::GetThresholdUnlockIndex(int, EChallengeUnlockType) const {
	return RwInt32();
}

void CBoRevengeMeter::SetThresholdUnlockIndex(int, int, EChallengeUnlockType) {

}

bool CBoRevengeMeter::Prepare(void) {
	return false;
}

void CBoRevengeMeter::Update(bool lbInitialUpdate) {
    int revRanks;
    if (!lbInitialUpdate) {
        mnLastRank = mnRevengeRank;
    }
    int * pRevRanks = (int *)(gGame.mpProgressionData->mRevengeMeter.mpRevengeRanks);
    int numRevRanks = gGame.mpProgressionData->mRevengeMeter.mnNumRevengeRanks;
    for (int i = 0; i < numRevRanks; i++) {
        revRanks = *pRevRanks + (i * 24);
        if (mnRevengePoints < gGame.mpProgressionData->mRevengeMeter.mpRevengeRanks->mnRevengePointsNeeded || i == numRevRanks - 1) {
            mnRevengeRank = gGame.mpProgressionData->mRevengeMeter.mpRevengeRanks->mnID;
        }
        numRevRanks = gGame.mpProgressionData->mRevengeMeter.mnNumRevengeRanks;
    }
    if (lbInitialUpdate) {
        mnLastRank = mnRevengeRank;
    }
}

void CBoRevengeMeter::Construct() {

}

void CBoRevengeMeter::Release() {

}

void CBoRevengeMeter::Destruct() {

}

void CBoRevengeMeter::SetRankID(RwInt32 lnRank) {

}
