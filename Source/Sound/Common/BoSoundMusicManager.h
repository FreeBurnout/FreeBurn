#include "../../../../GameShared/CodeSDKs/rw37/include/os/win/ostypes.h"

enum EBoMusicManagerSoundtrackPlayMode {
	eBoPlayModeNULL = 0, 
	eBoPlayModeSequential = 1, 
	eBoPlayModeRandom = 2, 
	eBoPlayModeSingle = 3, 
	eBoPlayModeLooping = 4, 
	eBoPlayModeMusicOff = 5
};

class CBoSoundMusicSong {
public:
    RwUInt32 munSongID;
    RwUInt32 munSongLength;
    RwUInt32 mxPlayFlags;
};

class CBoSoundMusicSoundtrack {
public:
    RwUInt32 munSoundtrackID;
    RwUInt32 munSongCount;
    RwUInt32 munSoundtrackLength;
    char16_t maName[32];
    CBoSoundMusicSong* mpSongs;
    RwInt32 mnIndex;
    bool mbIsGameSoundtrack;
};