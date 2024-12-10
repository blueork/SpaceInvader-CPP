#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "player.h"
#include "Bomb.h"
#ifndef DRAGON_H_
#define DRAGON_H_
using namespace sf;

class Dragon: public Enemy {

public:
  Dragon();
  Dragon( int x, int y, Texture& texture);
  virtual bool move();
  virtual void fire( Texture& texture, Bomb* bomb, int bombCount, int x);
  void setEquilibirum();
};

Dragon::Dragon() : Enemy() {}
Dragon::Dragon( int x, int y, Texture& texture) : Enemy( x, y, texture, 4) {
  this->sprite.setTextureRect( IntRect( 0, 0, 286, 280) );
  this->sprite.setScale( 0.25, 0.25 );
  this->width = 286;
  this->height = 280;
  this->score = 60;
  this->interval = 10;
}
bool Dragon::move() {
  if( this->x == 350 && this->y >= 30 )
  {
    if( this->sprite.getPosition().x >= 350 && this->sprite.getPosition().y >= 30 )
      return true;
    else
    {
      this->sprite.move( 0, +10);
      return false;      
    }
  }
  return false;
}
void Dragon::fire( Texture& texture, Bomb* bomb, int bombCount, int x) {
  this->sprite.setTextureRect( IntRect(286, 0, 286, 280) );
  (bomb+bombCount-1)->sprite.setTexture( texture);
  (bomb+bombCount-1)->sprite.setScale( 0.5, 0.5);
  (bomb+bombCount-1)->setScale( 0.5, 0.5);
  (bomb+bombCount-1)->sprite.setPosition(this->sprite.getPosition().x+70,this->sprite.getPosition().y+130);
  if( x <= 250 )
  {
    (bomb+bombCount-1)->setDiagonal( -1 );
    //(bomb+bombCount-1)->sprite.setTextureRect( IntRect( 0, 277, 244, 287) );
    (bomb+bombCount-1)->sprite.setTextureRect( IntRect( 0, 0, 105, 277) );
    (bomb+bombCount-1)->setWidth( 244 );
    (bomb+bombCount-1)->setHeight( 287 );  
  }
  else if( x <= 500)
  {
    (bomb+bombCount-1)->setDiagonal( 0 );
    (bomb+bombCount-1)->sprite.setTextureRect( IntRect( 0, 0, 105, 277) );
    (bomb+bombCount-1)->setWidth( 105 );
    (bomb+bombCount-1)->setHeight( 277 );  
  }
  else
  {
    (bomb+bombCount-1)->setDiagonal( 1 );
    //(bomb+bombCount-1)->sprite.setTextureRect( IntRect( 0, 564, 244, 287) );
    (bomb+bombCount-1)->sprite.setTextureRect( IntRect( 0, 0, 105, 277) );
    (bomb+bombCount-1)->setWidth( 244 );
    (bomb+bombCount-1)->setHeight( 287 );  
  }
}
void Dragon::setEquilibirum() {
  this->sprite.setTextureRect( IntRect( 0, 0, 286, 280));
}


#endif