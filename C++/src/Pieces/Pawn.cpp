#include "Pawn.h"

bool Pawn::checkMove(Piece board[8][8], int *move, bool side) {
    return false;
}

Pawn::Pawn(bool side, int value, const std::string &representation) : side(side), value(value),
                                                                      representation(representation) {}


Pawn::~Pawn() {

}


const std::string &Pawn::getRepresentation() {
    return this->representation;
}