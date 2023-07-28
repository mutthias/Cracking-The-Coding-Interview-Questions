#include <iostream>
#include <queue>

/*
- Animal shelter is FIFO, so we use queue
- People adopt the 'oldest', so they take the first item in the queue
- Or can choose a dog or cat, and return the firstly inserted dog or cat

If people could solely adopt the oldest pet, this would be super straightforward, 
we'd just pop the top element of the queue. But, since they can choose between
a dog or cat, we then need to keep track of the oldeest dogs and cats.

Need to create enqueue, dequeueAny, dequeueDog, and dequeueCat:
1) enqueue: Depending on the pet, enqueue them into their respective queue.
   For example, if we get a dog, enqueue them into a queue for only dogs.
   Also enqueue them into a main queue incase the person doesn't have a preference

2) dequeueAny: Same logic as enqueue, but remove from respective queues

3) dequeueDog and dequeueCat: Remove respective pet from their queue.
   BUT, then we also need to remove it from the main array. 

Dequeueing appears to be the tricky part of this problem. So, perhaps 
for now we can just first remove the pet from their respective queue. 
The key here could be keeping track of the top element of each queue.
Say we have these queues:

Cat Queue: cat1 cat2 cat3
Dog Queue: dog1 dog2 dog3
Main Queue: cat1 cat2 dog1 cat3 dog2 dog3

If we want 'dog1' (the first dog enqueued), we get this: 

Cat Queue: cat1 cat2 cat3
Dog Queue: dog2 dog3
Main Queue: cat1 cat2 dog1 cat3 dog2 dog3

And our main queue is unchanged. What we could do is that we can check if the 
main queue head is equal to the head of any of the other queues. And while it 
isn't, we continuously pop elements from the main queue. Say we want cat1 now:

Cat Queue: cat2 cat3
Dog Queue: dog2 dog3
Main Queue: cat1 cat2 dog1 cat3 dog2 dog3

And now the top of Main Queue is not equal to the top of either queue, so we pop until
it is:

Cat Queue: cat3
Dog Queue: dog2 dog3
Main Queue: cat2 dog1 cat3 dog2 dog3

And we repeat until our shelter is empty!

What if everyoen just has 0 preference? We apply the reverse logic!

Cat Queue: cat1 cat2 cat3
Dog Queue: dog1 dog2 dog3
Main Queue: dog1 cat2 cat3 dog2 dog3

i will finish code later

*/

// class Pet {
//   std::queue<std::string> main_queue;
//   std::queue<std::string> dogs;
//   std::queue<std::string> cats;

//   public:
//     void Enqueue(std::string& pet_type) {
//       main_queue.push(pet_type);
//       if (pet_type == "dog") {
//         dogs.push(pet_type);
//       } else if (pet_type == "cat") {
//         cats.push(pet_type);
//       } else {
//         std::cout << "We don't have that animal here!" << std::endl;
//       }
//     }

//     void DequeueAny() {
//       main_queue.pop();
//       if ((main_queue.front() != dogs.front()) 
//         && main_queue.front() != cats.front()) {
//           if 
//         }
//     }    

// };

// int main() {
//   return 0;
// }