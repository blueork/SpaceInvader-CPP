#include "Alpha.h"

Alpha::Alpha() : Invader() {
  this->score = 10;
  this->interval = 5;
  this->enemyType = 1;
}
Alpha::Alpha( int x, int y, Texture& texture) : Invader( x, y, texture, 1 )
{
  this->sprite.setTextureRect( IntRect(0, 0, 124, 106) );
  this->sprite.setScale( 0.5, 0.5);
  this->width = 124;
	this->height = 106;
  this->score = 10;
  this->interval = 5; 
}
Alpha::Alpha( const Enemy& copy, Texture& texture) : Invader( copy.getPosX(), copy.getPosY(), texture, 1) {
  this->sprite.setTextureRect( IntRect(0, 0, 124, 106) );
  this->width = 124;
	this->height = 106;
  this->score = 10;
  this->interval = 5; 
}
Alpha::Alpha( const Invader& copy, Texture& texture) : 
  Invader( copy.sprite.getPosition().x, copy.sprite.getPosition().y, texture, 1 ) {
  this->sprite.setTextureRect( IntRect(0, 0, 124, 106) );
  this->width = 124;
	this->height = 106;
  this->score = 10;
  this->interval = 5; 
}
Alpha::Alpha( const Alpha& copy, Texture& texture ) 
: Invader( copy.sprite.getPosition().x, copy.sprite.getPosition().y, texture, 1) {
  this->sprite.setTextureRect( IntRect(0, 0, 124, 106) );
  this->width = 124;
	this->height = 106;
  this->score = 10;
  this->interval = 5;   
}
