#include "game.h"
#include "move.h"
#include <nf_lib.h>
#include <nds.h>

typedef struct{
    int x;
    int y;
}Object;

void game(){
    Object player = {50, 90};
    NF_LoadSpriteGfx("player", 0, 16, 16);
    NF_LoadSpritePal("player", 0);
    NF_VramSpriteGfx(0, 0, 0, false);
    NF_VramSpritePal(0, 0, 0);

    NF_LoadTiledBg("bg/daybg", "day", 256, 256);
    NF_CreateTiledBg(0, 0, "day");
    NF_CreateSprite(0, 0, 0, 0, player.x, player.y);
    while(1){
        scanKeys();
        int keys = keysHeld();
        move(&player.x, &player.y, keys);
        NF_MoveSprite(0, 0, player.x, player.y);

        NF_SpriteOamSet(0);
        swiWaitForVBlank();
        oamUpdate(&oamMain);
    }
}
