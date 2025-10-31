#include <iostream>

template <typename T>
class BSTree {
private:
	struct Node {
		T data;
		Node* lhs;
		Node* rhs;

		bool is_leaf() {
			return lhs == nullptr && rhs == nullptr;
		}
	};

	unsigned int members;
	Node* root;

	void insert(T addend, Node* cur) {
		// this makes me feel like yanderedev
		if (addend < cur->data && cur->lhs == nullptr) {
			cur->lhs = new Node{addend, nullptr, nullptr};
			members++;
		} else if (addend > cur->data && cur->rhs == nullptr) {
			cur->rhs = new Node{addend, nullptr, nullptr};
			members++;
		} else if (addend < cur->data && cur->lhs != nullptr) {
			insert(addend, cur->lhs);
		} else if (addend > cur->data && cur->rhs != nullptr) {
			insert(addend, cur->rhs);
		}
	}

	void leafcount(Node* cur, unsigned int& count) {
		if (cur != nullptr) {
			leafcount(cur->lhs, count);
			if (cur->is_leaf()) count++;
			leafcount(cur->rhs, count);
		}
	}

	void depth(Node* cur, int& count, int edges) {
		if (cur != nullptr) {
			depth(cur->lhs, count, edges++);
			if (edges > count) count = edges;
			depth(cur->rhs, count, edges++);
		}
	}

	void inorder(Node* cur) {
		if (cur != nullptr) {
			inorder(cur->lhs);
			std::cout << cur->data << ' ';
			inorder(cur->rhs);
		}
	}

	T minimum(Node* cur) {
		if (cur != nullptr) {
			if (cur->lhs == nullptr)
				return cur->data;
			else
				return minimum(cur->lhs);
		} else throw new std::logic_error("this must not happen.");
										  // this is an invalid state.
										  // The program MUST crash.
	}

	T maximum(Node* cur) {
		if (cur != nullptr) {
			if (cur->rhs == nullptr)
				return cur->data;
			else
				return maximum(cur->rhs);
		} else throw new std::logic_error("this must not happen.");
	}

public:
	void nodes() {
		std::cout << "\nThere are " << members << " nodes.\n";
	}

	void leaves() {
		unsigned int count = 0;
		if (root == nullptr)
			std::cout << "\nBST is empty.\n";
		else {
			leafcount(root, count);
			std::cout << "\nThere are " << count << " leaves.\n";
		}
	}

	void min() {
		if (root == nullptr)
			std::cout << "\nBST is empty.\n";
		else {
			std::cout << "\nMinimum item is " << minimum(root) << ".\n";
		}
	}
	
	void max() {
		if (root == nullptr)
			std::cout << "\nBST is empty.\n";
		else {
			std::cout << "\nMaximum item is " << maximum(root) << ".\n";
		}
	}

	void inorder() {
		std::cout << "\nOrdered contents of the BST:\n";
		inorder(root);
		std::cout << '\n';
	}

	void insert(T addend) {
		if (root == nullptr) {
			root = new Node{addend, nullptr, nullptr};
			members++;
			return;
		} else {
			insert(addend, root);
		}
	}

	void height() {
		int count = -1;
		depth(root, count, -1);
		std::cout << "\nThe BST is " << count << " edges tall.\n";
	}

	BSTree() {
		root = nullptr;
		members = 0;
	}
};

void help() {
	std::cout << "\n=== BasicBST ==="
			  << "\na) Add a node"
			  << "\nm) Get Minimum Value"
			  << "\nM) Get Maximum Value"
			  << "\ne) Enumarate all Values in order"
			  << "\nn) Count all nodes"
			  << "\nl) Count all leaf nodes"
			  << "\nh) Get BST height"
			  << "\nq) Quit Program"
			  << '\n';
}

void wrappin(BSTree<int>& bst) {
	std::string buf;
	std::cout << "\nProvide an integer: ";
	std::getline(std::cin, buf);
	try {
		bst.insert(std::stoi(buf));
	} catch (...) {
		std::cout << "\nInput invalid.\n";
	}
}

#include<string>
int main(void) {
	std::string buf;
	BSTree<int> bst;
	bool run = true;

	while(true) {
		buf.clear();
		std::cout << "\n> ";
		try {
			std::getline(std::cin, buf);
			switch(buf.at(0)) {
				case 'a': wrappin(bst); break;
				case 'm': bst.min(); break;
				case 'M': bst.max(); break;
				case 'l': bst.leaves(); break;
				case 'n': bst.nodes(); break;
				case 'e': bst.inorder(); break;
				case 'h': bst.height(); break;
				case 'q': return 0; break;
				default: help(); break;
			}
		} catch (std::out_of_range e) {
			help();
			continue;
		}
	}
}
