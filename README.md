# Chess 

Just a Terminal Chess in different Programming Languages

## Introduction

This project does not show an optimal, best, fastest and greatest variant to develop chess in the respective languages. The project served only personal educational purposes. Since chess is one of the most complex board games and already after 2 moves 72.084 possible positions can arise, it may well be the case that this implementation still contains a bug. The logic behind chess is the same in all languages. If an error is discovered, please let me know.

## Running 

The games can be started in different ways. It could be loaded into an IDE of choice and started there, or via command line.

### Java

```bash
$ cd Java/src
$ javac Main.java 
$ java Main
```

### Python

```bash
$ cd Python/src
$ python3 main.py
```

### GoLang

```bash
$ cd GoLang/src
$ go run main.go
```

### C / C++

> Currently the C++ project is only a copied and adapted variant of the C project. Generally no problem, this is also a valid way to program C++. Nevertheless, an [OOP variant](https://github.com/RaphaeleL/Chess/tree/C++_OOP/C++) is in development. The main focus is on new languages. Therefore the OOP variant of the C++ project may take some time. 

Navigate into the Main Directory, so `$ cd C` or `$ cd C++`.

```bash
$ mkdir build; cd build
$ cmake ..
$ make
$ ./chess
```

### Rust

```bash
$ cd Rust/src 
$ cargo run 
```

### Ruby

```bash
$ cd Ruby/src 
$ ruby main.rb 
```

### Swift 

> Under Development

```bash
$ cd Swift/src 
$ swiftc main.swift Board/board.swift Utils/movement.swift Pieces/piece.swift -o chess 
$ ./chess
```

## Progress 

There are plenty of other languages that should be implemented in this project. The most common ones (Java, Python, C/C++, ...) have already been implemented. Other languages like Rust and Ruby of course will follow. 

As written above, this is probably not the best, greatest and fastest way to implement chess. during the development process, some different approaches have crystallized, but the general logic of the game is the same. one crucial point is the implementation of the chess board and the allowed moves. the allowed moves, have quite some optimization potential, but do not lead to any big performance disadvantages. therefore, this implementation will be kept for the time being. another point is the chess board. how should pieces be represented? In Python and Java, this is achieved using a 2D array and objects. Each individual piece inherits from a 'piece' class. furthermore, in GoLang there is a variant which includes a 2D array using strings. C and C++ rely on integer values instead, further an OOP variant is created in C++ in addition. Rust on the other hand has an implementation with integer values and a 1D array.

## Todo

Since all languages are based more or less on the same logic, there are generally still some open points which have not been implemented. 

- Remi Detection 
- Castling 
- En-Passant
- Fancy Shit (Flip Board, Stockfish, Hints, TUI, ...)
    
## Contact

If you have discovered any bugs or have any further ideas for optimization or improvement, feel free to contact me. Feel free to leave suggestions for additional languages.


