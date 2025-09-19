#define DEFAULT_COLLECTION_SIZE 32

#include<cstring>

template<typename T>
class Stack { // Heap-allocated stack

	unsigned int members, capacity;
	T *arr; // The main array containing the stack
	T *ptr; // object-local stack pointer (must always point to arr)

public:
	void push(T addend) {
		if (members < capacity) {
			*ptr = addend;
			ptr++;
			members++;
		} else {
			T* new_arr = new T[capacity * 2];
			std::memcpy(new_arr, arr, sizeof(arr));
			delete arr;
			arr = new_arr;
			ptr = arr[members - 1];
			push(addend);
		}
	}

	T pop() {
		if (members == 0)
			return;

		
		ptr--;
		T popped
	}

	// Default constructor (32 spaces by default)
	Stack() {
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
};
