#include <rwcore.h>

enum class EBoSoundTakedownState {
    eIdle = 0,
    eInTakedown = 1,
    eInTakedownFadeOut = 2
};

class CBoSoundTakedown {
public:
    void Construct();
    bool Prepare();
    void Update();
    void TriggerTakeDown();
    void UpdateTakedown();
    void StartTakedown(ERaceCarIndex, bool);
    void TriggerCameraCut();
    void CancelTakedown();
    void SetTakeDownIsRevenge();
    void SetTakeDownIsBastard();
    bool DoBastardStreamOverride();

private:
    EBoSoundTakedownState meState;
    RwReal mrTotalPitcherTime;
    RwReal mrPitcherTimer;
    RwReal mrPitcherTimeLastFrame;
    RwReal mrCamOutTime;
    ERaceCarIndex meTakenDownCarIndex;
    CGtSoundVoiceInterface mVoice;
    CGtSoundWave * mpTakeWave;
    CGtSoundWave * mpCameraCutWave;
    CGtSoundWave * mpTDInWave;
    CGtSoundWave * mpTDOutWave;
    bool mbSpecialTakedown;
    bool mbRevengeTakedown;
    bool mbBastardTakedown;
    bool mbTriggerTakedownStart;
    bool mbWasInSloMo;
    RwInt32 mnFlashdamper;
    
    bool IsInTakedown();
    void SetTakeDownIsSignature();
    bool IsInBastard();
    bool HasPitchTimerReachedTime(float);
};