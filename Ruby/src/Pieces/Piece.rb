def check(movement, board, side) 
    fromPiece = board[movement[0]][movement[1]] 
    result = false
    if fromPiece == -6 || fromPiece == 6 
        result = check_pawn(movement, board, side)
    elsif fromPiece == -2 || fromPiece == 2 
        result = check_knight(movement, board, side)
    elsif fromPiece == -3 || fromPiece == 3 
        result = check_bishop(movement, board, side)
    elsif fromPiece == -1 || fromPiece == 1 
        result = check_rook(movement, board, side)
    elsif fromPiece == -4 || fromPiece == 4 
        result = check_queen(movement, board, side)
    elsif fromPiece == -5 || fromPiece == 5 
        result = check_king(movement, board, side)
    end
    return result
end

def key_list_check_pawn(allowed_movements, movement, board, side)
    for i in 0 ... allowed_movements.length
        x = movement[0] - allowed_movements[i][0]
        y = movement[1] - allowed_movements[i][1]
        if !side 
            x = movement[0] + allowed_movements[i][0]
            y = movement[1] + allowed_movements[i][1]
        end
        if 0 <= x and x < 8 and 0 <= y and y < 8
          if board[x][y] != 0 and (allowed_movements[i][1] != 0)
            return true 
          elsif board[x][y] == 0 and (allowed_movements[i][1] == 0)
            return true 
          end
        end
    end
    return false
end

def key_list_check(allowed_movements, movement, board, side)
    puts allowed_movements.length
    for i in 0 ... allowed_movements.length
        print allowed_movements[i], "\n"
        x = movement[0] - allowed_movements[i][0]
        y = movement[1] - allowed_movements[i][1]
        if !side 
            x = movement[0] + allowed_movements[i][0]
            y = movement[1] + allowed_movements[i][1]
        end
        if 0 <= x and x < 8 and 0 <= y and y < 8
            if board[x][y] > 0 and side
                return true
            elsif board[x][y] < 0 and !side
                return true
            elsif board[x][y] == 0
                return true
            end
        end
    end
    return false
end

def check_pawn(movement, board, side) 
    allowed_movements = [[1, 1], [1, -1], [1, 0]]
    x = movement[0] - 2 
    y = movement[1]
    if !side
        x = movement[0] + 2 
        y = movement[1] 
    end
    if movement[2] == x and movement[3] == y 
        return true
    end
    return key_list_check_pawn(allowed_movements, movement, board, side)
end

def check_knight(movement, board, side) 
    allowed_movements = [[2, 1], [2, -1], [-2, -1], [-2, 1], 
                         [1, 2], [1, -2], [-1, -2], [-1, 2]]
    return key_list_check(allowed_movements, movement, board, side)
end

def check_king(movement, board, side) 
    allowed_movements = [[1, 1], [1, -1], [-1, 1], [-1, -1], 
                         [1, 0], [-1, 0], [0, -1], [0, 1]]
    return key_list_check(allowed_movements, movement, board, side)
end

def check_queen(movement, board, side) 
    ba = ba(movement, board, side) 
    bbx = bb(movement, board, side) 
    bc = bc(movement, board, side) 
    bd = bd(movement, board, side) 
    ra = ra(movement, board, side) 
    rb = rb(movement, board, side) 
    rc = rc(movement, board, side) 
    rd = rd(movement, board, side) 
    return (ra or rb or rc or rd or ba or bbx or bc or bd) 
end

def check_bishop(movement, board, side) 
    ba = ba(movement, board, side) 
    bbx = bb(movement, board, side) 
    bc = bc(movement, board, side) 
    bd = bd(movement, board, side) 
    return (ba or bbx or bc or bd) 
end

def check_rook(movement, board, side) 
    ra = ra(movement, board, side) 
    rb = rb(movement, board, side) 
    rc = rc(movement, board, side) 
    rd = rd(movement, board, side) 
    return (ra or rb or rc or rd)
end

def ba(movement, board, side) 
    x = movement[0] + 1
    y = movement[1] + 1
    while 0 <= x and x < 8 and 0 <= y and y < 8 
        if side 
            if board[x][y] < 0  
              return false
            elsif board[x][y] < 0 != board[movement[0]][movement[1]] < 0
              return true
            elsif board[x][y] == 0 
              return true
            end
        else
            if board[x][y] > 0  
              return false
            elsif board[x][y] > 0 != board[movement[0]][movement[1]] > 0
              return true
            elsif board[x][y] == 0 
              return true
            end
        end
    end
    x = x + 1 
    y = y + 1 
    return false
end

def bb(movement, board, side) 
    x = movement[0] + 1
    y = movement[1] - 1
    while 0 <= x and x < 8 and 0 <= y and y < 8 
        if side 
            if board[x][y] < 0  
              return false
            elsif board[x][y] < 0 != board[movement[0]][movement[1]] < 0
              return true
            elsif board[x][y] == 0 
              return true
            end
        else
            if board[x][y] > 0  
              return false
            elsif board[x][y] > 0 != board[movement[0]][movement[1]] > 0
              return true
            elsif board[x][y] == 0 
              return true
            end
        end
    end
    x = x + 1 
    y = y - 1 
    return false
end

def bc(movement, board, side) 
    x = movement[0] - 1
    y = movement[1] + 1
    while 0 <= x and x < 8 and 0 <= y and y < 8 
        if side 
            if board[x][y] < 0  
              return false
            elsif board[x][y] < 0 != board[movement[0]][movement[1]] < 0
              return true
            elsif board[x][y] == 0 
              return true
            end
        else
            if board[x][y] > 0  
              return false
            elsif board[x][y] > 0 != board[movement[0]][movement[1]] > 0
              return true
            elsif board[x][y] == 0 
              return true
            end
        end
    end
    x = x - 1 
    y = y + 1 
    return false
end

def bd(movement, board, side) 
    x = movement[0] - 1
    y = movement[1] - 1
    while 0 <= x and x < 8 and 0 <= y and y < 8 
        if side 
            if board[x][y] < 0  
              return false
            elsif board[x][y] < 0 != board[movement[0]][movement[1]] < 0
              return true
            elsif board[x][y] == 0 
              return true
            end
        else
            if board[x][y] > 0  
              return false
            elsif board[x][y] > 0 != board[movement[0]][movement[1]] > 0
              return true
            elsif board[x][y] == 0 
              return true
            end
        end
    end
    x = x - 1 
    y = y - 1 
    return false
end

def ra(movement, board, side) 
    x = movement[0] - 1
    y = movement[1]
    while 0 <= x and x < 8 and 0 <= y and y < 8 
        if side 
            if board[x][y] < 0  
              return false
            elsif board[x][y] < 0 != board[movement[0]][movement[1]] < 0
              return true
            elsif board[x][y] == 0 
              return true
            end
        else
            if board[x][y] > 0  
              return false
            elsif board[x][y] > 0 != board[movement[0]][movement[1]] > 0
              return true
            elsif board[x][y] == 0 
              return true
            end
        end
    end
    x = x - 1 
    return false
end

def rb(movement, board, side) 
    x = movement[0] + 1
    y = movement[1]
    while 0 <= x and x < 8 and 0 <= y and y < 8 
        if side 
            if board[x][y] < 0  
              return false
            elsif board[x][y] < 0 != board[movement[0]][movement[1]] < 0
              return true
            elsif board[x][y] == 0 
              return true
            end
        else
            if board[x][y] > 0  
              return false
            elsif board[x][y] > 0 != board[movement[0]][movement[1]] > 0
              return true
            elsif board[x][y] == 0 
              return true
            end
        end
    end
    x = x + 1 
    return false
end

def rc(movement, board, side) 
    x = movement[0]
    y = movement[1] - 1
    while 0 <= x and x < 8 and 0 <= y and y < 8 
        if side 
            if board[x][y] < 0  
              return false
            elsif board[x][y] < 0 != board[movement[0]][movement[1]] < 0
              return true
            elsif board[x][y] == 0 
              return true
            end
        else
            if board[x][y] > 0  
              return false
            elsif board[x][y] > 0 != board[movement[0]][movement[1]] > 0
              return true
            elsif board[x][y] == 0 
              return true
            end
        end
    end
    y = y - 1 
    return false
end

def rd(movement, board, side) 
    x = movement[0] 
    y = movement[1] + 1
    while 0 <= x and x < 8 and 0 <= y and y < 8 
        if side 
            if board[x][y] < 0  
              return false
            elsif board[x][y] < 0 != board[movement[0]][movement[1]] < 0
              return true
            elsif board[x][y] == 0 
              return true
            end
        else
            if board[x][y] > 0  
              return false
            elsif board[x][y] > 0 != board[movement[0]][movement[1]] > 0
              return true
            elsif board[x][y] == 0 
              return true
            end
        end
    end
    y = y + 1 
    return false
end



