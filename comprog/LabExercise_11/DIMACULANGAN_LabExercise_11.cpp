/* Library Manager, version negative 2 billion (i'll never release this abomination)
 * Written by Dimaculangan, Gionne Niño
 * With help from Almazan, Christian Lesbert
 *
 * Commands are implemented via the Action enum, allowing a defined set of
 * possible actions the user can do.
 *
 * Main input loop is found in main(). main() uses a switch to call different
 * functions based on user input. The switch itself is driven by parse(), a
 * function that takes a character and returns an Action enum.
 *
 * Books are defined by the struct BookMetaData.
 *
 * The main "dAtAbAsE" is stored in book_db. It's declared in main() as a
 * vector of BookMetadata's. All functions involving book_db take a reference
 * to a std::vector<BookMetadata> as its argument. This preserves memory even
 * when functions like listBooks() don't mutate book_db. However, I'm pretty
 * sure gcc knows when to automagically optimize for that kinda stuff. If not,
 * then I guess I'm spoiled by the concepts of Haskell and Rust.
 *
 * (Sorry, I like how Rust calls their enum members waa)
 * Action::list calls listBooks(), which iterates through book_db and displays
 * the contents of each BookMetadata entry.
 * Action::add calls addBook(), which lets the user interactively add entries
 * and push them onto book_db.
 * Action::modify calls modBook(), which lets the user choose a book from a
 * list of entries and interactively modify the chosen entry.
 * Action::help shows help info, and Action::quit gives the user a $20 fortnite
 * gift card.
 *
 * No Action::delete because lazy
 *
 * A lot is to be desired for code quality, but wrestling with getline() was
 * a bigger priority at the time. I regret not putting addBook and modBook's
 * input code into a separate "bookEntryEditor()" or something.
 */

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
        unsigned int book_id = 0;   // Simple way of counting in a range'd loop
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
    bool checked = false;   // Just a sentinel(?) for input validation.
                            // A "checked" value of false means input hasn't
                            // been validated yet.
    string buf;             // im addicted to buffers get them away from me

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
    }   // No other validation, imagine if this library contains a scroll
        // from Ancient Sumeria or something lol

    checked = false;    // Reset this so next input validation part can use it
    
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
    }   // Technically currencies should be fixed-point numbers, at least an int
        // There isn't such thing as "0.0000534 pesos"

    // sanity check before the user gets dementia
    cout << "\n[ADD] Book added!"
        << "\n\tName: " << newBook.name
        << "\n\tAuthor: " << newBook.author
        << "\n\tYear Published: " << newBook.year
        << "\n\tPrice: " << newBook.price
        << "\n\n";
    
    book_db.push_back(newBook); // Add the newBook struct to book_db
}

// Function for modifying a book interactively.
// Lists book entries then modifies a chosen entry.
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
        } catch (invalid_argument) {    // Not a number.
            cout << "Select a number: ";
            continue;
        } catch (out_of_range) {        // Out of range. Reminds user of valid range.
            cout << "Number must be between 1 and "
                << book_db.size()
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
    bool checked = false;   // Just a sentinel(?) for input validation.
                            // A "checked" value of false means input hasn't
                            // been validated yet.

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
