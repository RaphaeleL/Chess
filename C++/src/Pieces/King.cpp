#include "King.h"

King::~King() {

}

King::King(bool side, int value, const std::string &representation) : side(side), value(value),
                                                                      representation(representation) {

}

bool King::checkMove(Piece board[8][8], int *move, bool side) {
    return false;
}
