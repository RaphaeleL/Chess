package Board;
import Pieces.*;

import java.util.Locale;

public class Board {
    private Piece board[][] = new Piece[8][8];
    private boolean winner = false;
    private boolean currentSide = false;

    public Board() {
        this.fillBoard();
        this.printBoard();
    }

    public boolean isWinner() {
        return winner;
    }

    public void setWinner(boolean winner) {
        this.winner = winner;
    }

    public boolean isCurrentSide() {
        return currentSide;
    }

    public void setCurrentSide(boolean currentSide) {
        this.currentSide = currentSide;
    }

    public Piece[][] getBoard() {
        return board;
    }

    public void setBoard(Piece[][] board) {
        this.board = board;
    }

    public void setField(int [] move) {
        int x1, y1;
        int x2 = move[3];
        int y2 = move[2];

        if (!this.currentSide) {
            x1 = move[0];
            y1 = move[1];
        } else {
            x1 = move[1];
            y1 = move[0];
        }

        Piece toMove = this.board[x1][y1];
        this.board[x1][y1] = new Empty();
        this.board[x2][y2] = toMove;

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
        System.out.println("Black");
        for (Piece x[] : this.board) {
            for (Piece y : x) {
                System.out.print(y.getRepresentation() + "  ");
            }
            System.out.println();
        }
        System.out.println("White");
    }
}
