#ifndef CRAB_H
#define CRAB_H
#include <cstring>
#include "AquaticAnimal.h"

class Crab : public AquaticAnimal {
  private:
    const float initialPrice = 9;
    float currPrice = 0;
    int age;
    const int sickRate = -20;
    const int hungerRate = 18;
    string type = "crab";
  public:
    Crab(); // constructor
    Crab(string type, int hunger, int health, bool hasDisease, float initialPrice, float currPrice, int age); // overloaded constructor
    bool check_environment(float pH_level, float temperature, float volume); // checks if conditions are survivable for a crab
    float getPrice(); // returns current price of crab
    int getAge(); // returns age of crab
    void next_day(); // updates status accordingly
    void draw(); // draws ASCII art of crab
    void status();
    void updatePrice();
    string getType() {return type;}
    int getHunger() {return hunger;}
    int getHealth() {return health;}
    int getInitial() {return initialPrice;}
};

#endif