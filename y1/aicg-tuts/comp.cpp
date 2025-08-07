#include <iostream>

int main() {
    int a,b;

    std::cout << "Enter the first integer: ";
    std::cin >> a;

    std::cout << "Enter the second integer: ";
    std::cin >> b;

    if (a > b)
        std::cout << a << " is greater than " << b << ".\n";

    else if (a < b)
        std::cout << a << " is less than " << b << ".\n";

    else if (a == b)
        std::cout << a << " is equal to " << b << ".\n";

    return 0;
}
