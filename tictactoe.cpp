#include <iostream>
#include <string.h> // for strcpy()
#include <stdlib.h> // for srand() and abs(
#include <time.h> // for time()
using std::cout, std::cin, std::flush, std::abs;
// 9/23/25 Tic Tac Toe

namespace ttt {
  // tic tac toe namespace
  // do these count as global variables? i don't think they would because other programs aren't going to be using this namespace
  const char empty[4] = "   "; // used for emptying a char array easily
  const char chars[3] = "OX"; // theoretically, you could change these characters
  short turn = 0; // this is separate from the turn char
  short wins[2] = {0,0};
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
  cout << "\n" << flush;
  return;
}

void print_board(Board &board){
  // prints the board and its coordinates
  char turn_char = ttt::chars[ttt::turn];
  cout << turn_char << "'s Turn:\n";
  cout << "  1 2 3 \n";
  // now, print the board's contents
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
  if ((line[0] == ttt::chars[0]) || (line[0] == ttt::chars[1])){ // only need to check the first one
    if ((line[0] == line[1]) && (line[0] == line[2])){ // if all 3 chars are the same
      return line[0];
    }
  } else {
    return ' '; // default case
  }    
  return ' ';
}

void concatenate3(char* text, char x1, char x2, char x3){
  // makes concatination in check_lines easier
  text[0] = x1;
  text[1] = x2;
  text[2] = x3;
  return;
}

char check_lines(Board &board){
  // runs check_line for every possible line, returns the winning char
  char lines[8][4]; // array of char arrays, each representing a line
  // this char array needs to be blank, for some reason the intial values in memory mess it up
  for (int i = 0; i < 8; i++){
    strcpy(lines[i], ttt::empty);
  }
  // add all possible lines to a big array to iterate over
  concatenate3(lines[0], board.a[0], board.a[1], board.a[2]); // a1 a2 a3
  concatenate3(lines[1], board.b[0], board.b[1], board.b[2]); // b1 b2 b3
  concatenate3(lines[2], board.c[0], board.c[1], board.c[2]); // c1 c2 c3
  concatenate3(lines[3], board.a[0], board.b[0], board.c[0]); // a1 b1 c1
  concatenate3(lines[4], board.a[1], board.b[1], board.c[1]); // a2 b2 c2
  concatenate3(lines[5], board.a[2], board.b[2], board.c[2]); // a3 b3 c3
  concatenate3(lines[6], board.a[0], board.b[1], board.c[2]); // a1 b2 c3
  concatenate3(lines[7], board.a[2], board.b[1], board.c[0]); // a3 b2 c1
  // iterate over it to look for wins
  char win = ' ';
  for (int i = 0; i < 8; i++){
    char win1 = check_line(lines[i]);
    if (win1 != ' '){
      win = win1;
    }
  }
  return win;  
}

int main(){
  using ttt::turn;
  // outer main loop
  bool running1 = true;
  while (running1){
      Board board;
      srand(time(0));
      turn = rand(); // start as a random player
      turn %= 2; // i have never found a use for the %= operator before
      turn = abs(turn); // it was creating negative numbers otherwise. i think it's because i used a short for turn, so the int was overflowing
      // inner main loop
      bool running = true;
      while (running){
	// main loop
	cout << '\n';
	print_board(board);
	// get input
	bool valid = false;
	while (!valid){
	  char input[3];
	  cin >> input;
	  valid = true; // assume it is true, unless the default case runs
	  char turn_char = ttt::chars[turn];
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
	char win = check_lines(board);
	// check for winner
	if (win != ' '){
	  cout << "\n";
	  cout << win << " wins!\n";
	  ttt::wins[turn] += 1; // assuming the player who just moved won
	  cout << "Wins:\t";
	  cout << ttt::chars[0] << ": " << ttt::wins[0] << "\t";
	  cout << ttt::chars[1] << ": " << ttt::wins[1] << "\n" << flush;
	  running = false;
	}
	turn = 1 - turn; // this is a way of alternating between 1 and 0
      }
      char input[2];
      cout << "Do you want to play again? (y/n): " << flush;
      cin >> input; // need input before proceeding
      cout << '\n';
      if (input[0] != 'y'){
	running1 = false;
	cout << "Goodbye!";
      }
  }
  return 0;
}
