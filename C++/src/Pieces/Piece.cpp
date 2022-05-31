#include "Piece.h"

Piece::Piece(bool side, int value, const std::string &representation) : side(side), value(value),
                                                                        representation(representation) {}

Piece::Piece(bool side, int value) : side(side), value(value) {}

Piece::Piece(bool side) : side(side) {}

bool Piece::isSide() const {
    return side;
}

void Piece::setSide(bool side) {
    Piece::side = side;
}

int Piece::getValue() const {
    return value;
}

void Piece::setValue(int value) {
    Piece::value = value;
}

Piece::~Piece() {

}

const std::string &Piece::getRepresentation() {
    return this->representation;
}

bool Piece::checkMove(Piece (*board)[8], int *move, bool side) {
    return false;
}

Piece::Piece() {}
