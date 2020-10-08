#include "BoSoundListener.h"

void CBoSoundListener::Construct() {
	((CGtSoundListener *)this)->Construct();
	mbUseDoppler = false;
}