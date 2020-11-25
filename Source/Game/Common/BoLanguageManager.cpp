#include "BoLanguageManager.h"

char * gaLanguageCodePostfix[] = {
	"UK","US","Ja","Ge","Fr","Sp","It",
	"Ko","US","US","Du","Sw","Fi","Da"
};

char16_t kaZeroLengthStringString[] = u"NO CHARS";

CBoLanguageManager gLanguageManager;

void CBoLanguageManager::Construct() {

}

void CBoLanguageManager::SetLanguage(EGtLanguage leLanguage) {

}

bool CBoLanguageManager::Prepare() {
	return false;
}

EGtLanguage CBoLanguageManager::GetSKUHardwareLanguage() {
	return EGtLanguage();
}

GtUTF16 * CBoLanguageManager::FindString(const char * lpcStringID) {
	return nullptr;
}

const void CBoLanguageManager::ReleaseStrings() {
	return void();
}

bool CBoLanguageManager::PrepareInGame() {
	return false;
}

void CBoLanguageManager::ReleaseInGame() {

}

void CBoLanguageManager::SetNumericSeperators() {

}

void CBoLanguageManager::PrepareDollarStrings() {

}

void CBoLanguageManager::GenerateCrashHoleStringID(GtID lTrackID, RwInt32 lnHole, bool lbEasyHole, char * lacStringID) {

}

void CBoLanguageManager::GenerateTrackStringID(GtID lTrackID, char * lacStringID) {

}
