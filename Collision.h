#include <SFML/Graphics.hpp>
#include "Point.h"
#include "player.h"
#include "Enemy.h"
#include "Bomb.h"
#include "Alpha.h"
#include "Bullet.h"
#include "Invader.h"
#include "addOn.h"
#include <iostream>
using namespace sf;
#ifndef COLLISION_H_
#define COLLISION_H_

class Collision {
public:
  bool collisionCheck( Player& player, Bomb& bomb);
  bool collisionCheck( Enemy**& invader, Bullet& bullet, int invaderNum1, int invaderNum2 );
  bool collisionCheck( Invader**& invader, Bullet& bullet, int invaderNum1, int invaderNum2 );
  bool collisionCheck( Player& player, Invader**& invader, int invaderNum1, int invaderNum2);
  bool collisionCheck( Player& player, Enemy**& invader, int invaderNum1, int invaderNum2);
  bool collisionCheck( Player& player, Enemy*& enemy);
  bool collisionCheck( Player& player, AddOn*& addOn);
};

bool Collision::collisionCheck( Player& player, Bomb& bomb) {
  if(bomb.sprite.getPosition().x <= player.sprite.getPosition().x + player.getWidth()*0.75 && 
    player.sprite.getPosition().x <= bomb.sprite.getPosition().x + bomb.getWidth()*bomb.getScaleX() &&
    bomb.sprite.getPosition().y <= player.sprite.getPosition().y + player.getHeight()*0.75 && 
    player.sprite.getPosition().y <= bomb.sprite.getPosition().y + bomb.getHeight()*bomb.getScaleY() ) 
    return true;
  else
    return false;
}
bool Collision::collisionCheck( Invader**& invader, Bullet& bullet, int invaderNum1, int invaderNum2 ) {
if( bullet.sprite.getPosition().x <= invader[invaderNum1][invaderNum2].getPosX() + 
    invader[invaderNum1][invaderNum2].getWidth()*0.5 && 
   invader[invaderNum1][invaderNum2].getPosX() <= bullet.sprite.getPosition().x + bullet.getWidth()*0.75 &&
   bullet.sprite.getPosition().y <= invader[invaderNum1][invaderNum2].getPosY() + 
   invader[invaderNum1][invaderNum2].getHeight()*0.5 && 
   invader[invaderNum1][invaderNum2].getPosY() <= bullet.sprite.getPosition().y + bullet.getHeight()*0.75 ) 
    return true;
  else
    return false;
}
bool Collision::collisionCheck( Enemy**& invader, Bullet& bullet, int invaderNum1, int invaderNum2 ) {
if( bullet.sprite.getPosition().x <= invader[invaderNum1][invaderNum2].getPosX() + 
    invader[invaderNum1][invaderNum2].getWidth()*0.5 && 
   invader[invaderNum1][invaderNum2].getPosX() <= bullet.sprite.getPosition().x + bullet.getWidth()*0.75 &&
   bullet.sprite.getPosition().y <= invader[invaderNum1][invaderNum2].getPosY() + 
   invader[invaderNum1][invaderNum2].getHeight()*0.5 && 
   invader[invaderNum1][invaderNum2].getPosY() <= bullet.sprite.getPosition().y + bullet.getHeight()*0.75 ) 
    return true;
  else
    return false;
}
bool Collision::collisionCheck( Player& player, Invader**& invader, int invaderNum1, int invaderNum2) {
if( player.sprite.getPosition().x <= invader[invaderNum1][invaderNum2].getPosX() + 
    invader[invaderNum1][invaderNum2].getWidth()*0.5 && 
   invader[invaderNum1][invaderNum2].getPosX() <= player.sprite.getPosition().x + player.getWidth()*0.75 &&
   player.sprite.getPosition().y <= invader[invaderNum1][invaderNum2].getPosY() + 
   invader[invaderNum1][invaderNum2].getHeight()*0.5 && 
   invader[invaderNum1][invaderNum2].getPosY() <= player.sprite.getPosition().y + player.getHeight()*0.75 ) 
    return true;
  else
    return false;
}
bool Collision::collisionCheck( Player& player, Enemy**& invader, int invaderNum1, int invaderNum2) {
if( player.sprite.getPosition().x <= invader[invaderNum1][invaderNum2].getPosX() + 
    invader[invaderNum1][invaderNum2].getWidth()*0.5 && 
   invader[invaderNum1][invaderNum2].getPosX() <= player.sprite.getPosition().x + player.getWidth()*0.75 &&
   player.sprite.getPosition().y <= invader[invaderNum1][invaderNum2].getPosY() + 
   invader[invaderNum1][invaderNum2].getHeight()*0.5 && 
   invader[invaderNum1][invaderNum2].getPosY() <= player.sprite.getPosition().y + player.getHeight()*0.75 ) 
    return true;
  else
    return false;  
}
bool Collision::collisionCheck( Player& player, Enemy*& enemy) {
if( player.sprite.getPosition().x <= enemy->getPosX() + enemy->getWidth()*0.25 && 
   enemy->getPosX() <= player.sprite.getPosition().x + player.getWidth()*0.75 &&
   player.sprite.getPosition().y <= enemy->getPosY() + enemy->getHeight()*0.25 && 
   enemy->getPosY() <= player.sprite.getPosition().y + player.getHeight()*0.75 ) 
    return true;
  else
    return false; 
}
bool Collision::collisionCheck( Player& player, AddOn*& addOn) {
if( player.sprite.getPosition().x <= addOn->getPosX() + addOn->getWidth() * addOn->getScaleX() && 
   addOn->getPosX() <= player.sprite.getPosition().x + player.getWidth()*0.75 &&
   player.sprite.getPosition().y <= addOn->getPosY() + addOn->getHeight() * addOn->getScaleY() && 
   addOn->getPosY() <= player.sprite.getPosition().y + player.getHeight()*0.75 ) 
    return true;
  else
    return false;
}
#endif