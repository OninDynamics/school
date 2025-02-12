/* Word/char counter by [Dimaculangan, Gionne Niño P.] of BSIT-1B.
 * [2024 - 11 - 13]
 *
 * Input sentence is moved into a buffer string object, then the buffer
 * is validated and guaranteed (hopefully) to contain at least a char.
 * Each char in the buffer is checked to be whitespace. If not, the char 
 * is pushed into the latest pushed string object in the "words" vector.
 * If it is whitespace, a new empty string is pushed into "words". This
 * loops until the end of the buffer.
 *
 * Word count is measured by the length of the "words" buffer, and char
 * count is measured by how many times a char was pushed into a string
 * in "words".*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {

    // Create string to hold input
    string buf;

    // Input loop for when buf is empty
    while (buf.empty()) {
        cout << "Write a sentence: ";
        std::getline(std::cin, buf);

        // Notify user if buf is empty
        if (buf.empty()) {
            cerr << "Sentence is empty, try again\n";
        } 

        // Notify user if input has >100 chars
        else if (buf.length() > 100) {
            cerr << "Easy there, less than 100 characters, please.\n";

            // Clear the buffer
            buf.clear();
        }
    }

    // Init the "words" vector
    vector<string> words (1);

    int i = 0;
    unsigned int charCount = 0;

    for (char c : buf) {
        if (c == ' ' || c == '\t') {
            words.push_back("");
            i++;
        } else {
            words[i].push_back(c);
            charCount++;
        }
    }

    cout << "\n\n======\nWords:\n======\n";

    for (string str : words) {
        cout << str << endl;
    }

    cout << "\nThere are " << words.size() << " words, and " << charCount << " character(s).\n";

    return 0;
}
