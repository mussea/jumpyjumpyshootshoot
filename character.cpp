#include"texture.h"
#include "character.h"


Character::Character(int n, int x, int y, int w, int h){
     xposition = x;
     yposition = y;
     width = w;
     height = h;
     name = n;
     direction = 1;
}


int Character::getxposition(){
  return xposition;
}

bool Character::checkcolide(int x, int y, int w, int h) {
     if (x >= xposition  && y >= yposition &&
         x <= xposition + width &&
         y <= yposition  + height){
       return 1;}
     if (x + w >= xposition  && y >= yposition &&
         x + w <= xposition + width &&
         y <= yposition  + height){
       return 1;}
     if (x >= xposition  && y + h >= yposition &&
         x <= xposition + width &&
         y + h <= yposition  + height){
       return 1;}
     if (x + w >= xposition  && y + h >= yposition &&
         x + w <= xposition + width &&
         y + h <= yposition  + height){
       return 1;}
     else return 0;
} 

void Character::draw(){
  drawTexture(name, xposition, yposition, width, height);
}

