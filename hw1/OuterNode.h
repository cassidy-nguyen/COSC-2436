#include "LinkedList.h"

template <typename T>
class OuterNode {
public:
  string name;
  bool visitedAll;
  LinkedList innerList;

  OuterNode();
  ~OuterNode();

  void AddInteraction(T name);
  bool HasVisitedAll();

private:
  
};

template <typename T>
OuterNode<T>::OuterNode() {
  visitedAll = False;
}

template <typename T>
OuterNode<T>::~OuterNode() {
  visitedAll = False;
}