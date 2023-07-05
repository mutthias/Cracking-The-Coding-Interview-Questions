#include <iostream>
#include "linkedlist.h"

/*
Want to find the kth to the last element.
What about the kth to the first element? We can:
  1) Initialize a counter variable
  2) For each node we pass through, increment the counter
  3) Continue moving through nodes until the counter = k

With this approach, we could then reverse the linked list and then solve the exact problem described

*/
template <typename T>
void LinkedList<T>::FindKthElement(Node<T>* curr, const int k) {
  int index = 1;

  if (k > size)  {
    std::cout << "wala na\n";
    return;
  }
  while (index != k) {
    curr = curr->next;
    index++;
  }
  std::cout << curr->data << std::endl;
}


template <typename T>
void LinkedList<T>::FindLastKth(const int k) {

  Node<T>* slow = NULL;
  Node<T>* fast = NULL;
  while (head) {
    slow = head;
    head = head->next;
    slow->next = fast;
    fast = slow;
  }
  FindKthElement(fast, k);
}

int main() {
  LinkedList<int> list;
  list.insert(2);
  list.insert(4);
  list.insert(6);
  list.insert(8);
  list.insert(10);
  list.insert(12);
  list.insert(14);
  list.insert(16);
  list.print();
  list.FindLastKth(5);
  list.FindLastKth(10);
  
  
  return 0;
}