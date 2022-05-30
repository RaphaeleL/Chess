#ifndef PIECE_H
#define PIECE_H

int cap;

int checkKeyList(int size, int allowedKeys[cap][2], int side, int fromX, int fromY, int toX, int toY, int board[8][8]); 
int inBounds(int x, int y); 

int checkRook(int side, int fromX, int fromY, int toX, int toY, int board[8][8]); 
int checkBishop(int side, int fromX, int fromY, int toX, int toY, int board[8][8]); 
int checkKnight(int side, int fromX, int fromY, int toX, int toY, int board[8][8]); 
int checkKing(int side, int fromX, int fromY, int toX, int toY, int board[8][8]); 
int checkQueen(int side, int fromX, int fromY, int toX, int toY, int board[8][8]); 
int checkPawn(int side, int fromX, int fromY, int toX, int toY, int board[8][8]); 

int check(int fromY, int fromX, int toY, int toX, int board[8][8]); 

#endif //PIECE_H

