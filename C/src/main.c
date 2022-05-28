#include <stdio.h>
#include "Board/Board.h"
#include "Utils/Movement.h"

int main() {
  dearScreen();
  int side = 1; // WHITE 
  fillBoard();
  printBoard();
  
  while (hasWinner() == 1) {
    getPlayerInput(side);
    makeMove(getFromX(), getFromY(), getToX(), getToY()); 

    printBoard();
    
    side = side * -1;
  }
  
  return 0;
}
