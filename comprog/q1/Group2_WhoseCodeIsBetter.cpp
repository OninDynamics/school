#include <iostream>

void fred_sol() {
    for (int i = 1; i <= 10; i++) {
        std::cout 
        << i
        << "² = "
        << i*i
        << '\n';
    }
}

void shaggy_sol() {
    int i = 0;
    while (i++ < 10) {
        std::cout 
        << i
        << "² = "
        << i*i
        << '\n';
    }
}

int main() {
    fred_sol();
    shaggy_sol();

    return 0;
}
