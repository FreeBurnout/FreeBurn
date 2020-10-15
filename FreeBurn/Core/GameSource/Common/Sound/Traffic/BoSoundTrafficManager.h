#include <rwcore.h>

extern RwReal _grTrainPitchVariationMax;
extern RwReal _grTrainPitchVariationMin;
extern RwReal _grTrainPitchVariationStep;
extern RwInt32 _gnUpdatesDuringSqueak;
extern RwInt32 _gnUpdatesBetweenSqueaks;
extern RwReal _grLTrainSqueakVolumeBase;
extern RwReal _grLTrainSqueakVolumeRange;
extern RwReal _grLTrainRailsVolume;
extern RwReal _grLTrainMaxAudibleDistance;
extern RwReal _grLTrainMinAudibleDistance;
extern RwInt32 _gnCarriageCount;
extern RwInt32 _gnSqueakDurationVariation;
extern RwInt32 _gnTimeBetweenSqueaksVariation;
extern RwReal _grLTrainSqueakPitchBase;
extern RwReal _grLTrainSqueakPitchRange;
extern bool _gbRegisteredWithCommsTool;

class CBoSoundDoppler {
public:
	void Construct();
};

class CBoSoundTrafficPass {
public:
	void Construct();
};

class CBoSoundTrafficVehicle {
public:
	bool mbIsActive;
	CBoSoundTrafficPass mPass;
	CBoSoundDoppler mRoadDoppler;
	CBoSoundDoppler mEngineDoppler;

	void Construct();
};

