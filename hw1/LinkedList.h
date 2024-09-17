#pragma once
#include <iostream>
#include <fstream>
using namespace std;

template<typename T>
struct Node {
    T value;
    Node* next = nullptr;
};

template<typename T>
class LinkedList {
public:
    LinkedList();                      // Default Constructor
    ~LinkedList();                     // Destructor

    void Append(T value);            // Add a value to the end of the list
    int Get(int index);                // Return the value at the index requested, or 0
    bool Find(T value);              // Returns true if the value is found and false if not
    void Insert(int index, T value); // Insert value at index
    bool IsEmpty();                    // True if the list is currently empty
    void Print(ofstream& outFile);
    bool Delete(T value);            // Delete the first occurrence of value; true if successful
    bool DeleteAt(int index);            // Delete the value at the location; true if successful
    int Size();                        // Number of elements in the list
    T operator[](int index);           // Return the value at the index requested
    T GetHead();

private:
    Node<T>* head;                        // Items are linked to the head
    int size = 0;
};

// Add your code here
template<typename T>
LinkedList<T>::LinkedList() {                      // Default Constructor
  head = nullptr;
  size = 0;
}

template<typename T>
LinkedList<T>::~LinkedList() {                     // Destructor
  delete head;
  head = nullptr;
  size = 0;
}

template<typename T>
void LinkedList<T>::Append(T value) {            // Add a value to the end of the list
  if (head == nullptr) {
    Node<T>* newNode = new Node<T>();
    newNode->value = value;
    head = newNode;
  }
  else {
    Node<T>* curr = head;
    for (int i = 0; i < size - 1; i++) {
      curr = curr->next;
    }
    Node<T>* newNode = new Node<T>();
    newNode->value = value;
    curr->next = newNode;
  }
  size++;
}

template<typename T>
int LinkedList<T>::Get(int index) {                // Return the value at the index requested, or 0
  if (index < 0 || index >= size) {
    return 0;
  }
  else if (index == 0) {
    return head->value;
  }
  else {
    Node<T>* curr = head;
    for (int i = 0; i < index; i++) {
      curr = curr->next;
    }
    return curr->value;
  }
}

template<typename T>
bool LinkedList<T>::Find(T value) {              // Returns true if the value is found and false if not
  Node<T>* curr = head;
  for (int i = 0; i < size; i++) {
    if (curr->value == value) {
      return true;
    }
    else {
      curr = curr->next;
    }
  }
  return false;
}

template<typename T>
void LinkedList<T>::Insert(int index, T value) { // Insert value at index
  if (index < 0 || index > size)
      return;
  
  Node<T>* newNode = new Node<T>();
  newNode->value = value;
  if (index == 0) {
    head->next = head->next->next;
    head = newNode;
  }
  else if (index < 0 || index > size) {
    return;
  }
  else {
    Node<T>* curr = head;
    for (int i = 0; i < index - 1; i++) {
      curr = curr->next;
    }
    curr->next = newNode;
  }
  size++;
}

template<typename T>
bool LinkedList<T>::IsEmpty() {                    // True if the list is currently empty
  return (size == 0);
}

template<typename T>
void LinkedList<T>::Print(ofstream& outFile) {
  ofstream& fout(outFile);
  Node<T>* curr = head;
  for (int i = 0; i < size; i++) {
    fout << curr->value;
    curr = curr->next;
    if (i != size - 1) {
      fout << endl;
    }
  }
  fout << endl;
}

template<typename T>
bool LinkedList<T>::Delete(T value) {            // Delete the first occurrence of value; true if successful
  Node<T>* curr = head;
  if (head->value == value) {
    head = head->next;
    size--;
    return true;
  }
  else {
    for (int i = 0; i < size - 1; i++) {
      if (curr->next->value == value) {
        curr->next = curr->next->next;
        size--;
        return true;
      }
    }
  }
  return false;
}

template<typename T>
bool LinkedList<T>::DeleteAt(int index) {            // Delete the value at the location; true if successful
  if (index == 0) {
    head = head->next;
    size--;
    return true;
  }
  else if (index > 0 && index < size) {
    Node<T>* curr = head;
    for (int i = 0; i < index; i++) {
      curr = curr->next;
    }
    curr->next = curr->next->next;
    size--;
    return true;
  }
  else
    return false;
}

template<typename T>
int LinkedList<T>::Size() {                        // Number of elements in the list
   return size;
}

template<typename T>
T LinkedList<T>::operator[](int index) {           // Return the value at the index requested
  Node<T>* curr = head;
  if (index < 0 && index*(-1) < Size()) {
    while (curr->next != nullptr) {
      curr = curr->next;
    }
    // curr is now the tail
    for (int i = -1; i > index; i--) {
      curr = curr->prev;
    }
  }
  else {
    for (int i = 0; i < index; i++) {
      curr = curr->next;
    }
  }
  return curr->value;
}

template<typename T>
T LinkedList<T>::GetHead() {
  return head->value;
}