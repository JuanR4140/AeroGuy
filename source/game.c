#include "game.h"
#include "move.h"
#include "collision.h"
#include <stdio.h>
#include <nf_lib.h>
#include <nds.h>

//Now for the main dish ;P

typedef struct{ //make a struct with the values x and y called Object
    int x;
    int y;
}Object;

void game(){
    int score = 0; //current score
    char sscore[32]; //the string value of score
    Object player = {50, 90}; //make an Object called player with the x value 50 and y value 90
    Object pollution = {250, 90}; //make an Object called pollution with the x value 250 and y value 90
    NF_LoadSpriteGfx("player", 0, 16, 16); //load sprite gfx from the "nitrofiles" folder called "player" with the id of 0 and the width and height of 16
    NF_LoadSpritePal("player", 0); //load sprite palette from the "nitrofiles" folder called "player" with the id of 0
    NF_VramSpriteGfx(0, 0, 0, false); //move the player gfx into vram on the top screen, ram and vram of 0, without keeping the frames (even I don't understand this one)
    NF_VramSpritePal(0, 0, 0); //move the player palette into vram on the top screen, with the id of 0 and the slot of 0

    NF_LoadSpriteGfx("enemies/pollution", 1, 32, 32); //load sprite gfx from the "nitrofiles" folder called "pollution" with the id of 1 and width and height of 32
    NF_LoadSpritePal("enemies/pollution", 1); //load sprite palette from the "nitrofiles" folder called "pollution" with the id of 1
    NF_VramSpriteGfx(0, 1, 1, false); //move the pollution gfx into vram on the top screen, ram and vram of 1, without keepiing the frames (even I don't understand this one)
    NF_VramSpritePal(0, 1, 1); //move the pollution palette into vram on the top screen, with the id of 1 and the slot of 1

    NF_LoadTiledBg("bg/daybg", "day", 256, 256); //load a bg from the folder "bg" in "nitrofiles" folder called "daybg" with the nickname of "day" and tell the width and height
    NF_LoadTiledBg("bg/gameover", "gameover", 256, 256); //load game over bg
    NF_CreateTiledBg(0, 0, "day"); //create a bg on the top screen, layer 0, with the loaded bg "day"
    NF_CreateTiledBg(1, 0, "day");

    NF_LoadTextFont("font/default", "font", 256, 256, 0); // load a text font from the font folder in nitrofiles called default with the nickname font, width and height of 256 and 0 rotation
    NF_CreateTextLayer(1, 0, 0, "font"); // create a text layer on the bottom screen, layer and rotation of 0 with loaded font "font"
    
    NF_WriteText(1, 0, 1, 1, "Score: 0"); // write text on the bottom screen, layer 0, x and y of 1 with the text "Score: 0"
    NF_UpdateTextLayers(); //update the text layers

    NF_CreateSprite(0, 0, 0, 0, player.x, player.y); //create a sprite on the top screen, with the id, gfx, and palette of 0 and x and y of the player (50 x; 90 y)
    NF_CreateSprite(0, 1, 1, 1, pollution.x, pollution.y); //create a sprite on the top screen, with the id, gfx and palette of 1 and x and y of the pollution (250 x; 90 y;)
    while(1){ //while true, repeats forever
        scanKeys(); //scan keys (I.E the up, left, bottom, right, START, SELECT keys)
        int keys = keysHeld();  //make a boolean (0 = false; 1 = true) to determine if the keys are being held
        
        //this is dealing with pointers, which I can't explain well. Just search up "C Pointers" on Google
        move(&player.x, &player.y, keys); //send the x and y value of the player, along with the value of keys in the move function
        pollution.x--; //decrease the x value of pollution
        if(pollution.x == -50){ //if the x value of pollution is equal to -50,
            pollution.x = 250; //move the pollution to the other end of the screen
            score = score + 100; //increase the score by 100
            sprintf(sscore, "Score: %d", score); //convert the integer of score to a string in sscore as "Score: [value of score]"
            NF_WriteText(1, 0, 1, 1, sscore); //write text on the bottom screen, layer 0, with x and y of 1, writing the string of sscore
            NF_UpdateTextLayers(); //update the text layers
        }
        NF_MoveSprite(0, 0, player.x, player.y); //move the sprite on the top screen, id of 0 on the x and y value of the player
        NF_MoveSprite(0, 1, pollution.x, pollution.y);

        if(checkCollision(player.x, player.y, 16, pollution.x, pollution.y, 32)){ // if checking the collision (passing the x, y, sizes of both objects) returns 1 (true),
            NF_CreateTiledBg(0, 0, "gameover"); //create a bg on the bottom screen with layer 0 with the loaded bg "gameover"
            NF_DeleteSprite(0, 0); //delete the player sprite (id 0) from the top screen
            NF_DeleteSprite(0, 1); //delete the pollution sprite (id 1) from the top screen
            break; // break out of the game (advancing us to the next while true loop)
        }
        NF_SpriteOamSet(0); //set the OAM (Object Attribute Memory (place in memory that deals with sprites)) on the top screen
        swiWaitForVBlank(); //wait for the Vertical Blank
        oamUpdate(&oamMain); //update the OAM
    }

    while(1){
        scanKeys(); //scan keys for input
        int keys = keysHeld(); //boolean if keys are held
        if(keys & KEY_START) break; //if keys are held, break out the loop, which would bring us to the title screen as main.c is a while true loop itself
        NF_WriteText(1, 0, 9, 5, "YOU LOST!"); //make text on top screen, layer 0, 9 x; 5 y; saying "YOU LOST!"
        sprintf(sscore, "Total Game Score: %d", score); //convert score into a string and store it in sscore
        NF_WriteText(1, 0, 5, 7, sscore); //write text stored in sscore
        NF_WriteText(1, 0, 7, 12, "Try again?"); //write text saying "Try again?"
        NF_WriteText(1, 0, 3, 14, "Press START to try again!"); //write text explaining how to try again
        NF_UpdateTextLayers(); //update the text layers

        NF_SpriteOamSet(0); //set the OAM on the top screen
        swiWaitForVBlank(); //wait for Vertical Blank
        oamUpdate(&oamMain); //update the OAM
    }
}
