#include <iostream> 
#include "linkedlist.h"

// 1 4 3 2 1 6
// Want to remove dupes
/*
Brute Force:
  1) Start at the head
  2) Traverse each node, removing any instance of the current node
  3) Rinse and Repeat until the end
*/ 

int main() {
  LinkedList<int> list;
  list.insert(1);
  list.insert(4);
  list.insert(3);
  list.insert(2);
  list.insert(1);
  list.insert(6);
  list.insert(1);
  list.insert(2);
  list.print();
  list.RemoveDupes();
  list.print();

}