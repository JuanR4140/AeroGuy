#include "titleScreen.h"
#include <nds.h>
#include "gl2d.h"
#include <nf_lib.h>

void titleScreen(){
    NF_LoadTiledBg("bg/titlescreen", "top", 256, 256); //load a bg from the folder "bg" in "nitrofiles" folder called "titlescreen" with the nickname of "top" and tell the width and height
    NF_LoadTiledBg("bg/titlescreen2", "bottom", 256, 256); //load a bg from the folder "bg" in "nitrofiles" folder called "titlescreen2" with the nickname of "bottom" and tell the width and height
    NF_CreateTiledBg(0, 0, "top"); //create a bg on the top screen, layer 0, with the loaded bg "top"
    NF_CreateTiledBg(1, 0, "bottom"); //create a bg on the bottom screen, layer 0, with the loaded bg "bottom"
    while(1){ //while true, repeats forever
        scanKeys(); //scan keys (I.E the up, left, bottom, right, START, SELECT keys)
        int keys = keysHeld(); //make a boolean (0 = false; 1 = true) to determine if the keys are being held
        if(keys & KEY_START){ //if keys is 1 (true) and the key being pressed is START,
            NF_DeleteTiledBg(0, 0); //delete the bg on the top screen on the 0 layer
            NF_DeleteTiledBg(1, 0); //delete the bg on the bottom screen on the 0 layer
            break; //break out of the loop
        }
    }
}