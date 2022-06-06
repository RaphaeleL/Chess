#include "Movement.h"

Movement::Movement() {

}

int Movement::getPosition(char c) {
    int pos;
    const char * alphabet = "abcdefghijklmnopqrstuvwxyz";
    const char * found;
    c = tolower ((unsigned char)c);
    found = strchr (alphabet, c);
    pos = found - alphabet;
    if (!found)
        pos = 0;
    else if (pos == 26)
        pos = 0;
    else
        pos++;
    return pos;
}

void Movement::getInput(bool side) {
    std::string color = side ? "WHITE" : "BLACK";
    std::string input;
    std::cout << "\n" << color << " [FROM,TO] > ";
    std::getline(std::cin, input);
    for (int i = 0; i < input.length(); i++) {
        Movement::coords[i] = input[i];
        //std::cout << input[i] << std::endl;
    }
}

int Movement::getFromX() {
    return getPosition(coords[0]) - 1;
}

int Movement::getFromY() {
    return (int) coords[1] - '0' - 1;
}

int Movement::getToX() {
    return getPosition(coords[2]) - 1;
}

int Movement::getToY() {
    return (int) coords[3] - '0' - 1;
}

void Movement::dearScreen() {
    printf(" ######                       ######  ##     ## ########  ######   ######\n");
    printf("##    ##                     ##    ## ##     ## ##       ##    ## ##    ##\n");
    printf("##        #######  #######   ##       ##     ## ##       ##       ##\n");
    printf("##       ##     ## ##     ## ##       ######### ######    ######   ######\n");
    printf("##       ##     ## ##     ## ##       ##     ## ##             ##       ##\n");
    printf("##    ## ########  ########  ##    ## ##     ## ##       ##    ## ##    ##\n");
    printf(" ######  ##        ##         ######  ##     ## ########  ######   ######\n");
    printf("==========================================================================\n");
    printf("==========================================================================\n");
    printf("Hint: CppChess is still in development, so there might be any issues\n");
    printf("==========================================================================\n");
    printf("==========================================================================\n");
}

int Movement::chooseColor() {
    return 0;
}

void Movement::getPlayerInput(int side) {
    if (side == 1) {
        getInput(true);
    } else if (side == -1) {
        getInput(false);
    }
    printf("\n");
}

int Movement::checkWinner(int (*board)[8]) {
    int blackCount = 0;
    int whiteCount = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            int piece = board[i][j];
            if (piece > 0) {
                blackCount++;
            } else if (piece < 0) {
                whiteCount++;
            }
        }
    }
    if (blackCount == 0) {
        handleWinner(1);
        return 0;
    } else if (whiteCount == 0) {
        handleWinner(2);
        return 0;
    }
    return 1;
}

void Movement::handleWinner(int side) {
    printf("======================================================\n");
    if (side == 1) {
        printf("Black won\n");
    } else if (side == 2) {
        printf("White won\n");
    }
    printf("======================================================\n");
}
