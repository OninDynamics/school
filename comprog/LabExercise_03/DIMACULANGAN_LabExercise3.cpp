#include <iostream>
#include <string>

void say(std::string day) {
    std::cout << "You picked " << day << "\n\n";
}

int main(int argc, char **argv) {
    short num = 0;

    while ((num < 1) || (num > 7)) {
        std::cout << "Provide an integer from 1 to 7: ";
        std::cin >> num;

        if ((num < 1) || (num > 7)) {
            std::cout << "\nYou are out of bounds, try again.\n\n";
        }
    }

    switch (num) {
        case 1:
            say("Sunday");
            break;
        case 2:
            say("Monday");
            break;
        case 3:
            say("Tuesday");
            break;
        case 4:
            say("Wednesday");
            break;
        case 5:
            say("Thursday");
            break;
        case 6:
            say("Friday");
            break;
        case 7:
            say("Saturday");
            break;
    }
            return 0;
}
