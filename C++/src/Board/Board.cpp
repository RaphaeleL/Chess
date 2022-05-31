#include "Board.h"

Board::Board(bool color) {
    this->currentSide = color;
}

void Board::printBoard() {
    for (auto i = 0; i < 8; i++) {
        for (auto j = 0; j < 8; j++) {
            std::cout << "(" << this->myBoard[i][j].getRepresentation() << ")";
            //std::cout << "(" << i << "-" << j << ")";
        }
        if (i < 7) {
            std::cout << std::endl;
        }
    }
}

bool Board::isCurrentSide() {
    return this->currentSide;
}

void Board::setCurrentSide(bool currentSide) {
    this->currentSide = currentSide;
}

void Board::handleWinner() {

}

bool Board::isWinner() {
    return this->winner;
}

void Board::setWinner(bool winner) {
    this->winner = winner;
}

void Board::checkWinner() {

}