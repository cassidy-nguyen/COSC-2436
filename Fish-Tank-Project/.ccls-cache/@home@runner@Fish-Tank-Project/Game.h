#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <fstream>
#include <cstring>
#include "AquaticAnimal.h"
#include "Crab.h"
#include "Fish.h"
#include "FishTank.h"
#include "Seahorse.h"
#include "Turtle.h"
using namespace std;

class Game {
  private:
    float temp;
    float pH;
    float vol;
    // variables with _ are for input values for loading previous games
    string _type;
    int _hunger, _health, _age;
    bool _hasDisease;
    float _initial, _currPrice;
    float balance = 40; // the player's current amount of money
    float amountSold = 0; // how much the player has earned from selling animals
    const float target = 50; // the goal of how much the player needs to make through selling to win the game
    string file; // name of file whether to save or load game
    int numAnimals = 0; // total number of animals the player has
    AquaticAnimal *animals[10]; // ptr array: holds all animals that the player possesses
    int curr; // for looping
    Crab crab;
    Fish fish;
    Seahorse seahorse;
    Turtle turtle;
    int day = 1;
    bool forceEnd = false; // ends game automatically if player quits or saves game
  public:
    void start_game(); // begins a new game
    void load_game(string file); // finds a file with information about previous game
    void save_game(string file); // saves game in a new file
    void next_day(); // updates all animals accordingly
    bool checkGameOver(); // checks if game continues or not
    void feed(); // decreases hunger level
    void treatment(); // increases health level
    void sell(); // increases balance and decreases animal count
    void buy(); // decreases balance and increaes animal count
    void printMenu(); // gives player options on possible actions for each animal
    void gameLoop(); // game loop that allows player to select an action for each animal
    int getNumAnimals(); // returns number of animals player owns
};

#endif