#include <iostream>

bool inputIsBad(long* x) { // Poor man's reference passing
    return (*x < 1) || (*x > 15);   // Return true if value doesn't meet criteria
}

int main(int argc, char *argv[]) {
    long* buf = new long();
    short num;  // extreme memory optimization
                // will result in undefined behaviour if
                // the user inputs anything more than a short though

    // Begin Input Loop
    std::cout << "\nProvide a number from 1 to 15: ";
    do {
        std::cin >> *buf;    
        if ( inputIsBad(buf) ) {   
            std::cout << "come on man, gimme an integer from 1 to 15: ";
        }
    } while ( inputIsBad(buf) );

    num = short(*buf);  // Pass the (now validated) input to the short
    delete(buf);

    // Begin Printing Table
    for (short i = 1; i <= num; i++) {
        std::cout << "\n";
        for (short j = 1; j <= num; j++) {
            std::cout << i << "*" << j << "=" << i*j << "\t|";  // Print it like a table or something
        }
    }

    std::cout << "\n\n";

    return 0;
}
