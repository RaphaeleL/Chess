class Piece(): 
    def __init__(self):
        pass

class Empty(): 
    def __init__(self, representation):
        self.representation = representation
    
    def __str__(self): 
        return self.representation
