#include "BoSoundTrafficManager.h"
#include "../../../../../GameShared/Common/Development/CommsTool/GtCommsDatabase.h"

RwReal  _grTrainPitchVariationMax =       1.05;
RwReal  _grTrainPitchVariationMin =       0.95;
RwReal  _grTrainPitchVariationStep =      0.01;
RwInt32 _gnUpdatesDuringSqueak =          45;
RwInt32 _gnUpdatesBetweenSqueaks =        120;
RwReal  _grLTrainSqueakVolumeBase =       0.9;
RwReal  _grLTrainSqueakVolumeRange =      0.1;
RwReal  _grLTrainRailsVolume =            1.0;
RwReal  _grLTrainMaxAudibleDistance =     100.0;
RwReal  _grLTrainMinAudibleDistance =     70.0;
RwInt32 _gnCarriageCount =                0;
RwInt32 _gnSqueakDurationVariation =      30;
RwInt32 _gnTimeBetweenSqueaksVariation =  30;
RwReal  _grLTrainSqueakPitchBase =        0.9;
RwReal  _grLTrainSqueakPitchRange =       0.2;
bool    _gbRegisteredWithCommsTool =      false;

char * kpcLTrainDir =     "Sound/L Train/";
char * kpcLTrainVDBFile = "../Data/Export/ValueDB/Sound/LTrain.cfg";

void CBoSoundTrafficVehicle::Construct() {
    mPass.Construct();
    mRoadDoppler.Construct();
    mEngineDoppler.Construct();
    mbIsActive = false;
    if (!_gbRegisteredWithCommsTool) {
        GtComms::CGtCommsToolBase::mpToolBase->mDatabase.AddEntry(&_grLTrainMaxAudibleDistance,    "Max distance",                            kpcLTrainDir, kpcLTrainVDBFile, 0, 0, 0, 0);
        GtComms::CGtCommsToolBase::mpToolBase->mDatabase.AddEntry(&_grLTrainMinAudibleDistance,    "Min distance",                            kpcLTrainDir, kpcLTrainVDBFile, 0, 0, 0, 0);
        GtComms::CGtCommsToolBase::mpToolBase->mDatabase.AddEntry(&_grTrainPitchVariationMax,      "Max pitch gain",                          kpcLTrainDir, kpcLTrainVDBFile, 0, 0, 0, 0);
        GtComms::CGtCommsToolBase::mpToolBase->mDatabase.AddEntry(&_grTrainPitchVariationMin,      "Min pitch gain",                          kpcLTrainDir, kpcLTrainVDBFile, 0, 0, 0, 0);
        GtComms::CGtCommsToolBase::mpToolBase->mDatabase.AddEntry(&_grTrainPitchVariationStep,     "Pitch gain step",                         kpcLTrainDir, kpcLTrainVDBFile, 0, 0, 0, 0);
        GtComms::CGtCommsToolBase::mpToolBase->mDatabase.AddEntry(&_grLTrainSqueakPitchBase,       "Squeak base pitch",                       kpcLTrainDir, kpcLTrainVDBFile, 0, 0, 0, 0);
        GtComms::CGtCommsToolBase::mpToolBase->mDatabase.AddEntry(&_grLTrainSqueakPitchRange,      "Squeak pitch range",                      kpcLTrainDir, kpcLTrainVDBFile, 0, 0, 0, 0);
        GtComms::CGtCommsToolBase::mpToolBase->mDatabase.AddEntry(&_gnUpdatesDuringSqueak,         "Length of squeak (frames)",               kpcLTrainDir, kpcLTrainVDBFile, 0, 0, 0, 0);
        GtComms::CGtCommsToolBase::mpToolBase->mDatabase.AddEntry(&_gnUpdatesBetweenSqueaks,       "Frames between squeaks",                  kpcLTrainDir, kpcLTrainVDBFile, 0, 0, 0, 0);
        GtComms::CGtCommsToolBase::mpToolBase->mDatabase.AddEntry(&_gnSqueakDurationVariation,     "Squeak duration variation (frames)",      kpcLTrainDir, kpcLTrainVDBFile, 0, 0, 0, 0);
        GtComms::CGtCommsToolBase::mpToolBase->mDatabase.AddEntry(&_gnTimeBetweenSqueaksVariation, "Time between squeaks variation (frames)", kpcLTrainDir, kpcLTrainVDBFile, 0, 0, 0, 0);
        GtComms::CGtCommsToolBase::mpToolBase->mDatabase.AddEntry(&_grLTrainRailsVolume,           "Rails volume",                            kpcLTrainDir, kpcLTrainVDBFile, 0, 0, 0, 0);
        GtComms::CGtCommsToolBase::mpToolBase->mDatabase.AddEntry(&_grLTrainSqueakVolumeBase,      "Squeak base volume",                      kpcLTrainDir, kpcLTrainVDBFile, 0, 0, 0, 0);
        GtComms::CGtCommsToolBase::mpToolBase->mDatabase.AddEntry(&_grLTrainSqueakVolumeRange,     "Squeak volume range",                     kpcLTrainDir, kpcLTrainVDBFile, 0, 0, 0, 0);
        _gbRegisteredWithCommsTool = true;
    }
}