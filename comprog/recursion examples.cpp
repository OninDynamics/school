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






#DEFINE MAX_ITERATIONS 1000

// If the point is part of the mandelbro
bool 
