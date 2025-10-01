#include <iostream>
#include <cstring>
using std::cout, std::cin, std::flush;
// 9/23/25 Tic Tac Toe

namespace ttt {
  // tic tac toe namespace
  // do these count as global variables? i don't think they would because other programs aren't going to be using this namespace
  const char empty[4] = "   "; // used for emptying a char array easily
  // add ttt chars
}

struct Board {
  // they need to be 4 long for /0
  // i could probably use a map for this, but i wanted to try out structs
  char a[4] = "---";
  char b[4] = "---";
  char c[4] = "---";
};

void print_line(char* line){
  // prints out a line of tic tac toe
  for (int i = 0; i < 3; i++){
    cout << ' ' << line[i];
  }
  cout << "\n" << std::flush;
  return;
}

void print_board(Board &board){
  // prints the board and its coordinates
  cout << "  1 2 3 \n";
  
  char* a = board.a;
  cout << "a";
  print_line(a);
  char* b = board.b;
  cout << "b";
  print_line(b);
  char* c = board.c;
  cout << "c";
  print_line(c);
  
  return;
}

char check_line(char* line){
  // returns ' ' if there is no connection of 3, otherwise returns the player char
  if (line[0] == 'O' || line[0] == 'X'){ // only need to check the first one
    if (line[0] == line[1] && line[0] == line[2]){ // if all 3 chars are the same
      return line[0];
    }
  } else {
    return ' '; // default case
  }    
  return ' ';
}

void concatenate3(char* text, char x1, char x2, char x3){
  // makes concatination in check_lines easier
  text[0], text[1], text[2] = x1, x2, x3;
  return;
}

char check_lines(Board &board){
  // runs check_line for every possible line
  char lines[8][4]; // array of char arrays, each representing a line

  // this char array needs to be blank, for some reason the intial values in memory mess it up
  for (int i = 0; i < 8; i++){
    strcpy(lines[i], ttt::empty);
  }


  concatenate3(lines[0], board.a[0], board.a[1], board.a[2]);
  return 'a';  
}

int main(){
  Board board;
  cout << "O goes first.";
  short turn = 0;
  
  bool running = true;
  while (running){
    // main loop
    cout << '\n';
    char turnchars[3] = "OX"; // theoretically, you could change the ascii codes used in tictactoe
    print_board(board);
    
    bool valid = false;
    while (!valid){
      char input[3];
      cin >> input;
      valid = true; // assume it is true, unless the default case runs
      char turn_char = turnchars[turn];
      int num = input[1] - '0' - 1;// apparently this works because the digits are sorted in ascii
      // and it uses the ascii codes when converting to int, so (int)'9' - '0' = 9
      switch (input[0]){
      case 'a':
	if (board.a[num] != '-'){
	  cout << "Invalid placement.\n"; // i need to repeat this 3 times, which is another reason a map might've worked better
	    valid = false;
	    break;
	  }
	board.a[num] = turn_char;
	break;
      case 'b':
	if (board.b[num] != '-'){
	    cout << "Invalid placement.\n";
	    valid = false;
	    break;
	  }
	board.b[num] = turn_char;
	break;
      case 'c':
	if (board.c[num] != '-'){
	    cout << "Invalid placement.\n";
	    valid = false;
	    break;
	  }
	board.c[num] = turn_char;
	break;
      default: // repeat this input
	cout << "Try: a1, b2, c1, a3\n" << flush;
	valid = false;
      }
    }
      
    check_lines(board);
    turn = 1 - turn; // this is a sketchy way of alternating between 1 and 0
  }



  
  return 0;
}
