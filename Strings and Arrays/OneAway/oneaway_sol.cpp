#include <iostream>
#include <string>
#include <vector>


/*
pale --> pae = true
pale --> bae = false
pales --> pale = true
pales --> bale = false

Want to check the case in which a string is valid for insetion, removal, and replalcement.
3 functions to check for each.
*/
bool OneInsertion(std::string& s1, std::string& s2);
bool OneRemoval(std::string& s1, std::string& s2);

bool OneEdit(std::string& s1, std::string& s2) {
    if (s1.size() == s2.size()) {
        return OneInsertion(s1, s2);
    } else if (s1.size() + 1 == s2.size()) {
        return OneRemoval(s1, s2);
    } else if (s1.size() - 1 == s2.size()) {
        return OneRemoval(s2, s1);
    }
    return false;
}

bool OneInsertion(std::string &s1, std::string &s2) {
  int index1, index2 = 0;
  while (index2 < s2.size() && index1 < s1.size()) {
    if (s1[index1] != s2[index2]) {
      if (index1 != index2) {
        return false;
      }
      index2++;
    } else {
      index1++;
      index2++;
    }
  }
  return true;
}

bool OneRemoval(std::string &s1, std::string &s2) {
  bool found_diff = false; 
  for (int i = 0; i < s1.size(); i++) {
    if (s1[i] != s2[i]) {
      if (found_diff) {
        return false;
      }
      found_diff = true;
    }
  }
  return true;
}




int main() {
  std::string s1 = "pale";
  std::string s2 = "pae";
  std::string s3 = "pales";
  std::string s4 = "bale";
  std::string s5 = "bae";

  std::cout << OneEdit(s1, s2) << std::endl;
  std::cout << OneEdit(s3, s1) << std::endl;
  std::cout << OneEdit(s1, s4) << std::endl;
  std::cout << OneEdit(s1, s5) << std::endl;
  
  return 0;
}
