#ifndef GTCOMMSDATABASE_H
#define GTCOMMSDATABASE_H

#include <rwcore.h>

namespace GtComms {
	class CGtCommsDatabaseEntry {

	};

	class CGtCommsDatabase {
	public:
		void Construct(CGtCommsDatabaseEntry* lpElements, RwInt32 lnDatabaseSize);
	};
	
	class CGtValueDatabase {

	};

	class CGtCommsToolBase {
	public:
		void Construct(char* lpcFileServerRoot);
	};
}
#endif // !#define GTCOMMSDATABASE_H

