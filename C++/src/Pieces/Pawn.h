#ifndef C_PAWN_H
#define C_PAWN_H

#include "./Piece.h"

class Pawn : Piece {

private:
    bool side;
    int value;
    std::string representation;

public:
    Pawn(bool side, int value, const std::string &representation);

    bool checkMove(Piece board[8][8], int move[], bool side) override;

    virtual ~Pawn();

    const std::string &getRepresentation() ;

};

#endif //C_Pawn_H