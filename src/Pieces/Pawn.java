package Pieces;

public class Pawn extends Piece{
    private boolean side;
    private int value;
    private String representation;

    public Pawn(boolean side, int value, String representation) {
        super(side, value, representation);
    }

}
