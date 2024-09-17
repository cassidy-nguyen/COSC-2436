#include <iostream>
#include <fstream>
#include "ArgumentManager.h"
#include "Bush.h"

using namespace std;

int main(int argc, char* argv[]) {
  ArgumentManager am(argc, argv);
  ifstream fin(am.get("input"));
  ofstream fout(am.get("output"));
  //ifstream fin("input1.txt");
  //ofstream fout("output1.txt");
  
  int size, num;
  fin >> size;
  int **MinArray = new int*[size];
  int **MaxArray = new int*[size];

  for (int i = 0; i < size; i++) {
    MinArray[i] = new int[i+1];
    MaxArray[i] = new int[i+1];
  }
  
  for (int i = 0; i < size; i++) {
    for (int j = 0; j <= i; j++) {
      fin >> num;
      MinArray[i][j] = num;
      MaxArray[i][j] = num;
    }
  }

  // max
  Bush maxBush(MaxArray[0][0]);
  maxBush.FindMaximum(MaxArray, fout, size);

  // min
  Bush minBush(MinArray[0][0]);
  minBush.FindMinimum(MinArray, fout, size);
  
  // delete
  for (int i = 0; i < size; i++) {
    delete[] MaxArray[i];
    delete[] MinArray[i];
  }
  delete[] MaxArray;
  delete[] MinArray;

  // close files
  fin.close();
  fout.close();

  return 0;
}