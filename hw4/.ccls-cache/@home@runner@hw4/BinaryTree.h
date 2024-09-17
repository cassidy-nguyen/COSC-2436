#pragma once
#include <iostream>
#include <ostream>
#include <vector>
using namespace std;

template<typename T>
struct TreeNode {
    T value;
    TreeNode<T>* parent, *left, *right;
};

template<typename T>
class BinaryTree {
public:
    BinaryTree();                     // Default Constructor
    ~BinaryTree();                    // Destructor
    void Clear(TreeNode<T>* node);

    void Insert(T value);            // Add a value into the tree
    void MakeTree(int numRows, fstream& fin);
    bool Find(T value);              // Return true if the value is found
    bool IsEmpty();                  // True if the list is currently empty
    void Preorder(ostream& out);     // Output the pre-order traversal
    void PreorderRecursive(TreeNode<T>* node, ostream& out);
    void Inorder(ostream& out);      // Output the in-order traversal
    void InorderRecursive(TreeNode<T>* node, ostream& out);
    void Postorder(ostream& out);    // Output the post-order traversal  
    void PostorderRecursive(TreeNode<T>* node, ostream& out);
    bool Remove(T value);            // Find the value and remove the value; true if successful

private:
    TreeNode<T>* root;                   // Root pointer
};

template<typename T>
BinaryTree<T>::BinaryTree() {                     // Default Constructor
   root = nullptr;
}

template<typename T>
BinaryTree<T>::~BinaryTree() {                    // Destructor
   if (root != nullptr)
      Clear(root);
}

template<typename T>
void BinaryTree<T>::Clear(TreeNode<T>* node) {
   if (node != nullptr) {
      Clear(node->left);
      Clear(node->right);
      delete node;
   }
}

template<typename T>
void BinaryTree<T>::Insert(T value) {            // Add a value into the tree
   TreeNode<T>* newNode = new TreeNode<T>;
   newNode->value = value;
   if (root == nullptr) {
      root = newNode;
   }
   else {
      TreeNode<T>* curr = root;
      while (curr != nullptr) {
        if (curr->right == nullptr) {
          curr->right = newNode;
          newNode->left = curr;
        }
      }
   }
}

template<typename T>
void BinaryTree<T>::MakeTree(int numRows, fstream& fin) {
  // get triangle values
  vector<vector<TreeNode<T>>> triangle;
  TreeNode<T> newNode;
  int value;
  for (int row = 1; row <= numRows; row++) {
    vector<TreeNode<T>> line;
    for (int i = 1; i <= row; i++) {
      cin >> value;
      newNode->value = value;
      line.push_back(newNode);
    }
    triangle.push_back(line);
  }

  // turn triangle into a binary tree
  for (int row = 1; row <= numRows; row++) {
    for (int i = 1; i <= row; i++) {
      
    }
  }
}

template<typename T>
bool BinaryTree<T>::Find(T value) {              // Return true if the value is found
   TreeNode<T>* curr = root;
   while (curr != nullptr) {
      if (curr->value == value) {
         return true;
      }
      else if (curr->value > value) {
         curr = curr->left;
      }
      else {
         curr = curr->right;
      }
   }
   return false;
}

template<typename T>
bool BinaryTree<T>::IsEmpty() {                  // True if the list is currently empty
   return root == nullptr;
}

template<typename T>
void BinaryTree<T>::Preorder(ostream& out) {     // Output the pre-order traversal  
   out << "Preorder:" << endl;
   PreorderRecursive(root, out);
   out << endl;
}

template<typename T>
void BinaryTree<T>::PreorderRecursive(TreeNode<T>* node, ostream& out) {
   if (node != nullptr) {
      out << node->value << " ";
      PreorderRecursive(node->left, out);
      PreorderRecursive(node->right, out);
   }
}

template<typename T>
void BinaryTree<T>::Inorder(ostream& out) {      // Output the in-order traversal    
   out << "Inorder:" << endl;
   InorderRecursive(root, out);
   out << endl;
}

template<typename T>
void BinaryTree<T>::InorderRecursive(TreeNode<T>* node, ostream& out) {
   if (node != nullptr) {
      InorderRecursive(node->left, out);
      out << node->value << " ";
      InorderRecursive(node->right, out);
   } 
}

template<typename T>
void BinaryTree<T>::Postorder(ostream& out) {    // Output the post-order traversal   
   out << "Postorder:" << endl;
   PostorderRecursive(root, out);
   out << endl;
}

template<typename T>
void BinaryTree<T>::PostorderRecursive(TreeNode<T>* node, ostream& out) {
   if (node != nullptr) {
      PostorderRecursive(node->left, out);
      PostorderRecursive(node->right, out);
      out << node->value << " ";
   } 
}

template<typename T>
bool BinaryTree<T>::Remove(T value) {            // Find the value and remove the value; true if successful
   TreeNode<T>* parent = nullptr;
   TreeNode<T>* curr = root;
   while (curr != nullptr) { // Search for node
      if (curr->value == value) { // Node found 
         if (curr->left == nullptr && curr->right == nullptr) { // Remove leaf
            if (parent == nullptr) // Node is root
               root = nullptr;
            else if (parent->left == curr)
               parent->left = nullptr;
            else
               parent->right = nullptr;
         }
         else if (curr->right == nullptr) {                // Remove node with only left child
            if (parent == nullptr) // Node is root
               root = curr->left;
            else if (parent->left == curr)
               parent->left = curr->left;
            else
               parent->right = curr->left;
         }
         else if (curr->left == nullptr) {                // Remove node with only right child
            if (parent == nullptr) // Node is root
               root = curr->right;
            else if (parent->left == curr) 
               parent->left = curr->right;
            else
               parent->right = curr->right;
         }
         else {                                      // Remove node with two children
            // Find successor (leftmost child of right subtree)
            TreeNode<T>* succ = curr->right;
            while (succ->left != nullptr)
               succ = succ->left;
            TreeNode<T> temp;
            temp.value = succ->value;
            Remove(succ->value);     // Remove successor
            curr->value = temp.value;
         }
         return true;// Node found and removed
      }
      else if (curr->value < value) { // Search right
         parent = curr;
         curr = curr->right;
      }
      else {                     // Search left
         parent = curr;
         curr = curr->left;
      }
   }
   return false; // Node not found
}