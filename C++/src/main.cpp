#include <iostream>
#include "./Pieces/Piece.h"
#include "./Utils/Movement.h"

int main() {
    Movement movement;
    movement.dearScreen();
    Board board = new Board(movement.chooseColor());
    while(!board.isWinner()) {
        movement.move(board);
        board.setCurrentSide(!board.isCurrentSide());
        board.checkWinner();
    }
    board.handleWinner();
    std::cout << "CppChess" << std::endl;
  return 0;
}
