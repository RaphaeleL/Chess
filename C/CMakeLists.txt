cmake_minimum_required(VERSION 3.22)
project(Chess C)

set(CMAKE_C_STANDARD 99)

add_executable(chess src/main.c src/Board/Board.c src/Board/Board.h)
