#include <rwcore.h>
#include "../../../../GameShared/Common/System/FileSystem/GTFileSystem.h"

class CBoPendingFileRequest {

};

class CBoAsyncDataLoader {
public:
	void Construct();
	void Destruct();
	void Update();
	RwUInt32 QueueLoadRequest(const char * lpcName, bool * lpbCompletionReturn, void * lpBuffer, RwUInt32 luReadLen);
	bool Abort(unsigned int);

private:
	CBoPendingFileRequest maRequests[24];
    CGtFile * mpCurrentStream;
	bool mbAbortInProgress;
	bool mbPendingRead;
	RwUInt32 muHead;
	RwUInt32 muTail;
	RwUInt32 muCurrentId;

	void AbortAll();
	bool IsBusy();
};