#include <vcruntime_string.h>

#include "BoCrashRamp.h"

void CBoCrashRamp::Construct() {
	memset(maPoints, 0, sizeof(maPoints));
}
