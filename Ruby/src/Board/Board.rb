def fillBoard()
  vec = [
      [1, 2, 3, 4, 5, 3, 2, 1],
      [6, 6, 6, 6, 6, 6, 6, 6],
      [0, 0, 0, 0, 0, 0, 0, 0],
      [0, 0, 0, 0, 0, 0, 0, 0],
      [0, 0, 0, 0, 0, 0, 0, 0],
      [0, 0, 0, 0, 0, 0, 0, 0],
      [-6, -6, -6, -6, -6, -6, -6, -6],
      [-1, -2, -3, -5, -4, -3, -2, -1]
  ]
  return vec
end

def printBoard(board)
  puts "\nBLACK's Side"
  for i in 0 ... board.size
    for j in 0 ... board.size
      print getRepr(board[i][j])
      print " "
    end
    puts "\n"
  end
  puts "WHITE's Side\n\n"
end

def getRepr(piece) 
    if piece == 1  
        return "R"
    elsif piece == 2 
        return "K"
    elsif piece == 3 
        return "B"
    elsif piece == 4 
        return "Q"
    elsif piece == 5 
        return "X"
    elsif piece == 6  
        return "P"
    elsif piece == -1  
        return "r"
    elsif piece == -2  
        return "k"
    elsif piece == -3  
        return "b"
    elsif piece == -4  
        return "q"
    elsif piece == -5  
        return "x"
    elsif piece == -6  
        return "p"
    elsif piece == -9  
        return "+"
    end 
    return "-";
end

def checkWinner()
    return false
end
