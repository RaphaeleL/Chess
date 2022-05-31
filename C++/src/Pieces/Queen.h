#ifndef C_QUEEN_H
#define C_QUEEN_H

#include "./Piece.h"

class Queen : Piece {

private:
    bool side;
    int value;
    std::string representation;

public:
    Queen(bool side, int value, const std::string &representation);

    bool checkMove(Piece board[8][8], int move[], bool side) override;

    virtual ~Queen();

    const std::string &getRepresentation() ;

};

#endif //C_QUEEN_H
