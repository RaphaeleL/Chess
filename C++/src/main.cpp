#include <iostream>
#include "./Utils/Movement.h"

int main() {
    Board *board = new Board();
    Movement *movement = new Movement();
    movement->dearScreen();
    int side = 1; // WHITE
    board->fillBoard();
    board->printBoard();
    while (movement->checkWinner(board->board)) {
        movement->getPlayerInput(side);
        board->makeMove(movement->getFromX(), movement->getFromY(), movement->getToX(), movement->getToY());
        board->printBoard();
        side = side * -1;
    }
  return 0;
}
