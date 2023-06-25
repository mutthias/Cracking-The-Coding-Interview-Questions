#include <iostream>
#include <unordered_map>
#include <string>

bool UniqueStr(std::string &s) {
	if (s.length() > 128) return false;								// Only 128 unique characters, therefore any string > 128 has 1 duplicated char
	std::unordered_map<char, int> map;								// Hashmap
	for (int i = 0; i < s.length(); i++) {
		if (map[s[i]]) return false;										// If found in our hash table, duplicated char
		else map[s[i]]++;																// Otherwise add to hash table
	}
	return true;
}

int main() {
	std::string s = "Hello Guys";
  std::cout<< UniqueStr(s) << "hi"<< std::endl;
	return 0;
}