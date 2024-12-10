#include <SFML/Graphics.hpp>
#include "Bomb.h"
#include "Invader.h"
#include "Enemy.h"
using namespace sf;
#ifndef BETA_H_
#define BETA_H_
class Beta: public Invader {
public:
  Beta();
  Beta( int x, int y, Texture& texture);
  Beta( const Enemy& copy, Texture& texture);
  Beta( const Invader& copy, Texture& texture);
  Beta( const Beta& copy, Texture& texture);
};
Beta::Beta() : Invader() {
  this->score = 10;
  this->interval = 5;
  this->enemyType = 2;
}
Beta::Beta( int x, int y, Texture& texture) : Invader( x, y, texture, 3 )
{
  this->sprite.setTextureRect( IntRect(245, 0, 173, 132) );
  this->sprite.setScale( 0.5, 0.5);
  this->width = 173;
	this->height = 132;
  this->score = 10;
  this->interval = 5; 
}
Beta::Beta( const Enemy& copy, Texture& texture) : Invader(copy.getPosX(), copy.getPosY(), texture, 3) {
  this->sprite.setTextureRect( IntRect(245, 0, 173, 132) );
  this->width = 173;
	this->height = 132;
  this->score = 10;
  this->interval = 5; 
}
Beta::Beta( const Invader& copy, Texture& texture) : 
  Invader( copy.sprite.getPosition().x, copy.sprite.getPosition().y, texture, 3 ) {
  this->sprite.setTextureRect( IntRect(245, 0, 173, 132) );
  this->width = 173;
	this->height = 132;
  this->score = 10;
  this->interval = 5; 
}
Beta::Beta( const Beta& copy, Texture& texture ) 
: Invader( copy.sprite.getPosition().x, copy.sprite.getPosition().y, texture, 3 ) {
  this->sprite.setTextureRect( IntRect(245, 0, 173, 132) );
  this->width = 173;
	this->height = 132;
  this->score = 10;
  this->interval = 5; 
}
#endif
