#include <iostream>
#include <string>
#include "linkedlist.h"

int main() {
    LinkedList<int> intList;
    intList.insert(5);
    intList.insert(10);
    intList.insert(15);
    intList.print();  // Output: 5 10 15

    LinkedList<std::string> stringList;
    stringList.insert("Hello");
    stringList.insert("World");
    stringList.print();  // Output: Hello World

    return 0;
}