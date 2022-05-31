#ifndef C_PIECE_H
#define C_PIECE_H

#include <iostream>

class Piece {

private:
    bool side;
    int value;
    std::string representation;

public:
    Piece();

    virtual ~Piece();

    Piece(bool side, int value, const std::string &representation);

    Piece(bool side, int value);

    Piece(bool side);

    virtual bool checkMove(Piece board[8][8], int move[], bool side);

    bool isSide() const;

    void setSide(bool side);

    int getValue() const;

    void setValue(int value);

    virtual const std::string &getRepresentation();

};


#endif //C_PIECE_H
