enum class EBoProgressionRating {
	None = -1,
	OK = 0,
	Good = 1,
	Great = 2,
	Awesome = 3,
	Perfect = 4,
	Count = 5
};

class CBoInGameRatingManager {
public:
	RwReal mrRatingBalance;
	RwReal mrCurrentRatingRatio;
	EBoProgressionRating meProgressionRating;
	EBoProgressionRating meDebugProgressionRating;

	void Construct();
};