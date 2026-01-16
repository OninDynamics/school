#include <iostream>
#include <string>
#include <random>
//#include <chrono>
//#include <thread>
#include <unistd.h>

using namespace std;

class NameRoulette {
	
};

void show(string& i) {
	system("clear");
	cout << '\n' << i;
}

int main(void) {
	random_device r;
	default_random_engine eng(r());
	uniform_int_distribution<unsigned int> uniform_dist(0, ((sizeof(names) / sizeof(string)) - 1));

	for (int i = 0; i < 3; i++) {
		for (string i : names) {
			show(i);
			usleep(10000);
		}
	}
}
