#include "BoMenuFlowManager.h"

CGtStateOffset CBoMenuFlowManager::maOffsetTable[58] = {
	{ 0, 3 },
	/*
	{ 0x961E69AEA9654D29, 0x18 }, 
	{ 0x962416E20F09B5A8, 0x30 }, 
	{ 0x962288D54E5E1B2A, 0x550 }, 
	{ 0x94483A2578410651, 0xA70 }, 
	{ 0x94413EE6EE66CE78, 0xAE0 }, 
	{ 0x94413EE6EE66B740, 0xB00 }, 
	{ 0x962C720DB0B4C738, 0xB10 }, 
	{ 0x962C720D87AAD878, 0xB28 }, 
	{ 0x962CBC4132EA1028, 0xB78 }, 
	{ 0x72B837B8B6DA8651, 0xBC8 }, 
	{ 0x72C2FB67E608FCCF, 0xC18 }, 
	{ 0x72C8EB42CEA4FCCF, 0xC28 }, 
	{ 0xB3A430E1CA7ACCF7, 0xC38 }, 
	{ 0x5BCAAF402DE871A0, 0xC48 }, 
	{ 0x5BCAAF402DE90881, 0xC58 }, 
	{ 0x94413EE6C5A81FD7, 0xCF8 }, 
	{ 0x94413EE709551963, 0xD10 }, 
	{ 0x94413E530645EBB8, 0xCC0 }, 
	{ 0x94413E8F1B21EBB8, 0xCD0 }, 
	{ 0x94413F9DD26F4762, 0xCE8 }, 
	{ 0x94413EE695BE7D97, 0xCA8 }, 
	{ 0x96260DA03A3CFFFF, 0xD28 }, 
	{ 0x961F57619210C87F, 0xD40 }, 
	{ 0x9616388F4A196CB8, 0x10C0 },
	{ 0x962400355E616CB8, 0xD50 },
	{ 0x961EBB7795196CB8, 0x10D0 }, 
	{ 0x9618609B552D6CB8, 0x10E8 }, 
	{ 0x96160895DF216CB8, 0x10F8 }, 
	{ 0x961611F08C3D6CB8, 0x1178 }, 
	{ 0x9448879FFAB252C7, 0x1380 }, 
	{ 0x94413FD35BB72F40, 0x16F8 }, 
	{ 0x94413FCEB8B62340, 0x19C0 }, 
	{ 0x94413FCE5FBEBF40, 0x19D8 }, 
	{ 0x94413FCEAC8FC940, 0x19F0 }, 
	{ 0x94413FCEAEB3C2F7, 0x1A08 }, 
	{ 0x9617741639BD5871, 0x1A28 }, 
	{ 0x9617741639C39028, 0x1A48 }, 
	{ 0x9617741639C238A8, 0x1A60 }, 
	{ 0x9617741639C33560, 0x1A78 }, 
	{ 0x96170A24972FEDAC, 0x1B08 }, 
	{ 0x9617741639B6001E, 0x1B18 }, 
	{ 0x962288D46055C9FF, 0x1B30 }, 
	{ 0x96163156BE3D6508, 0x1B48 }, 
	{ 0x94413EDF730D5E97, 0x1C30 }, 
	{ 0x961F6FC6E7B8F9FF, 0x1B60 },
	{ 0x9614A335FC1EF47F, 0x1B78 }, 
	{ 0x9440FEF265EEC78A, 0x1B90 }, 
	{ 0x9441085DFC4EA64B, 0x1BB8 }, 
	{ 0x94410F7E6C98D108, 0x1BE0 }, 
	{ 0x9440AFF473DAEF08, 0x1C00 }, 
	{ 0x94413E70BF8E74AF, 0x1C50 }, 
	{ 0x94413E560E367D57, 0x1C60 }, 
	{ 0x9441401C9FB6451F, 0x1FA0 }, 
	{ 0x9441401457A62820, 0x1FD8 }, 
	{ 0x9441400E39071420, 0x1FE8 }, 
	{ 0x96218D07638BCF02, 0x2050 }, 
	{ 0x96165B62DB143763, 0x20A0 }, 
	{ 0x0, 0x0 }*/
};

void CBoMenuFlowManager::Construct(void* lpOwner, CGtStateOffset* lpOffsetTable, CGtTimer* lpStateTimer) {

}

void CBoMenuFlowManager::Destruct() {

}

void CBoMenuFlowManager::Update() {

}

CGtStateOffset * CBoMenuFlowManager::GetOffsetTable() {
	return nullptr;
}

CBoMenuFlowManager gMenuFlowManager;