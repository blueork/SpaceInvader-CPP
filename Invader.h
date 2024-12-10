#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "Bomb.h"
//#include "player.h"
//#include "cmath"
#ifndef INVADER_H_
#define INVADER_H_
using namespace sf;

class Invader: public Enemy {
public:
  //Sprite sprite;
  //int score, interval, invaderType;
public:
  Invader();
  Invader( int x, int y, Texture& texture, int enemyType);
  int getInvaderType() const;
  void setInvaderType( int invaderType ) ;
  // virtual void setSprite( Texture& texture );
  // virtual void setPosition( int x, int y);
  virtual void fire( Texture& texture, Bomb* bomb, int bombCount, int x);
  virtual void setRectangle( Enemy** enemy);
  virtual void setCircle( Enemy** enemy);
  virtual void setTriangle( Enemy** enemy);
  virtual void setDiamond( Enemy**& enemy);
  virtual void setHeart(Enemy **& enemy);
  virtual void setCross(Enemy **& enemy);
  virtual bool move();
};
Invader::Invader() : Enemy() {}
Invader::Invader( int x, int y, Texture& texture, int invaderType) : 
  Enemy(x, y, texture, invaderType) {
  // this->sprite.setTexture( texture );
  // this->sprite.setPosition( x, y);
  // this->sprite.setScale( 0.5, 0.5);
  // if( invaderType == 1) {
  // this->sprite.setTextureRect( IntRect(0, 0, 124, 106) );
  // this->width = 124;
	// this->height = 106;
  // this->score = 10;
  // this->interval = 5; 
  // }
  // else if( invaderType == 2) {
  //   this->sprite.setTextureRect( IntRect(124, 0, 120, 154) );
  //   this->width = 120;
	//   this->height = 154;
  //   this->score = 10;
  //   this->interval = 5; 
  // }
  // else if( invaderType == 3) {
  //   this->sprite.setTextureRect( IntRect(245, 0, 173, 132) );
  //   this->width = 173;
	//   this->height = 132;
  //   this->score = 10;
  //   this->interval = 5;     
  // }
  // this->invaderType = invaderType;
}
int Invader::getInvaderType() const {
  return this->enemyType;
}
void Invader::setInvaderType( int invaderType ) {
  this->enemyType = enemyType;
}
// void Invader::setSprite( Texture& texture ) {
//   this->sprite.setTexture( texture );
// }
// void Invader::setPosition( int x, int y) {
//   this->sprite.setPosition( x, y);
// }

void Invader::fire( Texture& texture, Bomb* bomb, int bombCount, int x) {
  if( bombCount > 0)
  {
    (bomb+bombCount-1)->sprite.setScale( 0.75, 0.75);
    (bomb+bombCount-1)->sprite.setPosition(this->sprite.getPosition().x+28,this->sprite.getPosition().y+40);
    (bomb+bombCount-1)->sprite.setTextureRect( IntRect(0, 466, 9, 54) );
    (bomb+bombCount-1)->setWidth( 9 );
    (bomb+bombCount-1)->setHeight( 54 );
  }
}
void Invader::setRectangle( Enemy** enemy) {
  for( int i = 0; i<5; ++i)
  {
    enemy[0][i].sprite.setPosition( i * 153 + 50, -200);
    enemy[0][i].setY( 0 );
  }
  for( int i = 0; i<5; ++i)
  {
    enemy[1][i].sprite.setPosition( i * 153 + 50, 250 - 200);
    enemy[1][i].setY( 250 );
  }
  enemy[2][0].sprite.setPosition( 50, 90 - 200);
  enemy[2][0].setY( 90 );
  enemy[2][1].sprite.setPosition( 662, 90 - 200);
  enemy[2][1].setY( 90 );  
  enemy[2][2].sprite.setPosition( 50, 180 - 200);
  enemy[2][2].setY( 180 );
  enemy[2][3].sprite.setPosition( 662, 180 - 200);
  enemy[2][3].setY( 180 );
}
void Invader::setCircle( Enemy** enemy) {
  float a = ( 2.0 * 3.14159 )/14;
  float angle = 0, x, y;
  for( int i = 0, j = 0, k = 0; i< 14; ++i, ++k) 
  {
    angle = a * i;
    x = std::cos(angle)*170 + 360;
    y = std::sin(angle)*170 + 200;
    enemy[j][k].sprite.setPosition( x, y - 150);
    enemy[j][k].setY(y);
    if( i == 4 || i == 9)
    {
      ++j;
      k = -1;
    }
  }
}
void Invader::setTriangle( Enemy** enemy) {
  for( int i = 0; i<5; ++i)
  {
    enemy[0][i].sprite.setPosition( 360 + i * 50, i * 50 - 150);
    enemy[0][i].setY( i * 50 );
  }
  for( int i = 0; i<5; ++i)
  {
    enemy[1][i].sprite.setPosition( 280 - i * 50, i * 50 - 150);
    enemy[1][i].setY( i * 50 );
  }
  for( int i = 0; i<4; ++i)
  {
    enemy[2][i].sprite.setPosition( 95 + 150 * i, 290 - 150 );
    enemy[2][i].setY( 290 );
  }
}
void Invader::setDiamond( Enemy**& enemy) {
  for( int i = 0; i<4; ++i)
  {
    enemy[0][i].sprite.setPosition( 340 + i* 50, i * 50 - 150);
    enemy[0][i].setY( i * 50);
  }
  enemy[0][4].sprite.setPosition( 340, 320 - 150 );
  enemy[0][4].setY( 320);
  for( int i = 0; i<4; ++i)
  {
    enemy[1][i].sprite.setPosition( 290 - i* 50, i * 50 - 150);
    enemy[1][i].setY( i * 50);
  }
  enemy[0][4].sprite.setPosition( 290, 320 - 150 );
  enemy[0][4].setY( 320 );  
  enemy[2][0].sprite.setPosition( 190, 220 - 150 );
  enemy[2][0].setY( 220 );
  enemy[2][1].sprite.setPosition( 240, 270 - 150);
  enemy[2][1].setY( 270 );
  enemy[2][2].sprite.setPosition( 440, 220 - 150);
  enemy[2][2].setY( 220 );
  enemy[2][3].sprite.setPosition( 390, 270 - 150);
  enemy[2][3].setY( 270 );
}
void Invader::setHeart(Enemy **&en){
  en[0][0].sprite.setPosition( 270, 90 - 150);
  en[0][0].setY( 90 );
	en[0][1].sprite.setPosition( 400, 90 - 150);
  en[0][1].setY( 90 );
	en[0][2].sprite.setPosition( 190, 160 - 150);
  en[0][2].setY( 1600 );
	en[0][3].sprite.setPosition( 230, 230 - 150);
	en[0][3].setY( 230 );
  en[0][4].sprite.setPosition( 280, 290 - 150);
  en[0][4].setY( 290 );
	
  en[1][0].sprite.setPosition( 210, 50 - 150);
  en[1][0].setY( 50 );
	en[1][1].sprite.setPosition( 340, 100 - 150);
  en[1][1].setY( 100 );
	en[1][2].sprite.setPosition( 470, 50 - 150);
  en[1][2].setY( 50 );
	en[1][3].sprite.setPosition( 160, 100 - 150);
  en[1][2].setY( 100 );
	en[1][4].sprite.setPosition( 520, 100 - 150);
  en[1][4].setY( 100 );

	en[2][0].sprite.setPosition( 340, 330 - 150);
  en[2][0].setY( 330 );
	en[2][1].sprite.setPosition( 400, 290 - 150);
  en[2][1].setY( 290 );
	en[2][2].sprite.setPosition( 450, 230 - 150);
  en[2][2].setY( 230 );
	en[2][3].sprite.setPosition( 490, 160 - 150);
  en[2][3].setY( 160 );
}
void Invader::setCross(Enemy **& enemy){
	for(int i=0;i<5;i++)
  {
		enemy[0][i].sprite.setPosition( 200+i*50, i*50 - 150 );
    enemy[0][i].setY( i*50 );
  }
	for(int i=0;i<5;i++)
		if(i!=3)
    {
		  enemy[1][i].sprite.setPosition(500-i*50,i*50 - 150);
      enemy[1][i].setY( i*50 );
    }
  enemy[1][3].sprite.setPosition( 350, 250 - 150);
  enemy[1][3].setY( 250 );
	enemy[2][0].sprite.setPosition( 450, 250 - 150);
  enemy[2][0].setY( 250 );
  enemy[2][1].sprite.setPosition( 500, 300 - 150);
  enemy[2][1].setY( 300 );
  enemy[2][2].sprite.setPosition( 250, 250 - 150);
  enemy[2][2].setY( 250 );
	enemy[2][3].sprite.setPosition( 200, 300 - 150);
  enemy[2][3].setY( 300 );
}
bool Invader::move() {
  if( this->sprite.getPosition().y >= this->y )
    return true;
  else
  {
    this->sprite.move( 0 , + 20 );
    return false;
  }
}
#endif