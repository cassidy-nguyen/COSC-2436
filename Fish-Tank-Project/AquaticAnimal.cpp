#include <iostream>
#include <iomanip>
#include "AquaticAnimal.h"
using namespace std;

AquaticAnimal::AquaticAnimal() {
  health = 70;
  hunger = 70;
  hasDisease = false;
  initialPrice = 4;
  age = 1;
}

AquaticAnimal::AquaticAnimal(string type, int hunger, int health, bool hasDisease, float initialPrice, float currPrice, int age) {
  this->type = type;
  this->hunger = hunger;
  this->health = health;
  this->hasDisease = hasDisease;
  this->initialPrice = initialPrice;
  this->currPrice = currPrice;
  this->age = age;
}

bool AquaticAnimal::check_environment(float pH_level, float temperature, float volume) {
  if (pH_level < 0 || pH_level > 14) {
    return false;
  }
  if (volume < 0) {
    return false;
  }
  if (temperature < 0 || temperature > 100) {
    return false;
  }
  return true;
}

void AquaticAnimal::next_day() {
  age += 1;
  updateHealth(-10);
  updateHunger(10);
  updatePrice();
}

bool AquaticAnimal::getSickStatus() {
  return hasDisease;
}

void AquaticAnimal::status() {
  hasDied();
  cout << fixed << setprecision(2) << endl;
  cout << "Animal: " << endl;
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

void AquaticAnimal::updateHealth(int num) {
  health += num;
  if (health < 0) {
    health = 0;
  }
  else if (health > 100) {
    health = 100;
  }
}

void AquaticAnimal::updateHunger(int num) {
  hunger += num;
  if (hunger < 0) {
    hunger = 0;
  }
  else if (hunger > 100) {
    hunger = 100;
  }
}

bool AquaticAnimal::hasDied() {
  if (hunger == 100 || health == 0) {
    cout << "This animal has sadly passed away. Please sell to get rid of the animal" << endl;
    return true;
  }
  else {
    return false;
  }
}

void AquaticAnimal::updatePrice() {
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