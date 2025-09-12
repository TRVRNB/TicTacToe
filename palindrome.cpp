#include <iostream>
#include <cstring>

using namespace std;

bool in(char str, char*arr){
  // returns whether or not str is in array
  for (int i = 0; i < strlen(arr); i++){
    if (arr[i] == str){
      return true;
    }
  }
  
  return false;
}


char* reverse(char*str){
  // returns a pointer to a reversed char array
  char str2[81];
  int len = strlen(str);
  for (int i = 0; i < len; i++){
    str2[len-i-1] = str[i]; // reverse logic    
  }
  str2[len] = '\0';
  char* pointer = new char[81]; // this needs to return a pointer so it doesn't rely on local memory
  strcpy(pointer, str2);
  return pointer;
}

char* rmext(char*str){
  // removes data that can interfere with strcmp and lowercases capital letters
  char str2[81];
  int len = strlen(str);
  char valid[40] = "abcdefghijklmnopqrstuvwxyz0123456789"; // array of all characters to be used in the comparison
  int j = 0; // the spot to place a letter in str2
  char str3[81];
  strcpy(str3, str); // turn a pointer into a char array

  for (int i = 0; i < len; i++){
    str3[i] = tolower(str3[i]);
    if (in(str3[i], valid)){ // look for str[i] in valid
      str2[j] = str3[i];
	j++;
    }
  }
  char* pointer = new char[81]; // same as reverse()
  strcpy(pointer, str2);
  return pointer;
}

int main(){
  char str[81]; // 1 extra length so the input doesn't write over the terminating char, is that how this works?
  std::cout << "Enter a phrase: " << std::flush;
  cin.get(str, 80);
  char* str2 = rmext(str);
  char str4[81];
  strcpy(str4, str2);
  char* str3 = reverse(str2);
  std::cout << str3 << "\n";
  // now, compare them
  if (strcmp(str4, str3)){ // this is very unintuitive
    std::cout << "This is not a palindrome.";
  } else {
    std::cout << "This is a palindrome!";
  }
  return 0;
}
 
