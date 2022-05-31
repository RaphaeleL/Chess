#include "Pawn.h"

Pawn::~Pawn() {

}

Pawn::Pawn(bool side, int value, const std::string &representation) : side(side), value(value),
                                                                      representation(representation) {

}

bool Pawn::checkMove(Piece board[8][8], int *move, bool side) {
    return false;
}
