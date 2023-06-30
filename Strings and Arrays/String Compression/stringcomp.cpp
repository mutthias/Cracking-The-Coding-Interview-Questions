#include <iostream>
#include <string>
#include <vector>

/* 
aabbcca ==> a2b2c2a1
Brute Force: 
  1) Iterate through each character in the string
  2) For each unique character, increment a count until a different
     character appears
  3) Reset count everytime a new character appears
  4) Once we reach the new character, put the old character as well as
     the current count in a string . For ex, if char[i] = 'a' and count = 4, 
     then result += a4
  5) If the result.size() < original_str.size() return the original string,
     else return the result

  This has O(n) time complexity as we loop through the array n times, and 
  O(1) space as it doesn't use any new space except for the result.
*/

std::string StringComp(std::string &str) {
  std::string res;
  int count = 1;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] != str[i+1]) {
      std::string tmp = std::to_string(count);
      res += str[i] + tmp;
      count = 1;
    } else {
      count++;
    }
  }
  if (res.size() > str.size())
    return str;
  return res;
}

int main() {
  std::string s = "aabcccccaaa";
  std::string s2 = "abca";

  std::cout << StringComp(s2) << std::endl;
  return 0;
}