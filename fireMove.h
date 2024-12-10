#include <SFML/Graphics.hpp>
#include "Point.h"
//#include "Bomb.h"
#include "addOn.h"
#ifndef FIREMOVE_H_
#define FIREMOVE_H_

class FireMove : public AddOn {

public:
  FireMove();
  FireMove( int x, int y, Texture& texture);
};
FireMove::FireMove() : AddOn() {}
FireMove::FireMove( int x, int y, Texture& texture) : AddOn( x, y, texture) {
  this->sprite.setTextureRect( IntRect( 0, 96, 34, 33) );
  this->scaleX = 0.75;
  this->scaleY = 0.75;
  this->sprite.setScale( this->scaleX, this->scaleY);
  this->addOnType = "Fire";
  this->width = 34;
  this->height = 33;
  this->interval = 0;
}


#endif