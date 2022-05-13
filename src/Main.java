import Board.Board;
import Utils.*;

public class Main {
    public static void main(String[] args) {
        Board board = new Board();
        Movement movement = new Movement();

        while (!board.isWinner()) {
            movement.move(board);
            board.setCurrentSide(!board.isCurrentSide());
        }

    }
}