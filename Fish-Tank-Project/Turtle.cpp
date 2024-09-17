#include <iostream>
#include <iomanip>
#include <cstring>
#include "Turtle.h"

using namespace std;

Turtle::Turtle():AquaticAnimal() {
  age = 1;
  currPrice += initialPrice;
}

Turtle::Turtle(string type, int hunger, int health, bool hasDisease, float initialPrice, float currPrice, int age) {
  this->type = type;
  this->hunger = hunger;
  this->health = health;
  this->hasDisease = hasDisease;
  this->currPrice = currPrice;
  this->age = age;
}

bool Turtle::check_environment(float pH_level, float temperature, float volume) {
  if (pH_level < 7 || pH_level > 8.5)
    return false;
  if (temperature < 78 || temperature > 90)
    return false;
  if (volume <= 0) {
    return false;
  }
  return true;
}

float Turtle::getPrice() {
  return currPrice;
}

int Turtle::getAge() {
  return age;
}

void Turtle::next_day() {
  updateHunger(hungerRate);
  if (getSickStatus())
    updateHealth(sickRate);
  age += 1;
  updatePrice();
}

void Turtle::draw() {
  cout << "       /^\\" << endl;
  cout << "      |   |" << endl;
  cout << "/\\     |_|     /\\" << endl;
  cout << "| \\___/' `\\___/ |" << endl;
  cout << " \\_/  \\___/  \\_/" << endl;
  cout << "  |\\__/   \\__/|" << endl;
  cout << "  |/  \\___/  \\|" << endl;
  cout << " ./\\__/   \\__/\\," << endl;
  cout << " | /  \\___/  \\ |" << endl;
  cout << " \\/     V     \\/" << endl;
}

void Turtle::status() {
  draw();
  hasDied();
  cout << fixed << setprecision(2) << endl;
  cout << "Animal: Turtle" << endl;
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

void Turtle::updatePrice() {
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