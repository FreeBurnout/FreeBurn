#ifndef GTID_H
#define GTID_H

#include <rwcore.h>

typedef unsigned long GtID;

unsigned long gaGtIDCharacterMasks[13] = {
	0x1,
	0x28,
	0x640,
	0xFA00,
	0x271000,
	0x61A8000,
	0xF4240000,
	0x2625A00000,
	0x5F5E1000000,
	0xEE6B28000000,
	0x2540BE40000000,
	0x5D21DBA00000000,
	0xE8D4A51000000000
};

GtID GtIDCompress(const char* lcpString);
void GtIDUnCompress(GtID, char*);
GtID GtIDMaskCharacters(GtID, RwInt32, RwInt32);
GtID GtIDScroll(GtID, int);
GtID GtIDConcatenate(GtID, GtID);
RwInt32 GtIDGetLength(GtID);
void GtIDConvertToString(GtID, char*);
RwInt32 GtIDExtractTrailingNumber(GtID);

#endif // !GTID_H