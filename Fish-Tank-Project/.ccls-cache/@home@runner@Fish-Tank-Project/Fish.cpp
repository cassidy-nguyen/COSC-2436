#include <iostream>
#include <iomanip>
#include <cstring>
#include "Fish.h"

using namespace std;

Fish::Fish():AquaticAnimal() {
  age = 1;
  currPrice += initialPrice;
}

Fish::Fish(string type, int hunger, int health, bool hasDisease, float initialPrice, float currPrice, int age){
  this->type = type;
  this->hunger = hunger;
  this->health = health;
  this->hasDisease = hasDisease;
  this->currPrice = currPrice;
  this->age = age;
}

bool Fish::check_environment(float pH_level, float temperature, float volume) {
  if (pH_level < 0 || pH_level > 14)
    return false;
  if (temperature < 0 || temperature > 100)
    return false;
  if (volume <= 0) {
    return false;
  }
  return true;
}

float Fish::getPrice() {
  return currPrice;
}

int Fish::getAge() {
  return age;
}

void Fish::next_day() {
  updateHunger(hungerRate);
  if (getSickStatus())
    updateHealth(sickRate);
  age += 1;
  updatePrice();
}

void Fish::draw() {
 cout << "       /`·.¸" << endl;
 cout << "      /¸...¸`:·" << endl;
 cout << "  ¸.·´  ¸   `·.¸.·´)" << endl;
 cout << " : © ):´;      ¸  {" << endl;
 cout << "  `·.¸ `·  ¸.·´\\`·¸)" << endl;
 cout << "      `\\\\´´\\¸.·´" << endl;
}

void Fish::status() {
  draw();
  hasDied();
  cout << fixed << setprecision(2) << endl;
  cout << "Animal: Fish" << endl;
  cout << "Hunger Level: " << hunger << endl;
  cout << "Health Level: " << health << endl;
  cout << "Has Disease: ";
  if (getSickStatus())
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  cout << "Initial Price: $" << initialPrice << endl;
  cout << "Current Price: $" << currPrice << endl;
  cout << "Age: " << getAge() << endl;
}

void Fish::updatePrice() {
  if (health >= 50) {
    currPrice += 3;
  }
  else {
    currPrice -= 3;
  }
  if (hunger <= 50) {
    currPrice += 2;
  }
  else {
    currPrice -= 2;
  }
  if (health == 0 || hunger == 100) {
    currPrice = 0;
  }
}