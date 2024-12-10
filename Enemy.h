#include <SFML/Graphics.hpp>
#include <cmath>
#include "Point.h"
#include "Bomb.h"
//#include "player.h"
#ifndef ENEMY_H_
#define ENEMY_H_
using namespace sf;

class Enemy : public Point {
public:
  Sprite sprite;
  int score, interval, enemyType;
public:
  Enemy();
  Enemy( int x, int y, Texture& texture, int enemyType );
  const Sprite& getSprite() const;
  void setSpriteTexture( Texture& texture );
  void setPosition( int x, int y);
  int getPosX() const;
  int getPosY() const;
  int getScore() const;
  int getInterval() const;
  int getEnemyType() const;
  void setScore( int score);
  void setInterval( int interval);
  void setEnemyType( int enemyType);
  virtual void fire( Texture& texture, Bomb* bomb, int bombCount, int x) = 0;
  virtual void setRectangle( Enemy** enemy) {};
  virtual void setCircle( Enemy** enemy) {};
  virtual void setTriangle( Enemy** enemy) {};
  virtual void setDiamond( Enemy**& enemy) {};
  virtual void setHeart(Enemy **& enemy) {};
  virtual void setCross(Enemy **& enemy) {};
  virtual bool move();
};

Enemy::Enemy() : Point() { }
const Sprite& Enemy::getSprite() const {
  return this->sprite;
}
bool Enemy::move() {
  cout<<"Hello";
  return true;
}
Enemy::Enemy( int x, int y, Texture& texture, int enemyType ) : Point( x, y, 0) {
  this->sprite.setTexture( texture );
  this->sprite.setPosition( x, y);
  this->sprite.setScale( 0.5, 0.5);
  // if( enemyType == 1) {
  // // this->sprite.setTextureRect( IntRect(0, 0, 124, 106) );
  // this->width = 124;
	// this->height = 106;
  // this->score = 10;
  // this->interval = 5; 
  // }
  // else if( enemyType == 2) {
  //   //this->sprite.setTextureRect( IntRect(124, 0, 120, 154) );
  //   this->width = 120;
	//   this->height = 154;
  //   this->score = 10;
  //   this->interval = 5; 
  // }
  // else if( enemyType == 3) {
  //   // this->sprite.setTextureRect( IntRect(245, 0, 173, 132) );
  //   this->width = 173;
	//   this->height = 132;
  //   this->score = 10;
  //   this->interval = 5;     
  // }
  this->enemyType = enemyType;
}
void Enemy::setSpriteTexture( Texture& texture ) {
  this->sprite.setTexture( texture );
}
void Enemy::setPosition( int x, int y) {
  this->sprite.setPosition( x, y);
}
int Enemy::getPosX() const {
  return this->sprite.getPosition().x;
}
int Enemy::getPosY() const {
  return this->sprite.getPosition().y;
}
int Enemy::getScore() const {
  return this->score;
  }
int Enemy::getInterval() const {
  return this->interval;
}
int Enemy::getEnemyType() const {
  return this->enemyType;
}
void Enemy::setScore( int score) {
  this->score = score;
}
void Enemy::setInterval( int interval) {
  this->interval = interval;
}
void Enemy::setEnemyType( int enemyType) {
  this->enemyType = enemyType;
}
// void Enemy::fire( Texture& texture, Bomb* bomb, int bombCount) {
//   // if( bombCount > 0)
//   // {
//   //   (bomb+bombCount-1)->sprite.setScale( 0.75, 0.75);
//   //   (bomb+bombCount-1)->sprite.setPosition(this->sprite.getPosition().x+28,this->sprite.getPosition().y+40);
//   //   (bomb+bombCount-1)->sprite.setTextureRect( IntRect(0, 0, 9, 54) );
//   // } 
// }
// void Enemy::setRectangle( Enemy** enemy) {
//   for( int i = 0; i<5; ++i)
//     enemy[0][i].sprite.setPosition( i * 153 + 50, 0);
//   for( int i = 0; i<5; ++i)
//     enemy[1][i].sprite.setPosition( i * 153 + 50, 250);
//   enemy[2][0].sprite.setPosition( 50, 90);
//   enemy[2][1].sprite.setPosition( 662, 90);
//   enemy[2][2].sprite.setPosition( 50, 180);
//   enemy[2][3].sprite.setPosition( 662, 180);
// }
// void Enemy::setCircle( Enemy** enemy) {
//   float a = ( 2.0 * 3.14159 )/14;
//   float angle = 0, x, y;
//   for( int i = 0, j = 0, k = 0; i< 14; ++i, ++k) 
//   {
//     angle = a * i;
//     x = std::cos(angle)*170 + 360;
//     y = std::sin(angle)*170 + 200;
//     enemy[j][k].sprite.setPosition( x, y);
//     if( i == 4 || i == 9)
//     {
//       ++j;
//       k = -1;
//     }
//   }
// }
// void Enemy::setTriangle( Enemy** enemy) {
//   for( int i = 0; i<5; ++i)
//     enemy[0][i].sprite.setPosition( 360 + i * 50, i * 50);
//   for( int i = 0; i<5; ++i)
//     enemy[1][i].sprite.setPosition( 280 - i * 50, i * 50);
//   for( int i = 0; i<4; ++i)
//     enemy[2][i].sprite.setPosition( 95 + 150 * i, 290);
// }
#endif