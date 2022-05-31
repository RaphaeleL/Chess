#include "Bishop.h"

bool Bishop::checkMove(Piece board[8][8], int *move, bool side) {
    return false;
}

Bishop::Bishop(bool side, int value, const std::string &representation) : side(side), value(value),
                                                                          representation(representation) {}


Bishop::~Bishop() {

}


const std::string &Bishop::getRepresentation() {
    return this->representation;
}