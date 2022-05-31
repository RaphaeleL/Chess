#include "Rook.h"

Rook::~Rook() {

}

Rook::Rook(bool side, int value, const std::string &representation) : side(side), value(value),
                                                                      representation(representation) {

}

bool Rook::checkMove(Piece board[8][8], int *move, bool side) {
    return false;
}
