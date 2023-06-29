#include <iostream>
#include <string>
#include <unordered_map>

/*
Based on a hashmap approach:
	1) Build Hash Table
	2) Two conditions in the case of an odd string vs even string
	3) If the string is even, there cannot be a value with an even frequency (it is not a palindrome)
	4) If the string is odd, there can be only 1 char that has an odd frequency. Any more than that
		 then the string is not a palindrome
*/

bool PalisPerm(std::string &str) {
	std::unordered_map<char, int> map;
	int odd = 0;
	for (auto i : str)
		map[i]++;

	for (const auto& pair : map) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }
	
	if (str.length() % 2 == 0) {
		for (auto c : map) {
			if (c.second % 2 != 0)
				return false;
		}
	}

	else if (str.length() % 2 == 1) {
		for (auto c : map) {			
			if (c.second % 2 != 0)
				odd++;
			if (odd > 1)
				return false;
		}
	}
	return true;
}

int main() {
	std::string s = "abbabbaca";
	std::cout << PalisPerm(s) << std::endl;
	return 0;
}
