package Utils;
import Board.Board;
import Pieces.Empty;
import Pieces.Piece;

import java.util.List;
import java.util.Scanner;

public class Movement {
    private Scanner scanner;

    public Movement() {
        this.scanner = new Scanner(System.in);
    }

    public boolean isAllowed(List<int[]> allowedMovements, int [] move) {
        for (int[] movement : allowedMovements) {
            if ((movement[0] == move[2]) && (movement[1] == move[3])) {
                return true;
            }
        }

        return false;
    }

    public boolean isFree(Piece[][] board, int x, int y) {
        return board[x][y].getClass().isInstance(new Empty());
    }

    public boolean inBounds(int x, int y) {
        if ((0 <= x && x <= 8) && (0 <= y && y <= 8)) {
            return true;
        } 
        return false;
    }

    private int[] prepare(String movement) {
        String[] move = movement.split("");
        return new int[]{
                this.letterToNumber(move[0]) - 1,
                Integer.parseInt(move[1]) - 1,
                this.letterToNumber(move[3]) - 1,
                Integer.parseInt(move[4]) - 1
        };
    }

    private int letterToNumber(String letter) {
        char[] ch  = letter.toCharArray();
        for(char c : ch){
            int temp = (int)c;
            int temp_integer = 96;
            if (temp<=122 & temp>=97) {
                return temp-temp_integer;
            }
        }
        return -1;
    }

    private String getInput(Board board) {
        if (board.isCurrentSide()) {
            System.out.print("WHITE [From,To] > ");
        } else {
            System.out.print("BLACK [From|To] > ");
        }
        String playerInput = scanner.next();
        System.out.println();
        return playerInput;
    }


    public void move(Board board) {
        String playerInput = this.getInput(board);
        int[] movement = this.prepare(playerInput);
        board.setField(movement);
        board.printBoard();
    }
}
