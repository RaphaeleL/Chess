package Pieces;

public class Piece {
    private boolean side;
    private int value;
    private String representation;

    public boolean isSide() {
        return side;
    }

    public void setSide(boolean side) {
        this.side = side;
    }

    public int getValue() {
        return value;
    }

    public void setValue(int value) {
        this.value = value;
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
}
