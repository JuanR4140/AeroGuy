#include "titleScreen.h"
#include <nds.h>
#include "gl2d.h"
#include <nf_lib.h>

void titleScreen(){
    NF_LoadTiledBg("bg/titlescreen", "top", 256, 256);
    NF_LoadTiledBg("bg/titlescreen2", "bottom", 256, 256);
    NF_CreateTiledBg(0, 0, "top");
    NF_CreateTiledBg(1, 0, "bottom");
    while(1){
        scanKeys();
        int keys = keysHeld();
        if(keys & KEY_START){
            NF_DeleteTiledBg(0, 0);
            NF_DeleteTiledBg(1, 0);
            break;
        }
    }
}