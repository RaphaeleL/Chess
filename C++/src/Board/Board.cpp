#include "Board.h"
#include "../Pieces/Piece.h"

Board::Board() {

}

char Board::getRepresentation(int figure) {
    char repr = 'o';
    if (figure == 1) {
        repr = 'R';
    } else if (figure == 2) {
        repr = 'K';
    } else if (figure == 3) {
        repr = 'B';
    } else if (figure == 4) {
        repr = 'Q';
    } else if (figure == 5) {
        repr = 'X';
    } else if (figure == 6) {
        repr = 'P';
    } else if (figure == -1) {
        repr = 'r';
    } else if (figure == -2) {
        repr = 'k';
    } else if (figure == -3) {
        repr = 'b';
    } else if (figure == -4) {
        repr = 'q';
    } else if (figure == -5) {
        repr = 'x';
    } else if (figure == -6) {
        repr = 'p';
    } else if (figure == -9) {
        repr = '+';
    }
    return repr;
}

void Board::makeMove(int fromX, int fromY, int toX, int toY) {
    Piece piece;
    if (piece.check(fromX, fromY, toX, toY, board)) {
        int fromPiece = board[fromY][fromX];
        board[fromY][fromX] = 0;
        board[toY][toX] = fromPiece;
    }
}

void Board::fillBoard() {
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

void Board::printBoard() {

    printf("+-------------+\n");
    printf("| Black       |\n");
    printf("+-------------+\n");
    printf("\na1                    h1\n");
    printf("   +-----------------+\n");
    for (int i = 0; i < MAX_SIZE; i++) {
        printf("   | ");
        for (int j = 0; j < MAX_SIZE; j++) {
            //printf("(%d-%d) \t", i, j);
            printf("%c ", getRepresentation(board[i][j]));
        }
        printf("|");
        if (i != MAX_SIZE-1) {
            printf("\n");
        }
    }
    printf("\n   +-----------------+\n");
    printf("a8                    h8\n");
    printf("\t\t\t+-------------+\n");
    printf("\t\t\t| White       |\n");
    printf("\t\t\t+-------------+\n");
}