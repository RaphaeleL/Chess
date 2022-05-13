package Utils;
import Board.Board;
import Pieces.Empty;

import java.util.Scanner;

public class Movement {
    private Scanner scanner;

    public Movement() {
        this.scanner = new Scanner(System.in);
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
