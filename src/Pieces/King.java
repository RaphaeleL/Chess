package Pieces;

import Board.Board;
import Utils.Movement;

import java.util.ArrayList;
import java.util.List;

public class King extends Piece {

    public King(boolean side, String representation) {
        super(side, representation);
    }

    @Override
    public boolean checkMove(Board board, int[] move, boolean side) {
        Movement movementUtil = new Movement();
        List<int[]> allowedMovements = new ArrayList<>();
        int[][] allowedKeys = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}, {1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        int x, y;
        for (int[] allowedKey : allowedKeys) {
            x = move[0] - allowedKey[0];
            y = move[1] - allowedKey[1];
            if (movementUtil.inBounds(x, y)) {
                if (movementUtil.isFree(board, x, y, side, board.getFigure(move[0], move[1]))) {
                    allowedMovements.add(new int[] {x, y});
                }
            }
        }
        // TODO castling: d8d6
        // 1. rook never moved
        // 2. king never moved
        // 3. after castling there is no instant check
        // 4. no figures between king and rook
        return movementUtil.isAllowed(allowedMovements, move);
    }

}
