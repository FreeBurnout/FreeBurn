#include <rwcore.h>

#include "BoPlayerCar.h"
#include "../../../../GameShared/PC/Graphical/GtTexturePC.h"
#include "../../../../GameShared/PC/Numeric/GtV3dPC.h"
#include "../../../../GameShared/Common/Graphical/GtColour.h"

enum class ECrashModePickupType {
	Boost = 0,
	ScoreSmall = 1,
	ScoreMedium = 2,
	ScoreLarge = 3,
	NegativeMultiplier = 4,
	MultiplierSmall = 5,
	MultiplierLarge = 6,
	Crashbreaker = 7,
	ScoreStealer = 8,
	BoostSegment = 9,
	Number = 10
};

// DONE
struct CBoCrashModePickupStruct {
	CGtV3d mPosition;
	RwUInt8 meType;
	RwUInt8 mu8Flags;
	unsigned char mau8Pad[2];
};

// DONE
class CBoCrashPickup {
private:
	CBoCrashModePickupStruct * mpPickupData;
	RwReal mrPickupTime;
	bool mbPlayersInRange[6];
	bool mbHasBeenPickedUp;
	bool mbWantPickupEffect;
	RwInt8 mn8RaceCarIndex;
	RwUInt8 pad;
	CGtTexture * mpTexture;

	bool Prepare(CBoCrashModePickupStruct *, CGtTexture **);
	void Reset();
	CGtV3d GetPosition();
	ECrashModePickupType GetType();
	bool IsAvailable();

public:
	void Construct();
	void Update(float);
	void Release();
	void Destruct();
	void Draw(EPlayerCarIndex);
};

CGtRGBA kBasePickupColour;