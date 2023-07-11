#include <iostream>
#include "linkedlist.h"

/*
We want to remove the middle node:
  1 2 3 4 5
  ==> 1 2 4 5

How to do?
My first thought is that we can start off with the process of deleting a node 
normally, through the .h file. This can give us an idea of how deleting a node
from a linked list would work. 

But ordinary deletion of a linked list means deleting the node at the end. We 
want to be able to delete nodes that aren't at the start or end. 

Take the list 1 2 3 4 5 again as an example.
First we need to find the center of the linked list. We can do this by utilizing
the concept of a fast and slow pointer in order to find the center.

Once the center is found, we can take the node before it and set the node->next to 
be node->next->next, filling the "gap" left by the deleted node. Finally, delete
the center node. 
 
1* 2 3 4 5 6 7 8 9 10
1 2* 3* 4 5 6 7 8 9 10
1 2 3* 4 5* 6 7 8 9 10
1 2 3 4* 5 6 7* 8 9 10
1 2 3 4 5* 6 7 8 9* 10
1 2 3 4 5 6* 7 8 9 10

*/
template <typename T>
void LinkedList<T>::RemoveMiddle() {
  if (!head) return; // Edge case: No list exists
  if (size < 2) return; // Edge Case: No middle exists
  Node<T>* slow = head;
  Node<T>* fast = head;
  Node<T>* prev = NULL; // A pointer to the node that comes before the center
  while (fast && fast->next) {
    prev = slow; 
    slow = slow->next; // Move by 1 space
    fast = fast->next->next; // Move by 2 spaces
  }
  prev->next = prev->next->next; // prev->next is slow, which is the center, which we're about to delete. So, the new 
                                 // prev->next will now be slow->next, aka prev->next->next.
  delete slow;  // Goodbye middle node!
  size--;
  print();
}

int main() {
  
  LinkedList<int> list;
  list.insert(1);
  list.insert(2);
  list.insert(3);
  list.insert(4);
  list.insert(5);
  list.insert(6);

  list.print();
  list.RemoveMiddle();
  return 0;
}