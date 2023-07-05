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
  int size = 0;

  public: 
    LinkedList() { head = NULL; }

    void FindKthElement(Node<T>* head, const int k);
    void FindKthElement2(Node<T>* list, const int k, int i);
    LinkedList<T> ReverseList(LinkedList<T>* head);
    void FindLastKth(const int k);

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
      std::cout << "size: " << size << std::endl;
      std::cout << std::endl; 
    }

    void RemoveDupes() {
      Node<T>* curr = head;
      while (curr) {
        Node<T>* temp = curr;
        while (temp->next) {
          if (temp->next->data == curr->data) {
            temp->next = temp->next->next;
          } else {
            temp = temp->next;
          }
        }
        curr = curr->next;
      }
    }
};
