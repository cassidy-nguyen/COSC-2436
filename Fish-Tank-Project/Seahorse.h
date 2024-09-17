#ifndef SEAHORSE_H
#define SEAHORSE_H
#include <cstring>
#include "AquaticAnimal.h"

class Seahorse : public AquaticAnimal {
  private:
    const float initialPrice = 13;
    float currPrice = 0;
    int age;
    const int sickRate = -35;
    const int hungerRate = 40;
    string type = "seahorse";
  public:
    Seahorse(); // constructor
    Seahorse(string type, int hunger, int health, bool hasDisease, float initialPrice, float currPrice, int age); // overloaded constructor
    bool check_environment(float pH_level, float temperature, float volume); // checks if conditions are survivable for seahorse
    float getPrice(); // returns current price of seahorse
    int getAge(); // returns age of seahorse
    void next_day(); // updates status accordingly
    void draw(); // draws ASCII art of seahorse
    void status();
    void updatePrice();
    string getType() {return type;}
    int getHunger() {return hunger;}
    int getHealth() {return health;}
    int getInitial() {return initialPrice;}
};

#endif