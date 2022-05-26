package Utils

import (
	B "src/Board"
	"bufio"
	"fmt"
	"os"
	"strings"
)

func DearScreen() {
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

func ChooseColor() bool {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Hint: GoChess is still in development, so currently the \n " +
		"board does not rotate with the choice of color.")
	fmt.Print("\nWhich color? (W/b) > ")
	playerInput, _ := reader.ReadString('\n')
	playerInput = strings.Replace(playerInput, "\n", "", -1)
	fmt.Println()
	return strings.Compare("w", strings.ToLower(playerInput)) == 0
}

func Move(board [8][8]string, side bool) [8][8]string {
	playerInput := getPlayerInput(side)
	movement := prepare(playerInput)
	newBoard := B.SetField(board, movement)
	return newBoard
}

func getPlayerInput(side bool) string {
	reader := bufio.NewReader(os.Stdin)
	if side {
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
	x1 = letterToNumer(move[0])
	x2 = letterToNumer(move[2])
	fmt.Sscanf(move[1], "%d", &y1)
	fmt.Sscanf(move[3], "%d", &y2)
	y1 -= 1
	y2 -= 1
	return []int{x1, y1, x2, y2}
}

func indexOf(letter string, data []string) int {
	for index := range data {
		if data[index] == letter {
			return index
		}
	}
	return -1
}

func letterToNumer(letter string) int {
	letters := []string{"a", "b", "c", "d", "e", "f", "g", "h"}
	return indexOf(letter, letters)
}
