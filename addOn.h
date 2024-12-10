#include <SFML/Graphics.hpp>
#include "Point.h"
#include "Bomb.h"
#ifndef ADDON_H_
#define ADDON_H_
using namespace sf;

class AddOn : public Point {
protected:
  Sprite sprite;
  int interval; 
  double scaleX, scaleY;
  string addOnType;
public:
  AddOn();
  AddOn( int x, int y, Texture& texture );
  bool moveAddOn();
  bool boundaryCheck();
  int getPosX() const;
  int getPosY() const;
  double getScaleX() const;
  double getScaleY() const;
  int getInterval() const;
  string getAddOnType() const;
  //void setSpirte( Sprite& sprite);
  const Sprite getSprite() const;
};
AddOn::AddOn() : Point() {}
AddOn::AddOn( int x, int y, Texture& texture ) : Point( x, y, 0) {
  this->sprite.setTexture( texture );
  this->sprite.setPosition( x, y);
}
bool AddOn::boundaryCheck() {
  if( this->sprite.getPosition().y >= 700 )
    return false;
  else
    return true;
}
bool AddOn::moveAddOn() {
  if( this->boundaryCheck() )
  {
    this->sprite.move( 0, + 10);
    return true;
  }
  else
    return false;
}
int AddOn::getInterval() const {
  return this->interval;
}
string AddOn::getAddOnType() const {
  return this->addOnType;
}
const Sprite AddOn::getSprite() const {
  return this->sprite;
}
int AddOn::getPosX() const {
  return this->sprite.getPosition().x;
}
int AddOn::getPosY() const {
  return this->sprite.getPosition().y;
}
double AddOn::getScaleX() const {
  return this->scaleX;
}
double AddOn::getScaleY() const {
  return this->scaleY;
}
#endif