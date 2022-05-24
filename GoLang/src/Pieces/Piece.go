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

func me(fx int, fy int, tx int, ty int) bool {
  if fx != tx && fy != ty {
    return true
  } 
  return false
}

func pawnMovements(side bool, board [8][8]string, move []int) {
  // get baseline 
  baseline := 1
  if !side {
    baseline = 6
	}
  // get allowed steps and init allowed movements with helpfull counter
  allowedKeys := [][]int{{1, 0}, {1, 1}, {1, -1}}
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
  // temp. fill the board  
  for index := 0; index < len(allowedMovements); index = index + 1 {
    if len(allowedMovements[index]) == 2 {
      x := allowedMovements[index][0]
      y := allowedMovements[index][1]
      if inBounds(x,y) {
        board[x][y] = "-"
      }
    }
  }

  fmt.Println(allowedMovements)
	
  // temp. print the board  
  var i, j = 0, 0
	for ; i < 8; i++ {
		for j = 0; j < 8; j++ {
			fmt.Print(board[i][j] + "  ")
		}
		fmt.Println("")
	}

}

func knightMovements(side bool, board [8][8]string, move []int) {
	color := "black"
	if !side {
		color = "white"
	}
	fmt.Println("got a " + color + " knight")
}

func bishopMovements(side bool, board [8][8]string, move []int) {
	color := "black"
	if !side {
		color = "white"
	}
	fmt.Println("got a " + color + " bishop")
}

func rookMovements(side bool, board [8][8]string, move []int) {
	color := "black"
	if !side {
		color = "white"
	}
	fmt.Println("got a " + color + " rook")
}

func queenMovements(side bool, board [8][8]string, move []int) {
	color := "black"
	if !side {
		color = "white"
	}
	fmt.Println("got a " + color + " queen")
}

func kingMovements(side bool, board [8][8]string, move []int) {
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
		pawnMovements(isUpper(fromPiece), board, move)
	case "k":
		knightMovements(isUpper(fromPiece), board, move)
	case "b":
		bishopMovements(isUpper(fromPiece), board, move)
	case "r":
		rookMovements(isUpper(fromPiece), board, move)
	case "q":
		queenMovements(isUpper(fromPiece), board, move)
	case "x":
		kingMovements(isUpper(fromPiece), board, move)
	}

	return true
}
