#include <iostream>
#include <cstring>
// 9/23/25 Tic Tac Toe


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
    std::cout << ' ' << line[i];
  }
  std::cout << "\n" << std::flush;
  return;
}


void print_board(Board board){
  // prints the board and its coordinates
  std::cout << "  1 2 3 \n";
  
  char* a = board.a;
  std::cout << "a";
  print_line(a);
  char* b = board.b;
  std::cout << "b";
  print_line(b);
  char* c = board.c;
  std::cout << "c";
  print_line(c);
  
  return;
}



int main(){
  Board board;
  std::cout << "O goes first.";
  short turn = 0;
  
  bool running = true;
  while (running){
    // main loop
    std::cout << '\n';
    char turnchars[3] = "OX";
    print_board(board);
    
    bool valid = false;
    while (not valid){
      char input[3];
      std::cin >> input;
      valid = true; // assume it is true, unless the default case runs
      char turn_char = turnchars[turn];
      
      switch (input[0]){
      case 'a':
	board.a[(int)input[1] - 1] = turn_char;
	break;
      case 'b':
	board.b[(int)input[1] - 1] = turn_char;
	break;
      case 'c':
	board.c[(int)input[1] - 1] = turn_char;
	break;
      default: // repeat this input
	std::cout << "Try: a1, b2, c1, a3\n" << std::flush;
	valid = false;
      }

    }
      
    
    turn = 1 - turn; // this is a sketchy way of alternating between 1 and 0
  }



  
  return 0;
}
