pub fn fill_board() -> [i32; 64] {
    let vec: [i32; 64] = [
        1, 2, 3, 4, 5, 3, 2, 1,
        6, 6, 6, 6, 6, 6, 6, 6,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        -6, -6, -6, -6, -6, -6, -6, -6,
        -1, -2, -3, -5, -4, -3, -2, -1
    ];
    return vec;
}

pub fn get_repr(piece: i32) -> &'static str {
    if piece == 1 { return "R";
    } else if piece == 2 { return "K";
    } else if piece == 3 { return "B";
    } else if piece == 4 { return "Q";
    } else if piece == 5 { return "X";
    } else if piece == 6 { return "P";
    } else if piece == -1 { return "r";
    } else if piece == -2 { return "k";
    } else if piece == -3 { return "b";
    } else if piece == -4 { return "q";
    } else if piece == -5 { return "x";
    } else if piece == -6 { return "p";
    } else if piece == -9 { return "+";
    }
    return "-";
}

pub fn print_board(board: [i32; 64]) {
    println!("Black's Side");
    let mut counter = 0; 
    for piece in board.iter() {
        if counter % 8 == 0 { println!(""); }    
        print!("{} ", get_repr(*piece));
        counter = counter + 1;
    }
    println!("\n\nWhite's Side\n");
}


pub fn check_winner() -> bool {
    return false; 
}

