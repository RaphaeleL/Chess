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

func walkable(side bool, board [8][8]string, x int, y int) bool {
  if inBounds(x, y) {
    toField := board[x][y]
    toFieldSide := isUpper(toField)
    if toField == "o" {
      fmt.Println("empty")
      return true
    }
    if toFieldSide == side {
      fmt.Println("side equal")
      return false
    }
  }
  return true
}

func checkKeyList(side bool, board [8][8]string, move []int, allowedKeys [][]int) [][]int {
  // get baseline
  baseline := 1
  if !side { baseline = 6 }
  // init some variables
  allowedMovements := make([][]int, cap(allowedKeys)*2+2)
  counter := 0
  var x, y, x1, x2, y1, y2 int
  // iterate the allowed keys
  for _, allowedKey := range allowedKeys {
    // calc the x and y coords for two steps and key steps
    x = move[1] - allowedKey[0]
    y = move[0] - allowedKey[1]
    if side {
      x1, y1 = x+3, y-1
      x2 = move[1] + allowedKey[0]
      y2 = move[0] + allowedKey[1]
    } else {
      x1, y1 = x-1, y-1
      x2 = move[1] - allowedKey[0]
      y2 = move[0] - allowedKey[1]
    }
    // add baseline 2 steps movement
    if baseline == move[1] && checkDuplicate(allowedMovements, x1, y1) {
      if walkable(side, board, x1, y1) { allowedMovements[counter] = []int{x1, y1} }
      counter += 1
    }
    // add keylist steps
    if walkable(side, board, x2, y2) { allowedMovements[counter] = []int{x2, y2} }
    // helpfull stuff
    counter += 1
  }
  //printTmpBoard(allowedMovements, board)
  return allowedMovements
}

/*func printTmpBoard(allowedMovements [][]int, board [8][8]string) {
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
}*/

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
  return false
}

func rookMovements(side bool, board [8][8]string, move []int) bool {
  return false
}

func queenMovements(side bool, board [8][8]string, move []int) bool {
  return false
}

func CheckMovements(board [8][8]string, move []int) bool {
	fromPiece := board[move[1]][move[0]]
	// toPiece := board[move[3]][move[2]]
  result := false

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
