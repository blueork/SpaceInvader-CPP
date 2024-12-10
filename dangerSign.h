#include <SFML/Graphics.hpp>
#include "Point.h"
//#include "Bomb.h"
#include "addOn.h"
#ifndef DANGERSIGN_H_
#define DANGERSIGN_H_

class DangerSign : public AddOn {
public:
  DangerSign();
  DangerSign( int x, int y, Texture& texture);

};
DangerSign::DangerSign() : AddOn() {}
DangerSign::DangerSign( int x, int y, Texture& texture) : AddOn( x, y, texture) {
  this->sprite.setTextureRect( IntRect( 0, 0, 98, 96) );
  this->scaleX = 0.5;
  this->scaleY = 0.5;
  this->sprite.setScale( this->scaleX, this->scaleY);
  this->addOnType = "Meteor";
  this->width = 98;
  this->height = 96;
  this->interval = 0;
}


#endif