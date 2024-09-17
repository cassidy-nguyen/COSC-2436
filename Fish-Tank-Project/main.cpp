#include <iostream>
#include <fstream>
#include "AquaticAnimal.h"
#include "Crab.h"
#include "Fish.h"
#include "FishTank.h"
#include "Game.h"
#include "Seahorse.h"
#include "Turtle.h"
using namespace std;

int main() {
  int input;
  Game myGame;
  // intro "page" for game... figures out if we start or continue a game
  cout << "Hello! Welcome to the Fish Tank Management project. This game was created by Cassidy Nguyen (PSID: 2042567). This current version only permits the player to purchase one of each animal." << endl << "Would you like to (1) start a new game or (2) load a previous game?";
  cin >> input;
  cout << endl;

  // if neither option is selected, program keeps asking player to pick
  while (input != 1 && input != 2)
    {
      cout << "What you entered is not a valid option. Please enter '1' to start a new game or '2' to load a previous game.";
      cin >> input;
      cout << endl;
    }
  // starts a new game
  if (input == 1) {
    myGame.start_game();
  }
  // loads a previous game to continue
  else if (input == 2) {
    string fileName;
    cout << "Welcome back tank owner! Please enter the name of the file that you saved the game under:";
    cin >> fileName;
    myGame.load_game(fileName);
  }

  // triggers game loop
  while (!myGame.checkGameOver()) {
    myGame.gameLoop();
  }
  
  return 0;
}