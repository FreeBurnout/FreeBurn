#pragma once

class CBoAptManager {
public:
	bool mbEnabled;

	void Construct();
	void Render(float);
};

extern CBoAptManager gAptManager;