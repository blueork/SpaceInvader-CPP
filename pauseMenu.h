#include <SFML/Graphics.hpp>
//#include <Text.hpp>
#include <string>
#include "player.h"
using namespace sf;
#ifndef PAUSEMENU_H_
#define PAUSEMENU_H_

class PauseMenu{
private:
  Font font;
public:
  PauseMenu( Font& font);
  void displayMenu( RenderWindow& window, Player* player); 

};
PauseMenu::PauseMenu( Font& font) : font(font) {}
void PauseMenu::displayMenu( RenderWindow& window, Player* player) {
  Sprite* lifeSprite = player->getLivesSprite();
  for( int i = 0; i<player->getLives(); ++i)
  {
    player->lifeSprite[i].setPosition( 250 + i * 60, 200);
    player->lifeSprite[i].setScale( 0.5, 0.5); 
    window.draw( player->lifeSprite[i] );
  }
  Text gameName("Retro SpaceShooter", font, 25), choice1( "Press P to Resume Game", font, 20),
  choice2("Press R to Reset the Game", font, 20), choice3("Press M to go Back to Main Menu", font, 20),
  choice4("Press E to Exit the Game", font, 20);
  Text score("Score: ", font, 22), livesLeft("Lives Left: ", font, 22);
  gameName.setPosition( 220, 50);
  livesLeft.setPosition( 120, 200);
  score.setPosition( 120, 250);
  window.draw( score);
  score.setString( std::to_string( player->getScore()) );  
  score.setPosition( 220, 250);
  window.draw( score);
  choice1.setPosition( 120, 300);
  choice2.setPosition( 120, 350);
  choice3.setPosition( 120, 400);
  choice4.setPosition( 120, 450);
  window.draw( gameName);
  window.draw( livesLeft);
  window.draw( choice1);
  window.draw( choice2);
  window.draw( choice3);
  window.draw( choice4);
  player->setLivesEquilibrium();
}

#endif