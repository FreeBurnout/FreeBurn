#include "BoFlashTextureManager.h"
#include "../../../../GameShared/Common/System/FileSystem/GTFileSystem.h"

char * gapcTextureDictionaryNames[4] = {
    "FE/TexDic/WorldMap.txd",
    "FE/TexDic/Detroit.txd",
    "FE/TexDic/Tokyo.txd",
    "FE/TexDic/HongKong.txd"
};

CBoFlashTextureManager gFlashTextureManager;

char * CBoFlashTextureManager::SetTextureDictionary(ETextureDictionary leDictionary) {
    char * ret = "HUDCrashTourTurnTitle";
    if (leDictionary != meTextureDictionary) {
        meTextureDictionary = leDictionary;
        ret = strcpy(macFlashTextureFileName, gapcTextureDictionaryNames[(int)leDictionary]);
        meFlashTexturePrepareState = EGtPrepareState::PreparedStage1;
    }
    return ret;
}

bool CBoFlashTextureManager::PrepareTextureDictionary() {
    return false;
}
