package Pieces;
import Utils.Movement;

import java.util.*;

public class Pawn extends Piece {

    public Pawn(boolean side, int value, String representation) {
        super(side, value, representation);
    }

    @Override
    public boolean checkMove(Piece[][] board, int [] move, boolean side) {
        // TODO: en passent
        Movement movementUtil = new Movement();
        List<int[]> allowedMovements = new ArrayList<>();
        int[][] allowedKeys = {{1, 0}, {1, 1}, {1, -1}};
        int baseline = side ? 6 : 1;
        int x, y;
        for (int[] allowedKey : allowedKeys) {
            if (move[0] == baseline) {
                allowedMovements.add(new int[] { side ? move[0] - 2 : move[0] + 2, move[1]});
            }
            x = side ? move[0] - allowedKey[0] : move[0] - allowedKey[0];
            y = side ? move[1] - allowedKey[1] : move[1] - allowedKey[1];
            if (movementUtil.inBounds(x, y) && !movementUtil.isFree(board, x, y)) {
              allowedMovements.add(new int[] { x, y});
            }
        }
        return movementUtil.isAllowed(allowedMovements, move);
    }

}
