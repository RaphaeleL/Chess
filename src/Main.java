import Board.Board;
import Utils.*;

public class Main {
    public static void main(String[] args) {
        Movement movement = new Movement();
        movement.dearScreen();

        Board board = new Board();

        while (!board.isWinner()) {
            movement.move(board);
            board.setCurrentSide(!board.isCurrentSide());
        }

    }
}