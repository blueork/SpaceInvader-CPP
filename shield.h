#include <SFML/Graphics.hpp>
#include "Point.h"
#include "Bomb.h"
#include "addOn.h"
#ifndef SHIELD_H_
#define SHIELD_H_

class Shield : public AddOn {
public:
  Shield();
  Shield( int x, int y, Texture& texture);
};
Shield::Shield() : AddOn() {}
Shield::Shield( int x, int y, Texture& texture) : AddOn( x, y, texture) {
  this->sprite.setTextureRect( IntRect( 68, 96, 34, 33) );
  this->scaleX = 0.75;
  this->scaleY = 0.75;
  this->sprite.setScale( this->scaleX, this->scaleY);
  this->addOnType = "Shield";
  this->width = 34;
  this->height = 33;
  this->interval = 0;
}
#endif