/* Program to convert between fahrenheit and celsius. Divided into three+1 functions:
 *
 * "in_temp" FUNCTION:
 * Grabs value from stdin then validates it for use as a double
 *
 * "ctof" FUNCTION:
 * Takes a celsius value of type double and returns a fahrenheit value of type double.
 *
 * "ftoc" FUNCTION:
 * Takes a fahrenheit value of type double and returns a celsius value of type double.
 *
 * Main Function executes main program loop.
 */

#include <iostream> // for I/O
#include <string>   // for parsing input

// I'm using #define to hardcode this. A string variable would take 6 bytes
// in memory.
#define VERSION "1.0.0"

double in_temp() {
    // Use buffer object to story any data, valid or invalid
    std::string buf;
    double t;
    
    while (true) {
        try {
            std::cin >> buf;
            t = std::stod(buf);
        } catch (std::invalid_argument) {   // This runs if data is invalid
            std::cout << "Not a number, try again: ";
            continue;   // Start the loop over without reaching the break
        }
        break;
    }
    return t;
}

double ctof(double c) {
    // Celsius to Fahrenheit formula
    return ((c * 1.8) + 32);
}

double ftoc(double f) {
    // Fahrenheit to Celsius formula
    return ((f - 32) / 1.8);
}

int main(int argc, char *argv[]) {

    // Might as well act like an actual program...
    std::cout << "Temperature Converter " << VERSION << "\n";
    
    bool repeat = true; // Sentinel for the while loop

    std::string buf;    // Again, buffer for storing potentially invalid data
    short opt;          // Doesn't need to be a full int

    double result;      // Reserve memory for calculation result

    //  ================BEGIN LOOP================
    while (repeat) {
        std::cout << "\nSelect a conversion type."
            << "\n(1) Celsius to Fahrenheit"
            << "\n(2) Fahrenheit to Celsius"
            << "\n(3) Exit program"
            << "\n(1, 2, or 3): ";

        std::cin >> buf;

        try {
            opt = std::stoi(buf);
            if (opt < 1 || opt > 3) {
                throw std::out_of_range("");    // Throw exception if not in options
            }
        } catch (std::invalid_argument) {   // This runs if user inputs non-integer
            std::cerr << "\nA number between 1 and 2, please...\n";
            continue;
        } catch (std::out_of_range) {       // This runs if user inputs out-of-range
            std::cerr << "\nJust 1, 2, or 3, please...\n";
        }

        switch (opt) {
            case 1:
                std::cout << "\nProvide temperature in celsius to convert: ";
                result = ctof(in_temp());   /* Get and validate input,and convert
                                               it to fahrenheit in this case */
                std::cout << "\nTemperature in fahrenheit is: " << result
                    << "°F. Returning to menu...\n ";
                break;

            case 2:
                std::cout << "\nProvide temperature in fahrenheit to convert: ";
                result = ftoc(in_temp());
                std::cout << "\nTemperature in celsius is: " << result
                    << "°C. Returning to menu...\n ";
                break;
            case 3: repeat = false; // Set sentinel to false and end the loop
        }
    }
    //  ================END LOOP================

    // All errors are handled (afaik), so main() always returns 0
    return 0;
}
