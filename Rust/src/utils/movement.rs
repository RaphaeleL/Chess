use std::io::{stdin,stdout,Write};
use super::piece::check;

pub fn dear_screen() {
    println!(" #######   ######  ##     ## ########  ######   ######  ");
    println!("##     ## ##    ## ##     ## ##       ##    ## ##    ## ");
    println!("##     ## ##       ##     ## ##       ##       ##       ");
    println!("########  ##       ######### ######    ######   ######  ");
    println!("##   ##   ##       ##     ## ##             ##       ## ");
    println!("##    ##  ##    ## ##     ## ##       ##    ## ##    ## ");
    println!("##     ##  ######  ##     ## ########  ######   ######  ");
    println!("=======================================================");
    println!("=======================================================");
    println!("Hint: RChess is still in development, so currently the");
    println!("board does not rotate with the choice of color.");
    println!("=======================================================");
    println!("=======================================================");
}

pub fn make_move(board: &mut [i32; 64], side: bool) -> bool {
    let movement = get_input(side); 
    let from_index: usize = (movement[1] * 8 + movement[0] - 8) as usize;
    let to_index: usize = (movement[3] * 8 + movement[2] - 8) as usize;
    if check(movement, board, side) {
        interact_move(board, from_index, to_index);
        return true;
    }
    return false;
}

fn interact_move(board: &mut [i32; 64], from_index: usize, to_index: usize) {
    let from_piece = board[from_index]; 
    board[from_index] = 0; 
    board[to_index] = from_piece;
}

fn get_input_not_numeric(side: bool) -> i32 {
    if side {print!("WHITE> ");
    } else {print!("BLACK> ");}
    let mut user_input = String::new();
    let _ = stdout().flush();
    stdin().read_line(&mut user_input).expect("Did not enter a correct string");
    if let Some('\n') = user_input.chars().next_back() { user_input.pop(); }
    if let Some('\r') = user_input.chars().next_back() { user_input.pop(); }
    let alphabet = "abcdefghijklmnopqrstuvwxyz";
    let char_vec: Vec<char> = user_input.chars().collect();
    return alphabet.find(char_vec[0]).unwrap() as i32;
}

fn get_input_numeric(side: bool) -> i32 {
    if side {print!("WHITE> ");
    } else {print!("BLACK> ");}
    let mut user_input = String::new();
    let _ = stdout().flush();
    stdin().read_line(&mut user_input).expect("Did not enter a correct string");
    if let Some('\n') = user_input.chars().next_back() { user_input.pop(); }
    if let Some('\r') = user_input.chars().next_back() { user_input.pop(); }
    return match user_input.parse::<i32>() { Ok(x) => x, Err(_) => -1, }; 
}

fn get_input(side: bool) -> [i32; 4] {
    let result = [get_input_not_numeric(side), get_input_numeric(side), 
        get_input_not_numeric(side), get_input_numeric(side)];
    println!();
    return result;
}


