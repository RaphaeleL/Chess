package Pieces;

import Board.Board;
import Utils.Movement;

import java.util.ArrayList;
import java.util.List;

public class Knight extends Piece {

    public Knight(boolean side, int value, String representation) {
        super(side, value, representation);
    }

    @Override
    public boolean checkMove(Board board, int[] move, boolean side) {
        Movement movementUtil = new Movement();
        List<int[]> allowedMovements = new ArrayList<>();
        int[][] allowedKeys = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, -2}, {1, 2}, {-1, -2}, {-1, 2}};
        int x, y;
        for (int[] allowedKey : allowedKeys) {
            x = move[0] - allowedKey[0];
            y = move[1] - allowedKey[1];
            if (movementUtil.inBounds(x, y)) {
                if (!movementUtil.isFree(board, x, y, side)) {
                    allowedMovements.add(new int[] { x, y});
                }
            }
        }
        return movementUtil.isAllowed(allowedMovements, move);
    }

}
