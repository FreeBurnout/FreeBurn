class EAStringC {
public:
	char s_EmptyInternalData[9];
	AptUserFunctions* sAptCallbacks;
	
	EAStringC(const char*);
	EAStringC(const EAStringC&);
	EAStringC(unsigned int);
	EAStringC(unsigned int, unsigned int);
	EAStringC(void);
	~EAStringC(void);

	operator const char* (void); const
	operator!=(const char*); const
	operator+=(const char*);
	operator+=(const EAStringC&);
	operator=(const EAStringC&);
	operator==(const char*); const
	operator==(const EAStringC&); const

	EAStringC& Append(const char*, unsigned int);
	void CalculateHashValue(void); const
	void ChangeBuffer(unsigned int, unsigned int, unsigned int, EAStringC::CBPushZero, unsigned int);
	void Clear(void);
	char* c_str(void); const
	int Delete(int, int);
	EAStringC& Duplicate(const EAStringC&);
	bool EndWithRemove(const char*);
	bool Equal(const char*); const
	int Find(char, int); const
	int Find(const char*, int); const
	void Format(const char*, ...);
	void InitFromBuffer(const char*);
	bool IsEmpty(void); const
	EAStringC Left(int); const
	EAStringC& MakeLower(void);
	EAStringC Mid(int); const
	EAStringC Mid(int, int); const
	void ReserveSize(unsigned int);
	EAStringC& TrimRight(const char*);
	EAStringC& UTF8_Append(const char*, int);
	int UTF8_Find(const char*, int); const
	char* UTF8_GetBuffer(int);
	EAStringC& UTF8_Initialize(int);
	EAStringC& UTF8_MakeLower(void);
	EAStringC& UTF8_MakeUpper(void);
	EAStringC UTF8_Mid(int); const
	EAStringC UTF8_Mid(int, int); const
	char* UTF8_ReadCharacter(const char*, int*);
	int UTF8_Size(void); const
	void vsFormat(const char*, char*);

private:
	DebugDataC* m_pData;

	void AppendFormat(const char*, ...);
	bool EndWith(const char*);
	int FindOneOf(const char*);
	int Insert(int, char);
	int Insert(int, const char*);
	bool IsEnoughSize(unsigned int);
	EAStringC& MakeReverse();
	EAStringC& MakeUpper();
	int Remove(char);
	int Replace(char, char);
	int Replace(const char*, const char*);
	int ReverseFind(char);
	EAStringC Right(int);
	bool StartWithRemove(const char*);
	bool StartWith(const char*);
	EAStringC& TrimLeft(const char*);
	EAStringC& Trim(const char*);
	int UTF8_CharAt(int);
};