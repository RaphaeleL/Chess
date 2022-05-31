#include "Movement.h"

Movement::Movement() {

}

bool Movement::isAllowed(std::list<int> allowedMovements, int move[]) {
    return false;
}

void Movement::dearScreen() {
    std::cout << " ######                       ######  ##     ## ########  ######   ######  " << std::endl;
    std::cout << "##    ##                     ##    ## ##     ## ##       ##    ## ##    ## " << std::endl;
    std::cout << "##        #######  #######   ##       ##     ## ##       ##       ##       " << std::endl;
    std::cout << "##       ##     ## ##     ## ##       ######### ######    ######   ######  " << std::endl;
    std::cout << "##       ##     ## ##     ## ##       ##     ## ##             ##       ## " << std::endl;
    std::cout << "##    ## ########  ########  ##    ## ##     ## ##       ##    ## ##    ## " << std::endl;
    std::cout << " ######  ##        ##         ######  ##     ## ########  ######   ######  " << std::endl;
    std::cout << "===========================================================================" << std::endl;
    std::cout << "===========================================================================" << std::endl;
    std::cout << "Hint: CppChess is still in development, so currently the\nboard does not rotate with the choice of color." << std::endl;
    std::cout << "===========================================================================" << std::endl;
    std::cout << "===========================================================================" << std::endl;
}

bool Movement::isFree(Board board, int x, int y, bool mySide, Piece fromPiece) {
    return false;
}

bool Movement::chooseColor() {
    std::string input;
    std::cout << "Which color? (W/b) > ";
    std::getline(std::cin, input);
    return input == "w" ? true : false;
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
