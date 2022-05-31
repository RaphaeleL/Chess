cmake_minimum_required(VERSION 3.22)
project(C++)

set(CMAKE_CXX_STANDARD 23)

add_executable(chess src/main.cpp src/Board/Board.cpp src/Board/Board.h src/Utils/Movement.cpp src/Utils/Movement.h src/Pieces/Piece.cpp src/Pieces/Piece.h src/Pieces/Pawn.cpp src/Pieces/Pawn.h src/Pieces/Knight.cpp src/Pieces/Knight.h src/Pieces/Bishop.cpp src/Pieces/Bishop.h src/Pieces/Rook.cpp src/Pieces/Rook.h src/Pieces/King.cpp src/Pieces/King.h src/Pieces/Queen.cpp src/Pieces/Queen.h)
