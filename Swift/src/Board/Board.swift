import Foundation

func fillBoard() -> Array<Array<Int>> {
    return [
      [1, 2, 3, 4, 5, 3, 2, 1],
      [6, 6, 6, 6, 6, 6, 6, 6],
      [0, 0, 0, 0, 0, 0, 0, 0],
      [0, 0, 0, 0, 0, 0, 0, 0],
      [0, 0, 0, 0, 0, 0, 0, 0],
      [0, 0, 0, 0, 0, 0, 0, 0],
      [-6, -6, -6, -6, -6, -6, -6, -6],
      [-1, -2, -3, -5, -4, -3, -2, -1]
    ]
}

func getRepr(piece: Int) -> String {
    if piece == 0 {
        return "-"
    } else if piece == 6 {
        return "p"
    } else if piece == -6 {
        return "P"
    } else if piece == 1 {
        return "r"
    } else if piece == -1 {
        return "R"
    } else if piece == 2 {
        return "k"
    } else if piece == -2 {
        return "K"
    } else if piece == 3 {
        return "b"
    } else if piece == -3 {
        return "B"
    } else if piece == 4 {
        return "q"
    } else if piece == -4 {
        return "Q"
    } else if piece == 5 {
        return "x"
    } else if piece == -5 {
        return "X"
    }
    return String(piece)
}

func printBoard(board: Array<Array<Int>>) {
    print()
    for (_, row) in board.enumerated() {
        for (_, element) in row.enumerated() {
            print(getRepr(piece: element) + " ", terminator: "")
        }
        print()
    }
}



