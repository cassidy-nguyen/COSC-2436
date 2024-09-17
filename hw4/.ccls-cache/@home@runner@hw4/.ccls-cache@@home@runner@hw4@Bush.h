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
  int FindMinimum();
  int FindMaximum();
  string GetMinimumPath();
  string GetMaximumPath();
private:
  BushNode* root;
  vector<int> minPath;
  vector<int> maxPath;
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

int Bush::FindMinimum() {
  BushNode* curr = root;
  int answer = curr->key;
  while (curr->left != nullptr) {
    if (curr->left->key <= curr->right->key) {
      curr = curr->left;
      answer += curr->key;
    }
    else {
      curr = curr->right;
      answer += curr->key;
    }
  }
  return answer;
}

int Bush::FindMaximum() {
  BushNode* curr = root;
  int answer = curr->key;
  while (curr->left != nullptr) {
    if (curr->left->key >= curr->right->key) {
      curr = curr->left;
      answer += curr->key;
    }
    else {
      curr = curr->right;
      answer += curr->key;
    }
  }
  return answer;
}