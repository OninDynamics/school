#include <vector>
#include <iostream>

using namespace std;

void sort(vector<int>& in_vec) {
	int min = in_vec.at(0), max = in_vec.at(0);

	// Find the minimum and maximum bound.
	// This is O(n).
	for (int i : in_vec) {
		if (i < min) {
			min = i;
		} else if (i > max) {
			max = i;
		}
	}

	// Make a new array that will contain the amounts of
	// each key in the input array. Init values to 0.
	// This is O(1).
	vector<int> distribution = vector<int>( 1 + (max - min) , 0);

	// Count how many of each key is present in the array.
	// This is O(n).
	for (int i : in_vec) {
		distribution.at(i - min)++;
	}

	
	// clear() the in_vec...
	in_vec.clear();

	// ...then repopulate it:

	// For each index of the distribution... (O(k))
	for (int i = min; i <= max; i++) {

		// append the number distribution[i] times. (O(n))
		for (int j = 0; j < distribution.at(i-min); j++) {
			in_vec.push_back(i);
		}
	}

	// ^ The above operation is O(n + k).
}

// adapter for show_vec(sort()).
vector<int>& counting_sort(vector<int>& vec) {
	sort(vec);
	return vec;
}

void show_vec(vector<int> vec) {
	cout << "{ ";
	for (int i : vec) {
		cout << i << " ";
	}
	cout << "}\n";
}

int main(int argc, char *argv[]) {
	cout << "\n=== Counting Sort Test Suite ===\n";

	vector<int> vec1 = {-2, 3, 1, 5, 4};
	cout << "\nInitial Vector: "; show_vec(vec1);
	cout << "Sorted Vector:  "; show_vec(counting_sort(vec1));

	vector<int> vec2 = {0, 3, 1, 5, 2, 4};
	cout << "\nInitial Vector: "; show_vec(vec2);
	cout << "Sorted Vector:  "; show_vec(counting_sort(vec2));

	vector<int> vec3 = {1, 3, 1, 5, 2, 4};
	cout << "\nInitial Vector: "; show_vec(vec3);
	cout << "Sorted Vector:  "; show_vec(counting_sort(vec3));

	vector<int> vec4 = {1};
	cout << "\nInitial Vector: "; show_vec(vec4);
	cout << "Sorted Vector:  "; show_vec(counting_sort(vec4));

	vector<int> vec5 = {0, 1, 2, 3, 4};
	cout << "\nInitial Vector: "; show_vec(vec5);
	cout << "Sorted Vector:  "; show_vec(counting_sort(vec5));

	vector<int> vec6 = {2, 4, 5, 3, 5, 6, 2, 9, 0, -2, -1};
	cout << "\nInitial Vector: "; show_vec(vec6);
	cout << "Sorted Vector:  "; show_vec(counting_sort(vec6));

	cout << "\n=== Counting Sort Test finished! ===\n\n";
}
