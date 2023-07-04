#include <iostream>

// From https://www.geeksforgeeks.org/program-to-implement-singly-linked-list-in-c-using-class/# and ChatGPT

template <typename T>
class Node {
  public:
    T data;
    Node* next;
    Node* head;
    int size;
    Node(const T& value) : data(value), next(nullptr) {}
};

template <typename T>
class LinkedList {
  Node<T>* head;
  int size;

  public: 
    LinkedList() { head = NULL; }

    void insert(const T& value) {
      Node<T>* newNode = new Node<T>(value);  // Create/Allocate a new node
      if (!head) {                      // Is the head null?
        head = newNode;                 // Then the head will be the newly added node
      } else {                          // Otherwise while there exists a successive node, keep traversing until the end
        Node<T>* curr = head;
        while (curr->next) {
          curr = curr->next;
        }
        curr->next = newNode;           // Reached the end, new node is now added to the end
      }
      size++; 
    }

    void remove(const T& value) {
      if (!head) return;                // Nothing to remove
      if (head->data == value) {        // The head is the node we want to delete?
        Node<T>* temp = head;              // Then set a temp variable equal to our head, set the head now equal the next node, and delete temp (the value we set to delete)
        head = temp->next;
        delete temp;
        size--;
        return;
      }
      Node<T>* curr = head;
        while (curr->next && curr->next->value != value) { // Find the value we want to delete
          curr = curr->next;
      }
      if (!curr->next) {                // 1 2 3 4 5
        Node<T>* temp = curr->next;       // Then prepare to delete 
        curr->next = curr->next->next;
        delete temp;
        size--;
      }
    }

    void print() {
      Node<T>* curr = head;
      while (curr) {
        std::cout << curr->data << " ";
        curr = curr->next;
      }
      std::cout << std::endl; 
    }
};
