package Pieces;

import Board.Board;
import Utils.Movement;

import java.util.ArrayList;
import java.util.List;

public class Queen extends Piece {

    public Queen(boolean side, int value, String representation) {
        super(side, value, representation);
    }

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

    private List<int[]> getAllBishopMovesA(int[] move) {
        Movement movementUtil = new Movement();
        List<int[]> allMovements = new ArrayList<>();
        int x = move[0];
        int y = move[1];
        while (movementUtil.inBounds(x, y)) {
            x--;
            y--;
            if (!allMovements.contains(new int[] {x, y})) { allMovements.add(new int[] {x, y}); }
        }
        return allMovements;
    }

    private List<int[]> getAllBishopMovesB(int[] move) {
        Movement movementUtil = new Movement();
        List<int[]> allMovements = new ArrayList<>();
        int x = move[0];
        int y = move[1];
        while (movementUtil.inBounds(x, y)) {
            x++;
            y++;
            if (!allMovements.contains(new int[] {x, y})) { allMovements.add(new int[] {x, y}); }
        }
        return allMovements;
    }

    private List<int[]> getAllBishopMovesC(int[] move) {
        Movement movementUtil = new Movement();
        List<int[]> allMovements = new ArrayList<>();
        int x = move[0];
        int y = move[1];
        while (movementUtil.inBounds(x, y)) {
            x++;
            y--;
            if (!allMovements.contains(new int[] {x, y})) { allMovements.add(new int[] {x, y}); }
        }
        return allMovements;
    }

    private List<int[]> getAllBishopMovesD(int[] move) {
        Movement movementUtil = new Movement();
        List<int[]> allMovements = new ArrayList<>();
        int x = move[0];
        int y = move[1];
        while (movementUtil.inBounds(x, y)) {
            x--;
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

        List<List<int[]>> allMovements = new ArrayList<>(8);
        allMovements.add(0, getAllRookMovesA(move));
        allMovements.add(1, getAllRookMovesB(move));
        allMovements.add(2, getAllRookMovesC(move));
        allMovements.add(3, getAllRookMovesD(move));
        allMovements.add(4, getAllBishopMovesA(move));
        allMovements.add(5, getAllBishopMovesB(move));
        allMovements.add(6, getAllBishopMovesC(move));
        allMovements.add(7, getAllBishopMovesD(move));

        for (List<int[]> ints : allMovements) {
            for (int[] movement : ints) {
                x = movement[0];
                y = movement[1];
                if (movementUtil.inBounds(x, y)) {
                    if (board.getFigure(x, y).getClass().isInstance(new Empty())) {
                        allowedMovements.add(new int[] {x, y});
                    } else {
                        if (board.getFigure(x, y).getSide() != board.getFigure(move[0], move[1]).getSide()) {
                            allowedMovements.add(new int[] {x, y});
                        }
                        break;
                    }
                }
            }
        }

        return movementUtil.isAllowed(allowedMovements, move);
    }

}
