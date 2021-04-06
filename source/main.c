#include <stdio.h> 
#include <stdlib.h>
#include <nds.h>
#include <gl2d.h>
#include <nf_lib.h>

#include "init.h"
#include "titleScreen.h"
#include "game.h"

int main(void){
    while(1){
        init(); //function to initialize the DS
        titleScreen(); //function to run the title screen
        game(); //function to run the main game
    }
}
