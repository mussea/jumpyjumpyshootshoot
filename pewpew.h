#ifndef _PEWPEW_
#define _PEWPEW_
#include<iostream>
#include "character.h"

class PewPew : public Character {
 public:
  PewPew(int, int, int, int, int);
  void checkPlayerPos (int Playerx) {
    if (Playerx < xposition)
      direction = 1;
    if (Playerx > xposition)
      direction = 0;
     }
};

#endif
