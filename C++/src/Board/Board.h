#ifndef C_BOARD_H
#define C_BOARD_H

#include "../Pieces/Piece.h"
#include "../Pieces/Rook.h"

class Board {

private:
    Piece myBoard[8][8] = {
            {new Piece(false), new Piece(false), new Piece(false), new Piece(false), new Piece(false), new Piece(false), new Piece(false), new Piece(false)},
            {new Piece(false), new Piece(false), new Piece(false), new Piece(false), new Piece(false), new Piece(false), new Piece(false), new Piece(false)},
            {new Piece(false), new Piece(false), new Piece(false), new Piece(false), new Piece(false), new Piece(false), new Piece(false), new Piece(false)},
            {new Piece(false), new Piece(false), new Piece(false), new Piece(false), new Piece(false), new Piece(false), new Piece(false), new Piece(false)},
            {new Piece(false), new Piece(false), new Piece(false), new Piece(false), new Piece(false), new Piece(false), new Piece(false), new Piece(false)},
            {new Piece(false), new Piece(false), new Piece(false), new Piece(false), new Piece(false), new Piece(false), new Piece(false), new Piece(false)},
            {new Piece(false), new Piece(false), new Piece(false), new Piece(false), new Piece(false), new Piece(false), new Piece(false), new Piece(false)},
            {new Piece(false), new Piece(false), new Piece(false), new Piece(false), new Piece(false), new Piece(false), new Piece(false), new Piece(false)},
    };
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
