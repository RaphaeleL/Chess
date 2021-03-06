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

    public void dearScreen() {
        String banner3 = "      ##  ######  ##     ## ########  ######   ######  \n" +
                "      ## ##    ## ##     ## ##       ##    ## ##    ## \n" +
                "      ## ##       ##     ## ##       ##       ##       \n" +
                "      ## ##       ######### ######    ######   ######  \n" +
                "##    ## ##       ##     ## ##             ##       ## \n" +
                "##    ## ##    ## ##     ## ##       ##    ## ##    ## \n" +
                " ######   ######  ##     ## ########  ######   ###### ";

        System.out.println(banner3);
        System.out.println("==========================================================");
        System.out.println("==========================================================");
    }

    public boolean isFree(Board board, int x, int y, boolean mySide, Piece fromPiece) {
        // 1. field is empty -> true
        if (board.getFigure(x, y).getClass().isInstance(new Empty())) {
            return true;
        }
        // 2. field is not empty, blocked with his figure -> true
        if (fromPiece.getSide() != board.getFigure(x, y).getSide()) {
            return false;
        }
        // 3. field is not empty, blocked with my figure -> false
        if (fromPiece.getSide() == board.getFigure(x, y).getSide()) {
            return true;
        }
        return false;
    }

    public boolean chooseColor() {
        System.out.println("Hint: JChess is still in development, so there might be any issues\n");
        System.out.print("Which color? (W/b) > ");
        String playerInput = scanner.next();
        System.out.println("==========================================================");
        System.out.println("==========================================================");
        return playerInput.toLowerCase().equalsIgnoreCase("w");
    }

    public boolean inBounds(int x, int y) {
        return ((0 <= x && x < 8) && (0 <= y && y < 8));
    }

    private int[] prepare(String movement) {
        String[] move = movement.split("");
        return new int[] {
                this.letterToNumber(move[0]) - 1,
                Integer.parseInt(move[1]) - 1,
                this.letterToNumber(move[2]) - 1,
                Integer.parseInt(move[3]) - 1
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
