#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void) {

    vector<int> listofnums = {0, 3, 4, 5};
    string str1 = "This is a string";
    string str2 = {'h', 'e', 'l', 'l', 'o', '!'};

    vector<string> test = {"hi","hello"};

    for (int num : listofnums) {
        cout << num << '\n';
    }

    cout << "str1 is: " << str1 << endl;
    cout << "str2 is: " << str2 << endl;

    cout << "test[0] is: " << test[0] << endl;
    cout << "test[1] is: " << test[1] << endl;


    cout << "{str1 + str2} is: " << str1 + str2 << endl;

    str1.push_back('a');

    cout << "str1 after pushing 'a' into it is: " << str1 << endl;
}
