#include <iostream>
#include <iomanip>
#include <cstring>
#include "Crab.h"

using namespace std;

Crab::Crab():AquaticAnimal() {
  age = 1;
  currPrice += initialPrice;
}

Crab::Crab(string type, int hunger, int health, bool hasDisease, float initialPrice, float currPrice, int age) {
  this->type = type;
  this->hunger = hunger;
  this->health = health;
  this->hasDisease = hasDisease;
  this->currPrice = currPrice;
  this->age = age;
}

bool Crab::check_environment(float pH_level, float temperature, float volume) {
  if (pH_level < 7 || pH_level > 8)
    return false;
  if (temperature < 50 || temperature > 60)
    return false;
  if (volume <= 0) {
    return false;
  }
  return true;
}

float Crab::getPrice() {
  return currPrice;
}

int Crab::getAge() {
  return age;
}

void Crab::next_day() {
  updateHunger(hungerRate);
  if (getSickStatus())
    updateHealth(sickRate);
  age += 1;
  updatePrice();
}

void Crab::draw() {
 cout << "      /\\" << endl;
 cout << "     ( /   @ @    ()" << endl;
 cout << "      \\\\ __| |__  /" << endl;
 cout << "       \\/   \"   \\/" << endl;
 cout << "      /-|       |-\\" << endl;
 cout << "     / /-\\     /-\\ \\" << endl;
 cout << "      / /-`---'-\\ \\" << endl;
 cout << "       /         \\ " << endl;
}

void Crab::status() {
  draw();
  hasDied();
  cout << fixed << setprecision(2) << endl;
  cout << "Animal: Crab" << endl;
  cout << "Hunger Level: " << hunger << endl;
  cout << "Health Level: " << health << endl;
  cout << "Has Disease: ";
  if (getSickStatus())
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  cout << "Initial Price: $" << initialPrice << endl;
  cout << "Current Price: $" << currPrice << endl;
  cout << "Age: " << age << endl;
}

void Crab::updatePrice() {
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