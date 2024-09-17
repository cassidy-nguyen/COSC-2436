#include "ArgumentManager.h"
#include <iostream>
#include <string>
#include <fstream>
#include "LinkedList.h"

using namespace std;

bool isOver(LinkedList<string>** array, int size, int max) {
  for (int i = 0; i < size; i++) {
    if (array[i]->Size() == max) {
      return true;
    }
  }
  return false;
};

int main(int argc, char* argv[]){
  ArgumentManager am(argc, argv);
  ifstream inFile(am.get("input"));
  ofstream outFile(am.get("output"));
  //ifstream inFile("input2.txt");
  //ofstream outFile("output2.txt");

  // Do all the work here
  int max;
  inFile >> max; // Get how many things there are
  inFile.ignore();

  // creating an array composed of Linked Lists based on the number of participants
  LinkedList<string>** array = new LinkedList<string>*[max];
  int size = 0;
  for (int i = 0; i < max; i++) {
    array[i] = new LinkedList<string>();
  }

  // reading interactions
  string line;
  while (!isOver(array, size, max)) {
    while (getline(inFile, line)) {
      stringstream ss(line);
      string first, second;
      ss >> first >> second;
      bool found = false;
  
      // first participant met second participant
      for (int i = 0; i < size; i++) {
        if (array[i]->GetHead() == first) {
          if (!array[i]->Find(second))
            array[i]->Append(second);
          found = true;
          break;
        }
      }
      if (!found) {
        array[size] = new LinkedList<string>();
        array[size]->Append(first);
        array[size]->Append(second);
        size++;
      }
  
      // tiebreaker
      if (isOver(array, size, max)) {
        break;
      }
  
      // second participant met first participant
      found = false;
      for (int i = 0; i < size; i++) {
        if (array[i]->GetHead() == second) {
          if (!array[i]->Find(first))
            array[i]->Append(first);
          found = true;
          break;
        }
      }
      if (!found) {
        array[size] = new LinkedList<string>();
        array[size]->Append(second);
        array[size]->Append(first);
        size++;
      }
    }
  }

  // if game is over, print winner
  if (isOver(array, size, max)) {
    for (int i = 0; i < size; i++) {
      if (array[i]->Size() == max) {
        array[i]->Print(outFile);
        break;
      }
    }
  }

  // delete arrays
  for (int i = 0; i < max; i++) {
    delete array[i];
  }
  delete[] array;
  
  // Close the files
  inFile.close();
  outFile.close();
  
  return 0;
}