package Pieces

type Piece struct {
	Side           bool
	Value          int
	Representation string
	Empty          bool
}

func (Piece) CheckMovements(representation string) bool {
	// if pawn black go to ...
	// if pawn white go to ...
	// ...
	return true
}
