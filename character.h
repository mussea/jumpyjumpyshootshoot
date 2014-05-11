#ifndef _CHARACTER_
#define _CHARACTER_
#include<iostream>
using namespace std;
#include<fstream>
#ifdef MACOSX
#include<GLUT/glut.h>
#else
#include<GL/glut.h>
#endif
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<sys/time.h>
#include"texture.h"

class Character {
 public:
   bool direction = 0;
   bool show = 0;
   int xposition;
   int yposition;
   int width;
   int height;
   int name;
   Character(int n, int x, int y, int w, int h);
   int getxposition();
   int getyposition() {
     return yposition; } 
   int getheight(){
     return height;}
   int getwidth(){
     return width;}
   bool getdirection(){
     return direction;}
   bool getshow(){
     return show;}
   void updatedirection(bool d){
     direction = d;}
   void updatexposition(int x) {
     xposition = x;}
   void updateyposition(int y){
     yposition = y;}
   void updatetextureID(int textureID){
     name = textureID;}
   void updateshow(bool s){
     show = s;
   }
   void draw();
   void remove() {
     show = 1;
     }
   bool checkcolide(int x, int y, int w, int h);
};



#endif
