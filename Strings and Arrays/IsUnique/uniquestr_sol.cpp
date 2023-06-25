#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

// Java Solution from the book translated into C++

/* 
This uses a vector with size 128 to represent all distinct chars (which can be
256 depending on the character encoding). It takes the ASCII value of each char
and stores a boolean value to indicate whether that char has been seen or not.

For example, if we have 'A', then the value at char_set['A'] = char_set[65]
will be true. So now anytime we run into char_set['A'] again, since it's now
set to true, we can return false since it was already found and the string
does not have all unique characters.
*/


bool isUniqueChars(std::string str) {
  if (str.length() > 128) return false;       // Only 128 unique characters, therefore any string > 128 has 1 duplicated char
  std::vector<bool> char_set(128);            // "Hashmap"
  for (int i = 0; i < str.length(); i++) {
    int val = str[i];
    if (char_set[val]) return false;          // Char already found in string, return false
    char_set[val] = true;                     // Else set the char found to be true
  }
  return true;
}
