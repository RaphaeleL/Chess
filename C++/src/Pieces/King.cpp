#include "King.h"

bool King::checkMove(Piece board[8][8], int *move, bool side) {
    return false;
}

King::King(bool side, int value, const std::string &representation) : side(side), value(value),
                                                                      representation(representation) {}


King::~King() {

}

const std::string &King::getRepresentation() {
    return this->representation;
}
