#include <stdio.h>
#include "../Board/Board.h" 

int checkRook(int side, int fromX, int fromY, int toX, int toY, int board[8][8]) {
  return 1;
}

int checkQueen(int side, int fromX, int fromY, int toX, int toY, int board[8][8]) {
  return 1;
}

int checkKing(int side, int fromX, int fromY, int toX, int toY, int board[8][8]) {
  return 1;
}

int checkKnight(int side, int fromX, int fromY, int toX, int toY, int board[8][8]) {
  return 1;
}

int checkBishop(int side, int fromX, int fromY, int toX, int toY, int board[8][8]) {
  return 1;
}

int checkKeyList(int size, int allowedKeys[3][2], int side, int fromX, int fromY, int toX, int toY, int board[8][8]) {
  int x, y;
  // iterate the allowed keys
  for (int i = 0; i < size; i++) {
    // calc the x and y coords for two steps and key steps
    x = fromX - allowedKeys[i][0];
    y = fromY - allowedKeys[i][1];
    if (!side) {
      x = fromX + allowedKeys[i][0];
      y = fromY + allowedKeys[i][1];
    }
    // check if move is allowed
    if ((toX == x) && (toY == y)) {
      return 1;
    }
  }
  return -1;
}

int checkPawn(int side, int fromX, int fromY, int toX, int toY, int board[8][8]) {
  int x, y;
  int allowedKeys[3][2] = {{1, 0}, {1, 1}, {1, -1}};
  int size = sizeof(allowedKeys)/sizeof(allowedKeys[0]);
  // add baseline 2 steps movement
  x = fromX - 2; 
  y = fromY; 
  if (!side) {
    x = fromX + 2; 
    y = fromY; 
  }
  // check if move is allowed
  if ((toX == x) && (toY == y)) {
    return 1;
  }
  return checkKeyList(size, allowedKeys, side, fromX, fromY, toX, toY, board);
}

int check(int fromY, int fromX, int toY, int toX, int board[8][8]) {
  int fromPiece = board[fromX][fromY];
  if (fromPiece == 1) {
    return checkRook(0, fromX, fromY, toX, toY, board);
  } else if (fromPiece == 2) {
    return checkKnight(0, fromX, fromY, toX, toY, board);
  } else if (fromPiece == 3) {
    return checkBishop(0, fromX, fromY, toX, toY, board);
  } else if (fromPiece == 4) {
    return checkQueen(0, fromX, fromY, toX, toY, board);
  } else if (fromPiece == 5) {
    return checkKing(0, fromX, fromY, toX, toY, board);
  } else if (fromPiece == 6) {
    return checkPawn(0, fromX, fromY, toX, toY, board);
  } else if (fromPiece == -1) {
    return checkRook(1, fromX, fromY, toX, toY, board);
  } else if (fromPiece == -2) {
    return checkKnight(1, fromX, fromY, toX, toY, board);
  } else if (fromPiece == -3) {
    return checkBishop(1, fromX, fromY, toX, toY, board);
  } else if (fromPiece == -4) {
    return checkQueen(1, fromX, fromY, toX, toY, board);
  } else if (fromPiece == -5) {
    return checkKing(1, fromX, fromY, toX, toY, board);
  } else if (fromPiece == -6) {
    return checkPawn(1, fromX, fromY, toX, toY, board);
  }
  return -1;
}
