template<typename T>
class ICList {
public:
	void push_head(T) = 0;
	void push_tail(T) = 0;
	void insert_into(T) = 0;

	T pop_head() = 0;
	T pop_tail() = 0;
	T delete_from() = 0;
};

template<typename T>
class SCList : private ICList<T> {
	struct Node {
		T content;
		Node* next;
	};

	unsigned int members;
	Node* head, tail;

public:
	void push_tail(T addend) {
		if (members == 0) {
			Node* new_node = new Node{addend, nullptr};
			head = new_node;
			tail = new_node;
			new_node->next = head;
			members++;
		} else {
			Node* new_node = new Node{addend, head};
			tail->next = new_node;
			tail = new_node;
			members++;
		}
	}

	void push_head(T addend) {
		if (members == 0) {
			Node* new_node = new Node{addend, nullptr};
			head = new_node;
			tail = new_node;
			new_node->next = head;
			members++;
		} else {
			Node* new_node = new Node{addend, head};
			head = new_node;
			tail->next = new_node;
			members++;
		}
	}

	SCList() {
		members = 0;
		head = nullptr;
		tail = nullptr;
	}
};

int main() {
}
