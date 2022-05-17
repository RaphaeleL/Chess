package Board

import (
	"fmt"
	"strings"
)
import P "../Pieces"

type Board struct {
	MyBoard     [8][8]P.Piece
	Winner      bool
	CurrentSide bool
}

func (Board) FillBoard(winner bool, currentSide bool) Board {
	x := Board{
		[8][8]P.Piece{
			{
				{true, 5, "R", false},
				{true, 3, "K", false},
				{true, 3, "B", false},
				{true, 9, "Q", false},
				{true, 0, "X", false},
				{true, 3, "B", false},
				{true, 3, "K", false},
				{true, 5, "R", false},
			},
			{
				{true, 1, "P", false},
				{true, 1, "P", false},
				{true, 1, "P", false},
				{true, 1, "P", false},
				{true, 1, "P", false},
				{true, 1, "P", false},
				{true, 1, "P", false},
				{true, 1, "P", false},
			},
			{
				{true, -1, "o", true},
				{true, -1, "o", true},
				{true, -1, "o", true},
				{true, -1, "o", true},
				{true, -1, "o", true},
				{true, -1, "o", true},
				{true, -1, "o", true},
				{true, -1, "o", true},
			},
			{
				{true, -1, "o", true},
				{true, -1, "o", true},
				{true, -1, "o", true},
				{true, -1, "o", true},
				{true, -1, "o", true},
				{true, -1, "o", true},
				{true, -1, "o", true},
				{true, -1, "o", true},
			},
			{
				{true, -1, "o", true},
				{true, -1, "o", true},
				{true, -1, "o", true},
				{true, -1, "o", true},
				{true, -1, "o", true},
				{true, -1, "o", true},
				{true, -1, "o", true},
				{true, -1, "o", true},
			},
			{
				{true, -1, "o", true},
				{true, -1, "o", true},
				{true, -1, "o", true},
				{true, -1, "o", true},
				{true, -1, "o", true},
				{true, -1, "o", true},
				{true, -1, "o", true},
				{true, -1, "o", true},
			},
			{
				{true, 1, "p", false},
				{true, 1, "p", false},
				{true, 1, "p", false},
				{true, 1, "p", false},
				{true, 1, "p", false},
				{true, 1, "p", false},
				{true, 1, "p", false},
				{true, 1, "p", false},
			},
			{
				{true, 5, "r", false},
				{true, 3, "k", false},
				{true, 3, "b", false},
				{true, 0, "x", false},
				{true, 9, "q", false},
				{true, 3, "b", false},
				{true, 3, "k", false},
				{true, 5, "r", false},
			},
		},
		winner,
		currentSide,
	}
	return x
}

func (Board) PrintBoard(b Board) {
	fmt.Println("Black")
	var i, j = 0, 0
	for ; i < 8; i++ {
		for j = 0; j < 8; j++ {
			fmt.Print(b.MyBoard[i][j].Representation + "  ")
		}
		fmt.Println()
	}
	fmt.Println("White")
}

func (Board) SetField(move []int, b Board) Board {
	toMove := b.MyBoard[move[1]][move[0]]
	if toMove.CheckMovements(toMove.Representation) {
		b.MyBoard[move[1]][move[0]] = P.Piece{true, -1, "o", true}
		b.MyBoard[move[3]][move[2]] = toMove
	} else {
		fmt.Println(strings.ToUpper("Move is not allowed. Try again!"))
		b.CurrentSide = !b.CurrentSide
	}
	return b
}

func (Board) CheckWinner() {

}

func (Board) HandleWinner() {

}
