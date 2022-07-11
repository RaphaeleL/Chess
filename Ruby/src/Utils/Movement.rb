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

def prepare(userInputSplitted)
    alphabet = "abcdefgh"
    fromX = alphabet.index(userInputSplitted[0])
    toX = alphabet.index(userInputSplitted[2])
    if is_number?(userInputSplitted[1])
        fromY = userInputSplitted[1].to_i - 1
    end
    if is_number?(userInputSplitted[3])
        toY = userInputSplitted[3].to_i - 1
    end
    return fromY, fromX, toY, toX
end

def is_number? string
    true if Float(string) rescue false
end

def getInput(side) 
    if side 
        print "WHITE [From,To]> "
    else 
        print "BLACK [From,To]> "
    end
    userInputSplitted = gets.chomp.scan /\w/
    return prepare(userInputSplitted)
end 
