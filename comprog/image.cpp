#include <stdint.h>

int main() {

    // Declare a completely white 3x3 image.
    uint8_t img[3][3][3] = 
    {
        {
            { 0xff, 0xff, 0xff }, { 0xff, 0xff, 0xff }, { 0xff, 0xff, 0xff }
        },
        {
            { 0xff, 0xff, 0xff }, { 0xff, 0xff, 0xff }, { 0xff, 0xff, 0xff }
        },
        {
            { 0xff, 0xff, 0xff }, { 0xff, 0xff, 0xff }, { 0xff, 0xff, 0xff }
        },
    };

    // Example: Lower the brightness by 50%
    for (char row=0; row < 3; row++) {                          // For each row of pixels...
        for (char pixel=0; pixel < 3; pixel++) {                // For each pixel...
            for (char channel = 0; channel < 3; channel++) {    // Every color channel...
                img[row][pixel][channel] /= 2;                  // Must be halved!
            }
        }
    }

    // Example: Add a green filter
    for (char row=0; row < 3; row++) {                          // For each row of pixels...
        for (char pixel=0; pixel < 3; pixel++) {                // For each pixel...
            img[row][pixel][0] /= 2;                            // Halve the Red channel!
            img[row][pixel][1] /= 2;                            // Halve the Green channel!
        }                                                       // Because the blue channel was untouched...
    }                                                           // The image becomes blue!

    // Example: Lower the brightness by 50%
    for (char row=0; row < 3; row++) {                          // For each row of pixels...
        for (char pixel=0; pixel < 3; pixel++) {                // For each pixel...
            for (char channel = 0; channel < 3; channel++) {    // For each color channel...
                img[row][pixel][channel] /= 2;                  // Halve the channel!
            }
        }
    }
    return 0;
}
