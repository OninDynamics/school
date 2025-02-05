#include <iostream>
#include <string>
#include <curses.h>

enum Operation {
	add,
	sub,
	mul,
	dvd,
};

void bump_stack(double* stack) {
	for (uint8_t i=3; i > 0; i--) {
		stack[i] = stack[i - 1];
	}
}

void display_stack(double* stack) {
	std::cout << "\x1B[2J\x1B[H";

	std::cout << "Current Stack:\n";
	std::cout << "T:\t" << stack[3] << std::endl;
	std::cout << "Z:\t" << stack[2] << std::endl;
	std::cout << "Y:\t" << stack[1] << std::endl;
	std::cout << "X:\t" << stack[0] << std::endl;
}

void arith_stack(double* stack, Operation op) {
	switch (op) {
		case add: stack[0] = stack[1] + stack[0]; break;
		case sub: stack[0] = stack[1] - stack[0]; break;
		case mul: stack[0] = stack[1] * stack[0]; break;
		case dvd: stack[0] = stack[1] / stack[0]; break;
	}

	// Roll the stack down, duplicate T register
	for (uint8_t i=1; i < 3; i++) {
		stack[i] = stack[i + 1];
	}
}

int main() {
	double stack[4];
	std::string buf;
	double scratch;
	
	while(true) {
		std::cin >> buf;
		try {
			scratch = stod(buf);
		} catch (...) {
			switch (buf.at(0)) {
				case '+': arith_stack(stack, add); break;
				case '-': arith_stack(stack, add); break;
				case '*': arith_stack(stack, add); break;
				case '/': arith_stack(stack, add); break;
				default: display_stack(stack);
			}
		}
	}
	return 0;
}
