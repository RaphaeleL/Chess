#ifndef C_QUEEN_H
#define C_QUEEN_H

#include "./Piece.h"

class Bishop : Piece {

private:
    bool side;
    int value;
    std::string representation;

public:
    Bishop(bool side, int value, const std::string &representation);
    bool checkMove(Piece board[8][8], int move[], bool side);
    virtual ~Bishop();
};


#endif //C_BISHOP_H
