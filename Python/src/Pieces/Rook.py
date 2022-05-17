from Pieces.Piece import Piece

class Rook(Piece):
    def __init__(self, side, value, representation):
        self.side = side 
        self.value = value 
        self.representation = representation
    
    def __str__(self): 
        return self.representation

    def checkMove(self, board, move, side):
        return True
