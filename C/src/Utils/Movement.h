#ifndef MOVEMENT_H
#define MOVEMENT_H

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

#endif //MOVEMENT_H


