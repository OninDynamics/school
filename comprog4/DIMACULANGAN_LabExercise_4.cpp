#include <iostream>

int main(int argc, char* argv[]) {
    std::cout << "Provide a positive integer: ";
    int a;

    std::cin >> a;

    if (!(a > 0)) {
        std::cout << "\nInput is not a positive integer, aborting...\n";
        return 1;
    } else {
        for (int i = 1; i <= 20; i++) {
            std::cout << "Multiple " << i << ":\t" << (a*i) << "\n";
        }
    }

    return 0;
}
