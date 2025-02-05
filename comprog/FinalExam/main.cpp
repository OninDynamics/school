#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Enum of every possible user action
enum Action {
    Add,
    List,
    Quit,
    Help
};

struct ContactInfo {
    string name;
    unsigned long int number;
};

// Take a character then map it to an Action
Action parse(char c) {
    if (c == 'a') {
        return Add;
    } else if (c == 'l') {
        return List;
    } else if (c == 'q') {
        return Quit;
    } else {
        return Help;
    }
}

void addContact(vector<ContactInfo>& db) {
    string num_as_str;
    ContactInfo c;

    cout << "\n[ADD] Enter Contact Name:\n";
    getline(cin, c.name);

    while (true) {
        cout << "\n[ADD] Enter Contact Number:\n";

        // Get input and check if it's a valid uint64
        try {
            num_as_str.clear();
            getline(cin, num_as_str);
            c.number = stol(num_as_str);
        }
        catch (invalid_argument) {
            cout << "Contact numbers should be numeric and have no spaces.";
            continue;
        }
        catch (out_of_range) {
            cout << "Contact numbers don't go up that high, do they?";
            continue;
        }

        break;  // Only break if no exceptions are thrown
    }


    // Push contact to "database"
    db.push_back(c);

    cout << "\n[ADD] Contact added:"
         << "\nName:    " << c.name
         << "\nContact: " << c.number
         << "\n";
}

// Because the database won't be changed, there's no need to pass by reference
void listContacts(vector<ContactInfo> db) {
    // Check if db is empty
    if (db.empty()) {
        cout << "\nNo contacts in list.\n";
    } else {
        cout << "\n=== Contacts ===";

        // Iterate through all ContactInfo structs in db
        unsigned int i = 1;
        for (ContactInfo contact : db) {
            cout << "\nContact " << i++
                 << ": " << contact.name
                 << " - " << contact.number;
        }
        cout << "\n================\n";
    }
}


int main(int argc, char *argv[]) {
    // Initialize input buffer and contact db
    vector<ContactInfo> contact_db (0);
    string buf;

    bool keep_going = true;
    while (keep_going) {
        buf.clear();
        // Display controls
        cout << "\n[Contact Manager v0.0.1]"
             << "\n(a) Add a contact"
             << "\n(l) List contacts"
             << "\n(q) Quit program"
             << "\n> ";

        // Store user input in a string
        // No getline() for now, we only want the first char anyw
        cin >> buf;

        // Prevent the next instances of getline() from returning null
        cin.ignore();

        // Parse the first char of user input then decide what function to call
        switch (parse(buf.at(0))) {
            case Add:
                addContact(contact_db);
                break;

            case List:
                listContacts(contact_db);
                break;

            case Quit:
                keep_going = false;
                break;

            case Help:
                break;
        }
    }

    // This program shouldn't reach an error/undefined state... fingers crossed
    return 0;
}
