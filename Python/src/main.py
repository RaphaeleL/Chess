from Pieces.Pawn import Pawn
from Board.Board import Board
from Utils.Movement import  Movement

if __name__ == "__main__":
    movement = Movement()
    movement.dearScreen()

    board = Board(True)

    while not board.isWinner():
        movement.move(board)
        board.currentSide = not board.currentSide
        board.checkWinner()

    board.handleWinner()


