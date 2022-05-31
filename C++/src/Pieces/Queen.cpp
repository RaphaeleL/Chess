#include "Queen.h"

bool Queen::checkMove(Piece board[8][8], int *move, bool side) {
    return false;
}

Queen::Queen(bool side, int value, const std::string &representation) : side(side), value(value),
                                                                        representation(representation) {}


Queen::~Queen() {

}


const std::string &Queen::getRepresentation() {
    return this->representation;
}