#ifndef TURTLE_H
#define TURTLE_H
#include <cstring>
#include "AquaticAnimal.h"

class Turtle : public AquaticAnimal {
  private:
    const float initialPrice = 10;
    float currPrice = 0;
    int age;
    const int sickRate = -22;
    const int hungerRate = 13;
    string type = "turtle";
  public:
    Turtle(); // constructor
    Turtle(string type, int hunger, int health, bool hasDisease, float initialPrice, float currPrice, int age); // overloaded constructor
    bool check_environment(float pH_level, float temperature, float volume); // checks if conditions are survivable for turtle
    float getPrice(); // returns current price of turtle
    int getAge(); // returns age of turtle
    void next_day(); // updates status accordingly
    void draw(); // draws ASCII art of turtle
    void status();
    void updatePrice();
    string getType() {return type;}
    int getHunger() {return hunger;}
    int getHealth() {return health;}
    int getInitial() {return initialPrice;}
};

#endif