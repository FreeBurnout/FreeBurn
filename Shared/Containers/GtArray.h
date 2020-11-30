#include <rwcore.h>

#include "../Core/GtID.h"

struct CGtArrayEntry {
public:
	void* mpData;
};

struct CGtArrayBase {
public:
	GtID mArrayID;
	RwInt32 mnNumEntries;
	CGtArrayEntry* mpaIndex;

	void FixUp();
	RwInt32 GetNumEntries();
	GtID GetArrayID();
};