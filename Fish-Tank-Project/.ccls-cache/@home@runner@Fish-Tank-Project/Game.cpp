#include "Game.h"
#include <cstdlib>

void Game::start_game() {
  // sets fish tank's environment data according to player
  cout << "Welcome new fish tank manager! Before you can buy your first animal, we need to set up your fish tank:" << endl;
  cout << "What would you like to set your fish tank temperature to?";
  cin >> temp;
  cout << endl << "Excellent! What should the pH level be inside the tank?";
  cin >> pH;
  cout << endl << "Lastly, what is the volume of your fish tank?";
  cin >> vol;
  cout << endl << "Great! Creating your fish tank now..." << endl;
  FishTank myTank(temp, pH, vol);
  myTank.drawTank();
  Crab crab;
  Fish fish;
  Seahorse seahorse;
  Turtle turtle;
  buy();
}

void Game::load_game(string file) {
  ifstream infile;
  infile.open(file);
  if (!infile.is_open()) { // if file does not exist or can't open...
    cout << "We are unable to locate your game progress." << endl;
    return;
  }
  else {
    cout << "Loading game..." << endl;
    infile >> temp >> pH >> vol; // reads tank's conditions
    FishTank myTank(temp, pH, vol); // creates tank based off of conditions
    myTank.drawTank();
    infile >> balance >> amountSold >> numAnimals; // reads next line of data
    for (curr = 0; curr < numAnimals; curr++) { // reads data on each animal
      infile >> _type >> _hunger >> _health >> _hasDisease >> _initial >> _currPrice >> _age;
      if (_type == "fish") {
        Fish myfish(_type, _hunger, _health, _hasDisease, _initial, _currPrice, _age);
        animals[curr] = &myfish;
        animals[curr]->status();
      }
      else if (_type == "crab") {
        Crab mycrab(_type, _hunger, _health, _hasDisease, _initial, _currPrice, _age);
        animals[curr] = &mycrab;
        animals[curr]->status();
      }
      else if (_type == "seahorse") {
        Seahorse myseahorse(_type, _hunger, _health, _hasDisease, _initial, _currPrice, _age);
        animals[curr] = &myseahorse;
        animals[curr]->status();
      }
      else if (_type == "turtle") {
        Turtle myturtle(_type, _hunger, _health, _hasDisease, _initial, _currPrice, _age);
        animals[curr] = &myturtle;
        animals[curr]->status();
      }
    }
    infile.close();
  }
}

void Game::save_game(string file) {
  ofstream outfile;
  outfile.open(file);
  if (!outfile.is_open()) {
    cout << "Invalid file name" << endl;
  }
  else {
    outfile << temp << " " << pH << " " << vol << endl; // saves tank environment conditions
    outfile << balance << " " << amountSold << " " << numAnimals << endl; // saves player's game status (money and how much sold) and number of animals owned
    for (int i = 0; i < numAnimals; i++) { // loop will save each individual animal's data
      if (animals[i] != nullptr) {
        outfile << animals[i]->getType() << " " << animals[i]->getHunger() << " " << animals[i]->getHealth() << " " << animals[i]->getSickStatus() << " " << animals[i]->getInitial() << " " << animals[i]->getPrice() << " " << animals[i]->getAge() << endl;
      }
    }
    outfile.close();
    forceEnd = true;
  }
}

void Game::next_day() {
  int sick = rand() % numAnimals;
  for (int i = 0; i < numAnimals; i++) {
    if (animals[i] != nullptr) {
      animals[i]->next_day();
    }
    if (i == sick) {
      animals[i]->changeDisease();
    }
  }
}

bool Game::checkGameOver() {
  if (balance <= 0) {
    cout << "GAME OVER: player is in debt and buisiness has gone bankrupt" << endl;
    return true;
  }
  else if (amountSold >= target) {
    cout << "GAME OVER: Congratulations! Player has reached target sales goal and business is booming" << endl;
    return true;
  }
  else if (numAnimals == 0 && balance == 0) {
    cout << "GAME OVER: Player has no money and no animals left to sell... you are back where you started" << endl;
    return true;
  }
  else if (forceEnd) {
    cout << "Your session has ended. Please run the program to play again" << endl;
    return true;
  }
  return false;
}

void Game::feed() {
  animals[curr]->updateHunger(-80);
  balance -= 2;
}

void Game::treatment() {
  if (animals[curr]->getSickStatus()) {
    animals[curr]->updateHealth(+95);
    animals[curr]->changeDisease();
  }
  else {
    animals[curr]->updateHealth(-30);
    animals[curr]->changeDisease();
  }
  balance -= 10;
}

void Game::sell() {
  balance += animals[curr]->getPrice();
  animals[curr] = nullptr;
  numAnimals -= 1;
  if (numAnimals == 0) {
    buy();
  }
}

void Game::buy() {
  cout << "Your current balance is $" << balance << "." << endl;
  cout << "Based on the conditions of your fish tank and your balance, you can purchase the following creature(s): " << endl;
  // calculates what creatures player can purchase
  if (crab.check_environment(pH, temp, vol) && crab.getPrice() <= balance)
    cout << "(1) Crab: $" << crab.getInitial() << endl;
  if (fish.check_environment(pH, temp, vol) && fish.getPrice() <= balance)
    cout << "(2) Fish: $" << fish.getInitial() << endl;
  if (seahorse.check_environment(pH, temp, vol) && seahorse.getPrice() <= balance)
    cout << "(3) Seahorse: $" << seahorse.getInitial() << endl;
  if (turtle.check_environment(pH, temp, vol) && turtle.getPrice() <= balance)
    cout << "(4) Turtle: $" << turtle.getInitial() << endl;
  // player purchases an animal
  cout << "Please type the corresponding digit for the creature you would like to purchase.";
  int input;
  cin >> input;
  while (input < 1 || input > 4) {
    cout << "Invalid number. Try again.";
    cin >> input;
  }
  if (input == 1) {
    balance -= crab.getPrice();
    animals[numAnimals] = &crab;
    numAnimals += 1;
  }
  else if (input == 2) {
    balance -= fish.getPrice();
    animals[numAnimals] = &fish;
    numAnimals += 1;
  }
  else if (input == 3) {
    balance -= seahorse.getPrice();
    animals[numAnimals] = &seahorse;
    numAnimals += 1;
  }
  else if (input == 4) {
    balance -= turtle.getPrice();
    animals[numAnimals] = &turtle;
    numAnimals += 1;
  }
}

void Game::printMenu() {
  cout << "___________________________________" << endl;
  cout << "|           ~GAME MENU~           |" << endl;
  cout << "| (1) Feed (costs $2)             |" << endl;
  cout << "| (2) Treatment (costs $10)       |" << endl;
  cout << "| (3) Sell                        |" << endl;
  cout << "| (4) Buy                         |" << endl;
  cout << "| (5) Quit game                   |" << endl;
  cout << "| (6) Save game                   |" << endl;
  cout << "|_________________________________|" << endl;
}

void Game::gameLoop() {
  for (curr = 0; curr < numAnimals; curr++) {
    cout << "DAY " << day << endl;
    if (animals[curr] != nullptr) {
      animals[curr]->status();
    }
    printMenu();
    cout << "Your current balance is $" << balance << endl;
    int input;
    cin >> input;
    while (input < 1 || input > 6) {
      cout << "Not a valid option. Please try again" << endl;
      cin >> input;
    }
    // corresponding actions for each number input
    if (input == 1)
      feed();
    else if (input == 2)
      treatment();
    else if (input == 3)
      sell();
    else if (input == 4)
      buy();
    else if (input == 5) {
      forceEnd = true; // triggers checkGameOver()
    }
    else if (input == 6) {
      cout << "We're sad to see you go :( Please enter the name of the file you would like to save your game under.";
      string fileName;
      cin >> fileName;
      save_game(fileName);
    }
  }
  next_day();
  day += 1;
  cout << endl;
}