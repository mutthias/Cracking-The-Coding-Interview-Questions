#include <iostream>
#include <string>
/* 
A stirng s1 is a rotation of a string s2 if you can start at any point in s2 and
recreate s1, and the rest of s1 is identical to s2. For example, "lohel" is a rotation
of "hello" by being rotated 3 spaces over. However, "helol" is NOT a rotation, as no 
matter how many times you shift the chacters over, you can never recreate "hello".

Approach 1: 
  1) Find the longest common substring of s1 and s2
  2) From the index starting at the end of the substring s1, check to see if the 
     rest of s1 matches with s2. 
  - This approach, while works, seems quite difficult as step 1 alone feels like
    its own problem

Approach 2: 
  1) Concatenate two instances of s1
  2) Search for s2 in the new concatenated string. Ex: s1 = llohe, s2 = hello,
     s1s1 = llohellohe
  3) Iterate through s1s1. Do nothing until s1s1[i] == s2[i]. Then we increment
     a count if the characters match. If the counter == s2.size(), return true. 
     If we ever get s1s1[i] != s2[i], set the counter back to 0.

  - Faster, easier approach, from the book. O(n) time complexity and O(n) space

*/

bool IsRotation(std::string s1, std::string s2) {
  if (s1.size() != s2.size()) return false;
  if (s1 == s2) return true;
  std::string s1s1 = s1 + s1;
  int count = 0;
  int index = 0;
  for (int i = 0; i < s1s1.size(); i++) {
    if (s1s1[i] == s2[count]) {
      count++;
      // std::cout << count << std::endl;
      if (count == s2.size()) {
        return true;
      }
    } else {
      count = 0;
    }
  }
  return false;
}

int main() {
  std::string s1 = "ellod";
  std::string s2 = "hello";
  std::string s3 = "lohel";
  std::cout << IsRotation(s1, s2) << std::endl;
  std::cout << IsRotation(s3, s2) << std::endl;
  return 0;
}