#include <stdio.h>

int checkRook(int side) {
  return 0;
}

int checkQueen(int side) {
  return 0;
}

int checkKing(int side) {
  return 0;
}

int checkKnight(int side) {
  return 0;
}

int checkBishop(int side) {
  return 0;
}

int checkPawn(int side) {
  return 0;
}

int check(int fromY, int fromX, int toY, int toX, int board[8][8]) {
  int fromPiece = board[fromX][fromY];
  if (fromPiece == 1) {
    checkRook(0);
  } else if (fromPiece == 2) {
    checkKnight(0);
  } else if (fromPiece == 3) {
    checkBishop(0);
  } else if (fromPiece == 4) {
    checkQueen(0);
  } else if (fromPiece == 5) {
    checkKing(0);
  } else if (fromPiece == 6) {
    checkPawn(0);
  } else if (fromPiece == -1) {
    checkRook(1);
  } else if (fromPiece == -2) {
    checkKnight(1);
  } else if (fromPiece == -3) {
    checkBishop(1);
  } else if (fromPiece == -4) {
    checkQueen(1);
  } else if (fromPiece == -5) {
    checkKing(1);
  } else if (fromPiece == -6) {
    checkPawn(1);
  }
  return 0;
}
