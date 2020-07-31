class CBoGame {
public:
	bool mbQuitNow;

	void Construct();
	void Destruct();
	void Release();
	bool Prepare();
	bool Update();
};

static CBoGame gGame;