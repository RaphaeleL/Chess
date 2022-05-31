#include "Knight.h"

bool Knight::checkMove(Piece board[8][8], int *move, bool side) {
    return false;
}

Knight::~Knight() {

}

Knight::Knight(bool side, int value, const std::string &representation) : side(side), value(value),
                                                                      representation(representation) {}


const std::string &Knight::getRepresentation() {
    return this->representation;
}