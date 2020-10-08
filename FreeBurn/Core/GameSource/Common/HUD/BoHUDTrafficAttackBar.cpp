#include "BoHUDComponent.h"

void CBoHUDTrafficAttackBar::Update(float param) {

}

void CBoHUDTrafficAttackBar2dObject::Update(float param) {
	*(float *)(mauDataBlock[2]) -= param * (5.0 / 6.0);
}