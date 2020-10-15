#include <rwcore.h>

#include "../Persistence/BoProfileProgression.h"

class CBoRevengeMeter {
public:
	RwInt32 GetPointsTotal(void) const;
	void    SetPointsTotal(int);
	RwInt32 GetPreviousPointsTotal(void) const;
	RwInt32 GetRankID(void) const;
	RwInt32 GetPreviousRankID(void) const;
	RwInt32 GetPreviousThresholdUnlockIndex(int, EChallengeUnlockType) const;
	RwInt32 GetThresholdUnlockIndex(int, EChallengeUnlockType) const;
	void    SetThresholdUnlockIndex(int, int, EChallengeUnlockType);
	bool    Prepare(void);
	void    Update(bool);

private:
	RwInt32 mnRevengePoints;
	RwInt32 mnRevengeRank;
	RwInt32 mnLastRevengePoints;
	RwInt32 mnLastRank;
	int     maanThresholdUnlockIndices[2][16];
	int     maanLastThresholdUnlockIndices[2][16];

	void Construct();
	void Release();
	void Destruct();
	void SetRankID(RwInt32 lnRank);
};