require_relative "../Pieces/Piece.rb"

def dearScreen()
    puts " #######            ######  ##     ## ########  ######   ######  "
    puts "##     ##          ##    ## ##     ## ##       ##    ## ##    ## "
    puts "##     ##          ##       ##     ## ##       ##       ##       "
    puts "########  ##    ## ##       ######### ######    ######   ######  "
    puts "##   ##   ##    ## ##       ##     ## ##             ##       ## "
    puts "##    ##  ##    ## ##    ## ##     ## ##       ##    ## ##    ## "
    puts "##     ##  ######   ######  ##     ## ########  ######   ######  "
    puts "================================================================="
    puts "================================================================="
    puts "Hint: RuChess is still in development, so there might be any issues"
    puts "================================================================="
    puts "================================================================="
end

def interactMove(movement, board) 
    fromPiece = board[movement[0]][movement[1]] 
    board[movement[0]][movement[1]] = 0
    board[movement[2]][movement[3]] = fromPiece
end 

def makeMove(board, side) 
    movement = getInput(side)
    if check(movement, board, side)
        interactMove(movement, board)
        return true
    end
    return false
end 