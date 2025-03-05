/*/ Definition of a list node
struct ll_node<T> {
	T content;
	ll_node<T>* next;
	// next is a nullptr if it's the end node
};

// Function to get to an end node
ll_node<T>* ll_end(ll_node<T> node) {
	if (node.next != nullptr) {
		// Run ll_end on the next node if this isn't the end node
		return ll_end( &(node.next) );
	} else {
		// Return the end node (end nodes have nullptr in their "next" member)
		return node;
	}
}

// Overloaded function, so the programmer can pass
// either a node, or a pointer to a node to the function
ll_node<T>* ll_end(ll_node<T>* node) {
	if (node->next != nullptr) {
		return ll_end( node->next );
	} else {
		return node;
	}
}*/





#define MAX_ITERATIONS 100	// Limit to amount of iterations needed
#define LIMIT 5				// If Z exceeds a distance than LIMIT to the
							// origin (0,0), C is not part of the set.

#include <complex>			// Use the <complex> library for complex numbers

using namespace std;

// If the point C exceeds value, consider it not part of the mandelbrot set, so
// return false. If max iterations are reached without exceeding LIMIT,
// consider point as part of set, so return true.
bool mandel(complex<double> z, complex<double> c, unsigned int iters) {

	// Check if max iterations achieved, and z is still within limit
	if (iters >= MAX_ITERATIONS && abs(z) < LIMIT ) {
		return true;
	
	// If z ever exceeds LIMIT, immediately return false
	} else if ( abs(z) > LIMIT ) {
		return false;
	}

	// If iteration limit still not achieved, continue iteration

	z = (z*z) + c;	// Equation of the Mandelbrot Set
	return mandel(z, c, iters++);
}

// The mandel() function should be called as follows:
complex<double> point;
bool is_part_of_set = mandel( complex<double>(0,0), point, 0 );
// ...where "point" contains the complex point being tested.







