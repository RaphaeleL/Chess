#ifndef PIECE_H
#define PIECE_H

int checkRook(int side); 
int checkBishop(int side); 
int checkKnight(int side); 
int checkKing(int side); 
int checkQueen(int side); 
int checkPawn(int side); 
int check(int fromY, int fromX, int toY, int toX, int board[8][8]); 

#endif //PIECE_H

