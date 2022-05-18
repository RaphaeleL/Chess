package main

import (
  B "src/Board"
	M "src/Utils"
)

func main() {
	M.DearScreen()
	side := M.ChooseColor()
	board := B.FillBoard()
	B.PrintBoard(board)
	for B.HasWinner() {
		board = M.Move(board, side)
		B.PrintBoard(board)
		if B.Success {
			side = !side
		}
		B.CheckWinner()
	}
	B.HandleWinner()
}
