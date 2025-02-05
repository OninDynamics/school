/* Written by:	Dimaculangan, Gionne Niño P.
 * at Time:		2025-01-22T13:34:00+08:00
 * Description:
 * 		A quiz program. Dynamically computes scores based on
 * 		question set, as defined by the vector<QuizItem> quiz.
 *
 * 		Extremely easy to modify question set. Handles user
 * 		input without errors.
 *
 * 		Designed for quadruple-choice questions only.
 *
 * 		I managed to get this to work perfectly on first compile.
 * 		Granted, it took me 1 hour to get the code to a compile-able
 * 		state. I guess this is what happens when someone obsessively
 * 		cares about "correctness", i.e. is a Rust/Functional
 * 		programmer. Anywho, I shouldn't toot my horn THIS much...
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum Answer {
	a,b,c,d,_	// Surely these are enough
				// '_' works as an "invalid" choice
};

// Allows for declarative definitions of each question
// The format is as follows:
// {
//   "<question>",
//   {"<choice>","<choice>","<choice>","<choice>"},
//   <answer>
// }
struct QuizItem {
	string			question;
	vector<string>	choice;
	Answer			answer;
};

Answer parseChoice(char choice) {
	// cursed pattern matching:
	switch ( (char)tolower(choice) ) {
		case 'a': return a;
		case 'b': return b;
		case 'c': return c;
		case 'd': return d;
		default: return _;
	}
}

int main() {

	// === Defining Questions... ===
	vector<QuizItem> quiz = {
		{	// Question
			"Which of these languages are considered purely functional?",
			{"Haskell", "C#", "Rust", "Java"},
			a
		},
		{	// Question
			"Minecraft's Bedrock Edition is written in...",
			{"C", "C++", "Kotlin", "Java"},
			b
		},
		{	// Question
			"Which of these languages compile to the JVM?",
			{"JavaScript", "Kotlin", "Lua", "C#"},
			b
		},
		{	// Question
			"C++'s std::string type stores string lengths in...",
			{"Storage", "Heap Memory", "CPU Cache", "Stack Memory"},
			d
		},
		{	// Question
			"Which language among these are most similar to Java?",
			{"F#", "C", "C#", "JavaScript"},
			c
		}
	};

	// === The quiz starts here... ===
	string buf;

	while(true) {
		unsigned int answered = 0;
		unsigned int correct = 0;
		Answer ans;
		cout << "\nRandom Programming Questions~\n\n";

		for (QuizItem q : quiz) {
			cout << "\n" << q.question << "\n"
				 << "a. " << q.choice.at(0) << "\n"
				 << "b. " << q.choice.at(1) << "\n"
				 << "c. " << q.choice.at(2) << "\n"
				 << "d. " << q.choice.at(3) << "\n";

			while(true) {
				cout << "\nAnswer (a,b,c,d): ";
				buf.clear();
				cin >> buf;
				ans = parseChoice(buf.at(0));

				if ( ans != _) {
					break;
				} else {
					cout << "\nPlease answer either a, b, c, or d...";
				}
			}

			if (ans == q.answer) {
				cout << "Nice! That's the correct answer.\n"
					 << "Your current score is " << ++correct << '/' << ++answered << ".\n";
			} else {
				cout << "Whoops, the answer was \"" << q.choice.at(q.answer) << "\"."
					 << "Your current score is " << correct << '/' << ++answered << ".\n";
			}
		}

		cout << "\nWell done! You finished the quiz with a score of "
			 << correct << '/' << answered << '.'
			 << "\nThis is equivalent of " << 100 * ((float)correct/(float)answered) << " percent!"
			 << "\nTry again? (y/n): ";
		
		buf.clear();
		cin >> buf;
		if (tolower(buf.at(0)) != 'y') {
			break;
		}
	}

	return 0;
}
