#include <SFML/Graphics.hpp>
#include <string.h>
#include "Point.h"
#include "Bullet.h"
#include "addOn.h"
using namespace sf;
#ifndef PLAYER_H_
#define PLAYER_H_
class Player: public Point {
private:
  int lives, score;
  bool permHealth;
  Sprite shield;
public:
  Texture tex;
  Sprite sprite;
  float speed=0.3;
  Sprite* lifeSprite;
Player(std::string png_path) : Point(340, 400, 0) {
  tex.loadFromFile(png_path);
  sprite.setTexture(tex);
  sprite.setTextureRect(IntRect(0,0,103,107));
  sprite.setPosition(x,y);
  sprite.setScale(0.75,0.75);
  shield.setTexture(tex);
  shield.setTextureRect( IntRect( 695, 0, 143, 119) );
  shield.setPosition( x, y);
  shield.setScale( 0.75, 0.75);
  this->width = 103;
  this->height = 107;
  this->lives = 3;
  this->lifeSprite = new Sprite[ this->lives ];
  for( int i = 0; i<this->lives; ++i)
  {
    lifeSprite[i].setTexture( tex );
    lifeSprite[i].setTextureRect(IntRect(0,0,103,107));
    lifeSprite[i].setScale( 0.25, 0.25 );
    lifeSprite[i].setPosition( 700 + i * 20, 700 );
  }
  this->score = 0;
  this->permHealth = false;
}
void fire( Texture& texture, Bullet* bullet, int bulletCount ) {
  if( bulletCount > 0)
  {
    if( diagonal == 0 )
    {
      (bullet + bulletCount - 1 )->sprite.setTexture( texture );
      (bullet + bulletCount - 1 )->sprite.setTextureRect( IntRect(0, 0, 9, 54) );
      (bullet + bulletCount - 1 )->setDiagonal( this->diagonal );
      (bullet + bulletCount - 1 )->setHeight( 54 ); //= 54;
      (bullet + bulletCount - 1 )->setWidth(9);
      (bullet+bulletCount-1)->sprite.setPosition(this->sprite.getPosition().x+35,this->sprite.getPosition().y-40);
    }
    else if( diagonal == 1 )
    {
      (bullet + bulletCount - 1 )->sprite.setTexture( texture );
      (bullet + bulletCount - 1 )->sprite.setTextureRect( IntRect(9, 0, 44, 44) );
      (bullet + bulletCount - 1 )->setDiagonal( this->diagonal );
      (bullet + bulletCount - 1 )->setHeight(44);
      (bullet + bulletCount - 1 )->setWidth(44);
      (bullet+bulletCount-1)->sprite.setPosition(this->sprite.getPosition().x+15,this->sprite.getPosition().y-30);
    }
    else if( diagonal == 2 )
    {
      (bullet + bulletCount - 1 )->sprite.setTexture( texture );
      (bullet + bulletCount - 1 )->sprite.setTextureRect( IntRect(0, 54, 44, 44) );
      (bullet + bulletCount - 1 )->setDiagonal( this->diagonal );
      (bullet + bulletCount - 1 )->setHeight(54);
      (bullet + bulletCount - 1 )->setWidth(44);
      (bullet+bulletCount-1)->sprite.setPosition(this->sprite.getPosition().x+70,this->sprite.getPosition().y-30);
    }
    
    (bullet + bulletCount -1)->sprite.setScale( 0.75, 0.75 );
  }
}
void move(std::string s) {
  float delta_x=0,delta_y=0;
  if(s=="l")
	  delta_x = -1;
  else if(s=="r")
	  delta_x = 1;
  if(s=="u")
	  delta_y = -1;
  else if(s=="d")
	  delta_y = 1;

  delta_x*=speed;
  delta_y*=speed;
    
  sprite.move(delta_x, delta_y);
  if( sprite.getPosition().y > 700)
    sprite.setPosition( sprite.getPosition().x , 0 );  //play with values to get better visuals
  else if( sprite.getPosition().y < 0 )
    sprite.setPosition( sprite.getPosition().x , 700 );
  if( sprite.getPosition().x > 700 )
    sprite.setPosition( 0, sprite.getPosition().y );
  else if( sprite.getPosition().x < 0 )
    sprite.setPosition( 700, sprite.getPosition().y );
}
void setEquilibrium() {
  this->diagonal = 0;
  this->sprite.setTextureRect(IntRect(0,0,103,107));
}
void setUpperRightDagonal() {
  this->diagonal = 2;
  this->sprite.setTextureRect(IntRect(103,0,148,148));
}
void setUpperLeftDiagonal() {
  this->diagonal = 1;
  this->sprite.setTextureRect(IntRect(251,0,148,148));
}
// void setDownRightDiagonal() {
//   this->diagonal = 0;
//   this->sprite.setTextureRect(IntRect(399,0,148,148));
// }
// void setDownLeftDiagonal() {
//   this->diagonal = 0;
//  this->sprite.setTextureRect(IntRect(547,0,148,148));
// }
void setOrigin() {
  this->sprite.setPosition( 340, 600);
}
int getLives() const {
  return this->lives;
}
bool operator--() {
  if( this->permHealth == false )
  {
    if( this->lives > 0 )
    {
      if( this->lifeSprite != NULL )
        delete [] this->lifeSprite;
      this->lifeSprite = NULL;
      if( this->lives == 1 )
        this->lives = 0;
      else
      {
        --this->lives;
        this->lifeSprite = new Sprite[ this->lives ];
        for( int i = 0; i<this->lives; ++i)
        {
          lifeSprite[i].setTexture( this->tex );
          lifeSprite[i].setTextureRect(IntRect(0,0,103,107));
          lifeSprite[i].setScale( 0.25, 0.25 );
          lifeSprite[i].setPosition( 700 + i * 20, 700 );
        }
      }
      return false;
    }
    else
      return true;
  }
  else
    return false;
}
void operator++() {
  if( this->lives < 3)
  {
    if( this->lifeSprite != NULL )
      delete [] this->lifeSprite;
    this->lifeSprite = NULL;
    ++this->lives;
    this->lifeSprite = new Sprite[ this->lives ];
    for( int i = 0; i<this->lives; ++i)
    {
      lifeSprite[i].setTexture( this->tex );
      lifeSprite[i].setTextureRect(IntRect(0,0,103,107));
      lifeSprite[i].setScale( 0.25, 0.25 );
      lifeSprite[i].setPosition( 700 + i * 20, 700 );
    }
  }
}
int getScore() const {
  return this->score;
}
void updateScore( int score ){
  this->score += score;
}
Sprite* getLivesSprite() const {
  return this->lifeSprite;
}
void setLivesEquilibrium() {
  for( int i = 0; i<this->lives; ++i)
  {
    lifeSprite[i].setScale( 0.25, 0.25 );
    lifeSprite[i].setPosition( 700 + i * 20, 700 );    
  }
}
void checkAddOn( AddOn*& addOn) {
  if( "Shield" == addOn->getAddOnType() )
    this->permHealth = true;
}
void setDefault() {
  this->permHealth = false;
}
const Sprite getShieldSprite() {
  this->shield.setPosition( this->sprite.getPosition().x - 15, this->sprite.getPosition().y );
  return this->shield;
}
bool getPermHealth() const {
  return this->permHealth;
}
void reset() {
  this->score = 0;
  this->sprite.setTextureRect( IntRect(0,0,103,107) );
  this->sprite.setPosition( 340, 400);
  this->score = 0;
  this->lives = 3;
  this->diagonal = 0;
  if( this->lifeSprite != NULL )
    delete [] this->lifeSprite;
  this->lifeSprite = NULL;
  this->lifeSprite = new Sprite[ this->lives ];
  for( int i = 0; i<this->lives; ++i)
  {
    lifeSprite[i].setTexture( tex );
    lifeSprite[i].setTextureRect(IntRect(0,0,103,107));
    lifeSprite[i].setScale( 0.25, 0.25 );
    lifeSprite[i].setPosition( 700 + i * 20, 700 );
  }
  this->permHealth = false;
}
}; 
#endif