// #include <iostream>
// #include <string>
// #include <vector>

// void replaceSpaces(std::vector<char> &str, int trueLength) {
//   int num_spaces = 0;
//   for (auto i : str) {
//     if (i == ' ') num_spaces++;
//   }
//   int newIndex = trueLength - 1 + num_spaces * 2;
//   if (newIndex + 1 < str.size())
//     str[newIndex + 1] = '\0';
//   for (int i = trueLength - 1; i >= 0; i--) {
//     if (str[i] == ' ') {
//       str[newIndex] = '0';
//       str[newIndex - 1] = '2';
//       str[newIndex - 2] = '%';
//       newIndex -= 3;
//     } else {
//       str[newIndex] = str[i];
//       newIndex--;
//     }
//   }
  


// This doesn't work. My first solution works fine. Every solution (the book and chatgpt) 
// produces "%20" on the trailing whitespaces

