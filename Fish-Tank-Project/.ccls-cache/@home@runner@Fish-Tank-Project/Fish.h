#ifndef FISH_H
#define FISH_H
#include <cstring>
#include "AquaticAnimal.h"

class Fish : public AquaticAnimal {
  private:
    const float initialPrice = 5;
    float currPrice = 0;
    int age;
    const int sickRate = -15;
    const int hungerRate = 15;
    string type = "fish";
  public:
    Fish(); // constructor
    Fish(string type, int hunger, int health, bool hasDisease, float initialPrice, float currPrice, int age); // overloaded constructor
    bool check_environment(float pH_level, float temperature, float volume); // checks if conditions are survivable for fish
    float getPrice(); // returns current price of fish
    int getAge(); // returns age of fish
    void next_day(); // updates status accordingly
    void draw(); // draws ASCII art of fish
    void status();
    void updatePrice();
    string getType() {return type;}
    int getHunger() {return hunger;}
    int getHealth() {return health;}
    int getInitial() {return initialPrice;}
};

#endif