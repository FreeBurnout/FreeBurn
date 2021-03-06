#ifndef BOAPTMANAGER_H
#define BOAPTMANAGER_H

class CBoAptManager {
public:
	bool mbEnabled;

	void Construct();
	void Render(float param);
};

extern CBoAptManager gAptManager;

#endif // !define BOAPTMANAGER_H
