#include <iostream>
#include <fstream>
#include "ArgumentManager.h"

using namespace std;
const int NUM_VALUES = 15;
const int NUM_SUITS = 4;

void cardParser(int**, string, int, int);

int main(int argc, char* argv[]) {
  ArgumentManager am(argc, argv);
  ifstream inFile(am.get("input"));
  ofstream outFile(am.get("output"));
  //ifstream inFile("input1.txt");
  //ofstream outFile("output1.txt");

  //empty array
  int** cardArr = new int*[NUM_VALUES];
  for (int i = 0; i < NUM_VALUES; i++) {
    cardArr[i] = new int[NUM_SUITS];
    for (int j = 0; j < NUM_SUITS; j++) {
      cardArr[i][j] = 0;
    }
  }

  // Get the card info from the file
  string input = "";
  getline(inFile, input);
  cout << input << endl;
  
  int start = 0;
  int pos = 1;
  while (input.size() > 0){
    pos = input.find(',');
    string card = input.substr(start, pos);
    cout << input.substr(start, pos) << endl;
    cardParser(cardArr, card, NUM_VALUES, NUM_SUITS);
    input = input.substr(pos+2);
  }
  
  //the 2D array for the output file using a nested forloop
  for (int i = 0; i < NUM_VALUES; i++) {
    for (int j = 0; j < NUM_SUITS; j++) {
      outFile << cardArr[i][j] << " ";
    }
    if (i < NUM_VALUES - 1)
      outFile << endl;
  }

  // delete 2D array
  for (int i = 0; i < NUM_VALUES; i++) {
    delete cardArr[i];
    cardArr[i] = nullptr;
  }

  // Close the files
  inFile.close();
  outFile.close();

  return 0;
}

void cardParser(int** arr, string cardInfo, int numRows, int numCols) {
  int row = 0, col = 0;
  
   //the column index based on the suit
   switch (cardInfo[cardInfo.length() - 1])
   {
     case 'A':
       col = 0;
       break;
     case 'E':
       col = 1;
       break;
     case 'F':
       col = 2;
       break;
     case 'W':
       col = 3;
       break;
     default:
       cout << "Invalid suit." << endl;
       return;
   }
   
   //the row index based on the rank
   switch (cardInfo[0])
{
  case 'P':
    row = 0;
    break;
  case '2':
    row = 1;
    break;
  case '3':
    row = 2;
    break;
  case '4':
    row = 3;
    break;
  case '5':
    row = 4;
    break;
  case '6':
    row = 5;
    break;
  case '7':
    row = 6;
    break;
  case '8':
    row = 7;
    break;
  case '9':
    row = 8;
    break;
  case '1': // If a card with 10
    if ((cardInfo.length() == 3) && (cardInfo[1] == '0')) {// if the second character is 0
      row = 9;
      break;
    }
    else {
      cout << "Invalid rank." << endl;
      break;
    }
  case 'R':
    row = 10;
    break;
  case 'N':
    row = 11;
    break;
  case 'B':
    row = 12;
    break;
  case 'Q':
    row = 13;
    break;
  case 'K':
    row = 14;
    break;
  default:
    cout << "Invalid rank." << endl;
    return; 
}
   arr[row][col] = 1;
}