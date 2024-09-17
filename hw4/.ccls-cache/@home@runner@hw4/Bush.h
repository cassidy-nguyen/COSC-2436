#pragma once
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct BushNode {
  int key; 
  BushNode *parent, *left, *right;
  BushNode(int k, BushNode* up = nullptr, BushNode* r = nullptr, BushNode* l = nullptr) {
    key=k; parent=up; left=l; right=r;}
};

class Bush {
public:
  Bush(int value);
  ~Bush();
  void InsertLeft(int value);
  void InsertRight(int value);
  void FindMinimum(int** MaxArray, ofstream& fout, int size);
  void FindMaximum(int** MinArray, ofstream& fout, int size);
private:
  BushNode* root;
};

Bush::Bush(int value) {
  root = new BushNode(value);
}

Bush::~Bush() {
  delete root->left;
  delete root->right;
  delete root;
}

void Bush::InsertLeft(int value) {
  root->left = new BushNode(value, root);
}

void Bush::InsertRight(int value) {
  root->right = new BushNode(value, root);
}

void Bush::FindMinimum(int** MinArray, ofstream& fout, int size) {
  for (int i = size - 2; i >= 0; i--) {
    for (int j = 0; j <= i; j++) {
      if (MinArray[i+1][j] <= MinArray[i+1][j+1]) {
        MinArray[i][j] += MinArray[i+1][j];      
      }
      else {
        MinArray[i][j] += MinArray[i+1][j+1];
      }
    }
  }
  fout << MinArray[0][0] << endl;

  int minSum = MinArray[0][0];
  vector<int> minPath;
  minPath.push_back(MinArray[0][0]);
  int j = 0;
  for (int i = 1; i < size; i++) {
    if (MinArray[i][j] <= MinArray[i][j + 1]) {
      minPath.push_back(MinArray[i][j]);
    } 
    else {
      j++;
      minPath.push_back(MinArray[i][j]);
    }
  }
  for (int i = 0; i < minPath.size() - 1; i++) {
    fout << minPath[i] - minPath[i+1];
    minSum -= minPath[i] - minPath[i+1];
    if (i < minPath.size() - 2) {
      fout << ", ";
    }
    else {
      fout << ", " << minSum << endl;
    }
  }
}

void Bush::FindMaximum(int** MaxArray, ofstream& fout, int size) {
  for (int i = size - 2; i >= 0; i--) {
    for (int j = 0; j <= i; j++) {
      if (MaxArray[i+1][j] >= MaxArray[i+1][j+1]) {
        MaxArray[i][j] += MaxArray[i+1][j];      
      }
      else {
        MaxArray[i][j] += MaxArray[i+1][j+1];
      }
    }
  }
  fout << MaxArray[0][0] << endl;

  int maxSum = MaxArray[0][0];
  vector<int> maxPath;
  maxPath.push_back(MaxArray[0][0]);
  int j = 0;
  for (int i = 1; i < size; i++) {
    if (MaxArray[i][j] < MaxArray[i][j + 1]) {
      j++;
    }
    maxPath.push_back(MaxArray[i][j]);
  }
  for (int i = 0; i < maxPath.size() - 1; i++) {
    fout << maxPath[i] - maxPath[i+1];
    maxSum -= maxPath[i] - maxPath[i+1];
    if (i < maxPath.size() - 2) {
      fout << ", ";
    }
    else {
      fout << ", " << maxSum << endl;
    }
  }
}