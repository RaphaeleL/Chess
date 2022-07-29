import Foundation

var side = true
dearScreen()
var board = fillBoard()
var succ = false
printBoard(board: board)

while !hasWinner() {
    (succ, board) = makeMove(movement: getMovement(side: side), board: board, side: side)
    if succ {
        printBoard(board: board)
        checkWinner()
        side = !side
    }
}

handleWinner(winnerSide: side)
