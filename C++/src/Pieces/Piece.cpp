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

const std::string &Piece::getRepresentation() const {
    return representation;
}

void Piece::setRepresentation(const std::string &representation) {
    Piece::representation = representation;
}

Piece::~Piece() {

}

bool Piece::checkMove(Piece (*board)[8], int *move, bool side) {
    return false;
}
