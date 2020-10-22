#include "BoWorld.h"
#include "../Sound/BoSoundManager.h"
#include "../../../../GameShared/Common/System/FileSystem/GTFileSystem.h"
#include "../Physics/BoVehiclePhysics.h"
#include "../Game/BoGame.h"
#include "../Physics/BoRaceCarPhysics.h"
#include "BoRaceCar.h"
#include "BoEffectsManager.h"

void CBoWorld::Construct() {

}

void CBoWorld::Destruct() {

}

void CBoWorld::UpdateSound() {
	if (gSoundManager.mePrepareState == EGtPrepareState::PreparedFully) {
		gSoundManager.mGameModeManager.Update();
	}
}

void CBoWorld::UpdateTrack() {
}

void CBoWorld::Release() {

}

void CBoWorld::Update() {/*
    bool bVar1;
    int iVar2;
    int iVar3;
    CBoRaceCarPhysics * pCVar4;
    CBoCheckedTrafficPhysics * pCVar5;
    long lVar6;
    CBoVehiclePhysics * pCVar7;
    int iVar8;
    ERaceCarIndex EVar9;
    CBoVehiclePhysics ** ppCVar10;

    bVar1 = mbPausedForStreamSync || mbPausedForNetworkSync;

    if (bVar1) {
        gGame.mInputManager.ResetDeadInputTime(0);
        gGame.mInputManager.ResetDeadInputTime(1);
    }
    else {
        gEnvironmentManager.Update(mTimer.mrTimeStep);
        mStaticTrack.Update();
    }
    if (*(long *)(this + 0x177418) != 0) {
        if (gGame.mnGamePausedByPlayer == -1) {
            UpdateTrack();
        }
        if (mbPausedForStreamSync == false) {
            bVar1 = true;
            if (mbPausedForNetworkSync == false) {
                bVar1 = false;
            }
        }
        else {
            bVar1 = true;
        }
        if (!bVar1) {
            lVar6 = IsActive();
            if ((lVar6 == 0) && (iVar8 = 0, mnNumRaceCars > 0)) {
                while (iVar8 < mnNumRaceCars) {
                    iVar2 = iVar8 * 4;
                    iVar8++;
                    iVar3 = *(int *)(*(int *)(this + iVar2 + 0x177430) + 0x2c90);
                    (**(code **)(iVar3 + 0x14))(*(int *)(this + iVar2 + 0x177430) + (int)*(short *)(iVar3 + 0x10));
                } ;
            }
            Update((CBoRacePosition *)(this + 0x1680d0));
            Update((CBoTrafficSystem *)(this + 0x4ff0));
            gCrashVehicleStreamManager.Update();
            Update((CBoPropManager *)(this + 0x16a230));
            Update((CBoGameData *)(this + 0x167a40));
            mPhysicsManager.Update(mTimer.mrTimeStep);
            lVar6 = IsActive();
            if ((lVar6 == 0) && (iVar8 = 0, 0 < mnNumRaceCars)) {
                while (iVar8 < mnNumRaceCars) {
                    iVar3 = iVar8 * 4;
                    iVar8++;
                    UpdateAILaneSegment(*(CBoRaceCar **)(this + iVar3 + 0x177430));
                } ;
            }
            EVar9 = ERaceCarIndex::RaceCar0;
            gEffectsManager.BeginUpdate();
            if (mnNumRaceCars > 0) {
                while ((int)EVar9 < mnNumRaceCars) {
                    EVar9 = (ERaceCarIndex)((int)EVar9 + 1);
                    pCVar4 = (CBoRaceCarPhysics *)mPhysicsManager.GetRaceCarPhysics(EVar9);
                    gEffectsManager.UpdateRaceCarEffects((CBoEffectsManager *), pCVar4);
                    // EVar9 = EVar9;
                }
            }
            iVar8 = 0;
            if (mPhysicsManager.mnNumCheckedTrafficBodies > 0) {
                while (iVar8 < mPhysicsManager.mnNumCheckedTrafficBodies) {
                    pCVar5 = &mPhysicsManager.GetCheckedTrafficPhysics(iVar8);
                    iVar8++;
                    gEffectsManager.UpdateCheckedTrafficEffects(pCVar5);
                }
            }
            iVar8 = 0;
            if (mPhysicsManager.mnNumTrafficBodies > 0) {
                ppCVar10 = (CBoVehiclePhysics **)(this + 0x1674b8);
                pCVar7 = *ppCVar10;
                while (true) {
                    iVar8++;
                    ppCVar10 = ppCVar10 + 1;
                    gEffectsManager.UpdateCrashingTrafficEffects(pCVar7);
                    if (mPhysicsManager.mnNumTrafficBodies <= iVar8) {
                        break;
                    }
                    pCVar7 = *ppCVar10;
                }
            }
            gEffectsManager.UpdateCollisionEffects();
            UpdateEmitterEffects();
            gEffectsManager.EndUpdate();
            maPlayerCrashAnalysers[0].Update(mTimer.mrTimeStep);
            maPlayerCrashAnalysers[1].Update(mTimer.mrTimeStep);
            UpdateCollidingPairs();
            PostEffectsUpdate();
            gInGameRatingManager.Update();
        }
    }*/
}


