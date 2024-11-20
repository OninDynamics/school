#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Possible actions the user can do
enum Action {
    list,
    add,
    modify,
    help,
    quit
};

// Container for book data
struct BookMetadata {
    string name;
    string author;
    int year;
    float price;
};

// Parser for commands. Returns an Action.
Action parse(char& com) {
    if (com == 'l') {
        return list;
    } else if (com == 'a') {
        return add;
    } else if (com == 'm') {
        return modify;
    } else if (com == 'h') {
        return help;
    } else if (com == 'q') {
        return quit;
    } else {
        return help;
    }
}

// Lists every book in the provided vector of BookMetadata's.
void listBooks(vector<BookMetadata>& book_db) {
    if (book_db.empty()) {
        cout << "No books in database.\n";
    } else {
        unsigned int book_id = 0;
        cout << "\n\n";
        for (BookMetadata book : book_db) {
            cout << "=== Book " << (++book_id) << " ==="
                << "\nName: " << book.name
                << "\nAuthor: " << book.author
                << "\nYear Published: " << book.year
                << "\nPrice: " << book.price
                << "\n\n";
        }
    }
}

// Function for adding a book. Creates a struct newBook and pushes it
// onto the book database provided via its parameter. Takes a mutable
// reference to a vector of BookMetadata's.
void addBook(vector<BookMetadata>& book_db) {
    cin.ignore();

    BookMetadata newBook;
    bool checked = false;
    string buf;

    cout << "\n[ADD] Book Name: ";
    getline(cin, newBook.name);

    cout << "[ADD] Book Author: ";
    getline(cin, newBook.author);

    cout << "[ADD] Year Published: ";
    while (checked == false) {
        try {
            buf.clear();
            getline(cin, buf);
            newBook.year = stoi(buf);
            checked = true;
        } catch (invalid_argument) {
            cerr << "Integer is required: ";
            continue;
        }
    }

    checked = false;
    
    cout << "[ADD] Book Price: ";
    while (checked == false) {
        try {
            buf.clear();
            getline(cin, buf);
            newBook.price = stof(buf);
            checked = true;
        } catch (invalid_argument) {
            cerr << "Number is required: ";
            continue;
        } catch (out_of_range) {
            cerr << "Number is required: ";
            continue;
        } catch ( ... ) {
            cerr << "Number is required: ";
            continue;
        }
    }

    cout << "\n[ADD] Book added!"
        << "\n\tName: " << newBook.name
        << "\n\tAuthor: " << newBook.author
        << "\n\tYear Published: " << newBook.year
        << "\n\tPrice: " << newBook.price
        << "\n\n";
    
    book_db.push_back(newBook); // Add the newBook struct to book_db
}

void modifyBook(vector<BookMetadata>& book_db) {
    cin.ignore();
    
    bool idIsValid = false;
    string buf;

    // Display titles of every book
    cout << "\n[MOD] Choose a book to modify:\n";
    unsigned int id = 0;
    for (BookMetadata book : book_db) {
        cout << ++id << "\t: " << book.name << "\tby " << book.author << "\n";
    }
    cout << "\n";

    // Have the user select a book
    unsigned int selId;
    while (idIsValid == false) {
        buf.clear();
        cin >> buf;
        try {
            selId = stoi(buf) - 1;
            if (selId < 0 || selId >= book_db.size() ) {
                throw out_of_range("");
            } else {
                idIsValid = true;
            }
        } catch (invalid_argument) {
            cout << "Select a number: ";
            continue;
        } catch (out_of_range) {
            cout << "Number must be between 1 and "
                << book_db.size() - 1
                << ". \nSelect a number: ";
            continue;
        }
    }

    // Load book from database
    BookMetadata modBook = book_db.at(selId);

    // Display book metadata
    cout << "\n[MOD] Modifying book:"
        << "\n\tName: " << modBook.name
        << "\n\tAuthor: " << modBook.author
        << "\n\tYear Published: " << modBook.year
        << "\n\tPrice: " << modBook.price
        << "\n\n";

    // Begin editing book
    cin.ignore();
    bool checked = false;

    cout << "\n[MOD] Book Name: ";
    getline(cin, modBook.name);

    cout << "[MOD] Book Author: ";
    getline(cin, modBook.author);

    cout << "[MOD] Year Published: ";
    while (checked == false) {
        try {
            buf.clear();
            getline(cin, buf);
            modBook.year = stoi(buf);
            checked = true;
        } catch (invalid_argument) {
            cerr << "Integer is required: ";
            continue;
        }
    }

    checked = false;
    
    cout << "[MOD] Book Price: ";
    while (checked == false) {
        try {
            buf.clear();
            getline(cin, buf);
            modBook.price = stof(buf);
            checked = true;
        } catch (invalid_argument) {
            cerr << "Number is required: ";
            continue;
        } catch (out_of_range) {
            cerr << "Number is required: ";
            continue;
        } catch ( ... ) {
            cerr << "Number is required: ";
            continue;
        }
    }

    cout << "\n[] Book Modified!"
        << "\n\tName: " << modBook.name
        << "\n\tAuthor: " << modBook.author
        << "\n\tYear Published: " << modBook.year
        << "\n\tPrice: " << modBook.price
        << "\n\n";

    book_db.at(selId) = modBook;
}

int main(int argc, char *argv[]) {

    vector<BookMetadata> book_db (0);
    string buf;

    while (true) {
        cout << "Action (h for help): ";
        cin >> buf;
        switch ( parse(buf.at(0)) ) {
            case list:
                listBooks(book_db);
                break;
            case add:
                addBook(book_db);
                break;
            case modify:
                modifyBook(book_db);
                break;
            case help:
                cout << "\nAvailable Commands:\n"
                    << "h: Get this help\n"
                    << "l: List all books\n"
                    << "a: Add a book\n"
                    << "m: Change (modify) a book\n"
                    << "q: Exit program\n\n";
                break;
            case quit:
                goto exit;  // don't worry i won't make BASIC spaghetti
        }
    }
exit:
    return 0;
}
