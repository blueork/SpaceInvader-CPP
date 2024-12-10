#include <SFML/Graphics.hpp>
#include <string>
#include "player.h"
using namespace sf;
#ifndef GAMEOVER_H_
#define GAMEOVER_H_

class GameOverMenu {
private:
  Font font;
public:
  GameOverMenu( Font& font);
  void displayMenu( RenderWindow& window, Player* player);

};
GameOverMenu::GameOverMenu( Font& font ) : font( font ) {}
void GameOverMenu::displayMenu( RenderWindow& window, Player* player) {
  Text gameName("Retro SpaceShooter", font, 25), choice1( "Press R to Play Again", font, 20),
  choice2("Press M to go Back to Main Menu", font, 20), choice3("Press E to Exit the Game", font, 20);
  Text score("Score: ", font, 22);
  gameName.setPosition( 220, 50);
  score.setPosition( 120, 250);
  window.draw( score);
  score.setString( std::to_string( player->getScore()) );  
  score.setPosition( 220, 250);
  window.draw( score);
  choice1.setPosition( 120, 300);
  choice2.setPosition( 120, 350);
  choice3.setPosition( 120, 400);
  window.draw( gameName);
  window.draw( choice1);
  window.draw( choice2);
  window.draw( choice3);
}
#endif