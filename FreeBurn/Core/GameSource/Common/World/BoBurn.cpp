#include "BoBurn.h"
#include "../../../../GameShared/Common/Development/CommsTool/GtCommsDatabase.h"

RwReal CBoBurn::gmrMinimumBoostTime = 1.0;
RwReal CBoBurn::gmrMinimumBoostRecoveryTime = 0.5;
RwReal CBoBurn::gmrPowerBoostDepletionMultiplier = 1.4;
RwReal CBoBurn::gmarBoostBarSizes[4] = { 100.0, 200.0, 300.0, 400.0 };
RwReal CBoBurn::gmarBurnoutBoostMultipliers[4] = { 1.0, 2.0, 3.0, 4.0 };
RwReal CBoBurn::gmarBoostRate[4] = { 10.0, 10.0, 10.0, 10.0 };

RwInt32 CBoBurn::mnNumExtraSegments;
RwReal CBoBurn::mrCurrentBoost;
RwReal CBoBurn::mrMaxBoost;
RwReal CBoBurn::mrBoostRate;
RwReal CBoBurn::mrBoostMultiplier;
RwReal CBoBurn::mrMinimumBoostUsed;

void CBoBurn::RegisterStaticVariables() {
    GtComms::CGtCommsToolBase::mpToolBase->mDatabase.AddEntry(&gmrMinimumBoostTime,              "Minimum Boost Time (seconds)",            "Boost Bar", "../Data/Export/ValueDB/Score.cfg", 0, 0, 0,      0);
    GtComms::CGtCommsToolBase::mpToolBase->mDatabase.AddEntry(&gmrMinimumBoostRecoveryTime,      "Minimum Boost Recovery Time (seconds)",   "Boost Bar", "../Data/Export/ValueDB/Score.cfg", 0, 0, 0,      0);
    GtComms::CGtCommsToolBase::mpToolBase->mDatabase.AddEntry(&gmrPowerBoostDepletionMultiplier, "Powerboost extra boost depletion factor", "Boost Bar", "../Data/Export/ValueDB/Score.cfg", 0, 0, 0,      0);
    GtComms::CGtCommsToolBase::mpToolBase->mDatabase.AddEntry(gmarBoostBarSizes,                 "Boost Bar sizes (Boost Units)",           "Boost Bar", "../Data/Export/ValueDB/Score.cfg", 0, 0, 1500.0, 4);
    GtComms::CGtCommsToolBase::mpToolBase->mDatabase.AddEntry(gmarBurnoutBoostMultipliers,       "Boost Earning Multiplier",                "Boost Bar", "../Data/Export/ValueDB/Score.cfg", 0, 0, 10.0,   4);
    GtComms::CGtCommsToolBase::mpToolBase->mDatabase.AddEntry(gmarBoostRate,                     "Boost Rate (Boost Units per Second)",     "Boost Bar", "../Data/Export/ValueDB/Score.cfg", 0, 0, 1000.0, 4);
}

void CBoBurn::UnregisterStaticVariables() {
    GtComms::CGtCommsToolBase::mpToolBase->mDatabase.RemoveEntry(&gmrMinimumBoostTime);
    GtComms::CGtCommsToolBase::mpToolBase->mDatabase.RemoveEntry(&gmrMinimumBoostRecoveryTime);
    GtComms::CGtCommsToolBase::mpToolBase->mDatabase.RemoveEntry(&gmrPowerBoostDepletionMultiplier);
    GtComms::CGtCommsToolBase::mpToolBase->mDatabase.RemoveEntry(gmarBoostBarSizes);
    GtComms::CGtCommsToolBase::mpToolBase->mDatabase.RemoveEntry(gmarBurnoutBoostMultipliers);
    GtComms::CGtCommsToolBase::mpToolBase->mDatabase.RemoveEntry(gmarBoostRate);

}

void CBoBurn::SetNumExtraBoostBarSegments(RwInt32 lnNumSegments) {
    mnNumExtraSegments = lnNumSegments;
    mrMaxBoost = gmarBoostBarSizes[lnNumSegments];
    mrBoostRate = gmarBoostRate[lnNumSegments];
    mrBoostMultiplier = gmarBurnoutBoostMultipliers[lnNumSegments];
    mrMinimumBoostUsed = mrBoostRate * gmrMinimumBoostTime;

}

void CBoBurn::AddSegment() {
    if (mnNumExtraSegments < 3) {
        SetNumExtraBoostBarSegments(mnNumExtraSegments + 1);
    }
}

void CBoBurn::RemoveSegment() {
    if (mnNumExtraSegments > 0) {
        SetNumExtraBoostBarSegments(mnNumExtraSegments - 1);
        mrCurrentBoost = mrMaxBoost;
    }
}

EBoShockwaveType CBoBurn::CalcCrashbreakerType() {
    RwInt32 lnBoostBarSizeIndex = 10;
    int i = 0;
    if (mnNumExtraSegments + 1 > 0) {
        while (mnNumExtraSegments > lnBoostBarSizeIndex) {
            lnBoostBarSizeIndex = i++;
        }
    }
    return (EBoShockwaveType)lnBoostBarSizeIndex;
}
