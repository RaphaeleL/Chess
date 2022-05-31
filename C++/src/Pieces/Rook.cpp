#include "Rook.h"

bool Rook::checkMove(Piece board[8][8], int *move, bool side) {
    return false;
}

Rook::~Rook() {

}

Rook::Rook(bool side, int value, const std::string &representation) : side(side), value(value),
                                                                      representation(representation) {
    this->representation = representation;
    this->value = value;
    this->side = side;

}

const std::string &Rook::getRepresentation() {
    return this->representation;
}



