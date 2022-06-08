pub fn check(movement: [i32; 4], board: &mut [i32; 64], side: bool) -> bool {
    let from_index: usize = get_index(movement[1], movement[0], 8); 
    let from_piece = board[from_index];
    let mut result: bool = false;
    if from_piece == -6 || from_piece == 6 {
        result = check_pawn(movement, board, side);
    } else if from_piece == -2 || from_piece == 2 {
        result = check_knight(movement, board, side);
    } else if from_piece == -3 || from_piece == 3 {
        result = check_bishop(movement, board, side);
    } else if from_piece == -1 || from_piece == 1 {
        result = check_rook(movement, board, side);
    } else if from_piece == -4 || from_piece == 4 {
        result = check_queen(movement, board, side);
    } else if from_piece == -5 || from_piece == 5 {
        result = check_king(movement, board, side);
    }
    return result; 
}

fn get_index(a: i32, b: i32, size: i32) -> usize {
    return (a * size + b - size) as usize;
}

fn eatable(to_piece: i32, side: bool) -> bool {
    if to_piece == 0 {
        return true; 
    } else if to_piece < 0 && !side {
        return true;
    } else if to_piece > 0 && side {
        return true;
    }
    return false;
}

fn check_knight(movement: [i32; 4], board: &mut [i32; 64], side: bool) -> bool{
    let allowed_movements = [[2, 1], [2, -1], [-2, -1], [-2, 1], [1, 2], [1, -2], [-1, -2], [-1, 2]];
    return check_key_list_movements(allowed_movements, movement, board, side);
}
fn check_king(movement: [i32; 4], board: &mut [i32; 64], side: bool) -> bool{
    let allowed_movements = [[1, 1], [1, -1], [-1, 1], [-1, -1], [1, 0], [-1, 0], [0, -1], [0, 1]];
    return check_key_list_movements(allowed_movements, movement, board, side);
}

fn check_pawn(movement: [i32; 4], board: &mut [i32; 64], side: bool) -> bool{
    let allowed_movements = [[1, 0], [1, 1], [1, -1], 
                                [0, 0], [0, 0], [0, 0], [0, 0], [0, 0]];
    let mut x; 
    let mut y;
    x = movement[1] - 2; 
    y = movement[0];
    if !side {
        x = movement[1] + 2; 
        y = movement[0];
    }
    let index = get_index(x, y, 8);
    let to_index = get_index(movement[3], movement[2], 8);
    if to_index == index {
        return true;
    } else {
        return check_key_list_movements_pawn(allowed_movements, movement, board, side);
    } 
}

fn check_key_list_movements(allowed_movements: [[i32; 2]; 8], movement: [i32; 4], 
                            board: &mut [i32; 64], side: bool) -> bool{
    let mut x; 
    let mut y;
    let mut index: usize;
    let mut from_index: usize;
    let mut to_index: usize;
    for i in 0..8 {
        x = movement[1] - allowed_movements[i][0]; 
        y = movement[0] - allowed_movements[i][1]; 
        if !side {
            x = movement[1] + allowed_movements[i][0]; 
            y = movement[0] + allowed_movements[i][1]; 
        }
        index = get_index(x, y, 8);
        from_index = get_index(movement[1], movement[0], 8);
        to_index = get_index(movement[3], movement[2], 8);
        if from_index != index {
            if eatable(board[to_index], side) {
                if to_index == index { return true; } 
            }
        }
    } 
    return false;
}

fn check_key_list_movements_pawn(allowed_movements: [[i32; 2]; 8], movement: [i32; 4], 
                            board: &mut [i32; 64], side: bool) -> bool{
    let mut x; 
    let mut y;
    let mut index: usize;
    let mut from_index: usize;
    let mut to_index: usize;
    for i in 0..8 {
        x = movement[1] - allowed_movements[i][0]; 
        y = movement[0] - allowed_movements[i][1]; 
        if !side {
            x = movement[1] + allowed_movements[i][0]; 
            y = movement[0] + allowed_movements[i][1]; 
        }
        index = get_index(x, y, 8);
        from_index = get_index(movement[1], movement[0], 8);
        to_index = get_index(movement[3], movement[2], 8);
        if from_index != index {
            if allowed_movements[i][1] != 0 {
                if ((board[to_index] < 0) == !side)  || ((board[to_index] > 0) == side) {
                    return true;
                }
                return false;
            }
            if eatable(board[to_index], side) {
                if to_index == index { return true; } 
            }
        }
    } 
    return false;
}
