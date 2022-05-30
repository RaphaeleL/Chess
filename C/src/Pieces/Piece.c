#include <stdio.h>
#include "../Board/Board.h"
#include "Piece.h"

int inBounds(int x, int y) {
  if ((0 <= x) && (x < 8) && (0 <= y) && (y < 8)) {
    return 1;
  }
  return 0;
}

int ba(int side, int fromX, int fromY, int toX, int toY, int board[8][8]) {
  int x = fromX - 1; 
  int y = fromY - 1;
  while (inBounds(x, y)) {
    if (side) {
      if (board[x][y] > 0) { 
        break;
      } else if ((board[x][y] > 0) != (board[fromX][fromY] > 0)) {
        if ((toX == x) && (toY == y)) { return 1; }
        break;
      } else if (board[x][y] == 0) {
        if ((toX == x) && (toY == y)) { return 1; }
      }
    } else {
      if (board[x][y] < 0) { 
        break;
      } else if ((board[x][y] < 0) != (board[fromX][fromY] < 0)) {
        if ((toX == x) && (toY == y)) { return 1; }
        break;
      } else if (board[x][y] == 0) {
        if ((toX == x) && (toY == y)) { return 1; }
      }
    }
    x--;
    y--;
  }
  return 0;
}

int bb(int side, int fromX, int fromY, int toX, int toY, int board[8][8]) {
  int x = fromX + 1; 
  int y = fromY + 1;
  while (inBounds(x, y)) {
    if (side) {
      if (board[x][y] > 0) { 
        break;
      } else if ((board[x][y] > 0) != (board[fromX][fromY] > 0)) {
        if ((toX == x) && (toY == y)) { return 1; }
        break;
      } else if (board[x][y] == 0) {
        if ((toX == x) && (toY == y)) { return 1; }
      }
    } else {
      if (board[x][y] < 0) { 
        break;
      } else if ((board[x][y] < 0) != (board[fromX][fromY] < 0)) {
        if ((toX == x) && (toY == y)) { return 1; }
        break;
      } else if (board[x][y] == 0) {
        if ((toX == x) && (toY == y)) { return 1; }
      }
    }
    x++;
    y++;
  }
  return 0;
}

int bc(int side, int fromX, int fromY, int toX, int toY, int board[8][8]) {
  int x = fromX - 1; 
  int y = fromY + 1;
  while (inBounds(x, y)) {
    if (side) {
      if (board[x][y] > 0) { 
        break;
      } else if ((board[x][y] > 0) != (board[fromX][fromY] > 0)) {
        if ((toX == x) && (toY == y)) { return 1; }
        break;
      } else if (board[x][y] == 0) {
        if ((toX == x) && (toY == y)) { return 1; }
      }
    } else {
      if (board[x][y] < 0) { 
        break;
      } else if ((board[x][y] < 0) != (board[fromX][fromY] < 0)) {
        if ((toX == x) && (toY == y)) { return 1; }
        break;
      } else if (board[x][y] == 0) {
        if ((toX == x) && (toY == y)) { return 1; }
      }
    }
    x--;
    y++;
  }
  return 0;
}

int bd(int side, int fromX, int fromY, int toX, int toY, int board[8][8]) {
  int x = fromX + 1; 
  int y = fromY - 1;
  while (inBounds(x, y)) {
    if (side) {
      if (board[x][y] > 0) { 
        break;
      } else if ((board[x][y] > 0) != (board[fromX][fromY] > 0)) {
        if ((toX == x) && (toY == y)) { return 1; }
        break;
      } else if (board[x][y] == 0) {
        if ((toX == x) && (toY == y)) { return 1; }
      }
    } else {
      if (board[x][y] < 0) { 
        break;
      } else if ((board[x][y] < 0) != (board[fromX][fromY] < 0)) {
        if ((toX == x) && (toY == y)) { return 1; }
        break;
      } else if (board[x][y] == 0) {
        if ((toX == x) && (toY == y)) { return 1; }
      }
    }
    x++;
    y--;
  }
  return 0;
}

int ra(int side, int fromX, int fromY, int toX, int toY, int board[8][8]) {
  int x = fromX - 1; 
  int y = fromY;
  while (inBounds(x, y)) {
    if (side) {
      if (board[x][y] > 0) { 
        break;
      } else if ((board[x][y] > 0) != (board[fromX][fromY] > 0)) {
        if ((toX == x) && (toY == y)) { return 1; }
        break;
      } else if (board[x][y] == 0) {
        if ((toX == x) && (toY == y)) { return 1; }
      }
    } else {
      if (board[x][y] < 0) { 
        break;
      } else if ((board[x][y] < 0) != (board[fromX][fromY] < 0)) {
        if ((toX == x) && (toY == y)) { return 1; }
        break;
      } else if (board[x][y] == 0) {
        if ((toX == x) && (toY == y)) { return 1; }
      }
    }
    x--;
  }
  return 0;
}

int rb(int side, int fromX, int fromY, int toX, int toY, int board[8][8]) {
  int x = fromX + 1; 
  int y = fromY;
  while (inBounds(x, y)) {
    if (side) {
      if (board[x][y] > 0) { 
        break;
      } else if ((board[x][y] > 0) != (board[fromX][fromY] > 0)) {
        if ((toX == x) && (toY == y)) { return 1; }
        break;
      } else if (board[x][y] == 0) {
        if ((toX == x) && (toY == y)) { return 1; }
      }
    } else {
      if (board[x][y] < 0) { 
        break;
      } else if ((board[x][y] < 0) != (board[fromX][fromY] < 0)) {
        if ((toX == x) && (toY == y)) { return 1; }
        break;
      } else if (board[x][y] == 0) {
        if ((toX == x) && (toY == y)) { return 1; }
      }
    }
    x++;
  }
  return 0;
}

int rc(int side, int fromX, int fromY, int toX, int toY, int board[8][8]) {
  int x = fromX; 
  int y = fromY + 1;
  while (inBounds(x, y)) {
    if (side) {
      if (board[x][y] > 0) { 
        break;
      } else if ((board[x][y] > 0) != (board[fromX][fromY] > 0)) {
        if ((toX == x) && (toY == y)) { return 1; }
        break;
      } else if (board[x][y] == 0) {
        if ((toX == x) && (toY == y)) { return 1; }
      }
    } else {
      if (board[x][y] < 0) { 
        break;
      } else if ((board[x][y] < 0) != (board[fromX][fromY] < 0)) {
        if ((toX == x) && (toY == y)) { return 1; }
        break;
      } else if (board[x][y] == 0) {
        if ((toX == x) && (toY == y)) { return 1; }
      }
    }
    y++;
  }
  return 0;
}

int rd(int side, int fromX, int fromY, int toX, int toY, int board[8][8]) {
  int x = fromX; 
  int y = fromY - 1;
  while (inBounds(x, y)) {
    if (side) {
      if (board[x][y] > 0) { 
        break;
      } else if ((board[x][y] > 0) != (board[fromX][fromY] > 0)) {
        if ((toX == x) && (toY == y)) { return 1; }
        break;
      } else if (board[x][y] == 0) {
        if ((toX == x) && (toY == y)) { return 1; }
      }
    } else {
      if (board[x][y] < 0) { 
        break;
      } else if ((board[x][y] < 0) != (board[fromX][fromY] < 0)) {
        if ((toX == x) && (toY == y)) { return 1; }
        break;
      } else if (board[x][y] == 0) {
        if ((toX == x) && (toY == y)) { return 1; }
      }
    }
    y--;
  }
  return 0;
}

int checkRook(int side, int fromX, int fromY, int toX, int toY, int board[8][8]) {
  int a = ra(side, fromX, fromY, toX, toY, board);
  int b = rb(side, fromX, fromY, toX, toY, board);
  int c = rc(side, fromX, fromY, toX, toY, board);
  int d = rd(side, fromX, fromY, toX, toY, board);
  return (a || b || c || d);
}

int checkQueen(int side, int fromX, int fromY, int toX, int toY, int board[8][8]) {
  return 0;
}

int checkBishop(int side, int fromX, int fromY, int toX, int toY, int board[8][8]) {
  int a = ba(side, fromX, fromY, toX, toY, board);
  int b = bb(side, fromX, fromY, toX, toY, board);
  int c = bc(side, fromX, fromY, toX, toY, board);
  int d = bd(side, fromX, fromY, toX, toY, board);
  return (a || b || c || d);
}

int checkKeyList(int size, int allowedKeys[cap][2], int side, int fromX, int fromY, int toX, int toY, int board[8][8]) {
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

int checkKing(int side, int fromX, int fromY, int toX, int toY, int board[8][8]) {
  int x, y;
  cap = 8;
  int allowedKeys[8][2] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}, {1, 0}, {-1, 0}, {0, -1}, {0, 1}};
  int size = sizeof(allowedKeys)/sizeof(allowedKeys[0]);
  return checkKeyList(size, allowedKeys, side, fromX, fromY, toX, toY, board);
}

int checkKnight(int side, int fromX, int fromY, int toX, int toY, int board[8][8]) {
  int x, y;
  cap = 8;
  int allowedKeys[8][2] = {{2, 1}, {2, -1}, {-2, -1}, {-2, 1}, {1, 2}, {1, -2}, {-1, -2}, {-1, 2}};
  int size = sizeof(allowedKeys)/sizeof(allowedKeys[0]);
  return checkKeyList(size, allowedKeys, side, fromX, fromY, toX, toY, board);
}

int checkPawn(int side, int fromX, int fromY, int toX, int toY, int board[8][8]) {
  int x, y;
  cap = 3;
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
