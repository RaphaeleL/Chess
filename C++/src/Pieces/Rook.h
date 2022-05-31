#ifndef C_QUEEN_H
#define C_QUEEN_H

#include "./Piece.h"

class Rook : Piece {

private:
    bool side;
    int value;
    std::string representation;

public:
    Rook(bool side, int value, const std::string &representation, bool side1, int value1,
         const std::string &representation1);

    bool checkMove(Piece board[8][8], int move[], bool side);

    virtual ~Rook();

};

#endif //C_ROOK_H
