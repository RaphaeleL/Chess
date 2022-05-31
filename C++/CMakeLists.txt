cmake_minimum_required(VERSION 3.22)
project(C++)

set(CMAKE_CXX_STANDARD 23)

add_executable(chess src/main.cpp src/Board/Board.cpp src/Board/Board.h src/Utils/Movement.cpp src/Utils/Movement.h src/Pieces/Piece.cpp src/Pieces/Piece.h)
