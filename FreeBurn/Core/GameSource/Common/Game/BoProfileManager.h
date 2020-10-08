#include "Persistence/BoProfile.h"

class CBoProfileManager {
public:
	CBoProfile * mpActiveProfile;

	void Construct();
};

extern CBoProfileManager gProfileManager;