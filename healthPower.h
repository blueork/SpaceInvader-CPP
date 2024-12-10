#include <SFML/Graphics.hpp>
#include "Point.h"
//#include "Bomb.h"
#include "addOn.h"
#ifndef HEALTHPOWER_H_
#define HEALTHPOWER_H_

class HealthPower : public AddOn {
public:
  HealthPower();
  HealthPower( int x, int y, Texture& texture);
};
HealthPower::HealthPower() : AddOn() {}
HealthPower::HealthPower( int x, int y, Texture& texture) : AddOn( x, y, texture) {
  this->sprite.setTextureRect( IntRect( 34, 96, 34, 33) );
  this->scaleX = 0.75;
  this->scaleY = 0.75;
  this->sprite.setScale( this->scaleX, this->scaleY);
  this->addOnType = "Health";
  this->width = 34;
  this->height = 33;
  this->interval = 0;
}


#endif