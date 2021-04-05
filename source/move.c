#include "move.h"
#include <nds.h>

//this is dealing with pointers, which I can't explain well. Just search up "C Pointers" on Google

void move(int *x, int *y, int keys){ //take the value x, y, and keys (0 or 1) as parameters
    if(keys & KEY_UP) (*y)--; //if keys is true and the key being held is UP, decrease the y value
    if(keys & KEY_LEFT) (*x)--; //if keys is true and the key being held is LEFT, decrease the x value
    if(keys & KEY_RIGHT) (*x)++; //if keys is true and the key being held is RIGHT, increase the x value
    if(keys & KEY_DOWN) (*y)++; //if keys is true and the key being held is DOWN, increase the y value
}