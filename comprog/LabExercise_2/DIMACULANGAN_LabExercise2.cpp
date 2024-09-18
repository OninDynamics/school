#include <iostream>

int main(int argc, char **argv) {
    int num;

    while(true) {
        std::cout << "Provide an integer: ";
        std::cin >> num;
        
        if ((num % 2) != 0) {
            std::cout << "\nThe integer " << num << " is odd.\n";
        } else if ((num % 10) == 0)  {
            std::cout << "\nThe integer " << num << " is even and divisible by 10.\n";
        } else {
            std::cout << "\nThe integer " << num << " is even but not divisible by 10.\n";
        }

        std::cout << "\nThe program will now loop. Press CTRL + C to exit.\n\n";
    }

    return 0;
}
