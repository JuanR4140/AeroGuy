#include "init.h"
#include <nf_lib.h>

void init(){
    NF_Set2D(0, 0); //initalize the top screen with the mode "0"
    NF_Set2D(1, 0); //initalize the bottom screen with the mode "0"
    NF_SetRootFolder("NITROFS"); //set the root folder to "NITROFS" or "nitrofiles"

    NF_InitTiledBgBuffers(); //initialize the background buffers
    NF_InitTiledBgSys(0); //initalize the bg system on the top screen
    NF_InitTiledBgSys(1); //initalize the bg system on the bottom screen

    NF_InitTextSys(1); //initalize the text system on the bottom screen

    NF_InitSpriteBuffers(); //initalize the sprite buffers
    NF_InitSpriteSys(0); //initalize the sprite system on the top screen
    NF_InitSpriteSys(1); //initalize the sprite system on the bottom screen
}
