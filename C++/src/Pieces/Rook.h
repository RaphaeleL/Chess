#ifndef C_QUEEN_H
#define C_QUEEN_H

#include "./Piece.h"

class Rook : Piece {

private:
    bool side;
    int value;
    std::string representation;

public:
    Rook(bool side, int value, const std::string &representation);

    bool checkMove(Piece board[8][8], int move[], bool side);

    virtual ~Rook();

    const std::string &getRepresentation() ;


};

#endif //C_ROOK_H
