#ifndef C_BOARD_H
#define C_BOARD_H

#include "../Pieces/Piece.h"

class Board {

private:
    Piece board[8][8];
    bool winner = false;
    bool winnerSide;
    bool currentSide;

public:

    Board(bool color);
    void setCurrentSide(bool currentSide);
    bool isCurrentSide();
    void handleWinner();
    void fillBoard();
    void printBoard();
    bool isWinner();
    void setWinner(bool winner);
    void checkWinner();
};

#endif //C_BOARD_H
