#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include <iostream>
#include <string>
using namespace std;
#include "Menu.h"
#include "pauseMenu.h"
#include "gameOver.h"
#include "player.h"
#include "Point.h"
#include "Enemy.h"
#include "Monster.h"
#include "dragon.h"
#include "Invader.h"
#include "Bullet.h"
#include "Alpha.h"
#include "Gamma.h"
#include "Beta.h"
#include "Bomb.h"
#include "addOn.h"
#include "dangerSign.h"
#include "healthPower.h"
#include "fireMove.h"
#include "shield.h"
#include "Collision.h"
const char title[] = "OOP-Project, Spring-2023";
using namespace sf;

class Game {
public:
  Font comic_sans;
  Sprite background; //Game background sprite
  Texture bg_texture;
  Player* p; //player 
  //Bullet Related Attributes
  Bullet* bullet;
  Texture bulletTex, bulletTex2;
  int bulletCount;
  //Invader Related Attributes
  bool levelDisplay;
  Enemy** invader;
  Texture invaderTex;
  int invaderCount = 0, alphaCount = 0, gammaCount = 0, betaCount = 0;
  int level = 1;
  int phase = 1;
  //Monster Related Attributes
  Enemy* monsterEnemy;
  Texture monsterTex;
  int monsterCount;
  bool monsterOn;
  //Dragon Related Attributes
  Enemy* dragonEnemy;
  Texture dragonTex;
  int dragonCount = 0;
  bool dragonOn = false;
  //Bomb Related Attributes
  Bomb* bomb;
  Texture bombTex, bombTex2;
  int temp1 = 1;
  int bombCount = 0;
  //AddOn Related Attributes
  AddOn* addOn;
  Texture addOnTex;
  int addOnCount = 0;

Game() {
  comic_sans.loadFromFile("img/cuphead.ttf");
  p=new Player("img/playerShip.png");
  //Bullet Related Attributes
  bullet = NULL;
  bulletCount = 0;
  bulletTex.loadFromFile("img/laserBlue.png");
  bulletTex2.loadFromFile("img/fireMove.png");
  //Invader Related Attributes
  this->levelDisplay = true;
  this->invader = NULL;
  this->invaderTex.loadFromFile("img/enemy.png");
  //Monster Related Attributes
  this->monsterEnemy = NULL;
  this->monsterCount = 0;
  this->monsterOn = false;
  this->monsterTex.loadFromFile("img/monster1.png");
  //Dragon Related Attributes
  this->dragonEnemy = NULL;
  this->dragonTex.loadFromFile("img/spritesheet.png");
  //Bomb Related Attributes
  bomb = NULL;
  bombTex.loadFromFile("img/bomb.png");
  bombTex2.loadFromFile("img/fire.png");
  //Background related Attributes
  bg_texture.loadFromFile("img/background.jpg");
  background.setTexture(bg_texture);
  background.setScale(2, 1.5);
  //AddOn Related Attributes
  this->addOn = NULL;
  this->addOnTex.loadFromFile("img/addOn.png");
}

void start_game() {
  Music music;
  music.openFromFile("img/crystals1.ogg");
  srand(time(0));
  RenderWindow window(VideoMode(780, 780), title);
  Clock clock, bulletClock1, bulletClock2, bombClock1, bombClock2, gammaClock, betaClock, levelClock;
  Clock monsterClock, monsterMoveClock, invaderMoveClock, addOnClock1, addOnClock2, dragonClock, dragonMoveClock;
  Clock dragonFireClock;
  float timer=0;
  int temp =1;
  bool upMVMT = false, downMVMT = false, rightMVMT = false, leftMVMT = false, reset = false;
  bool gunOn = false, laserOn = false, addOnOn = false, inContact = false;
  bool menuDisplay = true, gameStart = false, gamePause = false, gameOver = false;
  Menu menu( this->comic_sans);
  PauseMenu pause_menu( this->comic_sans);
  GameOverMenu gameOverMenu( this->comic_sans);
  while (window.isOpen())
  {
    music.play();
    while( menuDisplay)
    {
      window.clear( Color::Black);
      window.draw( background);
      menu.displayMenu( window);
      Event event;
      while( window.pollEvent( event ) )
      {
        if (event.type == Event::Closed)
        {
          music.stop();
          window.close();
        }
        if (event.type == Event::KeyPressed)
        {
          if (event.key.code == Keyboard::Num1)
          {
            gameStart = true;
            menuDisplay = false;
          }
          // else if(menu.key.code == Keyboard::Num3)
          // {
          //     help_display = true;
          //     menu_display = false;
          // }
          else if(event.key.code == Keyboard::Num2)
          {
            music.stop();
            window.close();
          }
        }        
      }
      window.display();
    }
    if( gameStart )
    {
      this->reset();
      gunOn = false, laserOn = false, addOnOn = false, inContact = false, reset = false;
      clock.restart(), bulletClock1.restart(), bulletClock2.restart(), bombClock1.restart(), 
      bombClock2.restart(), gammaClock.restart(), betaClock.restart(), levelClock.restart();
      monsterClock.restart(), monsterMoveClock.restart(), invaderMoveClock.restart(), addOnClock1.restart(), 
      addOnClock2.restart(), dragonClock.restart(), dragonMoveClock.restart(), dragonFireClock.restart();
    }
    while( gameStart )
    {

      window.clear(Color::Black); //clears the screen
	    window.draw(background); 
      upMVMT = downMVMT = rightMVMT = leftMVMT = false;
      float time = clock.getElapsedTime().asSeconds(); 
      clock.restart();
      //timer += time;  

 	    Event e;
      while (window.pollEvent(e))
      {  
        if (e.type == Event::Closed) // If cross/close is clicked/pressed
        {  
          music.stop();
          window.close(); //close the game                        	    
        }
        if( e.type == Event::KeyPressed )
        {
          if (e.key.code == Keyboard::P)         //for pause menu
            gamePause = !gamePause;  
          else if(e.key.code == Keyboard::E)          //exit the game entirely
          { 
            music.stop(); 
            window.close();
          }
          else if(e.key.code == Keyboard::M)
          {
            gameStart = false;
            menuDisplay = true;
            gamePause = false;
            gameOver = false;
          }
          else if(e.key.code == Keyboard::R)
          {
            gameStart = true;
            gamePause = false;
            gameOver = false;
            reset = true;
          }
        }
      }    
	    if (Keyboard::isKeyPressed(Keyboard::Left)) //If left key is pressed
      {
        p->move("l");    // Player will move to left
        leftMVMT = true;
      }
      if (Keyboard::isKeyPressed(Keyboard::Right)) // If right key is pressed
      {
        p->move("r");  //player will move to right
        rightMVMT = true;
      }
      if (Keyboard::isKeyPressed(Keyboard::Up)) //If up key is pressed
      {
        p->move("u");    //playet will move upwards
        upMVMT = true;
      }
      if (Keyboard::isKeyPressed(Keyboard::Down)) // If down key is pressed
      {
        p->move("d");  //player will move downwards
        downMVMT = true;
      }
      ////////////////////////////////////////////////
	    /////  Call your functions here            ////
	    //////////////////////////////////////////////
      if( gameOver )
        gameOverMenu.displayMenu( window, this->p);
      else
      {
        if( gamePause )
          pause_menu.displayMenu( window, this->p ); 
        else
        {
          if( reset )
          {
            reset = false;
            this->reset();
            gunOn = false, laserOn = false, addOnOn = false, inContact = false, reset = false;
            clock.restart(), bulletClock1.restart(), bulletClock2.restart(), bombClock1.restart(), 
            bombClock2.restart(), gammaClock.restart(), betaClock.restart(), levelClock.restart();
            monsterClock.restart(), monsterMoveClock.restart(), invaderMoveClock.restart(), addOnClock1.restart(), 
            addOnClock2.restart(), dragonClock.restart(), dragonMoveClock.restart(), dragonFireClock.restart();
          }
          // window.clear(Color::Black); //clears the screen
          // window.draw(background);  // setting background
          if( this->levelDisplay == false) 
          {
            if( upMVMT == true && rightMVMT == true )
              p->setUpperRightDagonal();
            else if( upMVMT == true && leftMVMT == true )
              p->setUpperLeftDiagonal();
            else if( downMVMT == true && rightMVMT == true )
              p->setUpperLeftDiagonal();
            else if( downMVMT == true && leftMVMT == true )
              p->setUpperRightDagonal();
            else
              p->setEquilibrium();

            if( bulletClock1.getElapsedTime().asSeconds() >= 0.3 && gunOn == true )
            {
              bulletClock1.restart();
              this->createBullet();
              this->p->fire( this->bulletTex, this->bullet, this->bulletCount );
            }
            if( bulletClock2.getElapsedTime().asSeconds() >= 0.08 )
            {
              bulletClock2.restart();
              for( int i = 0; i<bulletCount; ++i)
              {
                if( (bullet + i)->moveBullet() )
                  continue;
                else
                  this->deleteBullet( i );
              }
            }
            int randCheck = rand()%100000;
            if( this->monsterOn == false && randCheck == 659 )
            {
              ++temp;
              if( this->invader != NULL )
              {
                if( this->invader[0][0].move() )
                {
              monsterClock.restart();
              monsterMoveClock.restart();
              this->createMonster();
              while( this->bomb != NULL )
                this->deleteBomb( 0 );
                }
              }
            }
            if( this->monsterOn == true )
            {
              if( monsterMoveClock.getElapsedTime().asSeconds() > 0.1 )
              {
                monsterMoveClock.restart();
                if( this->monsterEnemy->move() )
                {
                  gunOn = true;
                  //bombClock1.restart();
                  laserOn = false;
                  if( this->bomb != NULL )
                    this->deleteBomb( 0 );
                }
                else if( gunOn == true )
                {
                  laserOn = true;
                  if( this->bomb == NULL )
                  {
                    this->createBomb();
                    this->monsterEnemy->fire( this->bombTex, this->bomb, this->bombCount, 0 );
                  }
                  bomb->sprite.setPosition(this->monsterEnemy->sprite.getPosition().x+70,
                  this->monsterEnemy->sprite.getPosition().y+130);
                }
              }
              if( monsterClock.getElapsedTime().asSeconds() > 10 )
              {
                monsterClock.restart();
                this->p->updateScore( this->monsterEnemy[0].getScore() * this->level );
                this->deleteMonster();
                this->deleteBomb( 0 );
                laserOn = false;
                while( this->bullet != NULL )
                  this->deleteBullet( 0 );
                bombClock1.restart();
              }
            }
            if( this->invader == NULL && this->invaderCount == 0 && this->monsterOn == false && this->dragonOn == false)
            {
              this->createLevel( gameOver );
              invaderMoveClock.restart();
              this->p->setOrigin();
              gunOn = false;
            }
            if(this->invader!=NULL&&this->invaderCount!=0&&invaderMoveClock.getElapsedTime().asSeconds()>0.1
              && gunOn == false && this->monsterOn == false && this->dragonOn == false)
            {
              invaderMoveClock.restart();
              gunOn = this->moveInvaders();
            }
            this->collision( gameOver);   
            if( this->levelDisplay == true )
            {
              levelClock.restart();
              while( this->bullet != NULL )
                this->deleteBullet( 0 );
              while( this->bomb != NULL )
                this->deleteBomb( 0 );
              this->p->setOrigin();
            }
            if(invaderCount!=0&&this->alphaCount!=0&&bombClock1.getElapsedTime().asSeconds()>=2&&this->monsterOn==false
              && gunOn == true && this->dragonOn == false) 
            {
              bombClock1.restart();
              this->createBomb();
              int rand1 = rand() % this->alphaCount;
              this->invader[0][rand1].fire( this->bombTex, this->bomb, this->bombCount, 0);
            }
            if(invaderCount!=0&&this->gammaCount!=0&&gammaClock.getElapsedTime().asSeconds()>=3&&this->monsterOn==false
              && gunOn == true && this->dragonOn == false) 
            {
              gammaClock.restart();
              this->createBomb();
              int rand1 = rand() % this->gammaCount;
              this->invader[1][rand1].fire( this->bombTex, this->bomb, this->bombCount, 0);
            }
            if(invaderCount!=0&&this->betaCount!=0&&betaClock.getElapsedTime().asSeconds()>=4&&this->monsterOn==false
              && gunOn == true && this->dragonOn == false) 
            {
              betaClock.restart();
              this->createBomb();
              int rand1 = rand() % this->betaCount;
              this->invader[2][rand1].fire( this->bombTex, this->bomb, this->bombCount, 0);
            }       
            if( bombClock2.getElapsedTime().asSeconds() >= 0.08 )
            {
              bombClock2.restart();
              for( int i = 0; i<bombCount && laserOn == false; ++i)
              {
                if( (bomb + i)->moveBomb() )
                  continue;
                else
                  this->deleteBomb( i );
              }
            }
            //int randomCheck = rand() % 10000;
            if( this->addOn == NULL ) //randomCheck == 500 && 
            {
              this->createAddOn();
              addOnOn = true;
            }
            if( addOnClock2.getElapsedTime().asSeconds() >= 0.05 )
            {
              addOnClock2.restart();
              for( int i = 0; i<addOnCount && addOnOn == true; ++i)
              {
                if( (this->addOn + i)->moveAddOn() )
                  continue;
                else
                {
                  this->deleteAddOn();
                  addOnOn = false;
                }
              }
            }
              if( this->addOnCollision( gameOver) )
              {
                this->p->checkAddOn( this->addOn );
                this->deleteAddOn();
                addOnClock1.restart();
                inContact = true;
              }
              if( inContact == true && addOnClock1.getElapsedTime().asSeconds() > 5 )
              {
                inContact = false;
                addOnClock1.restart();
                this->p->setDefault();
              } 
              //window.clear(Color::Black); //clears the screen
              //window.draw(background);  // setting background
              window.draw(p->sprite);   // setting player on screen
              if( this->p->getPermHealth() )
                window.draw( this->p->getShieldSprite() );
              for( int i = 0; i<this->p->getLives(); ++i )
                window.draw( this->p->lifeSprite[i] );
              this->displayScore( window );
              for( int i = 0; i<bulletCount; ++i)
                window.draw( bullet[i].sprite );
              for( int i = 0; i<this->addOnCount; ++i)
                window.draw( (this->addOn + i)->getSprite() );
              if( this->monsterCount > 0 && this->monsterOn == true)
                window.draw( this->monsterEnemy->sprite );
              if( this->dragonCount > 0 && this->dragonOn == true)
                window.draw( this->dragonEnemy->sprite );
              if( this->invaderCount > 0 && this->monsterOn == false && this->dragonOn == false)
              {
                for( int i = 0; i<this->alphaCount; ++i)
                  window.draw( invader[0][i].sprite );
                for( int i = 0; i<this->gammaCount; ++i)
                  window.draw( invader[1][i].sprite );
                for( int i = 0; i<this->betaCount; ++i)
                  window.draw( invader[2][i].sprite );
              }
              for( int i = 0; i<bombCount; ++i )
                window.draw( bomb[i].sprite );
            }
            else
            {
              if( levelClock.getElapsedTime().asSeconds() > 2 )
              {
                this->levelDisplay = false;
                bulletClock1.restart(), bulletClock2.restart(), bombClock1.restart();
                bombClock2.restart(), gammaClock.restart(), betaClock.restart();
              }
              this->displayLevel( window );
            }
        //window.display();  //Displying all the sprites
        }
      }  
      window.display();
    }
  }
}
void createBullet() {
  if( this->bullet == NULL )
    this->bullet = new Bullet [ 1 ];
  else
  {
    Bullet* temp = new Bullet[ this->bulletCount + 1];
    for( int i = 0; i<this->bulletCount; ++i)
    {
      if( (bullet + i)->getDiagonal() == 4)
        *(temp + i ) = Bullet( *(bullet + i), this->bulletTex2 );
      else
        *(temp + i) = Bullet( *(bullet + i), this->bulletTex );
    }
    *(temp + this->bulletCount) = Bullet();
    delete [] this->bullet;
    this->bullet = NULL;
    this->bullet = temp;
    temp = NULL;
  }
  ++this->bulletCount;
}
void deleteBullet( int skip ) {
  if( this->bullet != NULL )
  {
    if( bulletCount > 1 )
    {
      Bullet* temp = new Bullet[ bulletCount - 1 ];
      int newCount = 0;
      for( int i = 0; i<bulletCount; ++i)
      {
        if( i != skip)
        {
          if( (bullet + i)->getDiagonal() == 4)
            *(temp + newCount ) = Bullet( *(bullet + i), this->bulletTex2 );
          else
            *(temp + newCount ) = Bullet( *(bullet + i), this->bulletTex );
          ++newCount;
        }
        else
          continue;
      } 
      delete [] this->bullet;
      bullet = NULL;
      bullet = temp;
      temp = NULL;
      --bulletCount;
    }
    else
    {
      if( bulletCount != 0)
        delete [] this->bullet;
      this->bullet = NULL;
      this->bulletCount = 0;
    }
  }
}


void deleteInvader( int row, int skip ) {
  if( this->invader != NULL )
  { 
    if( this->invaderCount > 1)
    {
      if( row == 0)
      {
        if( this->invader[row] != NULL )
        {
          if( this->alphaCount > 1 )
          {
            Enemy* temp = new Alpha[ this->alphaCount - 1];
            int newCount = 0;
            for( int i = 0; i<this->alphaCount; ++i)
            {
              if( i != skip )
              {
                temp[newCount] = Alpha( this->invader[row][i], this->invaderTex );
                ++newCount;
              }
              else
                continue;
            }
            delete [] this->invader[row];
            this->invader[row] = NULL;
            this->invader[row] = temp;
            temp = NULL;
            --this->alphaCount;
          }
          else
          {
            if( this->alphaCount != 0)
              delete [] this->invader [ row ];
            this->invader[ row ] = NULL;
            this->alphaCount = 0;
          }
        }
      }
      else if( row == 1)
      {
        if( this->invader[row] != NULL )
        {
          if( this->gammaCount > 1 )
          {
            Enemy* temp = new Gamma[ this->gammaCount - 1];
            int newCount = 0;
            for( int i = 0; i<this->gammaCount; ++i)
            {
              if( i != skip )
              {
                temp[newCount] = Gamma( this->invader[row][i], this->invaderTex );
                ++newCount;
              }
              else
                continue;
            }
            delete [] this->invader[row];
            this->invader[row] = NULL;
            this->invader[row] = temp;
            temp = NULL;
            --this->gammaCount;
          }
          else
          {
            if( this->gammaCount != 0)
              delete [] this->invader [ row ];
            this->invader[ row ] = NULL;
            this->gammaCount = 0;
          }
        }
      }
      else if( row == 2)
      {
        if( this->invader[row] != NULL )
        {
          if( this->betaCount > 1 )
          {
            Enemy* temp = new Beta[ this->betaCount - 1];
            int newCount = 0;
            for( int i = 0; i<this->betaCount; ++i)
            {
              if( i != skip )
              {
                temp[newCount] = Beta( this->invader[row][i], this->invaderTex );
                ++newCount;
              }
              else
                continue;
            }
            delete [] this->invader[row];
            this->invader[row] = NULL;
            this->invader[row] = temp;
            temp = NULL;
            --this->betaCount;
          }
          else
          {
            if( this->betaCount != 0)
              delete [] this->invader [ row ];
            this->invader[ row ] = NULL;
            this->betaCount = 0;
          }
        }
      }
      --this->invaderCount;
    }
    else
    {
      if( this->invaderCount != 0)
        delete [] this->invader[ row ];
      delete [] this->invader;
      this->invader = NULL;
      this->invaderCount = 0;
      this->alphaCount = this->betaCount = this->gammaCount = 0;
      this->levelDisplay = true;
    }
  }
}
void collision( bool& gameOver ) {
  if( this->monsterOn == false && this->dragonOn == false)
  {
    this->invaderBulletCollision();
    this->playerInvaderCollision( gameOver);
  }
  else
    this->playerMonsterCollision( gameOver);
  this->playerBombCollision( gameOver);
}
void invaderBulletCollision() {
  Collision collision;
  for( int i = 0; i<this->bulletCount; ++i)
  {
    for( int j = 0; j<this->alphaCount && this->bulletCount>0; ++j)
    {
      if( collision.collisionCheck( this->invader, *(bullet + i), 0, j ) )
      {
        this->p->updateScore( this->invader[0][j].getScore() * this->level );
        if( this->bullet[i].getDiagonal() != 4 )
          this->deleteBullet( i );
        this->deleteInvader( 0, j );
      }
    }
  }
  for( int i = 0; i<this->bulletCount; ++i)
  {
    for( int j = 0; j<this->gammaCount && this->bulletCount>0; ++j)
    {
      if( collision.collisionCheck( this->invader, *(bullet + i), 1, j ) )
      {
        this->p->updateScore( this->invader[1][j].getScore() * this->level );
        if( this->bullet[i].getDiagonal() != 4 )  
          this->deleteBullet( i );
        this->deleteInvader( 1, j );
      }
    }
  }
  for( int i = 0; i<this->bulletCount; ++i)
  {
    for( int j = 0; j<this->betaCount && this->bulletCount>0; ++j)
    {
      if( collision.collisionCheck( this->invader, *(bullet + i), 2, j ) )
      {
        this->p->updateScore( this->invader[2][j].getScore() * this->level );
        if( this->bullet[i].getDiagonal() != 4 )
          this->deleteBullet( i );
        this->deleteInvader( 2, j );
      }
    }
  }
}
void playerBombCollision(bool& gameOver) {
  Collision collision;
  for( int i = 0; i<this->bombCount; ++i)
  {
    if( collision.collisionCheck( *this->p, *(this->bomb + i) ) )
    {  
      this->deleteBomb( i );
      gameOver = --(*this->p);
      if( gameOver)
        return;      
    }
  }
}
void playerInvaderCollision( bool& gameOver) {
  Collision collision;
  if( this->invaderCount > 0)
  {
    for( int i = 0; i<this->alphaCount; ++i)
      if( collision.collisionCheck( *this->p, this->invader, 0, i ) )
      {
        this->deleteInvader( 0, i );
        gameOver = --(*this->p);
        if( gameOver)
          return;
      }
    for( int i = 0; i<this->gammaCount; ++i)
      if( collision.collisionCheck( *this->p, this->invader, 1, i) )
      { 
        this->deleteInvader( 1, i );
        gameOver = --(*this->p);
        if( gameOver)
        return;
      }
    for( int i = 0; i<this->betaCount; ++i)
      if( collision.collisionCheck( *this->p, this->invader, 2, i) )
      {  
        this->deleteInvader( 2, i );
        gameOver = --(*this->p);
        if( gameOver)
          return;      
      }
  }
}
void playerMonsterCollision( bool& gameOver) {
  Collision collision;
  if( this->monsterCount > 0)
  {
    for( int i = 0; i<this->monsterCount; ++i)
      if( collision.collisionCheck( *this->p, this->monsterEnemy) )
      {  
        gameOver = --(*this->p);
        if( gameOver )
          return;
      }
  }
}
bool addOnCollision( bool& gameOver) {
  Collision collision;
  if( this->addOnCount > 0)
  {
    if( collision.collisionCheck( *this->p, this->addOn ) )
    {
      if( "Meteor" == this->addOn->getAddOnType() )
      {
        this->deleteAddOn();
        gameOver = --(*this->p);
        return false;
      }
      else if( "Health" == this->addOn->getAddOnType() )
      {
        this->deleteAddOn();
        ++(*this->p);
        return false;
      }
      else if ( "Fire" == this->addOn->getAddOnType() )
      {
        this->deleteAddOn();
        this->createBullet();
        this->p->fire( this->bulletTex, this->bullet, this->bulletCount);
        (bullet + bulletCount - 1 )->sprite.setTexture( this->bulletTex2 );
        (bullet + bulletCount - 1 )->sprite.setTextureRect( IntRect( 0, 0, 105, 277) );
        (bullet + bulletCount - 1)->setWidth( 105 );
        (bullet + bulletCount - 1)->setHeight( 277);
        (bullet + bulletCount - 1)->setDiagonal( 4 );
        return false;
      }
      else if( "Shield" == this->addOn->getAddOnType() )
      {
        this->p->checkAddOn( this->addOn );
        return true;
      }
    }
    else
    {
      return false;
    }
  }
  return false;
}
void createBomb() {
  if( this->bomb == NULL )
  {
    this->bomb = new Bomb[ 1 ];
    this->bomb->sprite.setTexture( this->bombTex );
    this->bomb->sprite.setPosition( 300, 300 );
  }
  else
  {
    Bomb* temp = new Bomb[ this->bombCount + 1];
    for( int i = 0; i<this->bombCount; ++i)
      *(temp + i) = Bomb( *(bomb + i), this->bombTex );
    *(temp + this->bombCount) = Bomb( this->bombTex );
    delete [] this->bomb;
    this->bomb = NULL;
    this->bomb = temp;
    temp = NULL;
  }
  ++this->bombCount;
}
void deleteBomb( int skip ) {
  if( this->bomb != NULL )
  {
    if( bombCount > 1 )
    {
      Bomb* temp = new Bomb[ bombCount - 1 ];
      int newCount = 0;
      for( int i = 0; i<bombCount; ++i)
      {
        if( i != skip)
        {
          *(temp + newCount ) = Bomb( *(bomb + i), this->bombTex );
          ++newCount;
        }
        else
          continue;
      } 
      delete [] this->bomb;
      bomb = NULL;
      bomb = temp;
      temp = NULL;
      --bombCount;
    }
    else
    {
      if( bombCount != 0)
        delete [] this->bomb;
      this->bomb = NULL;
      this->bombCount = 0;
    }
  }
}
void createAddOn() {
  if( this->addOn == NULL )
  {
    //int random = rand() % 4;
    int x = rand() % 700;
    int random = 3;
    if( 1 ) 
    {
      this->addOn = new DangerSign[ 1 ];
      *this->addOn = DangerSign( x, -100, this->addOnTex );
    }
    else if( random == 1)
    {
      this->addOn = new HealthPower[ 1 ];
      *this->addOn = HealthPower( x, -100, this->addOnTex );
    }
    else if( random == 2)
    {
      this->addOn = new FireMove[ 1 ];
      *this->addOn = FireMove( x, -100, this->addOnTex );      
    }
    else if( random == 3 )
    {
      this->addOn = new Shield[ 1 ];
      *this->addOn = Shield( x, -100, this->addOnTex );      
    }
    ++this->addOnCount;
  }
  else
  {
    return;
  }
}
void deleteAddOn() {
  if( this->addOn != NULL)
    delete [] this->addOn;
  this->addOn = NULL;
  this->addOnCount = 0;

}
void createLevel( bool& gameOver) {
  if( this->level <=3 )
  {
    this->invaderCount = 14;
    this->alphaCount = 5;
    this->gammaCount = 5;
    this->betaCount = 4;
    if( this->invader != NULL )
      delete [] this->invader;
    this->invader = new Enemy*[ 3 ];
    this->invader[0] = new Alpha[ 5 ];
    this->invader[1] = new Gamma[ 5 ];
    this->invader[2] = new Beta[ 4 ];
    for( int i = 0; i<5; ++i)
    {
      this->invader[0][i] = Alpha( 300, 300, this->invaderTex);
      this->invader[1][i] = Gamma( 300, 300, this->invaderTex);
    }
    for( int i = 0; i<4; ++i)
      this->invader[2][i] = Beta( 300, 300, this->invaderTex);
    if( this->level == 1 )
    { 
      if( this->phase == 1)
      {
        this->invader[0][0].setRectangle( this->invader );
        ++this->phase;
      }
      else if( this->phase == 2)
      {
        this->invader[0][0].setCircle( this->invader );
        ++this->phase;
      }
      else
      {
        this->invader[0][0].setTriangle( this->invader );
        this->phase = 1;
        ++this->level;
      }
    }
    else if( this->level == 2)
    {
      if( this->phase == 1)
      {
        this->invader[0][0].setDiamond( this->invader );
        ++this->phase;
      } 
      else if( this->phase == 2)
      {
        this->invader[0][0].setHeart( this->invader );
        ++this->phase;
      } 
      else
      {
        this->invader[0][0].setCross( this->invader );
        this->phase = 1;
        ++this->level;
      }
    }
    else if( this->level == 3)
    {
      if( this->phase == 1)
      {
        this->invader[0][0].setRectangle( this->invader );
        ++this->phase;
      }
      else if( this->phase == 2)
      {
        this->invader[0][0].setCircle( this->invader );
        ++this->phase;
      }
      else if( this->phase == 3)
      {
        this->invader[0][0].setTriangle( this->invader );
        ++this->phase;
      }
      else if( this->phase == 4)
      {
        this->invader[0][0].setDiamond( this->invader );
        ++this->phase;
      } 
      else if( this->phase == 5)
      {
        this->invader[0][0].setHeart( this->invader );
        ++this->phase;
      } 
      else if( this->phase == 6)
      {
        this->invader[0][0].setCross( this->invader );
        ++this->level;
      }
    }
  }
  else
  { 
    gameOver = true;
    cout<<"Game end reached";
  }
}
void displayLevel( RenderWindow& window) {
  sf:: Text text;
  text.setFont( this->comic_sans );
  text.setCharacterSize(30);
  if( this->level == 1) 
  {
    if( this->phase == 1 )
    {
      text.setString("Level 1");
      text.setCharacterSize(35);
      text.setPosition(340, 300);
      window.draw( text );
      text.setString("Wave 1");
      text.setCharacterSize(30);
      text.setPosition(340, 340);
      window.draw( text );
    }
    else if( this->phase == 2)
    {
      text.setString("Wave 2");
      text.setPosition(340, 340);
      window.draw( text );
    }
    else if( this->phase == 3 )
    {
      text.setString("Wave 3");
      text.setPosition(340, 340);
      window.draw( text );
    }
  }
  else if( this->level == 2)
  {
    if( this->phase == 1 )
    {
      text.setString("Level 2");
      text.setCharacterSize(35);
      text.setPosition(340, 300);
      window.draw( text );
      text.setString("Wave 1");
      text.setCharacterSize(24);
      text.setPosition(340, 340);
      window.draw( text );
    }
    else if( this->phase == 2)
    {
      text.setString("Wave 2");
      text.setPosition(340, 340);
      window.draw( text );
    }
    else if( this->phase == 3 )
    {
      text.setString("Wave 3");
      text.setPosition(340, 340);
      window.draw( text );
    }
  }
  else if( this->level == 3)
  {
    if( this->phase == 1 )
    {
      text.setString("Wave 3");
      text.setCharacterSize(35);
      text.setPosition(340, 300);
      window.draw( text );
      text.setString("Wave 1");
      text.setCharacterSize(24);
      text.setPosition(340, 340);
      window.draw( text );
    }
    else if( this->phase == 2)
    {
      text.setString("Wave 2");
      text.setPosition(340, 340);
      window.draw( text );
    }
    else if( this->phase == 3 )
    {
      text.setString("Wave 3");
      text.setPosition(340, 340);
      window.draw( text );
    }
    else if( this->phase == 4 )
    {
      text.setString("Wave 4");
      text.setPosition(340, 340);
      window.draw( text );
    }
    else if( this->phase == 5)
    {
      text.setString("Wave 5");
      text.setPosition(340, 340);
      window.draw( text );
    }
    else if( this->phase == 6 )
    {
      text.setString("Wave 6");
      text.setPosition(340, 340);
      window.draw( text );
    }
  }
  else
  {
    text.setString("You Finished The Game");
    text.setCharacterSize(35);
    text.setPosition(340, 300);
    window.draw( text );
  }
}
void createMonster() {
  if( this->monsterEnemy != NULL )
    delete [] this->monsterEnemy;
  this->monsterEnemy = NULL;
  ++this->monsterCount;
  this->monsterEnemy = new Monster[ this->monsterCount ];
  *this->monsterEnemy = Monster( 360, -200, this->monsterTex);
  this->monsterEnemy->setY( 30 );
  this->monsterOn = true;
}
void deleteMonster() {
  if( this->monsterEnemy != NULL )
    delete [] this->monsterEnemy;
  this->monsterEnemy = NULL;
  this->monsterCount = 0;
  this->monsterOn = false;
}
void createDragon() {
  if( this->dragonEnemy != NULL )
    delete [] this->dragonEnemy;
  this->dragonEnemy = NULL;
  ++this->dragonCount;
  this->dragonEnemy = new Dragon[ this->dragonCount ];
  *this->dragonEnemy = Dragon( 350, -100, this->dragonTex);
  this->dragonEnemy->setY( 30 );
  this->dragonOn = true; 
}
void deleteDragon() {
  if( this->dragonEnemy != NULL )
    delete [] this->dragonEnemy;
  this->dragonEnemy = NULL;
  this->dragonCount = 0;
  this->dragonOn = false;
}
bool moveInvaders() {
  if( this->invader[0][0].move() )
    return true;
  else
  {
    for( int i = 1; i<this->alphaCount; ++i )
      this->invader[0][i].move();
    for( int i = 0; i<this->gammaCount; ++i )
      this->invader[1][i].move();
    for( int i = 0; i<this->betaCount; ++i )
      this->invader[2][i].move();
    return false;
  }
}
void displayScore( RenderWindow& window) {
  sf:: Text text;
  int score = this->p->getScore();
  text.setFont( this->comic_sans );
  text.setString( "Score: " );
  text.setCharacterSize(24);
  text.setPosition(30, 710);
  window.draw( text );
  text.setString( std::to_string(score) );
  text.setCharacterSize(24);
  text.setPosition(120, 710);
  window.draw( text );
}
void reset() {
  this->level = 1;
  this->phase = 1;
  while( this->bullet != NULL)
    this->deleteBullet( 0 );
  while( this->bomb != NULL)
    this->deleteBomb( 0 );
  while( this->addOn != NULL )
    this->deleteAddOn();
  while( this->invader != NULL )
  {
    this->deleteInvader( 0, 0);
    this->deleteInvader( 1, 0);
    this->deleteInvader( 2, 0);
  }
  this->deleteDragon();  
  this->p->reset();
  this->levelDisplay = true;
}
};

