#ifndef C_PIECE_H
#define C_PIECE_H

#include <iostream>

class Piece {

private:
    bool side;
    int value;
    std::string representation;

public:
    bool isSide() const;
    void setSide(bool side);
    int getValue() const;
    void setValue(int value);
    const std::string &getRepresentation() const;
    void setRepresentation(const std::string &representation);

    Piece();
    Piece(std::string representation);
    Piece(bool side, std::string representation);
    Piece(bool side, int value, std::string representation);

    bool checkMove(Piece board[8][8], int move[], bool side);

};


#endif //C_PIECE_H
