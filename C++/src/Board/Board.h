#ifndef C_BOARD_H
#define C_BOARD_H

#define MAX_SIZE 8

#include "../Pieces/Piece.h"

class Board {

public:
    Board();
    int board [MAX_SIZE][MAX_SIZE];

    char getRepresentation(int figure);
    void makeMove(int fromX, int fromY, int toX, int toY);
    void fillBoard();
    void printBoard();

};

#endif //C_BOARD_H
