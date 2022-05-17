package main

import B "./Board"
import M "./Utils"

func main() {
	b := B.Board{}
	m := M.Movement{}
	m.DearScreen()
	x := b.FillBoard(false, m.ChooseColor())
	b.PrintBoard(x)

	for !b.Winner {
		m.Move(x)
		b.CurrentSide = !b.CurrentSide
		b.CheckWinner()
	}

	b.HandleWinner()

}
