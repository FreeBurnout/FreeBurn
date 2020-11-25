#include <rwcore.h>
#include "../Common/BoSoundMusicManager.h"
#include "../../../../GameShared/GameClasses/System/Common/Unicode/GtUnicode.h"

class CBoSoundCustomSoundtrack {
public:
	void Construct();
    bool Prepare();
    void Update();
    void Cue();
    void Destruct();
    void Play();
    void Stop();
    void Pause();
    void Resume();
    bool IsPlaying();
    RwInt32 GetSongPlayingTimeMS();
    void GetCustomSoundtrackByIndex(int lnIndex, CBoSoundMusicSoundtrack * lpSoundtrack);
    void GetCustomSongByIndex(int lnIndex, CBoSoundMusicSoundtrack * lpSoundtrack, CBoSoundMusicSong * lpSong, GtUTF16 * lpNameBuffer, int lnIndex0);
    bool SetCustomSoundtrack(CBoSoundMusicSoundtrack *, int lnIndex, EBoMusicManagerSoundtrackPlayMode lePlayMode);
    void SetCustomSong(int lnIndex);
    void PlayContinuously(bool lbPlayContinuously);
    void SetVolume(float lrVolume);
    void PausePlayback(bool lbPause);

private:
	RwInt32 mnSoundtrackCount;

	void Release();
};