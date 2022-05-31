#include "Queen.h"

Queen::~Queen() {

}

Queen::Queen(bool side, int value, const std::string &representation) : side(side), value(value),
                                                                      representation(representation) {

}

bool Queen::checkMove(Piece board[8][8], int *move, bool side) {
    return false;
}
