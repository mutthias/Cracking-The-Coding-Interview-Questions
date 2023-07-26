#include <iostream>
#include <stack>
#include <vector>

/* 
The problem is asking to imagine a stack of plates, and if the stack gets too 
tall, we need to create a new stack. So we want to implement this in code.

We can start off with an ordinary stack data structure that is implemented with a 
vector. Since it states that "SetofStacks" should have multiple stacks, we can 
create a vector of pairs, where the first element will be our stack, and the 
second element can be the index at which it is at. 

The stacks inside of the vector will just be ordinary stacks using the std library
(for simplicity), and will be available to push until the stack reaches a certain limit. 

[ {s1, 0} , {s2, 1}, {s3, 2}, ... ]
*/

class Stack {
  public:
    Stack() {}

  private:
    std::vector<std::pair<std::stack<int>, int>> stack;

    bool StackFull(std::stack<int> &stack) {
      if (stack.size() >= 5) 
        return true;
      else
        return false;
    }

    void Push(int plate) {
      if (stack.empty()) {  // There's nothing in the total stacks (No plates at all!)
        std::stack<int> temp; // Initialize a stack
        temp.push(plate); // Put the plate in that stack
        stack.push_back({temp, stack.size()}); // Put our first stack in our main stack (for this condition, push the new stack in, and save it at index stack.size() which is 0 here.)
      }
      else { // Stacks exist
        if (StackFull(stack.back().first)) {  // If the last stack worked on is full, create a new stack again and push it into our array
          std::stack<int> temp2;
          temp2.push(plate);
          stack.push_back({temp2, stack.size()});
        }
        else {
          stack.back().first.push(plate); // The last stack isn't full, so put the plate there. 
        }
      }
    }
    void Pop() {
      if (stack.back().first.empty()) { // If the stack at the end is empty, remove it and then remove the plate from the next stack
        stack.pop_back();
        stack.back().first.pop();
      }
      else { // The stack at the end isn't empty, so just remove a plate from that one
        stack.back().first.pop();
      }
    }
    int Size() {
      return stack.size();
    }
    int Top() {
      if (stack.size())
        return stack.back().first.top();
      else
        return -1;
    }
};

int main() {

}