#include <rwcore.h>

#include "BoGameData.h"

void CBoGameData::Construct() {

}

bool CBoGameData::Prepare() {
    return false;
}

bool CBoGameData::IsFileStreamReady() {
    return false;
}

RwInt32 CBoGameData::GetNumStartLines() {
    return RwInt32();
}

RwInt32 CBoGameData::GetNumFinishLines() {
    return RwInt32();
}

RwInt32 CBoGameData::GetNumSplitTimeCheckpoints() {
    return RwInt32();
}

void CBoGameData::Update() {

}

void CBoGameData::Release() {

}

void CBoGameData::Destruct() {

}

void CBoGameData::SetGameDataFileName(char * lpacGameDataFileName) {

}

void CBoGameData::SetStageID(GtID lID) {

}

void CBoGameData::Draw(EPlayerCarIndex param) {

}

RwInt32 CBoGameData::GetNumLaps() {
    return RwInt32();
}

void CBoGameData::GetGameDataThreshold(float * lprBronze, float * lprSilver, float * lprGold) {

}

void CBoGameData::GetGameDataThreshold(int * lpnBronze, int * lpnSilver, int * lpnGold) {

}

void CBoGameData::GetWindGameData(float * lprDirection, float * lprSpeed, signed char ln8Difficulty) {

}

void CBoGameData::GetCrashThreshold(signed char * lpn8Par, int * lpnTarget) {

}

RwInt32 CBoGameData::GetIntroSequence(signed char param) const {
    return RwInt32();
}

RwReal CBoGameData::GetTimeLimit() const {
    return RwReal();
}

RwUInt64 CBoGameData::GetNumPickups() {
    return RwUInt64();
}

RwUInt64 CBoGameData::GetDifficultyIndex() {
    return RwUInt64();
}

RwInt32 CBoGameData::GetNumSignatureTakedownZones() {
    return RwInt32();
}

CBoSignatureTakedownStruct CBoGameData::GetSignatureTakedownData(int) {
    return CBoSignatureTakedownStruct();
}

EBoSignatureTakedownType CBoGameData::GetSignatureTakedownType(GtMathPC::CGtV3d lTakedownPosition) {
    return EBoSignatureTakedownType();
}

CBoGameStageDataStruct CBoGameData::GetGameStageData() {
    return CBoGameStageDataStruct();
}

void CBoGameDataStruct::FixUp() {

}

void CBoGameStageDataStruct::FixUp() {

}

void CBoSingleRaceDataStruct::FixUp() {

}
