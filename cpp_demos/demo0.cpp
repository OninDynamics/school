#include <iostream>

int main() {
    
    std::cout << "Test\n";

    int nums[] = {0,6,9,6,9,6,9,42};

    for ( int i : nums ) {
        std::cout << i << std::endl;
    }

    return 0;
}
