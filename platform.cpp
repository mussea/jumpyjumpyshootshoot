#include "platform.h" 

Platform::Platform(int n, int x, int y, int w, int h) : Character(n, x, y, w, h){}
bool Platform::checktouch(int x, int y, int w, int h) {
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
