#include <iostream>
#include <string.h>
using namespace std;
#ifndef POINT_H_
#define POINT_H_
class Point {
protected:
  int x, y, diagonal;
  int width, height;
public:
  Point();
  Point( int x, int y, int diagonal);  
  int getDiagonal() const;
  int getWidth() const;
  int getHeight() const;
  void setX( int x );
  void setY( int y );
  void setDiagonal( int diagonal );
  void setWidth( int width );
  void setHeight( int height );
};
Point::Point() {
  this->x = 0;
  this->y = 0;
  this->diagonal = 0;
}
Point::Point( int x, int y, int diagonal = 0) {
  this->x = x;
  this->y = y;
  this->diagonal = diagonal;
}
int Point::getDiagonal() const {
  return this->diagonal;
}
int Point::getWidth() const {
  return this->width;
}
int Point::getHeight() const {
  return this->height;
}
void Point::setDiagonal( int diagonal ) {
  this->diagonal = diagonal;
}
void Point::setWidth( int width ) {
  this->width = width;
}
void Point::setHeight( int height ) {
  this->height = height;
}
void Point::setX( int x ) {
  this->x = x;
}
void Point::setY( int y ) {
  this->y = y;
}
#endif