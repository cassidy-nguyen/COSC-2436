#include <iostream>
#include <iomanip>
#include <cstring>
#include "Seahorse.h"

using namespace std;

Seahorse::Seahorse():AquaticAnimal() {
  age = 1;
  currPrice += initialPrice;
}

Seahorse::Seahorse(string type, int hunger, int health, bool hasDisease, float initialPrice, float currPrice, int age) {
  this->type = type;
  this->hunger = hunger;
  this->health = health;
  this->hasDisease = hasDisease;
  this->currPrice = currPrice;
  this->age = age;
}

bool Seahorse::check_environment(float pH_level, float temperature, float volume) {
  if (pH_level < 8 || pH_level > 9.2)
    return false;
  if (temperature < 70 || temperature > 82)
    return false;
  if (volume <= 0) {
    return false;
  }
  return true;
}

float Seahorse::getPrice() {
  return currPrice;
}

int Seahorse::getAge() {
  return age;
}

void Seahorse::next_day() {
  updateHunger(hungerRate);
  if (getSickStatus())
    updateHealth(sickRate);
  age += 1;
  updatePrice();
}

void Seahorse::draw() {
  cout << "       \\\\_" << endl;
  cout << "      ,\"  \"-." << endl;
  cout << "      o ,- .`," << endl;
  cout << "     /.\" / ./" << endl;
  cout << "    // ,\" ..|" << endl;
  cout << "      / /.. ///" << endl;
  cout << "     / /.../--" << endl;
  cout << "    |  |...|\\\\\\" << endl;
  cout << "    |  |../" << endl;
  cout << "     \\ \\./    ,\"." << endl;
  cout << "      \\_\"-,__ `_/" << endl;
  cout << "        \"-.,.-\"" << endl;
}

void Seahorse::status() {
  draw();
  hasDied();
  cout << fixed << setprecision(2) << endl;
  cout << "Animal: Seahorse" << endl;
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

void Seahorse::updatePrice() {
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