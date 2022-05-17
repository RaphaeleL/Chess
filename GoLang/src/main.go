package main

import (
	B "./Board"
	M "./Utils"
)

func main() {
	M.DearScreen()
	side := M.ChooseColor()
	board := B.FillBoard()
	B.PrintBoard(board)
	for B.HasWinner() {
		board = M.Move(board, side)
		B.PrintBoard(board)
		side = !side
		B.CheckWinner()
	}
	B.HandleWinner()
}
