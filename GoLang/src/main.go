package main

import B "./Board"
import M "./Utils"

func main() {
	b := B.Board{}
	m := M.Movement{}
	m.DearScreen()
	b.FillBoard()
	b.PrintBoard()
}
