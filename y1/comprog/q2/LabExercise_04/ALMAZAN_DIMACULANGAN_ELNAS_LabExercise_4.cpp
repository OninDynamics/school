/* Written by: Dimaculangan, Gionne Niño P.
 *             Almazan, Christian Lesbert N.
 *             Elnas, Vhanna Marie Francesca
 * 
 * at Time(UTC):2025-04-30T17:04:00+8:00
 *
 * Desc: The "name" and "age" variables of the "Student" class is private
 *       and is only accessible through the functions (get|set)_(name|age).
 *
 *       Made pretty with some trial and error
 */

#define PROMPT "\n> "

#include <iostream>
#include <string>
using namespace std;

class Student {
	string name;
	unsigned short age;

public:
	// Reading functions (getters)
	string get_name() {
		return name;
	}

	unsigned short get_age() {
		return age;
	}

	// Writing functions (setters)
	void set_name(const string& newName) {
		name = newName;
	}

	void set_age(int newAge) {
		if (1 > newAge || newAge > 100)
			throw invalid_argument("Age invalid.");

		age = newAge;
	}
};

int main() {
	// no reason to use "new" here, but whatever
	Student* s = new Student;
	string buf;

	cout << "\n+-------------------------------------+"
		 << "\n| Poorly-designed Student ID Software |"
		 << "\n+---------------v0.1.0----------------+\n";

	cout << "\nProvide a name for your student."
		 << PROMPT;

	getline(cin, buf);
	s->set_name(buf);
	
	while(true) {
		buf.clear();

		cout << "\nWhat's their age?"
			 << PROMPT;
		
		cin >> buf;
		try {
			s->set_age(stoi(buf));
			break;
		} catch (const invalid_argument& err) {
			cout << "\nError: " << err.what()
				 << "\nHint: Age must be a positive integer from 1 to 100.";
		}
	}

	cout << "\nYou, a student named " << '\'' << s->get_name() << '\''
		 << "\nare " << s->get_age() << " years old.\n";

	return 0;
}
