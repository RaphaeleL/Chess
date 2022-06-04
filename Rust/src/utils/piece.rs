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
