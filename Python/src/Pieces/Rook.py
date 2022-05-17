from Pieces.Piece import Piece, Empty
from Utils.Movement import Movement

class Rook(Piece):
    def __init__(self, side, value, representation):
        self.side = side 
        self.value = value 
        self.representation = representation
    
    def __str__(self): 
        return self.representation

    def getAllRookMovesA(self, move): 
        movement = Movement()
        allMovements = []
        while (movement.inBounds(move[0], move[1])):
            move[0] -= 1 
            if not [move[0], move[1]] in allMovements: 
                allMovements.append([move[0], move[1]])
        return allMovements

    def getAllRookMovesB(self, move): 
        movement = Movement()
        allMovements = []
        while (movement.inBounds(move[0], move[1])):
            move[0] += 1 
            if not [move[0], move[1]] in allMovements: 
                allMovements.append([move[0], move[1]])
        return allMovements

    def getAllRookMovesC(self, move): 
        movement = Movement()
        allMovements = []
        while (movement.inBounds(move[0], move[1])):
            move[1] -= 1 
            if not [move[0], move[1]] in allMovements: 
                allMovements.append([move[0], move[1]])
        return allMovements

    def getAllRookMovesD(self, move): 
        movement = Movement()
        allMovements = []
        while (movement.inBounds(move[0], move[1])):
            move[1] += 1 
            if not [move[0], move[1]] in allMovements: 
                allMovements.append([move[0], move[1]])
        return allMovements

    def checkMove(self, board, move, side):
        movementUtil = Movement()
        allowedMovements = []
        allMovements = [self.getAllRookMovesA(move), self.getAllRookMovesB(move), 
            self.getAllRookMovesC(move), self.getAllRookMovesD(move)]
        for ints in allMovements: 
            for movement in ints: 
                x = movement[0]
                y = movement[1]
                if movementUtil.inBounds(x, y): 
                    if type(board.getFigure(x, y)) is Empty("o").__class__:
                        if movementUtil.isFree(board, x, y, side, board.getFigure(move[0], move[1])):
                            allowedMovements.append([x, y])
                    else: 
                        if board.getFigure(x, y).side != board.getFigure(move[0], move[1]).side: 
                            allowedMovements.append([x, y])
                        break
        return movementUtil.isAllowed(allowedMovements, move)
