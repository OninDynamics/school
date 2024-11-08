#include <iostream>
#include <string>
using namespace std;

string ntod(unsigned short num) {
    switch (num) {
        case 0: return "Sunday";
        case 1: return "Monday";
        case 2: return "Tuesday";
        case 3: return "Wednesday";
        case 4: return "Thursday";
        case 5: return "Friday";
        case 6: return "Saturday";
        default: throw out_of_range("ntod()");
    }
}

float weekly_min(float *temps) {
    float min = temps[0];
    for (int i = 0; i < 7; i++) {
        if (min > temps[i]) {
            min = temps[i];
        }
    }

    return min;
}

float weekly_max(float *temps) {
    float max = temps[0];
    for (int i = 0; i < 7; i++) {
        if (max < temps[i]) {
            max = temps[i];
        }
    }

    return max;
}

float weekly_mean(float *temps) {
    float sum = 0;
    for (int i = 0; i < 7; i++) {
        sum += temps[i];
    }

    return sum / 7;
}

int main(int argc, char *argv[]) {

    float temps[7];
    string buf;

    while (true) {
        cout << "\033[2J\033[1;1H"  //Attempts to clear the terminal
            << " === Weekly Temperature Stats ===\n"
            << "Provide temperatures in degrees \u00B0C.\n";

        for (unsigned short day = 0; day < 7; day++) {
            buf.clear();
            while (true) {
                cout << ntod(day) << ": ";
                try {
                    cin >> buf;
                    temps[day] = stof(buf);

                    if (temps[day] < -273.15) {
                        cout << "Below absolute zero, impossible!\n";
                    } else if (temps[day] > 100) {
                        cout << "Surely this temperature wasn't recorded on Earth!\n";
                    } else {
                        break;
                    }
                } catch (invalid_argument) {
                    cout << "That ain't even a number!\n";
                    continue;
                } catch (out_of_range) {
                    cout << "That's way too far!\n";
                    continue;
                }

            }
        }

        cout << "\nMinimum temperature:\t" << weekly_min(temps) << "\u00B0C\n"
            << "Mean temperature:   \t" << weekly_mean(temps) << "\u00B0C\n"
            << "Maximum temperature:\t" << weekly_max(temps) << "\u00B0C\n";
        
        buf.clear();
        cout << "\nTry again? [Y/n] ";
        cin >> buf;
        if (buf == "n" || buf == "N") { break; }
    }
    return 0;
}
