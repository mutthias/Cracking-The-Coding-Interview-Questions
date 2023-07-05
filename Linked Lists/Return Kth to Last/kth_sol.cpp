#include <iostream>
#include "linkedlist.h"

/* 
I overcomplicated my solution. Just simply return the k - size index with recursion
*/
template <typename T>
void FindKthElement(Node<T>* head, const int k, const int i) {
  if (head) return;
  Node<T>* curr = FindKthElement(head->next, k, i);
  i = i + 1;
  if (i == k) return head;
  return curr;
}
