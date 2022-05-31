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
    bool isAllowed(std::list<int> allowedMovements, int move[]);
    void dearScreen();
    bool isFree(Board board, int x, int y, bool mySide, Piece fromPiece);
    bool chooseColor();
    bool inBounds(int x, int y);
    int letterToNumber(std::string movement);
    std::string getInput(Board board);
    void move(Board board);

};


#endif //C_MOVEMENT_H
