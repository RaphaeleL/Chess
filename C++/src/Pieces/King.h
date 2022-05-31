#ifndef C_KING_H
#define C_KING_H

#include "./Piece.h"

class King : Piece {

private:
    bool side;
    int value;
    std::string representation;

public:
    King(bool side, int value, const std::string &representation);

    bool checkMove(Piece board[8][8], int move[], bool side) override;

    virtual ~King();

    const std::string &getRepresentation() ;

};

#endif //C_King_H
