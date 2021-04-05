#include "collision.h"

int checkCollision(int obj1X, int obj1Y, int obj1px, int obj2X, int obj2Y, int obj2px){ // take in the x, y and size of object 1 and 2
    if(obj1X < obj2X + obj2px && obj1X + obj1px > obj2X && obj1Y < obj2Y + obj2px && obj1Y + obj1px > obj2Y){ // if (a bunch of math to determine if both objects are colliding),
        return 1; // return 1 (true)
    }
    return 0; // return 0 (false)
}