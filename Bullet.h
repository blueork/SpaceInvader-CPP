#include <iostream>
#include <SFML/Graphics.hpp>
#include <string.h>
#include "Point.h"
#include "Alpha.h"
using namespace sf;
#ifndef BULLET_H_
#define BULLET_H_
class Bullet: public Point {
protected:
  double scaleX, scaleY;
public:
  Sprite sprite;
  Bullet();
  Bullet( int x, int y);
  Bullet( const Bullet& copy, Texture& texture);
  bool boundaryCheck();
  bool moveBullet();
  // void deleteBullet( Bullet*& bullet, int& bulletCount, int skip );
  int bulletX() const;
  int bulletY() const;
  // void setScale( double scaleX, double scaleY );
  // void setScaleX( double scaleX );
  // void setScaleY( double scaleY );
  // double getScaleX() const;
  // double getScaleY() const;
};

#endif