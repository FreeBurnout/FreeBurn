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

