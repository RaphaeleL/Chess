package Pieces;

import Board.Board;
import Utils.Movement;
import java.util.ArrayList;
import java.util.List;

public class Rook extends Piece {

    public Rook(boolean side, int value, String representation) { super(side, value, representation); }

    private List<int[]> getAllRookMovesA(int[] move) {
        Movement movementUtil = new Movement();
        List<int[]> allMovements = new ArrayList<>();
        int x = move[0];
        int y = move[1];
        while (movementUtil.inBounds(x, y)) {
            x--;
            if (!allMovements.contains(new int[] {x, y})) { allMovements.add(new int[] {x, y}); }
        }
        return allMovements;
    }

    private List<int[]> getAllRookMovesB(int[] move) {
        Movement movementUtil = new Movement();
        List<int[]> allMovements = new ArrayList<>();
        int x = move[0];
        int y = move[1];
        while (movementUtil.inBounds(x, y)) {
            x++;
            if (!allMovements.contains(new int[] {x, y})) { allMovements.add(new int[] {x, y}); }
        }
        return allMovements;
    }
    private List<int[]> getAllRookMovesC(int[] move) {
        Movement movementUtil = new Movement();
        List<int[]> allMovements = new ArrayList<>();
        int x = move[0];
        int y = move[1];
        while (movementUtil.inBounds(x, y)) {
            y--;
            if (!allMovements.contains(new int[] {x, y})) { allMovements.add(new int[] {x, y}); }
        }
        return allMovements;
    }

    private List<int[]> getAllRookMovesD(int[] move) {
        Movement movementUtil = new Movement();
        List<int[]> allMovements = new ArrayList<>();
        int x = move[0];
        int y = move[1];
        while (movementUtil.inBounds(x, y)) {
            y++;
            if (!allMovements.contains(new int[] {x, y})) { allMovements.add(new int[] {x, y}); }
        }
        return allMovements;
    }

    @Override
    public boolean checkMove(Board board, int[] move, boolean side) {
        Movement movementUtil = new Movement();
        List<int[]> allowedMovements = new ArrayList<>();
        int x, y;

        List<List<int[]>> foo = new ArrayList<>(4);
        foo.add(0, getAllRookMovesA(move));
        foo.add(1, getAllRookMovesB(move));
        foo.add(2, getAllRookMovesC(move));
        foo.add(3, getAllRookMovesD(move));

        for (List<int[]> ints : foo) {
            for (int[] movement : ints) {
                x = movement[0];
                y = movement[1];
                if (movementUtil.inBounds(x, y)) {
                    System.out.println("(" + x + "," + y + ") " + board.getFigure(x, y).getClass());
                    if (board.getFigure(x, y).getClass().isInstance(new Empty())) {
                        allowedMovements.add(new int[] {x, y});
                    } else {
                        break;
                    }
                }
            }
        }

        return movementUtil.isAllowed(allowedMovements, move);
    }

}


