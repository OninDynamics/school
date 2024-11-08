#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    
    string buf;

    cout << "Write a sentence:\n";
    cin >> buf;

    // Create a "C-Style String", which is an array of characters
    char *c_arr = new char[buf.length() + 1];
    copy(buf.begin(), buf.end(), c_arr);
    c_arr[buf.length()] = '\0';

    // Word Separator
    // Loop per character
    for (int i = 0; i < (sizeof(c_arr) / sizeof(*c_arr)); i++) {
        cout << c_arr[i];
        if (c_arr[i] == ' ') {
            break;
        }
    }

    cout << '\n';

    return 0;
}
