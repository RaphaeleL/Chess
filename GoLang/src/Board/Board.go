package Board

import (
	"fmt"
)

func FillBoard() [8][8]string {
	return [8][8]string{
		{"R", "K", "B", "Q", "X", "B", "K", "R"},
		{"P", "P", "P", "P", "P", "P", "P", "P"},
		{"o", "o", "o", "o", "o", "o", "o", "o"},
		{"o", "o", "o", "o", "o", "o", "o", "o"},
		{"o", "o", "o", "o", "o", "o", "o", "o"},
		{"o", "o", "o", "o", "o", "o", "o", "o"},
		{"p", "p", "p", "p", "p", "p", "p", "p"},
		{"r", "k", "b", "x", "q", "b", "k", "r"},
	}
}

func SetField(board [8][8]string, move []int) [8][8]string {
	toMove := board[move[1]][move[0]]
	board[move[1]][move[0]] = "o"
	board[move[3]][move[2]] = toMove
	return board
}

func PrintBoard(board [8][8]string) {
	fmt.Println("Black")
	var i, j = 0, 0
	for ; i < 8; i++ {
		for j = 0; j < 8; j++ {
			fmt.Print(board[i][j] + "  ")
		}
		fmt.Println()
	}
	fmt.Println("White")
}

func HasWinner() bool {
	return true
}

func CheckWinner() bool {
	return false
}

func HandleWinner() bool {
	return false
}
