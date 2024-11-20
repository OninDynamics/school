#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct BookMetadata {   // Container for book data
    string name;
    string author;
    int year;
    float price;
};

int main() {

    BookMetadata newBook;
    bool checked = false;
    string buf;

    while (true) {
    cout << "\n[ADD] Book Name: ";
    getline(cin, newBook.name);

    cout << "\n[ADD] Book Author: ";
    getline(cin, newBook.author);

    cout << "\n[ADD] Year Published:\n";
    cin >> newBook.year;
    /*
    while (checked == false) {
        try {
            cin >> newBook.year;
            ///newBook.year = stoi(buf);
            checked = true;
        } catch (invalid_argument) {
            cerr << "Error: Integer is required. ";
            continue;
        }
    }*/

    checked = false;
    
    cout << "\n[ADD] Book Price:\n";
    cin >> newBook.price;
    /*
    while (checked == false) {
        try {
            cin >> newBook.price;
            checked = true;
        } catch (invalid_argument) {
            cerr << "Error: Number is required. ";
            continue;
        } catch (out_of_range) {
            cerr << "Error: Number is required. ";
            continue;
        } catch ( ... ) {
            cerr << "Error: Number is required. ";
            continue;
        }
    }*/
    cout << "=== Book " << (1) << " ==="
        << "\nName: " << newBook.name
        << "\nAuthor: " << newBook.author
        << "\nYear Published: " << newBook.year
        << "\nPrice: " << newBook.price
        << "\n\n";
    }
    return 0;
}
