#ifndef GTID_H
#define GTID_H

#include <cstdint>
#include <rwcore.h>

typedef uint64_t GtID;

uint64_t gaGtIDCharacterMasks[];

GtID GtIDCompress(const char* lcpString);
void GtIDUnCompress(GtID, char*);
GtID GtIDMaskCharacters(GtID, RwInt32, RwInt32);
GtID GtIDScroll(GtID, int);
GtID GtIDConcatenate(GtID, GtID);
RwInt32 GtIDGetLength(GtID);
void GtIDConvertToString(GtID, char*);
RwInt32 GtIDExtractTrailingNumber(GtID);

#endif // !GTID_H