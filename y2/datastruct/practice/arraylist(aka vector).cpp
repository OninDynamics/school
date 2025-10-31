#include<stdexcept>
#include<cstring>

namespace onind {
	template <typename T>
	class Vector {
		unsigned int members, capacity;
		T* arr;

		bool empty() {
			return members == 0;
		}

		T* reallocate(unsigned int new_size) {
			if (new_size <= members) {
				return arr;
			} else {
				T* new_arr = new T[new_size];
				std::memcpy(new_arr, arr, capacity);
				capacity = new_size;
				delete [] arr;
				return new_arr;
			}
		}

	public:
		T& at(unsigned int id) {
			if (id < capacity) {
				return arr[id];
			} else {
				throw (std::range_error("Attempt to access outside of vector bounds."));
			}
		}

		T& operator[](unsigned int id) {
			return at(id);
		}

		Vector(unsigned int i) {
			arr = new T[i];
			capacity = i;
		}

		Vector() {
			arr = new T[16];
			capacity = 16;
		}

		~Vector() {
			delete [] arr;
		}
	};
}
