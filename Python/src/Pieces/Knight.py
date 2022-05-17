from Pieces.Piece import Piece, Empty
from Utils.Movement import Movement

class Knight(Piece):
    def __init__(self, side, value, representation):
        self.side = side 
        self.value = value 
        self.representation = representation
    
    def __str__(self): 
        return self.representation

    def checkMove(self, board, move, side):
        movementUtil = Movement()
        allowedMovements = []
        allowedKeys = [[2, 1], [2, -1], [-2, 1], [-2, -1], [1, -2], [1, 2], [-1, -2], [-1, 2]]
        for allowedKey in allowedKeys:
            x = move[0] - allowedKey[0]
            y = move[1] - allowedKey[1]
            if movementUtil.inBounds(x, y):
                print(type(board.getFigure(x, y)), Empty("o").__class__, type(board.getFigure(x, y)) is Empty("o").__class__)
                
                if type(board.getFigure(x, y)) is Empty("o").__class__:
                    if movementUtil.isFree(board, x, y, side, board.getFigure(move[0], move[1])):
                        allowedMovements.append([x, y])
                else: 
                    if board.getFigure(x, y).side != board.getFigure(move[0], move[1]).side: 
                        allowedMovements.append([x, y])
                    break
        return movementUtil.isAllowed(allowedMovements, move)