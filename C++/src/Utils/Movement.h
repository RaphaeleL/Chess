#ifndef C_MOVEMENT_H
#define C_MOVEMENT_H

#include <algorithm>
#include <iostream>
#include <list>

#include "../Board/Board.h"
#include "../Pieces/Piece.h"

class Movement {

public:
    Movement();
    int getPosition (char c);
    int getFromX();
    int getFromY();
    int getToX();
    int getToY();
    void dearScreen();
    int chooseColor();
    void getPlayerInput(int side);
    int checkWinner(int board[8][8]);
    void handleWinner(int side);
    void setCoords(int counter, int mod);
};


#endif //C_MOVEMENT_H
