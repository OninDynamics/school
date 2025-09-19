/* The best way to solve a problem like this is to simply use a signed integer
 * and use it as an accumulator; using a more advanced data type like a stack
 * is overkill and is detrimental to progrm efficiency.
 *
 * I'll use a stack here, since stacks are use to parse strings into syntax
 * trees. Just for the familiarity. I don't think a queue would've made a
 * difference for applications like counting '('s and ')'s, but it would when
 * we need to actually parse.
 */

// Stacks (at least, the ones i wrote) can dynamically resize
#define DEFAULT_COLLECTION_SIZE 32
// #define DEBUG

#include<iostream>
#include<string>
#include<stdexcept>
#include<cstring> // need this for std::memcpy
				  // C++ needs a rust-like <stdmem> header >:(

template<typename T>
class Stack { // Heap-allocated stack

	unsigned int members, capacity;
	T *arr; // The main array containing the stack
	T *ptr; // object-local stack pointer (must always point to arr)

public:
	unsigned int count() {
		return members;
	}

	void push(T addend) {
		#ifdef DEBUG
			std::cerr << "stack pushing...\n";
		#endif
		if (members < capacity) {
			*ptr = addend;
			ptr++;
			members++;
		} else { // Reallocation routine, makes a new bigger array if input exceeds capacity
			#ifdef DEBUG
				std::cerr << "stack reallocating...\n";
			#endif
			unsigned int old_capacity = capacity;
			unsigned int new_capacity = capacity * 2;
			T* new_arr = new T[new_capacity];
			std::memcpy(new_arr, arr, sizeof(T) * new_capacity);
			delete arr;
			arr = new_arr;
			ptr = arr + members; // pointer arithmetic wizardry
			capacity = new_capacity;
			push(addend);
		}
	}

	T pop() {
		#ifdef DEBUG
			std::cerr << "stack popping...\n";
		#endif
		if (members == 0)
			throw std::length_error("No members in stack.");
		
		members--;
		ptr--;
		return *ptr;
	}

	// Default constructor (32 spaces by default)
	Stack() {
		#ifdef DEBUG
			std::cerr << "new stack with default capacity...\n";
		#endif
		arr = new T[DEFAULT_COLLECTION_SIZE];
		ptr = arr;
		members = 0;
		capacity = DEFAULT_COLLECTION_SIZE;
	}

	// Constructor that allows to specify initial capacity
	Stack(unsigned int capacity) {
		arr = new T[capacity];
		ptr = arr;
		members = 0;
		this->capacity = capacity;
	}

	~Stack() {
		delete arr;
	}
};

bool is_balanced(std::string str) {
	Stack<char> stacc;
	for (char c : str) {
		stacc.push(c);
	}

	int accumulator = 0;

	while(stacc.count() > 0) {
		// inc. and dec. is reversed because we're going right-to-left
		char c = stacc.pop();
		if (c == '(') {
			accumulator--;
		} else if (c == ')') {
			accumulator++;
		}
		if (accumulator < 0) {
			return false;
		}
	}
	return accumulator == 0;
}

int main(int argc, char **argv) {
	std::string buf; // input buffer

	if (argc > 1) {
		buf = argv[1]; // allow argument-based input
		if (is_balanced(buf)) {
			std::cout << "balanced.\n";
		} else {
			std::cout << "not balanced.\n";
		}
		return 0;
	} else {
		while(true) {
			buf.clear();
			std::cout << "\nString to check: ";
			std::getline(std::cin, buf);

			if (is_balanced(buf)) {
				std::cout << "\nBalanced.\n";
			} else {
				std::cout << "\nNot balanced.\n";
			}

			std::cout << "\nContinuing... (Press Ctrl+C to quit.)\n";
		}
		return 0;
	}
}
