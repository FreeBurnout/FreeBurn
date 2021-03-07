struct CGtDictEntry {
public:
	GtID mID;
	void* mpData;
	RwInt32 mxUserFlags;
};

class CGtDictionaryBase<class T> {
public:
	GtID mDictionaryID;
	RwInt32 mnNumEntries;
	CGtDictEntry* mpaIndex;

	void FixUp();
	RwInt32 GetNumEntries();
	GtID GetDictionaryID();
	RwInt32 GetIndexByID(GtID);
	GtID GetIDByIndex(int);
};