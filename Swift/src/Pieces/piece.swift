import Foundation

public func check(movement: String, board: Array<Array<Int>>, side: Bool) -> Bool {
    let prepared = prepare(movement: movement)
    let fromPiece = board[Int(prepared[1])][Int(prepared[0])] 
    if fromPiece == 6 || fromPiece == -6 {
        return checkPawn(movement: movement, board: board, side: side)
    } else if fromPiece == 1 || fromPiece == -1 {
        return checkRook(movement: movement, board: board, side: side)
    } else if fromPiece == 2 || fromPiece == -2 {
        return checkKnight(movement: movement, board: board, side: side)
    } else if fromPiece == 3 || fromPiece == -3 {
        return checkBishop(movement: movement, board: board, side: side)
    } else if fromPiece == 4 || fromPiece == -4 {
        return checkQueen(movement: movement, board: board, side: side)
    } else if fromPiece == 5 || fromPiece == -5 {
        return checkKing(movement: movement, board: board, side: side)
    } 
    return false
}

func checkPawn(movement: String, board: Array<Array<Int>>, side: Bool) -> Bool {

    return false;
}

func checkKnight(movement: String, board: Array<Array<Int>>, side: Bool) -> Bool {

    return false;
}

func checkBishop(movement: String, board: Array<Array<Int>>, side: Bool) -> Bool {

    return false;
}

func checkRook(movement: String, board: Array<Array<Int>>, side: Bool) -> Bool {

    return false;
} 

func checkQueen(movement: String, board: Array<Array<Int>>, side: Bool) -> Bool {

    return false;
}

func checkKing(movement: String, board: Array<Array<Int>>, side: Bool) -> Bool {

    return false;
}



