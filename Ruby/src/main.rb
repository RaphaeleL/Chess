require "./Board/Board.rb"
require "./Utils/Movement.rb"

dearScreen()
board = fillBoard()
hasWinner = false
side = true
while !hasWinner
    printBoard(board)
    result = makeMove(board, side)
    hasWinner = checkWinner()
    if result
        side = !side
    end
end

