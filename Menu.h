#include <SFML/Graphics.hpp>
//#include <Text.hpp>
#include <string>
using namespace sf;

#ifndef MENU_H_
#define MENU_H_
class Menu {
private:
  Font font;
public:
  Menu( Font& font);
  void displayMenu( RenderWindow& window); //Font& font);
};
Menu::Menu( Font& font ) : font(font) { }
void Menu::displayMenu( RenderWindow& window) {
  Text prodHouse( "CD Projekct Red Represents", font, 30), 
  gameName("Retro SpaceShooter", font, 35), 
  choice1("Press 1 to Start New Game", font, 25); 
  //Text choice3("Press 2 for Help", font, 25), 
  Text choice4("Press 2 to Exit the Game", font, 25);  
  prodHouse.setPosition( 180, 50);
  gameName.setPosition( 200, 100);
  choice1.setPosition( 150, 300);
  //choice3.setPosition( 150, 350);
  choice4.setPosition( 150, 350);
  window.draw( prodHouse);
  window.draw( gameName);
  window.draw( choice1);
  //window.draw( choice3);
  window.draw( choice4);

}

#endif