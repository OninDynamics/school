#include <iostream>
using namespace std;

// Definition for each square in the game.
// "open" denotes empty squares.
enum square_t {
	pawn	= 'P',
	knight	= 'N',
	bishop	= 'B',
	rook	= 'R',
	queen	= 'Q',
	king	= 'K',
	open	= ' '
};

// Class for a chessboard.
class board {
	square_t contents[8][8]; // Stores 8x8 grid of square_t's.

public:
	// Constructor. Returns itself with state applied.
	board(char state[8][9]) {
		this->set_state(state);
	}

	// State parser from 8x9 char array.
	// Allows for easy state creation.
	void set_state(char state[8][9]) {

		for (char i = 0; i < 8; i++) {      // For each rank (row)...
			for (char j = 0; j < 8; j++) {  // For each file (column)...

				// ...See which char is in the array,
				// then translate into a corresponding square_t.
				switch (state[i][j]) {
					case 'P': contents[i][j] = pawn;	break;
					case 'N': contents[i][j] = knight;	break;
					case 'B': contents[i][j] = bishop;	break;
					case 'R': contents[i][j] = rook;	break;
					case 'Q': contents[i][j] = queen;	break;
					case 'K': contents[i][j] = king;	break;
					default:  contents[i][j] = open;	break;
				}

			}
		}
	}

	// Method of class "board" that shows the current pos graphically
	void show_tty() {
		cout << "\n           Current Position:";
		cout << "\n   +---+---+---+---+---+---+---+---+\n";

		// Loop through each rank (row)
		for (char i = 0; i < 8; i++) {

			// Labels for each file (column).
			// Board index 0-7 is file 8-1.
			cout << ' ' << 8 - i;

			// Loop through each file (column).
			for (char j = 0; j < 8; j++) {
				cout << " | " << (char)contents[i][j];
			}

			cout << " |\n   +---+---+---+---+---+---+---+---+\n";
		}

		// Left padding
		cout << "  ";

		// Labels for each file
		for (char i = 0; i < 8; i++) {
			cout << "   " << (char)(i + 97);
		}

		// Add a blank line below
		cout << "\n\n";
	}
};

int main() {

	// The standard starting position for a chess game.
	// Refer to the enum square_t.
	char std_start[8][9] = {
		"RBNQKNBR",
		"PPPPPPPP",
		"00000000",
		"00000000",
		"00000000",
		"00000000",
		"PPPPPPPP",
		"RBNQKNBR"
	};

	board game = board(std_start);

	game.show_tty();
}
