package Pieces;
import Board.Board;
import Utils.Movement;

import java.util.*;

public class Pawn extends Piece {

    public Pawn(boolean side, int value, String representation) {
        super(side, value, representation);
    }

    @Override
    public boolean checkMove(Board board, int [] move, boolean side) {
        Movement movementUtil = new Movement();
        List<int[]> allowedMovements = new ArrayList<>();
        int[][] allowedKeys = {{1, 0}, {1, 1}, {1, -1}};
        int baseline = side ? 6 : 1;
        int x, y;
        for (int[] allowedKey : allowedKeys) {
            if (move[0] == baseline) {
                allowedMovements.add(new int[] { side ? move[0] - 2 : move[0] + 2, move[1]});
            }
            x = side ? move[0] - allowedKey[0] : move[0] + allowedKey[0];
            y = side ? move[1] - allowedKey[1] : move[1] + allowedKey[1];
            if (movementUtil.inBounds(x, y)) {
                if (move[1] != y) {
                    if (!movementUtil.isFree(board, x, y, side, board.getFigure(move[0], move[1]))) {
                        allowedMovements.add(new int[] {x, y});
                    }
                } else {
                    allowedMovements.add(new int[] {x, y});
                }
            }
        }
        // TODO: en passent
        // 1. pawn made 2 steps
        // 2. pawn stands next to another pawn
        // 3. the enemy pawn makes a step behind the pawn and eats him
        return movementUtil.isAllowed(allowedMovements, move);
    }

}
