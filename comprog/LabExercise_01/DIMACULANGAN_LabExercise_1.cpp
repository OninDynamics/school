#include <iostream>
//  nah i don't want to use std namespace,
//  gotta practice for real life where we
//  import like 200 libraries

int main() {
    double a,b;
    std::cout << "Specify two integers:\n\na = ";
    std::cin >> a;

    std::cout << "b = ";
    std::cin >> b;

    std::cout << "\n===ANSWERS===\n\nAddition: " << a + b       << std::endl;
    std::cout << "Subtraction: "    << a - b			<< std::endl;
    std::cout << "Multiplication: " << a * b			<< std::endl;
    std::cout << "Division: "       << a / b			<< std::endl;
    std::cout << "Modulus: "        << ulong(a) % ulong(b)      << std::endl;

    return 0;
}
