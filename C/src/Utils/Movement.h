#ifndef MOVEMENT_H
#define MOVEMENT_H

void dearScreen(); 
int chooseColor();
int getPlayerInput(int side);
int hasWinner();
void checkWinner();
void handleWinner();
void prepare(int input);
void setCoords(int counter, int mod);
void printCoords();

#endif //MOVEMENT_H


