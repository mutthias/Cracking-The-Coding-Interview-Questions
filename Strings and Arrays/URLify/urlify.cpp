#include <iostream>
#include <string>

std::string URLify(std::string &str, int n) {
	std::string url_string = "";
	
	for (int i = 0; i < n; i++) {
		if(str[i] == 32) {
			str[i]--;
			url_string += "%20";
			
		}
		url_string += str[i];
	}
	return url_string;
}

int main() {
	std::string s = "Mr John Smith        ";
	std::cout << URLify(s, 13) << std::endl;
	return 0;
}