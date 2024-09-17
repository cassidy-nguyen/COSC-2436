#ifndef STACK_H
#define STACK_H

#include <iostream>

using namespace std;

class InvalidStackOperation : public exception {
public:
   const char* what() const throw() {
      return "Invalid Stack Operation.";
   }
};

template<typename T>
class Stack {
public:
  Stack(int capacity);
  ~Stack();
  void Push(T item);
  T Pop();
  T Top();
  bool IsEmpty();
private:
  int capacity;
  int size;
  T* stack;
};

template<typename T>
Stack<T>::Stack(int capacity) {
  this->capacity = capacity;
  stack = new T[capacity];
  size = 0;
}

template<typename T>
Stack<T>::~Stack() {
  delete[] stack;
}

template<typename T>
void Stack<T>::Push(T item) {
  if (size == capacity) {
     capacity = capacity * 2;
     T* newStack = new T[capacity];
     for (int i = 0; i < size; i++) {
        newStack[i] = stack[i];
     }
     delete[] stack;
     stack = newStack;
  }
  stack[size] = item;
  size++;
}

template<typename T>
T Stack<T>::Pop() {
  if (IsEmpty()) {
     throw InvalidStackOperation();
  }
  T popped = stack[size - 1];
  size--;
  return popped;
}

template<typename T>
T Stack<T>::Top() {
  if (IsEmpty()) {
    throw InvalidStackOperation();
  }
  return stack[size - 1];
}

template<typename T>
bool Stack<T>::IsEmpty() {
  return size == 0;
}

#endif