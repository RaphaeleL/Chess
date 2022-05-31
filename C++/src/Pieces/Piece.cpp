#include "Piece.h"

Piece::Piece() {

}

Piece::Piece(std::string representation) {

}

Piece::Piece(bool side, std::string representation) {

}

Piece::Piece(bool side, int value, std::string representation) {

}

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

bool Piece::checkMove(Piece board[8][8], int move[], bool side) {
    return false;
}
