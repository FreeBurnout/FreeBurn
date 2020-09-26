#include "BoCrashPickup.h"
#include "BoPlayerCar.h"

bool CBoCrashPickup::Prepare(CBoCrashModePickupStruct *, CGtTexture **) {
    return false;
}

void CBoCrashPickup::Reset() {

}

CGtV3d CBoCrashPickup::GetPosition() {
    return CGtV3d();
}

ECrashModePickupType CBoCrashPickup::GetType() {
    return ECrashModePickupType();
}

bool CBoCrashPickup::IsAvailable() {
    return false;
}

// DONE
void CBoCrashPickup::Construct() {
    Release();
}

void CBoCrashPickup::Update(float a) {

}

// DONE
void CBoCrashPickup::Release() {
    mpPickupData = nullptr;
    mn8RaceCarIndex = -1;
    mbHasBeenPickedUp = false;
    mbWantPickupEffect = false;
}

// DONE
void CBoCrashPickup::Destruct() {

}

void CBoCrashPickup::Draw(EPlayerCarIndex a) {/*
    float fVar1;
    float fVar2;
    float fVar3;
    float fVar4;
    float * pfVar5;
    uint uVar6;
    undefined2 uVar7;
    undefined2 uVar8;
    int iVar9;
    int iVar10;
    undefined8 unaff_s0;
    float fVar11;
    float fVar12;
    float fVar13;
    float fVar14;
    float local_230[4];
    undefined8 local_220;
    float local_218[4];
    float fStack520;
    undefined8 local_200;
    float local_1f0;
    float fStack492;
    float fStack488;
    undefined8 local_1e0;
    float local_1d0;
    float fStack460;
    float fStack456;
    undefined8 local_1c0;
    float local_1b0;
    float fStack428;
    float fStack424;
    undefined8 local_1a0;
    float local_190;
    float fStack396;
    float fStack392;
    undefined8 local_180;
    float local_170;
    float fStack364;
    float fStack360;
    undefined4 uStack356;
    float local_160;
    float fStack348;
    float fStack344;
    undefined4 uStack340;
    float local_150;
    float fStack332;
    float fStack328;
    undefined4 uStack324;
    undefined4 local_140;
    undefined4 uStack316;
    undefined4 uStack312;
    undefined4 uStack308;
    float local_130;
    float fStack300;
    float fStack296;
    undefined4 uStack292;
    float local_120;
    float fStack284;
    float fStack280;
    undefined4 uStack276;
    float local_110;
    float fStack268;
    float fStack264;
    undefined4 uStack260;
    undefined4 local_100;
    undefined4 uStack252;
    undefined4 uStack248;
    undefined4 uStack244;
    float local_f0;
    float fStack236;
    float fStack232;
    undefined4 uStack228;
    float local_e0;
    float fStack220;
    float fStack216;
    undefined4 uStack212;
    float local_d0;
    float fStack204;
    float fStack200;
    undefined4 uStack196;
    undefined4 local_c0;
    undefined4 uStack188;
    undefined4 uStack184;
    undefined4 uStack180;
    float local_b0;
    float fStack172;
    float fStack168;
    undefined4 uStack164;
    float local_a0;
    float fStack156;
    float fStack152;
    undefined4 uStack148;
    float local_90;
    float fStack140;
    float fStack136;
    undefined4 uStack132;
    undefined4 local_80;
    undefined4 uStack124;
    undefined4 uStack120;
    undefined4 uStack116;
    float local_70;
    float fStack108;
    float fStack104;
    undefined4 uStack100;
    float local_60;
    float fStack92;
    float fStack88;
    undefined4 uStack84;
    float local_50;
    float fStack76;
    float fStack72;
    undefined4 uStack68;
    undefined4 local_40;
    undefined4 uStack60;
    undefined4 uStack56;
    undefined4 uStack52;
    float local_24;
    undefined4 local_10;
    undefined4 uStack12;
    
    pfVar5 = local_230;
    local_10 = (int)unaff_s0;
    uStack12 = (int)((ulong)unaff_s0 >> 0x20);
    iVar9 = 5;
    do {
        iVar9 = iVar9 + -1;
        *pfVar5 = *pfVar5;
        pfVar5[1] = pfVar5[1];
        pfVar5[2] = pfVar5[2];
        pfVar5[3] = 0;
        pfVar5 = pfVar5 + 8;
    } while (iVar9 != -1);
    if ((!mbHasBeenPickedUp) && (pfVar5 = *(float **)this, pfVar5 != (float *)0x0)) {
        iVar9 = param_1 * 8000;
        fVar12 = *pfVar5;
        fVar13 = pfVar5[1];
        fVar14 = pfVar5[2];
        fVar1 = *(float *)(gGame + iVar9 + 0x22960) * 1.41421354;
        fVar2 = *(float *)(gGame + iVar9 + 0x22964) * 1.41421354;
        fVar3 = *(float *)(gGame + iVar9 + 0x22968) * 1.41421354;
        fVar4 = *(float *)(gGame + iVar9 + 0x2296c) * 1.41421354;
        local_24 = fVar4 * fVar3;
        fVar11 = 1.0 - fVar1 * fVar1;
        local_170 = ((1.0 - fVar2 * fVar2) - fVar3 * fVar3) + 0.0;
        local_150 = fVar1 * fVar3 + fVar4 * fVar2 + 0.0;
        local_160 = (fVar1 * fVar2 - local_24) + 0.0;
        fStack364 = fVar1 * fVar2 + local_24 + 0.0;
        fStack332 = (fVar2 * fVar3 - fVar4 * fVar1) + 0.0;
        fStack360 = (fVar1 * fVar3 - fVar4 * fVar2) + 0.0;
        local_80 = local_40;
        uStack124 = uStack60;
        uStack120 = uStack56;
        uStack116 = uStack52;
        fStack344 = fVar2 * fVar3 + fVar4 * fVar1 + 0.0;
        fStack328 = (fVar11 - fVar2 * fVar2) + 0.0;
        pfVar5 = local_218;
        iVar10 = 5;
        uStack164 = uStack100;
        uStack148 = uStack84;
        uStack132 = uStack68;
        uStack228 = uStack100;
        uStack212 = uStack84;
        uStack196 = uStack68;
        local_140 = *(undefined4 *)(gGame + iVar9 + 0x22970);
        uStack316 = *(undefined4 *)(gGame + iVar9 + 0x22974);
        uStack312 = *(undefined4 *)(gGame + iVar9 + 0x22978);
        uStack308 = *(undefined4 *)(gGame + iVar9 + 0x2297c);
        uStack356 = uStack100;
        uVar6 = (uint)(kBasePickupColour * 128.0);
        uVar7 = (undefined2)(int)(DAT_01cbdba8 * 128.0);
        uVar8 = (undefined2)(int)(DAT_01cbdbac * 128.0);
        uStack340 = uStack84;
        if (0xff < (int)uVar6) {
            uVar6 = 0xff;
        }
        if ((int)(DAT_01cbdba4 * 128.0) < 1) {
            _uVar6 = CONCAT44((int)(DAT_01cbdba4 * 128.0), uVar6);
        }
        else {
            _uVar6 = (ulong)uVar6;
        }
        if (0 < (int)(DAT_01cbdba8 * 128.0)) {
            uVar7 = 0;
        }
        if (0 < (int)(DAT_01cbdbac * 128.0)) {
            uVar8 = 0;
        }
        uStack324 = uStack68;
        uStack292 = uStack100;
        uStack276 = uStack84;
        uStack260 = uStack68;
        local_130 = local_170;
        fStack300 = fStack364;
        fStack296 = fStack360;
        local_120 = local_160;
        fStack284 = fStack348;
        fStack280 = fStack344;
        local_110 = local_150;
        fStack268 = fStack332;
        fStack264 = fStack328;
        local_100 = local_140;
        uStack252 = uStack316;
        uStack248 = uStack312;
        uStack244 = uStack308;
        local_f0 = local_170;
        fStack236 = fStack364;
        fStack232 = fStack360;
        local_e0 = local_160;
        fStack220 = fStack348;
        fStack216 = fStack344;
        local_d0 = local_150;
        fStack204 = fStack332;
        fStack200 = fStack328;
        local_c0 = local_140;
        uStack188 = uStack316;
        uStack184 = uStack312;
        uStack180 = uStack308;
        local_b0 = local_170;
        fStack172 = fStack364;
        fStack168 = fStack360;
        local_a0 = local_160;
        fStack156 = fStack348;
        fStack152 = fStack344;
        local_90 = local_150;
        fStack140 = fStack332;
        fStack136 = fStack328;
        local_70 = local_170;
        fStack108 = fStack364;
        fStack104 = fStack360;
        local_60 = local_160;
        fStack92 = fStack348;
        fStack88 = fStack344;
        local_50 = local_150;
        fStack76 = fStack332;
        fStack72 = fStack328;
        do {
            *(uint *)pfVar5 =
                CONCAT13((char)(((ulong)CONCAT22(uVar8, uVar7) << 0x20) >> 0x30),
                    CONCAT12((char)uVar7, CONCAT11((char)(_uVar6 >> 0x20), (char)_uVar6)));
            iVar10 = iVar10 + -1;
            pfVar5 = pfVar5 + 8;
        } while (-1 < iVar10);
        local_218[2] = (fVar12 - local_170 * 1.4) + 0.0;
        local_218[3] = (fVar13 - fStack364 * 1.4) + 0.0;
        fStack520 = (fVar14 - fStack360 * 1.4) + 0.0;
        local_230[0] = fVar12 + kPickupUp + 0.0;
        local_230[1] = fVar13 + DAT_01cbdb74 + 0.0;
        local_230[2] = fVar14 + DAT_01cbdb78 + 0.0;
        local_1f0 = (fVar12 - kPickupUp) + 0.0;
        fStack492 = (fVar13 - DAT_01cbdb74) + 0.0;
        fStack488 = (fVar14 - DAT_01cbdb78) + 0.0;
        local_1d0 = fVar12 + kPickupUp + 0.0;
        fStack460 = fVar13 + DAT_01cbdb74 + 0.0;
        fStack456 = fVar14 + DAT_01cbdb78 + 0.0;
        local_1b0 = (fVar12 - kPickupUp) + 0.0;
        fStack428 = (fVar13 - DAT_01cbdb74) + 0.0;
        fStack424 = (fVar14 - DAT_01cbdb78) + 0.0;
        local_190 = fVar12 + local_170 * 1.4 + 0.0;
        fStack396 = fVar13 + fStack364 * 1.4 + 0.0;
        fStack392 = fVar14 + fStack360 * 1.4 + 0.0;
        local_1c0 = kTopUV;
        local_1a0 = kBottomUV;
        local_220 = kTopUV;
        local_1e0 = kBottomUV;
        local_200 = kLeftUV;
        local_180 = kRightUV;
        BeginRendering();
        SetAlphaTestThreshold(0.07812500);
        SetTexture(*(CGtTexture **)(this + 0x14));
        RenderTrilist((CB4Im3dVertex *)local_230, 6);
        EndRendering();
    }*/
}
