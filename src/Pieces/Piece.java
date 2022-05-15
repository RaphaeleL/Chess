package Pieces;
import Board.Board;

public class Piece {
    private boolean side;
    private int value;
    private String representation;

    public boolean getSide() {
        return side;
    }

    public int getValue() {
        return value;
    }

    public String getRepresentation() {
        return representation;
    }

    public void setRepresentation(String representation) {
        this.representation = representation;
    }

    public Piece(String representation) {
        this.representation = representation;
    }

    public Piece(boolean side, String representation) {
        this.side = side;
        this.representation = representation;
    }

    public Piece(boolean side, int value, String representation) {
        this.side = side;
        this.value = value;
        this.representation = representation;
    }

    public boolean checkMove(Board board, int [] move, boolean side) {
        return false;
    }
}
