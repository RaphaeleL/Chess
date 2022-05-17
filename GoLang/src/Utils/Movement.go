package Utils

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)
import B "../Board"

type Movement struct{}

func (Movement) DearScreen() {
	fmt.Println(" ######              ######  ##     ## ########  ######   ######	")
	fmt.Println("##    ##            ##    ## ##     ## ##       ##    ## ##    ##")
	fmt.Println("##          #####   ##       ##     ## ##       ##       ##		  ")
	fmt.Println("##   #### ##     ## ##       ######### ######    ######   ######	")
	fmt.Println("##    ##  ##     ## ##       ##     ## ##             ##       ##")
	fmt.Println("##    ##  ##     ## ##    ## ##     ## ##       ##    ## ##    ##")
	fmt.Println(" ######     #####   ######  ##     ## ########  ######   ######	")
	fmt.Println("=================================================================")
	fmt.Println("=================================================================")
}

func (Movement) ChooseColor() bool {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Hint: JChess is still in development, so currently the \n " +
		"board does not rotate with the choice of color.")
	fmt.Print("\nWhich color? (W/b) > ")
	playerInput, _ := reader.ReadString('\n')
	playerInput = strings.Replace(playerInput, "\n", "", -1)
	fmt.Println()
	return strings.Compare("w", strings.ToLower(playerInput)) == 0
}

func (Movement) Move(board B.Board) {
	playerInput := getPlayerInput(board)
	movement := prepare(playerInput)
	board.PrintBoard(board.SetField(movement, board))
}

func getPlayerInput(board B.Board) string {
	reader := bufio.NewReader(os.Stdin)
	if board.CurrentSide {
		fmt.Print("\nWHITE [From,To] > ")
	} else {
		fmt.Print("\nBLACK [From,To] > ")
	}
	playerInput, _ := reader.ReadString('\n')
	fmt.Println()
	return strings.Replace(playerInput, "\n", "", -1)
}

func prepare(movement string) []int {
	move := strings.Split(movement, "")
	var x1, x2, y1, y2 int
	x1 = letterToNumer(move[0]) - 1
	x2 = letterToNumer(move[2]) - 1
	fmt.Sscanf(move[1], "%d", &y1)
	fmt.Sscanf(move[3], "%d", &y2)
	y1 -= 1
	y2 -= 1
	return []int{x1, y1, x2, y2}
}

func letterToNumer(letter string) int {
	var number int
	number, _ = strconv.Atoi(letter)
	return number + 1
}
