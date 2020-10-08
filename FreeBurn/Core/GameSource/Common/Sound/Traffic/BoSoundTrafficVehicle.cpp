#include "BoSoundTrafficManager.h"
#include "../../../../../GameShared/Common/Development/CommsTool/GtCommsDatabase.h"

void CBoSoundTrafficVehicle::Construct() {
    mPass.Construct();
    mRoadDoppler.Construct();
    mEngineDoppler.Construct();
    mbIsActive = false;
    if (!_gbRegisteredWithCommsTool) {
        AddEntry((CGtCommsDatabase *)(mpToolBase + 4), (float *)&_grLTrainMaxAudibleDistance, "Max distance", kpcLTrainDir, kpcLTrainVDBFile, 0, 0, 0, 0);
        AddEntry((CGtCommsDatabase *)(mpToolBase + 4), (float *)&_grLTrainMinAudibleDistance, "Min distance", kpcLTrainDir, kpcLTrainVDBFile, 0, 0, 0, 0);
        AddEntry((CGtCommsDatabase *)(mpToolBase + 4), (float *)&_grTrainPitchVariationMax, "Max pitch gain", kpcLTrainDir, kpcLTrainVDBFile, 0, 0, 0, 0);
        AddEntry((CGtCommsDatabase *)(mpToolBase + 4), (float *)&_grTrainPitchVariationMin, "Min pitch gain", kpcLTrainDir, kpcLTrainVDBFile, 0, 0, 0, 0);
        AddEntry((CGtCommsDatabase *)(mpToolBase + 4), (float *)&_grTrainPitchVariationStep,"Pitch gain step", kpcLTrainDir, kpcLTrainVDBFile, 0, 0, 0, 0);
        AddEntry((CGtCommsDatabase *)(mpToolBase + 4), (float *)&_grLTrainSqueakPitchBase,"Squeak base pitch", kpcLTrainDir, kpcLTrainVDBFile, 0, 0, 0, 0);
        AddEntry((CGtCommsDatabase *)(mpToolBase + 4), (float *)&_grLTrainSqueakPitchRange,"Squeak pitch range", kpcLTrainDir, kpcLTrainVDBFile, 0, 0, 0, 0);
        AddEntry((CGtCommsDatabase *)(mpToolBase + 4), &_gnUpdatesDuringSqueak,"Length of squeak (frames)", kpcLTrainDir, kpcLTrainVDBFile, 0, 0, 0, 0);
        AddEntry((CGtCommsDatabase *)(mpToolBase + 4), &_gnUpdatesBetweenSqueaks, "Frames between squeaks", kpcLTrainDir, kpcLTrainVDBFile, 0, 0, 0, 0);
        AddEntry((CGtCommsDatabase *)(mpToolBase + 4), &_gnSqueakDurationVariation,"Squeak duration variation (frames)", kpcLTrainDir, kpcLTrainVDBFile, 0, 0, 0, 0);
        AddEntry((CGtCommsDatabase *)(mpToolBase + 4), &_gnTimeBetweenSqueaksVariation,"Time between squeaks variation (frames)", kpcLTrainDir, kpcLTrainVDBFile, 0, 0, 0, 0);
        AddEntry((CGtCommsDatabase *)(mpToolBase + 4), (float *)&_grLTrainRailsVolume, "Rails volume", kpcLTrainDir, kpcLTrainVDBFile, 0, 0.0, 0.0, 0);
        AddEntry((CGtCommsDatabase *)(mpToolBase + 4), (float *)&_grLTrainSqueakVolumeBase, "Squeak base volume", kpcLTrainDir, kpcLTrainVDBFile, 0, 0.0, 0.0, 0);
        AddEntry((CGtCommsDatabase *)(mpToolBase + 4), (float *)&_grLTrainSqueakVolumeRange, "Squeak volume range", kpcLTrainDir, kpcLTrainVDBFile, 0, 0.0, 0.0, 0);
        _gbRegisteredWithCommsTool = true;
    }
}