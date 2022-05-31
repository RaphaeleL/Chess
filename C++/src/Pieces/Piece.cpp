#include <list>
#include "Piece.h"

Piece piece;

int Piece::checkKeyList(int size, int allowedKeys[8][2], int side, int fromX, int fromY, int toX, int toY,
                        int board[8][8]) {
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

int Piece::ba(int side, int fromX, int fromY, int toX, int toY, int board[8][8]) {
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

int Piece::bb(int side, int fromX, int fromY, int toX, int toY, int board[8][8]) {
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

int Piece::bc(int side, int fromX, int fromY, int toX, int toY, int board[8][8]) {
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

int Piece::bd(int side, int fromX, int fromY, int toX, int toY, int board[8][8]) {
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

int Piece::ra(int side, int fromX, int fromY, int toX, int toY, int board[8][8]) {
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

int Piece::rb(int side, int fromX, int fromY, int toX, int toY, int board[8][8]) {
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

int Piece::rc(int side, int fromX, int fromY, int toX, int toY, int board[8][8]) {
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

int Piece::rd(int side, int fromX, int fromY, int toX, int toY, int board[8][8]) {
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

int Piece::inBounds(int x, int y) {
    if ((0 <= x) && (x < 8) && (0 <= y) && (y < 8)) {
        return 1;
    }
    return 0;
}

int Piece::checkRook(int side, int fromX, int fromY, int toX, int toY, int board[8][8]) {
    int a = ra(side, fromX, fromY, toX, toY, board);
    int b = rb(side, fromX, fromY, toX, toY, board);
    int c = rc(side, fromX, fromY, toX, toY, board);
    int d = rd(side, fromX, fromY, toX, toY, board);
    return (a || b || c || d);
}

int Piece::checkBishop(int side, int fromX, int fromY, int toX, int toY, int board[8][8]) {
    int a = ba(side, fromX, fromY, toX, toY, board);
    int b = bb(side, fromX, fromY, toX, toY, board);
    int c = bc(side, fromX, fromY, toX, toY, board);
    int d = bd(side, fromX, fromY, toX, toY, board);
    return (a || b || c || d);
}

int Piece::checkKnight(int side, int fromX, int fromY, int toX, int toY, int board[8][8]) {
    int x, y;
    int allowedKeys[8][2] = {{2, 1}, {2, -1}, {-2, -1}, {-2, 1}, {1, 2}, {1, -2}, {-1, -2}, {-1, 2}};
    int size = sizeof(allowedKeys)/sizeof(allowedKeys[0]);
    return checkKeyList(size, allowedKeys, side, fromX, fromY, toX, toY, board);
}

int Piece::checkKing(int side, int fromX, int fromY, int toX, int toY, int board[8][8]) {
    int x, y;
    int allowedKeys[8][2] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}, {1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    int size = sizeof(allowedKeys)/sizeof(allowedKeys[0]);
    return checkKeyList(size, allowedKeys, side, fromX, fromY, toX, toY, board);
}

int Piece::checkQueen(int side, int fromX, int fromY, int toX, int toY, int board[8][8]) {
    int ar = ra(side, fromX, fromY, toX, toY, board);
    int br = rb(side, fromX, fromY, toX, toY, board);
    int cr = rc(side, fromX, fromY, toX, toY, board);
    int dr = rd(side, fromX, fromY, toX, toY, board);
    int ab = ba(side, fromX, fromY, toX, toY, board);
    int bB = bb(side, fromX, fromY, toX, toY, board);
    int cb = bc(side, fromX, fromY, toX, toY, board);
    int db = bd(side, fromX, fromY, toX, toY, board);
    return (ab || bB || cb || db || ar || br || cr || dr);
}

int Piece::checkPawn(int side, int fromX, int fromY, int toX, int toY, int board[8][8]) {
    int x, y;
    int allowedKeys[8][2] = {{1, 0}, {1, 1}, {1, -1}, {}, {},
                             {1, 0}, {1, 0}, {1, 0}};
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

int Piece::check(int fromY, int fromX, int toY, int toX, int board[8][8]) {
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
