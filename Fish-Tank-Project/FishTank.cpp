#include <iostream>
#include "FishTank.h"
using namespace std;

FishTank::FishTank(float temp, float pH, float vol) {
  temperature = temp;
  pHLevel = pH;
  volume = vol;
}

float FishTank::getTemp() {
  return temperature;
}

float FishTank::getpHLevel() {
  return pHLevel;
}

float FishTank::getVolume() {
  return volume;
}

void FishTank::setTemp(float temp) {
  temperature = temp;
}

void FishTank::setpHLevel(float pH) {
  pHLevel = pH;
}

void FishTank::setVolume(float vol) {
  volume = vol;
}

void FishTank::drawTank() {
  cout << "________________________________________________________________________" << endl;
  cout << "|                                                                       |" << endl;
  cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|" << endl;
  cout << "|                                                                       |" << endl;
  cout << "|                                                                       |" << endl;
  cout << "|        __________                                                     |" << endl;
  cout << "|       /          \\                                             (      |" << endl;
  cout << "|      /____________\\                                           (\\)     |" << endl;
  cout << "|       |:_:_:_:_:_|                                             ))     |" << endl;
  cout << "|       |_:_,--.:_:|                                          (\\//   )  |" << endl;
  cout << "|       |:_:|__|_:_|                         _               ) ))   ((  |" << endl;
  cout << "|     _  |_   _  :_:|   _   _   _            (_)             ((((   /)\\`|" << endl;
  cout << "|    | |_| |_| |   _|  | |_| |_| |             o              \\)) (( (  |" << endl;
  cout << "|     \\_:_:_:_:/|_|_|_|\\:_:_:_:_/             .                ((   ))))|" << endl;
  cout << "|      |_,-._:_:_:_:_:_:_:_.-,_|                                )) ((// |" << endl;
  cout << "|     |:|_|:_:_:,---,:_:_:|_|:|                               ,-.  )/   |" << endl;
  cout << "|     |_:_:_:_,'     `,_:_:_:_|           _  o               ,;'))((    |" << endl;
  cout << "|     |:_:_:_/  _ | _  \\_:_:_:|          (_O                   ((  ))   |" << endl;
  cout << "|_____|_:_:_|  (o)-(o)  |_:_:_|--'`-.     ,--.                (((\\'/    |" << endl;
  cout << "| ', ;|:_:_:| -( .-. )- |:_:_:| ', ; `--._\\  /,---.~           \\`))     |" << endl;
  cout << "|.  ` |_:_:_|   \\`-'/   |_:_:_|.  ` .  `  /()\\.__( ) .,-----'`-\\((      |" << endl;
  cout << "| ', ;|:_:_:|    `-'    |:_:_:| ', ; ', ; `--'|   \\ ', ; ', ; ',')).,-- |" << endl;
  cout << "|.  `     ` .  ` .  ` .  ` .  ` .  ` .  ` .    .  ` .  ` .  ` .  ` .  ` |" << endl;
  cout << "| ', ; ', ; ', ; ', ; ', ; ', ; ', ; ', ; ', ; ', ; ', ; ', ; ', ; ', ; |" << endl;
  cout << "|_______________________________________________________________________|" << endl;
}