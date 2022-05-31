#ifndef C_QUEEN_H
#define C_QUEEN_H

#include "./Piece.h"

class Pawn : Piece {

private:
    bool side;
    int value;
    std::string representation;

public:
    Pawn(bool side, int value, const std::string &representation);
    bool checkMove(Piece board[8][8], int move[], bool side);
    virtual ~Pawn();
};

#endif //C_PAWN_H
