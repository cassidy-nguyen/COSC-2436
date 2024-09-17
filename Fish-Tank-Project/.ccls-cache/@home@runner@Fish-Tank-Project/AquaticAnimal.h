#ifndef AQUATICANIMAL_H
#define AQUATICANIMAL_H
#include <cstring>

using namespace std;

class AquaticAnimal {
  protected:
    int hunger;
    int health;
    bool hasDisease;
  private:
    float initialPrice;
    float currPrice = initialPrice;
    int age;
    string type;
  public:
    AquaticAnimal(); // conductor
    AquaticAnimal(string type, int hunger, int health, bool hasDisease, float initialPrice, float currPrice, int age); // overloaded conductor
    virtual bool check_environment(float pH_level, float temperature, float volume); // checks if conditions of fish tank are suitable for aquatic animal
    virtual void next_day(); // increases hunger, decreases health, updates health and current price
    bool getSickStatus(); // returns if the animal has a disease
    void changeDisease() {return !hasDisease;} // changes sickness of animal
    virtual void status(); // will give the status of each animal;
    void updateHealth(int num); // changes health level
    void updateHunger(int num); // changes hunger level
    virtual void draw() = 0; // draws an ASCII image of animal
    bool hasDied(); // checks if animal is alive or dead
    void updatePrice(); // changes current price
    virtual float getPrice() = 0; // returns current price
    virtual string getType() = 0;
    virtual int getHunger() = 0;
    virtual int getHealth() = 0;
    virtual int getInitial() = 0;
    virtual int getAge() = 0;
};

#endif