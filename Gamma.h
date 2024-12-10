#include <SFML/Graphics.hpp>
#include "Bomb.h"
#include "Enemy.h"
#include "Invader.h"
using namespace sf;
#ifndef GAMMA_H_
#define GAMMA_H_
class Gamma: public Invader {
public:
  Gamma();
  Gamma( int x, int y, Texture& texture);
  Gamma( const Enemy& copy, Texture& texture);
  Gamma( const Invader& copy, Texture& texture);
  Gamma( const Gamma& copy, Texture& texture);
};
Gamma::Gamma() : Invader() {
  this->score = 10;
  this->interval = 5;
  this->enemyType = 2;
}
Gamma::Gamma( const Enemy& copy, Texture& texture) : Invader(copy.getPosX(), copy.getPosY(), texture, 2 ) {
  this->sprite.setTextureRect( IntRect(124, 0, 120, 154) );
  this->width = 120;
	this->height = 154;
  this->score = 10;
  this->interval = 5; 
}
Gamma::Gamma( int x, int y, Texture& texture) : Invader( x, y, texture, 2 )
{
  this->sprite.setTextureRect( IntRect(124, 0, 120, 154) );
  this->sprite.setScale( 0.5, 0.5);
  this->width = 120;
	this->height = 154;
  this->score = 10;
  this->interval = 5; 
}
Gamma::Gamma( const Invader& copy, Texture& texture) : 
  Invader( copy.sprite.getPosition().x, copy.sprite.getPosition().y, texture, 2 ) {
  this->sprite.setTextureRect( IntRect(124, 0, 120, 154) );
  this->width = 120;
	this->height = 154;
  this->score = 10;
  this->interval = 5; 
}
Gamma::Gamma( const Gamma& copy, Texture& texture ) 
: Invader( copy.getPosX(), copy.getPosY(), texture, 2) {
  this->sprite.setTextureRect( IntRect(124, 0, 120, 154) );
  this->width = 120;
	this->height = 154;
  this->score = 10;
  this->interval = 5; 
}
#endif