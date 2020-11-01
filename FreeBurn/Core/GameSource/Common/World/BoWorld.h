#include <rwcore.h>

#include "BoNetworkCar.h"
#include "../../Common/Graphics/VehicleRenderer/BoVehicleRenderer.h"
#include "../../Common/Physics/BoVehiclePhysics.h"
#include "../../Common/World/AI/BoAICar.h"
#include "../../../../GameShared/Common/Core/GtID.h"
#include "../../../../GameShared/PC/Numeric/GtMathPC.h"

extern char kacAIDriverOneString[];
extern char kacAIDriverTwoString[];
extern char kacAIDriverThreeString[];
extern char kacAIDriverFourString[];
extern char kacAIDriverFiveString[];

extern char * kacpAIDriverString[5];

class CBoWorld {
public:
    CBoWorld();
    void Construct();
    bool Prepare(bool lbQuickPrepare);
    bool LoadRaceCarData(GtID lnID, RwInt32 lnBufferIndex);
    CBoVehicleData GetRaceCarData(GtID lnID, RwInt32 lnBufferIndex);
    CBoVehiclePhysics GetRaceCar(ERaceCarIndex);
    void SetUpTrackExtents();
    void Update();
    void UpdateTrack();
    void Release();
    void SetTrackID(GtID lnID);
    void UnLoadRaceCarData(GtID lnID, RwInt32 lnBufferIndex);
    void Destruct();
    void SetCarNumbers(RwInt32 lnNumPlayerCars, RwInt32 lnNumAICars, RwInt32 lnNumNetworkCars, RwInt32 lnNumAdjustedAICars);
    void UpdateSound();
    void RenderRaceCars(EPlayerCarIndex, EPlayerCarIndex);
    void RenderFullScreenPoly(EPlayerCarIndex);
    void RenderCarUnlockEffects();
    void RenderOnePlayer();
    void Render(EPlayerCarIndex);
    void RenderTwoPlayer();
    void RenderFrontEnd(ERaceCarIndex);

private:
    void NetworkCatchupUpdate();
    void PauseForNetworkSync(bool);
    void PauseForStreamSync(bool);
    bool WeArePausedForNetworkOrStreamSync();
    void SetReplayRequestStatus(bool);
    bool GetReplayRequestStatus();
    bool IsReplaying();
    GtID GetTrackID();
    ERaceCarIndex GetNumRaceCars();
    RwInt32 GetNumActiveRaceCars();
    EPlayerCarIndex GetNumPlayerCars();
    EPlayerCarIndex GetNumAICars();
    EPlayerCarIndex GetNumNetworkCars();
    RwInt32 GetNumAdjustedAICars();
    void DecrementNumAdjustedAICars();
    RwInt32 GetLeadingAdjustedAICar();
    void IncrementLeadingAdjustedAICar();
    void DecrementLeadingAdjustedAICar();
    void SetNumLeadingCars(int);
    CBoPlayerCar * GetPlayerCar(EPlayerCarIndex);
    CBoAICar * GetAICar(EAICarIndex);
    CBoNetworkCar * GetNetworkCar(ENetworkCarIndex);
    bool IsPointToPoint();
    bool IsMarathon();
    bool IsRightHandDrive();
    GtMathPC::CGtV3d GetTrackCentre();
    void GetTrackExtents(GtMathPC::CGtV3d *, GtMathPC::CGtV3d *);
    void SetNumActiveRaceCars(int);
    void DecrementNumActiveRaceCars();
    bool IsCrashIntro() const;
    void SetCrashIntro(bool);
    bool IsCrashAftermath() const;
    void SetCrashAftermath(bool);
    RwReal GetTimeBeforeAutomaticTimeout();
    RwInt32 GetInitialWorldFrame();
    RwInt32 GetMaxRaceCarStreams() const;
    bool IsMultiPlayer();
    bool IsSinglePlayer();

};

extern CBoWorld gWorld;