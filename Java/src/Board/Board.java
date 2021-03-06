package Board;
import Pieces.*;

import java.util.ArrayList;
import java.util.List;

public class Board {
    private final Piece[][] board = new Piece[8][8];
    private boolean winner = false;
    private boolean winnerSide;
    private boolean currentSide; // true = white

    public Board(boolean color) {
        this.currentSide = color;
        this.fillBoard();
        this.printBoard();
    }

    public Piece getFigure(int x, int y) {
        return this.board[x][y];
    }
    public void setFigure(int x, int y, Piece figure) {
        this.board[x][y] = figure;
    }

    public boolean isWinner() {
        return winner;
    }

    public void setWinner(boolean winner) {
        this.winner = winner;
    }

    public void checkWinner() {
        int blackCount = 0;
        int whiteCount = 0;
        for (Piece[] tmp : this.board) {
            for (Piece piece : tmp) {
                if (!piece.getClass().isInstance(new Empty())) {
                    if (piece.getSide()) {
                        whiteCount++;
                    } else {
                        blackCount++;
                    }
                }
            }
        }
        if (blackCount == 0) {
            this.setWinner(true);
            this.winnerSide = false;
        } else if (whiteCount == 0) {
            this.setWinner(true);
            this.winnerSide = true;
        }
    }

    public void handleWinner() {
        System.out.println("==========================================================");
        System.out.println("==========================================================");
        if (this.winnerSide) {
            System.out.println("White won.");
        } else if (!this.winnerSide) {
            System.out.println("Black won.");
        }
        System.out.println("==========================================================");
        System.out.println("==========================================================");
    }

    public boolean isCurrentSide() {
        return currentSide;
    }

    public void setCurrentSide(boolean currentSide) {
        this.currentSide = currentSide;
    }

    public void setField(int [] move) {
        Piece toMove = this.getFigure(move[1], move[0]);
        if (toMove.checkMove(this, new int [] {move[1], move[0], move[3], move[2]}, this.currentSide)) {
            this.setFigure(move[1], move[0], new Empty());
            this.setFigure(move[3], move[2], toMove);
        } else {
            System.out.println("Move is not allowed. Try again!\n".toUpperCase());
            this.setCurrentSide(!this.isCurrentSide());
        }
    }

    public void fillBoard() {
        // Black
        this.board[0][0] = new Rook(true, 5, "R");
        this.board[0][7] = new Rook(true, 5, "R");
        this.board[0][1] = new Knight(true, 3, "K");
        this.board[0][6] = new Knight(true, 3, "K");
        this.board[0][2] = new Bishop(true, 3, "B");
        this.board[0][5] = new Bishop(true, 3, "B");
        this.board[0][3] = new Queen(true, 9, "Q");
        this.board[0][4] = new King(true, "X");

        // Pawns
        for (int i = 0; i < 8; i++) {
            this.board[1][i] = new Pawn(true, 1, "P");
            this.board[6][i] = new Pawn(false, 1, "p");
        }

        // Empty Fields
        for (int i = 0; i < 8; i++) {
            this.board[2][i] = new Empty();
            this.board[3][i] = new Empty();
            this.board[4][i] = new Empty();
            this.board[5][i] = new Empty();
        }

        // White
        this.board[7][0] = new Rook(false, 5, "r");
        this.board[7][7] = new Rook(false, 5, "r");
        this.board[7][1] = new Knight(false, 3, "k");
        this.board[7][6] = new Knight(false, 3, "k");
        this.board[7][2] = new Bishop(false, 3, "b");
        this.board[7][5] = new Bishop(false, 3, "b");
        this.board[7][4] = new Queen(false, 9, "q");
        this.board[7][3] = new King(false, "x");
    }

    public void printBoard() {
        System.out.println("+-------------+");
        System.out.println("| Black       |");
        System.out.println("+-------------+");
        System.out.println("\na1                              h1");
        System.out.println("   +--------------------------+");
        for (Piece[] x : this.board) {
            System.out.print("   |  ");
            for (Piece y : x) {
                System.out.print(y.getRepresentation() + "  ");
            }
            System.out.print("| ");
            System.out.println();
        }
        System.out.println("   +--------------------------+");
        System.out.println("a8                              h8\n");
        System.out.println("\t\t\t\t\t+-------------+");
        System.out.println("\t\t\t\t\t| White       |");
        System.out.println("\t\t\t\t\t+-------------+\n");
    }
}
