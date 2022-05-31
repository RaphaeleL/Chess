#include "Bishop.h"

Bishop::~Bishop() {

}

Bishop::Bishop(bool side, int value, const std::string &representation) : side(side), value(value),
                                                                      representation(representation) {

}

bool Bishop::checkMove(Piece board[8][8], int *move, bool side) {
    return false;
}
