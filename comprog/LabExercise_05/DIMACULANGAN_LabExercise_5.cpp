#include <iostream>

#define TRIANGLE_HEIGHT 9   // i just wanna play around with this

#define FILLER "#"          // terrible name, i know...
                            // it's here so we can customize the
                            // character(s) that will make the triangle

int main(/* int argc, char* argv[] */) {    // pointers will still be next week

    for (int i = 0; i < TRIANGLE_HEIGHT; i++) {

        for (int j = 0; j <= i; j++) {
            std::cout << FILLER;
        }

        std::cout << "\n";

    }

    return 0;
}
