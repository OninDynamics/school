/* Written by:	Dimaculangan, Gionne Niño P.
 * 				Almazan, Christian Lesbert N.
 * at Time(UTC):2025-01-22T13:34:00+08:00
 * Description:
 * Overengineered bit of code. All code involving the creation and mutation
 * of the data of the seat plan is encapsulated in the "SeatPlan" class. The
 * UI is implemented everywhere else, i.e. in the "Action" enum, "ParseAction"
 * function, and the main() function.
 *
 * Every interaction with the seat plan, whether it involves viewing it or
 * modifying it, are implemented as member functions (a.k.a. methods) of the
 * SeatPlan class. This allows for flexibility, i.e. the capability of having
 * multiple SeatPlan objects to save/load between, but that's not implemented
 * by the UI parts of this program.
 *
 * If you're my batchmate and you're reading this from my public repo
 * (https://github.com/OninDynamics/school), I'm sorry for what I'm about to
 * put you through.
 */

#define BLANK " ⍽ "	// Want to change the "blank seat" character? Change it here (make sure to incl. spaces)
#define PROMPT "> "	// Want to change the cli prompt? Change it here

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> // required for std::atoi()
//#include <cctype>	// required for std::isdigit()

using namespace std;

// Every possible action
enum Action {
	_,			// display help by default
	add,		// add a student
	del,		// delete a student
	swap,		// swap two seats (moves if one is null)
	overview,	// display the whole layout
	showinfo,	// display specific student info
	quit,		// idk what this does
};

Action ParseAction(char c) {
	switch ( tolower(c) ) {
		case 'a': return add;
		case 'd': return del;
		case 's': return Action::swap;
		case 'v': return overview;
		case 'i': return showinfo;
		case 'q': return quit;
		default: return _;
	}
}

class SeatPlan {
	struct Student {
		string initials;
		string name;
	};

	// "plan" = total table, size dictates amount of rows
	// plan.at(n) = each row, size dictates amount of columns
	// plan.at(n).at(m) = the content of the seat (contains Student structs)
	// ...this is probably extremely terrible for cache hits but whatev
	// at least i don't risk stack overflows
	vector<vector<Student>> plan;

	int* parse_coords(string raw_s) {
		// may the memory gods allow me to not forget to free (delete) this later
		int* coords = new int[2];

		coords[0] = raw_s.at(0) - 49;
		coords[1] = static_cast<int>((unsigned short)toupper(raw_s.at(1)) - 65); // even more forbidden ascii
		return coords;
	}

public:
	// initializer syntax took me forever to figure out, i'll admit
	// ChatGPT help on trying to explain this but that was still useless,
	// all it did was provide answers without explaining what each token
	// meant and how to use them properly
	//
	// spent hours bruteforcing GeeksforGeeks and cppreference.com instead -onind

	// enough yap: this parametrized constructor allocates a
	// vector of vectors of students in the variable named "plan"
	SeatPlan(unsigned short cols, unsigned short rows)
	: plan(rows, vector<Student>(cols, {"",""}))
	{
		cout << "\n\n==== Initialization finished ====\n";
	}

	// Method to show every seat in a grid.
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
		cout << "\n";
	}

	// Method for adding students to a seat. Notifies before override.
	void add() {
		string buf;
		cout << "\nAdd a student with the syntax \"COLROW\"\n"
			 << "i.e.: \"2D\", \"4E\", etc.\n"
			 << PROMPT;

		do {
			buf.clear();
			cin >> buf;
			cin.ignore();
			if (buf.length() > 2) {
				cout << "One number and one letter, please~\n"
					 << PROMPT;
			}
		} while (buf.length() > 2);
		
		int* coords = parse_coords(buf);

		try {
			// Check if seat at the requested coords are occupied
			if ( !(plan.at(coords[0]).at(coords[1]).name.empty()) ) {
				cout << "WARNING: Seat is not empty. Proceed? [y/N]\n"
					 << PROMPT;
				buf.clear();
				cin >> buf;
				cin.ignore();
				if ( !(buf.at(0) == 'y' || buf.at(0) == 'Y') ) {
					cout << "\nCancelling student addition...";
					delete coords;
					return;
				}
			}
		} catch (std::out_of_range) {
			cout << "Those coordinates are out of range! Aborting...\n";
			delete coords;
			return;
		}

		// Define new student struct
		Student new_student;

		cout << "Enter the Student's name: ";
		buf.clear();
		getline(cin, new_student.name);

		cout << "Enter the Student's initials: ";
		while (true) {
			buf.clear();
			cin >> new_student.initials;
			cin.ignore();

			if (new_student.initials.length() != 2) {
				break;
			} else {
				cout << "3 letters, please: ";
			}
		}

		// Finally change the seating plan to the new struct
		plan.at(coords[0]).at(coords[1]) = new_student;
		delete coords;
		cout << "\nFinished adding a student!\n";
	}

	void del() {
			string buf;
			cout << "\nDelete a student from a seat \"COLROW\"\n"
				 << "i.e.: \"2D\", \"4E\", etc.\n"
				 << PROMPT;

			do {
				buf.clear();
				cin >> buf;
				cin.ignore();
				if (buf.length() > 2) {
					cout << "One number and one letter, please~\n"
						 << PROMPT;
				}
			} while (buf.length() > 2);
			
			int* coords = parse_coords(buf);

		try {
			// Check if seat at the requested coords are occupied
			if ( (plan.at(coords[0]).at(coords[1]).name.empty()) ) {
				cout << "The seat is empty, aborting~\n";
				return;
			} else { // Otherwise, nullify the coord
				plan.at(coords[0]).at(coords[1]).name = "";
				plan.at(coords[0]).at(coords[1]).initials = "";
			}

			cout << "Successfully deleted the student~\n";
		} catch (std::out_of_range) {
			cout << "Those coordinates are out of range! Aborting...\n";
			delete coords;
			return;
		}
		delete coords;
	}

	void swap() {
			string buf;
			cout << "\nSelect a seat \"COLROW\"\n"
				 << "i.e.: \"2D\", \"4E\", etc.\n"
				 << PROMPT;

			do {
				buf.clear();
				cin >> buf;
				cin.ignore();
				if (buf.length() > 2) {
					cout << "One number and one letter, please~\n"
						 << PROMPT;
				}
			} while (buf.length() > 2);
			
			int* coord_a = parse_coords(buf);

			// Do a second one, now we'll have two sets of coords
			cout << "\nSelect a seat to swap places with:\n"
				 << PROMPT;

			do {
				buf.clear();
				cin >> buf;
				cin.ignore();
				if (buf.length() > 2) {
					cout << "One number and one letter, please~\n"
						 << PROMPT;
				}
			} while (buf.length() > 2);
			
			int* coord_b = parse_coords(buf);
		try {
			// Do a simple "swap these things around"
			Student a = plan.at(coord_a[0]).at(coord_a[1]);
			Student b = plan.at(coord_b[0]).at(coord_b[1]);
			Student c = a;
			plan.at(coord_a[0]).at(coord_a[1]) = b;
			plan.at(coord_b[0]).at(coord_b[1]) = c;
			cout << "Swapped successfully~\n";
		} catch (std::out_of_range) {
			cout << "Those coordinates are out of range! Aborting...\n";
			delete coord_a;
			delete coord_b;
			return;
		}
		delete coord_a;
		delete coord_b;
	}

	void info() {
		string buf;
		cout << "\nGet information of the student at a seat \"COLROW\"\n"
			 << "i.e.: \"2D\", \"4E\", etc.\n"
			 << PROMPT;

		do {
			buf.clear();
			cin >> buf;
			cin.ignore();
			if (buf.length() > 2) {
				cout << "One number and one letter, please~\n"
					 << PROMPT;
			}
		} while (buf.length() > 2);
		
		int* coords = parse_coords(buf);

		try {
			// Check if seat at the requested coords are occupied
			if ( (plan.at(coords[0]).at(coords[1]).name.empty()) ) {
				cout << "The seat is empty, aborting~\n";
				delete coords;
				return;
			} else {
				// This one's easy
				cout << "\nStudent at that seat:\n"
					 << "Name:      "   << plan.at(coords[0]).at(coords[1]).name
					 << "\nInitials:  " << plan.at(coords[0]).at(coords[1]).initials;
			}

			cout << "\n\n";
		} catch (std::out_of_range) {
			cout << "Those coordinates are out of range! Aborting...\n";
			delete coords;
			return;
		}
		delete coords;
	}
};

void help() {
	cout << "\n====== Available commands: ======\n"
		 << "h:\tRead this help\n"
		 << "a:\tAdd a Student\n"
		 << "d:\tRemove a Student\n"
		 << "s:\tMove a student (swaps if there's students in both seats)\n"
		 << "v:\tGraphically show the current layout\n"
		 << "i:\tSee a Student's full name\n"
		 << "q:\tQuit the program\n";
}

int main() {
	string buf;
	unsigned short cols,rows;

	cout << "  ==== Seatplan Manager ====\n\n";

	do {
		buf.clear();
		cout << "How many columns in the class? ";
		cin >> buf;
		cin.ignore();
		try {
			cols = stoi(buf);
			if (cols < 3 || cols > 26)
				throw std::invalid_argument("");
		} catch (...) {
			cout << "A number between 3 and 26, please~\n"; continue;
		}
	} while (cols < 3 || cols > 26);

	do {
		buf.clear();
		cout << "How many rows in the class? ";
		cin >> buf;
		cin.ignore();
		try {
			rows = stoi(buf);
			if (rows < 3 || cols > 9)
				throw std::invalid_argument("");
		} catch (...) {
			cout << "A number between 3 and 9, please~\n"; continue;
		}
	} while (rows < 3 || cols > 9);

	// ========= FINISH SETTING UP ==========
	SeatPlan plan(cols,rows);
	plan.show();
	help();

	while (true) {
		buf.clear();

		cout << '\n' << PROMPT;

		cin >> buf;
		cin.ignore();
		switch (ParseAction(buf.at(0))) {
			case _: 			help(); break;
			case add:			plan.add(); break;
			case del:			plan.del(); break;
			case Action::swap:	plan.swap(); break;
			case overview:		plan.show(); break;
			case showinfo:		plan.info(); break;
			case quit:			return 0;
		}
	}
}
