#include <iostream>
#include <cstring>

using namespace std;

char* strip(char*str){
  // strips a char array of its punctuation, and makes it lowercase
  char str2[81];
  int i = 0;
  while (str[i] != '\0'){
    if (str[i] != '\0'){
      str2[80-i] = str[i]; // test palindrome, move to palindrome() function later
      i++;
    }
  }
  std::cout << str2 << std::flush;
  return str; // update this to return the processed string
}


int main(){
  char str[81]; // 1 extra length so the input doesn't write over the terminating char, is that how this works?
  std::cout << "Enter a phrase: " << std::flush;
  cin.get(str, 80);
  char* str2 = strip(str);
  return 0;
}
 
