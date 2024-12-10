#include "Bullet.h"

Bullet::Bullet() : Point() {}
Bullet::Bullet( int x, int y) : Point( x, y, 0) {
  this->sprite.setPosition( x, y);
  this->sprite.setScale( 0.75, 0.75 );
  this->scaleX = 0.75;
  this->scaleY = 0.75;
}
Bullet::Bullet( const Bullet& bullet, Texture& texture ) : Point( bullet.bulletX() , bullet.bulletY(), 0 ) {
  this->sprite.setTexture( texture );
  this->sprite.setTextureRect( bullet.sprite.getTextureRect() );
  this->sprite.setPosition( x, y);
  // this->scaleX = bullet.getScaleX();
  // this->scaleY = bullet.getScaleY();
  this->sprite.setScale( 0.75, 0.75 );
  this->width = bullet.width;
  this->height = bullet.height;  
  this->diagonal = bullet.getDiagonal();
}
bool Bullet::boundaryCheck() {
  if( this->sprite.getPosition().y < 0 )
    return false;
  else if( this->sprite.getPosition().x < 0 )
    return false;
  else if( this->sprite.getPosition().x > 780 )
    return false;
  else
    return true;
}
bool Bullet::moveBullet() {
  if( this->boundaryCheck() )
  {
    float delta_x = 0,delta_y = -20;
    if( this->diagonal == 0 || this->diagonal == 4)
      delta_x=0;
    else if( diagonal == 2 || this->diagonal == 5)
      delta_x = 20;
    else if( diagonal == 1 || this->diagonal == 6)
      delta_x = -20;
    this->sprite.move(delta_x, delta_y);
    return true;
  }
  else
    return false;
}
// void Bullet::deleteBullet( Bullet*& bullet, int& bulletCount, int skip ) {
//   Bullet* temp = new Bullet[ bulletCount - 1 ];
//   int newCount = 0;
//   for( int i = 0; i<bulletCount; ++i)
//   {
//     if( i != skip)
//     {
//       *(temp + newCount ) = Bullet( *(bullet + i) );
//       ++newCount;
//     }
//     else
//       continue;
//   }
//   delete [] bullet;
//   bullet = NULL;
//   bullet = temp;
//   temp = NULL;
//   --bulletCount;
// }
int Bullet::bulletX() const {
  return this->sprite.getPosition().x;
}
int Bullet::bulletY() const {
  return this->sprite.getPosition().y;
}
// void Bullet::setScale( double scaleX, double scaleY ) {
//   this->scaleX = scaleX;
//   this->scaleY = scaleY;
// }
// void Bullet::setScaleX( double scaleX ) {
//   this->scaleX = scaleX;
// }
// void Bullet::setScaleY( double scaleY ) {
//   this->scaleY = scaleY;
// }
// double Bullet::getScaleX() const {
//   return this->scaleX;
// }
// double Bullet::getScaleY() const {
//   return this->scaleY;
// }