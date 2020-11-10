#include "BoSoundCustomSoundtrackPC.h"

void CBoSoundCustomSoundtrack::Construct() {
	mnSoundtrackCount = 0;
}

void CBoSoundCustomSoundtrack::Cue() {

}

void CBoSoundCustomSoundtrack::Destruct() {

}

void CBoSoundCustomSoundtrack::GetCustomSongByIndex(int lnIndex, CBoSoundMusicSoundtrack * lpSoundtrack, CBoSoundMusicSong * lpSong, GtUTF16 * lpNameBuffer, int lnIndex0) {

}

void CBoSoundCustomSoundtrack::GetCustomSoundtrackByIndex(int lnIndex, CBoSoundMusicSoundtrack * lpSoundtrack) {

}

RwInt32 CBoSoundCustomSoundtrack::GetSongPlayingTimeMS() {
	return 0;
}

bool CBoSoundCustomSoundtrack::IsPlaying() {
	return false;
}

void CBoSoundCustomSoundtrack::Pause() {

}

void CBoSoundCustomSoundtrack::PausePlayback(bool lbPause) {

}

void CBoSoundCustomSoundtrack::Play() {

}

void CBoSoundCustomSoundtrack::PlayContinuously(bool lbPlayContinuously) {

}

bool CBoSoundCustomSoundtrack::Prepare() {
	return true;
}

void CBoSoundCustomSoundtrack::Resume() {

}

void CBoSoundCustomSoundtrack::SetCustomSong(int lnIndex) {

}

bool CBoSoundCustomSoundtrack::SetCustomSoundtrack(CBoSoundMusicSoundtrack *, int lnIndex, EBoMusicManagerSoundtrackPlayMode lePlayMode) {
	return true;
}

void CBoSoundCustomSoundtrack::SetVolume(float lrVolume) {

}

void CBoSoundCustomSoundtrack::Stop() {

}

void CBoSoundCustomSoundtrack::Update() {

}