#include <iostream>
#include "linkedlist.h"

/*
In this one, we want to partition around a value. That is, whatever our value is,
we want to make it that every value less than that value comes before every value 
greater than or equal to that value.

Take a list 1 4 1 2 3 8 1 3 4 9, with our value = 3. Then our list could now be:
1 1 2 1 4 9 3 8 4
In this result, all the nodes less than 3 come before any node that is greater than
or equal to 3. As long as this case is satisfied, the order of the rest of the nodes don't
exactly matter. 

One potential solution is that once we find a value
*/

template <typename T>
void LinkedList<T>::Parition(const T& value) {}

int main() {
  
  LinkedList<int> list;
  list.insert(1);
  list.insert(2);
  list.insert(3);
  list.insert(4);
  list.insert(5);
  list.insert(6);

  list.print();
  return 0;
}