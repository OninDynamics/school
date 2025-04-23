/* Alright, now onto the first pillar of OOP:
 *          A B S T R A C T I O N           *
 * 
 * If you're a tiny bit advanced already, Abstraction is already present in
 * this class from the previous lesson: */

class Square {
	float side_length = 1.0f;
public:
	Square() {}
	float perimeter() {
		return side_length * 4;
	}
};

/* Noticed something? Instead of manually having to do something like...
 *------------------------------+
 | cout << (s1.side_length * 4) |
 *------------------------------+
 *
 * ... we just need to do this!
 *------------------------+
cout << s1.perimeter()
 *------------------------+
 *
 * This is the basis behind ABSTRACTION, where things are implemented in a way
 * that allows us "hide" the code away, and lets us use its functionality in
 * a more abstract way.
 *
 * "wtf is abstract?"
 *
 * For example, this is not abstract (getting the tail of a linked list):
 *--------------------------------+
 * int* list_tail = list_head;    |
 * while (list_tail != nullptr) { |   (confusing, right?)
 *     list_tail = li->next;      |
 * }                              |
 *--------------------------------+
 *
 * However, THIS is abstract:
 *-------------------------------+
 * int* list_tail = list.tail(); |    (much easier to understand!)
 *-------------------------------+
 */

// Okay then, let's implement a simple linked list of ints;

class onind_llist {
	struct node {
		int  content;
		node* next;
	};

	node* head;
	node* current;

	node* tail() {
		while (current->next != nullptr) {
			current = current->next;
		}
		return current;
	}

public:
	// Sets the properties of the first node, as soon as a new list is created
	onind_llist(int content) {
		head = new node;
		current = head;
		head->next = nullptr;
	}

	// Method to add +1 node to the end of the list.
	void append(int i) {

		if (current->next != nullptr)
			tail();

		node* new_node = new node;
		new_node->content = i;
		new_node->next    = nullptr;
		current = new_node;
	}

	// Method to remove the last node of the list.
	void pop_back() {
		if (current->next != nullptr)
			tail();

		delete current;
		tail();
	}
};

int main() {
	onind_llist sample_list = onind_llist(1);

	sample_list.append(45);
	return 0;
}
