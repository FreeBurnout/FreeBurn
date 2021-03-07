#include "BoFrontEnd.h"

void CBoFrontEnd::Construct() {}

bool CBoFrontEnd::Prepare() {
    return false;
}

void CBoFrontEnd::Update() {}

void CBoFrontEnd::Render() {}

void CBoFrontEnd::Release() {}

void CBoFrontEnd::Destruct() {}

void CBoFrontEnd::SetInitialMenu(GtID) {}

GtID CBoFrontEnd::GetInitialMenu() const {
    return GtID();
}
