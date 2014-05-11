#ifndef _PLAYER_
#define _PLAYER_
#include<iostream>
#include "character.h"


class Player : public Character {
 public:
  Player(int, int, int, int, int);
  int health = 5;
  int velocity = 0;
  bool onGround = 1; 
  void moveLeft() {
    --xposition; }
  void moveRight() {
    ++xposition; }
  void jump() {
    velocity =5; }
  int getVelocity() {
    return velocity; }
   };


#endif
