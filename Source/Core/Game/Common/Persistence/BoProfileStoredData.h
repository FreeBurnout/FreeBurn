#ifndef BOPROFILESTOREDDATA_H
#define BOPROFILESTOREDDATA_H

class CBoProfileStoredData {

};

class CBoProfileSettings {
public:
	void Construct();
	bool Prepare();
	void Update();
	void ConvertFromStoredData(const CBoProfileStoredData*);
	void UpdateStoredData(CBoProfileStoredData*);
};

#endif // !#define BOPROFILESTOREDDATA_H
