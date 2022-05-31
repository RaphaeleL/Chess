#include "Rook.h"

bool Rook::checkMove(Piece board[8][8], int *move, bool side) {
    return false;
}

Rook::Rook(bool side, int value, const std::string &representation, bool side1, int value1,
           const std::string &representation1) : Piece(side, value, representation), side(side1), value(value1),
                                                 representation(representation1) {}

Rook::~Rook() {

}
