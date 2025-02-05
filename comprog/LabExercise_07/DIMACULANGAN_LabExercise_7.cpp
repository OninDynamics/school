#include <iostream>
#include <string>

char gradeLetter(float& gp) {
    unsigned short index = (gp / 10) - 5;  // Convert grade in
                                           // percentage to an integral value.
    switch (index) {
        case 5:    return 'A'; break;
        case 4:    return 'A'; break;
        case 3:    return 'B'; break;
        case 2:    return 'C'; break;
        case 1:    return 'D'; break;
        default:   return 'F'; break;
    }
}

int main(int argc, char *argv[]) {  // Take in console arguments.
                                    // Not required but I like being able to
    float grade;                    // use programs non-interactively :)

    if (argc == 1) {    // If no console arguments, run interactively.
        std::cout << "Input your grade, 0 to 100: ";
        std::string inputStr;
        do {
            std::cin >> inputStr;
            
            // Try/Catch blocks to prevent undefined behaviour (i'm paranoid)
            try { grade = std::stof(inputStr); }
            catch (std::invalid_argument) {
                std::cout << "That's not a number. Quitting...\n";
                return -1;
            }

            if (100 < grade || grade <= 0) {    // Validate input.
                std::cout << "Out of range, try again: ";
            }

        } while (100 < grade || grade <= 0);
    }

    else {    // If console arguments are specified, use the first argument.
        try { grade = std::stof(argv[1]); }
        catch (std::invalid_argument) {
            std::cerr << "[ERROR] Argument is not a number.\n";
            return -1;
        }
        catch (std::out_of_range) {
            std::cerr << "[ERROR] Argument overflows.\n";
            return -1;
        }
    }

    std::cout << "The grade is marked as " << gradeLetter(grade) << ".\n";

    return 0;
}
