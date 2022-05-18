package Pieces

import (
	"fmt"
	"strings"
	"unicode"
)

func isUpper(s string) bool {
	for _, r := range s {
		if !unicode.IsUpper(r) && unicode.IsLetter(r) {
			return false
		}
	}
	return true
}

func isLower(s string) bool {
	for _, r := range s {
		if !unicode.IsLower(r) && unicode.IsLetter(r) {
			return false
		}
	}
	return true
}

func pawnMovements(side bool) {
	color := "black"
	if !side {
		color = "white"
	}
	fmt.Println("got a " + color + " pawn")
}

func knightMovements(side bool) {
	color := "black"
	if !side {
		color = "white"
	}
	fmt.Println("got a " + color + " knight")
}

func bishopMovements(side bool) {
	color := "black"
	if !side {
		color = "white"
	}
	fmt.Println("got a " + color + " bishop")
}

func rookMovements(side bool) {
	color := "black"
	if !side {
		color = "white"
	}
	fmt.Println("got a " + color + " rook")
}

func queenMovements(side bool) {
	color := "black"
	if !side {
		color = "white"
	}
	fmt.Println("got a " + color + " queen")
}

func kingMovements(side bool) {
	color := "black"
	if !side {
		color = "white"
	}
	fmt.Println("got a " + color + " king")
}

func CheckMovements(board [8][8]string, move []int) bool {
	fromPiece := board[move[1]][move[0]]
	toPiece := board[move[3]][move[2]]

	fmt.Println(fromPiece, toPiece)

	if fromPiece == "o" {
		return false
	}

	switch strings.ToLower(fromPiece) {
	case "p":
		pawnMovements(isUpper(fromPiece))
	case "k":
		knightMovements(isUpper(fromPiece))
	case "b":
		bishopMovements(isUpper(fromPiece))
	case "r":
		rookMovements(isUpper(fromPiece))
	case "q":
		queenMovements(isUpper(fromPiece))
	case "x":
		kingMovements(isUpper(fromPiece))
	}

	return true
}
