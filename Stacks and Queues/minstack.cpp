#include <iostream>
#include <vector>

/*
A min stack is just like any other stack except we are able to return the minimum
element of the stack in constant time. In other words, it is not a proper min
stack if we need to iterate through the entire stack in order to find the min
element each time we push and pop. Or rather, it does not have the proper time
complexity a stack should have.

Therefore, if we implement a stack with an array of pairs, we can have the first
element of the pair be whichever element (let's say, ints) we want to insert. Then,
the second element will be the minumum of the current min and the element being inserted.
This way, when we insert elements, we consistently keep track of the minimum as we
insert. If there's ever a case where a new minimum is found, then the last element
will include the minimum, while also saving the old minimum in the case that the 
current new minimum is popped out.

To simplify: the last element will always have the minumum, whether it's pushed
or popped out, allowing us to have constant time access to it.
*/


class Stack {
  public:
    Stack() {}

  private:
    std::vector<std::pair<int, int>> stack;

    void Push(int item) {
      if (stack.empty()) 
        stack.push_back({item, item});
      else
        stack.push_back({item, std::min(item, stack.back().second)})
    }

    void Pop() {
      stack.pop_back();
    }

    int Size() {
      return stack.size();
    }

    int GetMin() {
      return stack.back().second;
    }

    int Top() {
      if (stack.size())
        return stack.back().first;
      else
        return -1;
    }

};

int main() {
  return 0;
}

