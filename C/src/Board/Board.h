#ifndef BOARD_H
#define BOARD_H

#define MAX_SIZE 8

int board [MAX_SIZE][MAX_SIZE];

void makeMove(int fromX, int fromY, int toX, int toY);
void fillBoard();
void printBoard();

#endif //BOARD_H

