package Board

import "fmt"

type Board struct{}

func (*Board) FillBoard() {
	fmt.Println("<Filling Board>")
}

func (*Board) PrintBoard() {
	fmt.Println("<Printing Board>")
}
