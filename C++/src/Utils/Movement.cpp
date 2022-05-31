#include "Movement.h"

Movement::Movement() {

}

bool Movement::isAllowed(std::list<int> allowedMovements, int move[]) {
    return false;
}

void Movement::dearScreen() {

}

bool Movement::isFree(Board board, int x, int y, bool mySide, Piece fromPiece) {
    return false;
}

bool Movement::chooseColor() {
    return false;
}

bool Movement::inBounds(int x, int y) {
    return false;
}

int Movement::letterToNumber(std::string movement) {
    return 0;
}

std::string Movement::getInput(Board board) {
    return "";
}

void Movement::move(Board board) {

}
