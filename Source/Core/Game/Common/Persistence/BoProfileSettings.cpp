#include "BoProfileStoredData.h"
#include "../BoProfileManager.h"

void CBoProfileSettings::Construct() { }

bool CBoProfileSettings::Prepare() {
	return true;
}

void CBoProfileSettings::Update() { }

void CBoProfileSettings::ConvertFromStoredData(const CBoProfileStoredData*) { }

void CBoProfileSettings::UpdateStoredData(CBoProfileStoredData*) { }