#include "game.h"
#include "move.h"
#include <nf_lib.h>
#include <nds.h>

//Now for the main dish ;P

typedef struct{ //make a struct with the values x and y called Object
    int x;
    int y;
}Object;

void game(){
    Object player = {50, 90}; //make an Object called player with the x value 50 and y value 90
    NF_LoadSpriteGfx("player", 0, 16, 16); //load sprite gfx from the "nitrofiles" folder called "player" with the id of 0 and the width and height of 16
    NF_LoadSpritePal("player", 0); //load sprite palette from the "nitrofiles" folder called "player" with the id of 0
    NF_VramSpriteGfx(0, 0, 0, false); //move the player gfx into vram on the top screen, ram and vram of 0, without keeping the frames (even I don't understand this one)
    NF_VramSpritePal(0, 0, 0); //move the player palette into vram on the top screen, with the id of 0 and the slot of 0

    NF_LoadTiledBg("bg/daybg", "day", 256, 256); //load a bg from the folder "bg" in "nitrofiles" folder called "daybg" with the nickname of "day" and tell the width and height
    NF_CreateTiledBg(0, 0, "day"); //create a bg on the top screen, layer 0, with the loaded bg "day"
    NF_CreateSprite(0, 0, 0, 0, player.x, player.y); //create a sprite on the top screen, with the id, gfx, and palette of 0 and x and y of the player (50 x; 90 y)
    while(1){ //while true, repeats forever
        scanKeys(); //scan keys (I.E the up, left, bottom, right, START, SELECT keys)
        int keys = keysHeld();  //make a boolean (0 = false; 1 = true) to determine if the keys are being held
        
        //this is dealing with pointers, which I can't explain well. Just search up "C Pointers" on Google
        move(&player.x, &player.y, keys); //send the x and y value of the player, along with the value of keys in the move function
        NF_MoveSprite(0, 0, player.x, player.y); //move the sprite on the top screen, id of 0 on the x and y value of the player

        NF_SpriteOamSet(0); //set the OAM (Object Attribute Memory (place in memory that deals with sprites)) on the top screen
        swiWaitForVBlank(); //wait for the Vertical Blank
        oamUpdate(&oamMain); //update the OAM
    }
}
