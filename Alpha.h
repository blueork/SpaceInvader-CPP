#include <SFML/Graphics.hpp>
#include "Bomb.h"
#include "Invader.h"
using namespace sf;
#ifndef ALPHA_H_
#define ALPHA_H_

class Alpha: public Invader {
public:
  Alpha();
  Alpha( int x, int y, Texture& texture);
  Alpha( const Enemy& copy, Texture& texture);
  Alpha( const Invader& copy, Texture& texture);
  Alpha( const Alpha& copy, Texture& texture);
  //void fire( Texture& texture, Bomb* bomb, int bombCount );
  //void setRectangle( Alpha* alpha, int alphaCount );
};

#endif