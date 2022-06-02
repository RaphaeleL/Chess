mod board;
mod utils;

use board::board::fill_board;
use board::board::check_winner;
use board::board::print_board;
use utils::movement::dear_screen;
use utils::movement::make_move;

fn main() {
    dear_screen();
    let mut has_winner: bool = false;
    let mut side: bool = true; 
    let mut board: [i32; 64] = fill_board();
    while !has_winner {
        print_board(board);
        let result = make_move(&mut board, side); 
        has_winner = check_winner(); 
        if result { side = !side; } 
    } 
}
