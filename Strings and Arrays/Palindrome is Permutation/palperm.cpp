#include <iostream>
#include <string>
#include <unordered_map>

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