/* Written by:	Dimaculangan, Gionne Niño P.
 * 				Almazan, Christian Lesbert N.
 * at Time(UTC):2025-01-22T13:34:00+08:00
 * Description:
 */

#define BLANK " ⍽ "	// Want to change the "blank" representation? Change it here

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class SeatPlan {
	struct Student{
		string initials;
		string name;
	};
	vector<vector<Student>> plan;
	// "plan" = total table, size dictates amount of rows
	// plan.at(n) = each row, size dictates amount of columns
	// plan.at(n).at(m) = the 4-byte 3-char content of the seat
	// ...this is probably extremely terrible for cache hits but whatev

public:
	// initializer syntax took me forever to figure out, i'll admit
	// ChatGPT help on explaining this one (but cppreference and gforgeeks
	// was honestly better in the end, GPT kept spouting examples when I
	// wanted explanations instead) -onind
	SeatPlan(unsigned short cols, unsigned short rows)
	: plan(rows, vector<Student>(cols, {"",""})) {
		cout << "\nInitialization finished~\n";
	}

	void show() {
		cout << "\n    Seating Plan:\n   ";

		// Labels for each column
		for (unsigned short i = 0; i < plan.at(0).size();) {
			cout << " " << char(++i + 64) << "  ";
			// ASCII manip wizardry then print each label out
			// (converts numbers to letters)
		}

		cout << "\n";

		for (unsigned short row = 0; row < plan.size(); row++) {
			// Labels for each row
			cout << " " << row + 1;

			// List each seat of each row
			for (Student seat: plan.at(row)) {
				cout << " ";
				if (seat.name == "") {
					cout << BLANK;
				} else {
					cout << seat.initials;
				}
			}
			cout << "\n";
		}
	}
};

int main() {
	string buf;
	unsigned short cols = 0,rows = 0;

	cout << "Seatplan Manager\n\n";

	do {
		buf.clear();
		cout << "How many columns in the class? ";
		cin >> buf;
		try {
			cols = stoi(buf);
			if (rows < 2)
				throw std::invalid_argument("");
		} catch (...) {
			cout << "A number at least 5, please~\n"; continue;
		}
	} while (cols < 4);

	do {
		buf.clear();
		cout << "How many rows in the class? ";
		cin >> buf;
		try {
			rows = stoi(buf);
			if (rows < 2)
				throw std::invalid_argument("");
		} catch (...) {
			cout << "A number at least 3, please~\n"; continue;
		}
	} while (rows < 2);

	SeatPlan plan(cols,rows);
	plan.show();
}
