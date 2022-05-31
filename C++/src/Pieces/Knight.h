#ifndef C_KNIGHT_H
#define C_KNIGHT_H

#include "./Piece.h"

class Knight : Piece {

private:
    bool side;
    int value;
    std::string representation;

public:
    Knight(bool side, int value, const std::string &representation, bool side1, int value1,
         const std::string &representation1);

    bool checkMove(Piece board[8][8], int move[], bool side) override;

    virtual ~Knight();

};

#endif //C_Knight_H
