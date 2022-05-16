from Pieces.Piece import Empty
from Pieces.King import King
from Pieces.Knight import Knight
from Pieces.Bishop import Bishop
from Pieces.Pawn import Pawn
from Pieces.Piece import Empty
from Pieces.Queen import Queen
from Pieces.Rook import Rook

class Board():
    def __init__(self, color):
        self.currentColor = color
        self.board = [[], [], [], [], [], [], [], []]
        self.fillBoard()
        self.printBoard()

    def fillBoard(self):
        self.board[0].append(Rook(True, 5, "R"))
        self.board[0].append(Knight(True, 3, "K"))
        self.board[0].append(Bishop(True, 3, "B"))
        self.board[0].append(Queen(True, 9, "Q"))
        self.board[0].append(King(True, 0, "X"))
        self.board[0].append(Bishop(True, 3, "B"))
        self.board[0].append(Knight(True, 3, "K"))
        self.board[0].append(Rook(True, 5, "R"))
        for _ in range(8):
            self.board[1].append(Pawn(True, 1, "P"))
            for i in range(2, 6):
                self.board[i].append(Empty("o"))
            self.board[6].append(Pawn(False, 1, "p"))
        self.board[7].append(Rook(False, 5, "r"))
        self.board[7].append(Knight(False, 3, "k"))
        self.board[7].append(Bishop(False, 3, "b"))
        self.board[7].append(King(False, 0, "x"))
        self.board[7].append(Queen(False, 9, "q"))
        self.board[7].append(Bishop(False, 3, "b"))
        self.board[7].append(Knight(False, 3, "k"))
        self.board[7].append(Rook(False, 5, "r"))

    def printBoard(self):
        for tmp in self.board:
            for piece in tmp:
                print(str(piece) + "\t", end="")
            print()
            