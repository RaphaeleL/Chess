package Board

import (
	P "src/Pieces"
	"fmt"
	"strings"
  "unicode"
)

var Success = true

func FillBoard() [8][8]string {
	return [8][8]string{
		{"R", "K", "B", "Q", "X", "B", "K", "R"},
		{"P", "P", "P", "P", "P", "P", "P", "P"},
		{"-", "-", "-", "-", "-", "-", "-", "-"},
		{"-", "-", "-", "-", "-", "-", "-", "-"},
		{"-", "-", "-", "-", "-", "-", "-", "-"},
		{"-", "-", "-", "-", "-", "-", "-", "-"},
		{"p", "p", "p", "p", "p", "p", "p", "p"},
		{"r", "k", "b", "x", "q", "b", "k", "r"},
	}
}

func SetField(board [8][8]string, move []int) [8][8]string {
	toMove := board[move[1]][move[0]]
	if P.CheckMovements(board, move) {
		board[move[1]][move[0]] = "-"
		board[move[3]][move[2]] = toMove
	} else {
		fmt.Println(strings.ToUpper("Move is not allowed. Try again!\n"))
		Success = false
		return board
	}
	return board
}

func PrintBoard(board [8][8]string) {
	fmt.Println("+-------------+")
	fmt.Println("| Black       |")
	fmt.Println("+-------------+")
	fmt.Println("\na1                              h1")
	fmt.Println("   +-------------------------+")

	var i, j = 0, 0
	for ; i < 8; i++ {
		fmt.Print("   | ")
		for j = 0; j < 8; j++ {
			fmt.Print(board[i][j] + "  ")
		}
		fmt.Println("|")
	}

	fmt.Println("   +-------------------------+")
	fmt.Println("a8                              h8")
	fmt.Println()
	fmt.Println("\t\t\t+-------------+")
	fmt.Println("\t\t\t| White       |")
	fmt.Println("\t\t\t+-------------+")
}

func isUpper(s string) bool {
  for _, r := range s {
    if !unicode.IsUpper(r) && unicode.IsLetter(r) {
      return false
    }
  }
  return true
}

func CheckWinner(board [8][8]string) bool {
  blackCount := 0
  whiteCount := 0
	var i, j = 0, 0
	for ; i < 8; i++ {
		for j = 0; j < 8; j++ {
      if board[i][j] != "o" {
        if isUpper(board[i][j]) {
          blackCount++;
        } else {
          whiteCount++;
        }
      }
		}
	}
  if blackCount == 0 {
    HandleWinner(true)
    return false 
  } else if whiteCount == 0 {
    HandleWinner(false)
    return false 
  }
  return true
}

func HandleWinner(side bool) {
  fmt.Println("======================================================");
  if side {
    fmt.Println("Black won");
  } else {
    fmt.Println("White won");
  }
  fmt.Println("======================================================");
}
