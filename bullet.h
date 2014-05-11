#ifndef _BULLET_
#define _BULLET_

#include "character.h"

class Bullet : public Character{
 public:
  int fired = 0;
  Bullet(int, int, int, int, int);
  void move(){
    if (direction == false){
    xposition = xposition + 10;
    }
    if (direction == true){
      xposition = xposition  -10;
    }
  }
 bool checkInMap(int w){
    if ((xposition) < 0){
      return false;
    }
    if (xposition > w){
      return false;
    }
    else return true;
  }
    
};

#endif

