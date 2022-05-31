#ifndef C_PIECE_H
#define C_PIECE_H

#include <iostream>

class Piece {

public:

    int ba(int side, int fromX, int fromY, int toX, int toY, int board[8][8]);
    int bb(int side, int fromX, int fromY, int toX, int toY, int board[8][8]);
    int bc(int side, int fromX, int fromY, int toX, int toY, int board[8][8]);
    int bd(int side, int fromX, int fromY, int toX, int toY, int board[8][8]);

    int ra(int side, int fromX, int fromY, int toX, int toY, int board[8][8]);
    int rb(int side, int fromX, int fromY, int toX, int toY, int board[8][8]);
    int rc(int side, int fromX, int fromY, int toX, int toY, int board[8][8]);
    int rd(int side, int fromX, int fromY, int toX, int toY, int board[8][8]);

    static int checkKeyList(int size, int allowedKeys[8][2], int side, int fromX, int fromY, int toX, int toY, int board[8][8]);
    int inBounds(int x, int y);

    int checkRook(int side, int fromX, int fromY, int toX, int toY, int board[8][8]);
    int checkBishop(int side, int fromX, int fromY, int toX, int toY, int board[8][8]);
    int checkQueen(int side, int fromX, int fromY, int toX, int toY, int board[8][8]);

    int checkKnight(int side, int fromX, int fromY, int toX, int toY, int board[8][8]);
    int checkKing(int side, int fromX, int fromY, int toX, int toY, int board[8][8]);
    int checkPawn(int side, int fromX, int fromY, int toX, int toY, int board[8][8]);

    int check(int fromY, int fromX, int toY, int toX, int board[8][8]);

};

#endif //C_PIECE_H
