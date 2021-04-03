#include "move.h"
#include <nds.h>

void move(int *x, int *y, int keys){
    if(keys & KEY_UP) (*y)--;
    if(keys & KEY_LEFT) (*x)--;
    if(keys & KEY_RIGHT) (*x)++;
    if(keys & KEY_DOWN) (*y)++;
}