#include "Board.h"

Board::Board(bool color) {
    this->currentSide = color;
    this->fillBoard();
    this->printBoard();
}

void Board::fillBoard() {

}

void Board::printBoard() {

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