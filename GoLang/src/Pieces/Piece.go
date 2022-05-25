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

func inBounds(x int, y int) bool {
  return ((0 <= x) && (x < 8) && (0 <= y) && (y < 8))
}

func checkDuplicate(allowedMovements [][]int, x int, y int) bool {
  for index := 0; index < len(allowedMovements); index = index + 1 {
    if len(allowedMovements[index]) != 0 {
      if allowedMovements[index][0] != x && allowedMovements[index][1] != y {
        return true
      }
    }
  }
  return false 
}

func checkKeyList(side bool, board [8][8]string, move []int, allowedKeys [][]int) [][]int {
  // TODO at the moment the own pieces of black are also marked als moveable
  // TODO for white the same, but not always

  // get baseline 
  baseline := 1
  if !side {
    baseline = 6
	}
  // get allowed steps and init allowed movements with helpfull counter
  allowedMovements := make([][]int, cap(allowedKeys)*2+2)
  counter := 0
  // iterate the allowed steps / keys
  for _, allowedKey := range allowedKeys {
    // get white
    x := move[1] - allowedKey[0]  
    y := move[0] - allowedKey[1] 
    // get black
    if side {
	    // add baseline 2 steps movement
      if baseline == move[1] && checkDuplicate(allowedMovements, x+3, y-1) {
        allowedMovements[counter] = []int{x+3, y-1}
        counter += 1
      }
      x = move[1] + allowedKey[0]  
      y = move[0] + allowedKey[1]  
    }
	  // baseline 2 steps movement
    if baseline == move[1] && checkDuplicate(allowedMovements, x-1, y-1) { 
      allowedMovements[counter] = []int{x-1, y-1}
      counter += 1
    }
    // save the coords
    allowedMovements[counter] = []int{x, y}
    // helpfull stuff 
    counter += 1 
  }
  printTmpBoard(allowedMovements, board)
  return allowedMovements
}

func printTmpBoard(allowedMovements [][]int, board [8][8]string) {
  for index := 0; index < len(allowedMovements); index = index + 1 {
    if len(allowedMovements[index]) == 2 {
      x := allowedMovements[index][0]
      y := allowedMovements[index][1]
      if inBounds(x,y) {
        board[x][y] = "-"
      }
    }
  }
  print(allowedMovements)
  var i, j = 0, 0
	for ; i < 8; i++ {
		for j = 0; j < 8; j++ {
			fmt.Print(board[i][j] + "  ")
		}
		fmt.Println("")
	}
}

func checkIfAllowed(move []int, allowedMovements [][]int) bool {
  for index := 0; index < len(allowedMovements); index = index + 1 {
    if len(allowedMovements[index]) == 2 {
      x := allowedMovements[index][0]
      y := allowedMovements[index][1]
      if (move[3] == x && move[2] == y) {
        return true
      }
    }
  }
  return false
}

func pawnMovements(side bool, board [8][8]string, move []int) bool {
  allowedKeys := [][]int{{1, 0}, {1, 1}, {1, -1}}
  allowedMovements := checkKeyList(side, board, move, allowedKeys) 
  return checkIfAllowed(move, allowedMovements)
}

func knightMovements(side bool, board [8][8]string, move []int) bool {
  allowedKeys := [][]int{{2, 1}, {2, -1}, {-2, -1}, {-2, 1}, 
      {1, 2}, {1, -2}, {-1, -2}, {-1, 2}}
  allowedMovements := checkKeyList(side, board, move, allowedKeys) 
  return checkIfAllowed(move, allowedMovements)
}

func kingMovements(side bool, board [8][8]string, move []int) bool {
  allowedKeys := [][]int{{1, 1}, {1, -1}, {-1, 1}, {-1, -1}, 
      {1, 0}, {-1, 0}, {0, -1}, {0, 1}}
  allowedMovements := checkKeyList(side, board, move, allowedKeys) 
  return checkIfAllowed(move, allowedMovements)
}

func bishopMovements(side bool, board [8][8]string, move []int) bool {
	color := "black"
	if !side {
		color = "white"
	}
	fmt.Println("got a " + color + " bishop")
  return false
}

func rookMovements(side bool, board [8][8]string, move []int) bool {
	color := "black"
	if !side {
		color = "white"
	}
	fmt.Println("got a " + color + " rook")
  return false
}

func queenMovements(side bool, board [8][8]string, move []int) bool {
	color := "black"
	if !side {
		color = "white"
	}
	fmt.Println("got a " + color + " queen")
  return false
}

func CheckMovements(board [8][8]string, move []int) bool {
	fromPiece := board[move[1]][move[0]]
	toPiece := board[move[3]][move[2]]
  result := false

	fmt.Println(fromPiece, toPiece)

	if fromPiece == "o" {
		return false
	}
	
  switch strings.ToLower(fromPiece) {
	case "p":
    result = pawnMovements(isUpper(fromPiece), board, move)
	case "k":
		result = knightMovements(isUpper(fromPiece), board, move)
	case "b":
		result = bishopMovements(isUpper(fromPiece), board, move)
	case "r":
		result = rookMovements(isUpper(fromPiece), board, move)
	case "q":
		result = queenMovements(isUpper(fromPiece), board, move)
	case "x":
    result = kingMovements(isUpper(fromPiece), board, move)
	}

	return result 
}
