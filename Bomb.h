#include <SFML/Graphics.hpp>
#include <string.h>
#include "Point.h"
//#include "Alpha.h"
using namespace sf;
#ifndef BOMB_H_
#define BOMB_H_

class Bomb: public Point {
private:
  double scaleX, scaleY;
public:
  Sprite sprite;
  Bomb();
  Bomb( Texture& texture);
  Bomb( int x, int y, Texture& texture);
  Bomb( const Bomb& copy, Texture& texture);
  bool boundaryCheck();
  bool moveBomb();
  void moveBomb( int jump );
  void setScale( double scaleX, double scaleY );
  void setScaleX( double scaleX );
  void setScaleY( double scaleY );
  double getScaleX() const;
  double getScaleY() const;
};
Bomb::Bomb() : Point() {}
Bomb::Bomb( Texture& texture ) : Point() {
  this->sprite.setTexture( texture );
  this->sprite.setScale( 0.75, 0.75 );
  this->scaleX = 0.75;
  this->scaleY = 0.75;
  this->width = 9;
  this->height = 54;
}
Bomb::Bomb( int x, int y, Texture& texture) : Point(x, y, 0) {
  this->sprite.setTexture( texture );
  this->sprite.setScale( 0.75, 0.75 );
  this->scaleX = 0.75;
  this->scaleY = 0.75;
  this->sprite.setPosition( x, y);
  this->width = 9;
  this->height = 54;
}
Bomb::Bomb( const Bomb& copy, Texture& texture) :
 Point( copy.sprite.getPosition().x, copy.sprite.getPosition().y, 0) {
  this->sprite.setTexture( texture );
  this->sprite.setTextureRect( copy.sprite.getTextureRect() );
  this->scaleX = copy.getScaleX();
  this->scaleY = copy.getScaleY();
  this->sprite.setScale( this->scaleX, this->scaleY );
  this->sprite.setPosition( x, y);
  this->width = copy.getWidth();
  this->height = copy.getHeight();
}
bool Bomb::boundaryCheck() {
  if( this->sprite.getPosition().y > 800 )
    return false;
  else
    return true;
}
bool Bomb::moveBomb() {
  if( this->boundaryCheck() )
  {
    float delta_x = 0,delta_y = +20;
    if( this->diagonal == 0)
      delta_x = 0;
    else if( this->diagonal == -1)
      delta_x = -20;
    else if( this->diagonal == 1 )
      delta_x = +20;
    this->sprite.move(delta_x, delta_y);
    return true;
  }
  else
    return false;
}
void Bomb::moveBomb( int jump ) {
  this->sprite.move( 0, jump);
}
void Bomb::setScale( double scaleX, double scaleY ) {
  this->scaleX = scaleX;
  this->scaleY = scaleY;
}
void Bomb::setScaleX( double scaleX ) {
  this->scaleX = scaleX;
}
void Bomb::setScaleY( double scaleY ) {
  this->scaleY = scaleY;
}
double Bomb::getScaleX() const {
  return this->scaleX;
}
double Bomb::getScaleY() const {
  return this->scaleY;
}
#endif