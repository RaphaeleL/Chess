#ifndef C_BISHOP_H
#define C_BISHOP_H

#include "./Piece.h"

class Bishop : Piece {

private:
    bool side;
    int value;
    std::string representation;

public:
    Bishop(bool side, int value, const std::string &representation, bool side1, int value1,
         const std::string &representation1);

    bool checkMove(Piece board[8][8], int move[], bool side) override;

    virtual ~Bishop();

};

#endif //C_Bishop_H
