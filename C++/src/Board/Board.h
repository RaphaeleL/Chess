#ifndef C_BOARD_H
#define C_BOARD_H

#include "../Pieces/Piece.h"
#include "../Pieces/Rook.h"
#include "../Pieces/Bishop.h"
#include "../Pieces/Knight.h"
#include "../Pieces/Pawn.h"
#include "../Pieces/King.h"
#include "../Pieces/Queen.h"

class Board {

private:
    // TODO: replace piece with empty
    Piece myBoard[8][8] = {
            {
                    new Rook(false, 5, "R"),
                    new Knight(false, 3, "K"),
                    new Bishop(false, 3, "B"),
                    new Bishop(false, 9, "Q"),
                    new Bishop(false, 1, "X"),
                    new Bishop(false, 3, "B"),
                    new Knight(false, 3, "K"),
                    new Rook(false, 5, "R"),
                    },
            {
                    new Pawn(false, 1, "P"),
                    new Pawn(false, 1, "P"),
                    new Pawn(false, 1, "P"),
                    new Pawn(false, 1, "P"),
                    new Pawn(false, 1, "P"),
                    new Pawn(false, 1, "P"),
                    new Pawn(false, 1, "P"),
                    new Pawn(false, 1, "P"),
                },
            {new Piece(false, -1, "o"), new Piece(false, -1, "o"), new Piece(false, -1, "o"), new Piece(false, -1, "o"), new Piece(false, -1, "o"), new Piece(false, -1, "o"), new Piece(false, -1, "o"), new Piece(false, -1, "o")},
            {new Piece(false, -1, "o"), new Piece(false, -1, "o"), new Piece(false, -1, "o"), new Piece(false, -1, "o"), new Piece(false, -1, "o"), new Piece(false, -1, "o"), new Piece(false, -1, "o"), new Piece(false, -1, "o")},
            {new Piece(false, -1, "o"), new Piece(false, -1, "o"), new Piece(false, -1, "o"), new Piece(false, -1, "o"), new Piece(false, -1, "o"), new Piece(false, -1, "o"), new Piece(false, -1, "o"), new Piece(false, -1, "o")},
            {new Piece(false, -1, "o"), new Piece(false, -1, "o"), new Piece(false, -1, "o"), new Piece(false, -1, "o"), new Piece(false, -1, "o"), new Piece(false, -1, "o"), new Piece(false, -1, "o"), new Piece(false, -1, "o")},
            {
                new Pawn(true, 1, "p"),
                new Pawn(true, 1, "p"),
                new Pawn(true, 1, "p"),
                new Pawn(true, 1, "p"),
                new Pawn(true, 1, "p"),
                new Pawn(true, 1, "p"),
                new Pawn(true, 1, "p"),
                new Pawn(true, 1, "p"),
            },
            new Rook(true, 5, "r"),
            new Knight(true, 3, "k"),
            new Bishop(true, 3, "b"),
            new Bishop(true, 9, "q"),
            new Bishop(true, 1, "x"),
            new Bishop(true, 3, "b"),
            new Knight(true, 3, "k"),
            new Rook(true, 5, "r"),
    };

    bool winner = false;
    bool winnerSide;
    bool currentSide;

public:
    Board(bool color);
    void setCurrentSide(bool currentSide);
    bool isCurrentSide();
    void handleWinner();
    void printBoard();
    bool isWinner();
    void setWinner(bool winner);
    void checkWinner();
};

#endif //C_BOARD_H
