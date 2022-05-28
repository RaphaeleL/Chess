#include <stdio.h>
#include "Board/Board.h"
#include "Utils/Movement.h"

int main() {
  dearScreen();
  int side = 1; // WHITE 
  fillBoard();
  printBoard();
  
  while (hasWinner() == 1) {
    //int input = getPlayerInput(side);
    //prepare(input);
    getPlayerInput(side);

    side = side * -1;
  }
  
  return 0;
}
