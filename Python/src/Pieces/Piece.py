class Piece(): 
    def __init__(self, side, value, representation):
        self.side = side
        self.value = value
        self.representation = representation

class Empty(): 
    def __init__(self, representation):
        self.representation = representation
    
    def __str__(self): 
        return self.representation

    def checkMove(self, board, move, side):
        return False