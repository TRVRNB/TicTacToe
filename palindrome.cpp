#include <iostream>
#include <cstring>

using namespace std;

char* strip(char*str){
  // strips a char array of its punctuation, and makes it lowercase
  char str2[81];
  int i = 0;
  int len = strlen(str);
  for (int i = 0; i < strlen(str); i++){
    str2[len-i-1] = str[i]; // test palindrome, move to palindrome() function later
    
  }
  str2[len] = '\0';
  char* pointer = new char[81]; // this needs to return a pointer so it doesn't rely on local memory
  strcpy(pointer, str2);
  return pointer; // update this to return the processed string
}


int main(){
  char str[81]; // 1 extra length so the input doesn't write over the terminating char, is that how this works?
  std::cout << "Enter a phrase: " << std::flush;
  cin.get(str, 80);
  char* str2 = strip(str);
  std::cout << str2;
  return 0;
}
 
