#include "BoMenuFlowManager.h"

CBoMenuFlowManager gMenuFlowManager;

void CBoMenuFlowManager::Construct(void* lpOwner, const CGtStateOffset* lpOffsetTable, CGtTimer* lpStateTimer) {

}

CGtStateOffset* CBoMenuFlowManager::GetOffsetTable() {
	return CBoMenuFlowManager::maOffsetTable;
}
