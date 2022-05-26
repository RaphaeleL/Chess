#include <stdio.h>
#include "Board/Board.h"
#include "Utils/Movement.h"

int main() {
  dearScreen();
  chooseColor();
  
  fillBoard();
  printBoard();
  
  return 0;
}
