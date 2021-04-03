#include <stdio.h>
#include <stdlib.h>
#include <nds.h>
#include <gl2d.h>
#include <nf_lib.h>

#include "init.h"
#include "titleScreen.h"
#include "game.h"

int main(void){
    init();
    titleScreen();
    game();
}
