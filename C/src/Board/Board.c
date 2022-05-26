#include <stdio.h>
#include "Board.h"

void fillBoard() {
  // rook
  board[0][0] = 1; 
  board[0][7] = 1; 
  board[7][7] = -1; 
  board[7][0] = -1; 
  // knights
  board[0][1] = 2; 
  board[0][6] = 2; 
  board[7][6] = -2; 
  board[7][1] = -2; 
  // bishops 
  board[0][2] = 3; 
  board[0][5] = 3; 
  board[7][5] = -3; 
  board[7][2] = -3; 
  // king 
  board[0][3] = 4; 
  board[0][4] = 5; 
  board[7][4] = -4; 
  board[7][3] = -5; 
  // pawn
  for (int i = 0; i < MAX_SIZE; i++) {
    board[1][i] = 6; 
    board[6][i] = -6; 
  }
}

void printBoard() {
  for (int i = 0; i < MAX_SIZE; i++) {
    for (int j = 0; j < MAX_SIZE; j++) {
      //printf("(%d-%d) \t", i, j);
      printf("%d\t", board[i][j]);
    }
    if (i != MAX_SIZE-1) {
      printf("\n\n\n");
    }
  }
  printf("\n");
}

