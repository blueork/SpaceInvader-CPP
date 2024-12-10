#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "Bomb.h"
#ifndef MONSTER_H_
#define MONSTER_H_
using namespace sf;

class Monster: public Enemy {

public:
  Monster();
  Monster( int x, int y, Texture& texture);
  virtual bool move();
  virtual void fire( Texture& texture, Bomb* bomb, int bombCount, int x);

};

Monster::Monster() : Enemy() {}
Monster::Monster( int x, int y, Texture& texture) : Enemy( x, y, texture, 4) {
  this->sprite.setScale( 0.25, 0.25 );
  this->width = 665;
  this->height = 665;
  this->score = 40;
  this->interval = 10;
}
bool Monster::move() {
  if( this->x == 360 && this->y == 30)
  {
    if( this->sprite.getPosition().x >= 360 && this->sprite.getPosition().y >= 30 )
    {
      this->x = 500;
      this->y = 30;
      return true;
    }
    else
    {
      this->sprite.move( 0, +20 );
      return false;
    }
  }
  else if( this->x == 500 && this->y == 30 )
  {
    if( this->sprite.getPosition().x >= 500 && this->sprite.getPosition().y >= 30 )
    {
      this->x = 100;
      this->y = 30;
      return true;
    }
    else
    {
      this->sprite.move( + 10, 0);
      return false;
    }
  }
  else if( this->x == 100 && this->y == 30)
  {
    if( this->sprite.getPosition().x <= 100 && this->sprite.getPosition().y >= 30 )
    {
      this->x = 340;
      this->y = 30;
      return true;
    }
    else
    {
      this->sprite.move( - 10, 0);
      return false;
    }
  }
  else if( this->x == 340 && this->y == 30 )
  {
    if( this->sprite.getPosition().x >= 340 && this->sprite.getPosition().y >= 30 )
    {
      this->x = 340;
      this->y = -100;
      return true;
    }
    else
    {
      this->sprite.move( +10, 0);
      return false;
    }
  }
  else if( this->x == 340 && this->y == -100)
  {
    if( this->sprite.getPosition().x >= 340 && this->sprite.getPosition().y <= -100 )
    {
      this->x = 360;
      this->y = 30;
      this->sprite.move( +30, 0 );
      return true;
    }
    else
    {
      this->sprite.move( 0, -20);
      return false;
    }
  }
  return false;
}
void Monster::fire( Texture& texture, Bomb* bomb, int bombCount, int x) {
  if( bombCount > 0)
  {
    (bomb+bombCount-1)->sprite.setScale( 0.5, 1.7);
    (bomb+bombCount-1)->setScale( 0.5, 1.7);
    (bomb+bombCount-1)->sprite.setPosition(this->sprite.getPosition().x+70,this->sprite.getPosition().y+130);
    (bomb+bombCount-1)->sprite.setTextureRect( IntRect(0, 0, 58, 466) );
    (bomb+bombCount-1)->setWidth( 58 );
    (bomb+bombCount-1)->setHeight( 466 );
  }
}


#endif