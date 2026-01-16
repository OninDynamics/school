#include <string>
#include <iostream>

class BSTree {
	struct Node {
		float price;
		std::string name;
		Node *lhs, *rhs;
		bool leaf() {
			return lhs == nullptr && rhs == nullptr;
		}
	};

	Node* root;

	Node* search(Node* cur, float key) {
		if (cur == nullptr) return nullptr;
		if (cur->price > key) return search(cur->lhs, key);
		if (cur->price < key) return search(cur->rhs, key);
		if (cur->price == key) return cur;
		else return nullptr;
	}

	void insert(Node* cur, float price, std::string name) {
		if (root == nullptr) {
			root = new Node{price, name, nullptr, nullptr};
			std::cout << "\nKey Inserted: \""
					  << root->name
					  << "\" for $"
					  << root->price
					  << "\n";
			return;
		}

		if (cur->price == price) {
			std::cout << "\nNo insertion. Key already exists:\n"
					  << '"' << cur->name << "\" for $" << cur->price << '\n';
		} else if (cur->price < price && cur->rhs == nullptr) {
			cur->rhs = new Node{price, name, nullptr, nullptr};
			std::cout << "\nKey Inserted: \""
					  << cur->rhs->name
					  << "\" for $"
					  << cur->rhs->price
					  << "\n";
		} else if (cur->price > price && cur->lhs == nullptr) {
			cur->lhs = new Node{price, name, nullptr, nullptr};
			std::cout << "\nKey Inserted: \""
					  << cur->lhs->name
					  << "\" for $"
					  << cur->lhs->price
					  << "\n";
		} else if (cur->price < price && cur->rhs != nullptr) {
			insert(cur->rhs, price, name);
		} else if (cur->price > price && cur->lhs != nullptr) {
			insert(cur->lhs, price, name);
		}
	}

	void revorder(Node* cur) {
		if (cur != nullptr) {
			revorder(cur->rhs);
			std::cout << '\"' << cur->name << "\" for $" << cur->price << "\n";
			revorder(cur->lhs);
		}
	}

	void inorder(Node* cur) {
		if (cur != nullptr) {
			inorder(cur->lhs);
			std::cout << '\"' << cur->name << "\" for $" << cur->price << "\n";
			inorder(cur->rhs);
		}
	}

	// i've never managed to set things to nullptr after deleting the leaf raagh
	Node* get_parent_of_lowest(Node* cur) {
		if (cur->lhs != nullptr)
			return get_parent_of_lowest(cur->lhs);
		if (cur->lhs->lhs == nullptr)
			return cur;
	}

	Node* get_parent_of_highest(Node* cur) {
		if (cur->rhs != nullptr)
			return get_parent_of_highest(cur->lhs);
		if (cur->rhs->rhs == nullptr)
			return cur;
	}

public:
	void search(float key) {
		Node* a = search(root,key);
		if(a != nullptr) {
			std::cout << "\nKey Found: \""
					  << a->name
					  << "\" for $"
					  << a->price;
		} else {
			std::cout << "\nKey not found!\n";
		}
	}

	void insert() {
		std::string buf;
		std::cout << "\n[INS] Provide a price: ";
		buf.clear();
		std::getline(std::cin, buf);
		float price;
		try {
			price = std::stof(buf);
		} catch (...) {
			std::cout << "\n[ERR] Invalid price!\n";
			return;
		}
		std::cout << "\n[INS] Name the product: ";
		buf.clear();
		std::getline(std::cin, buf);
		
		insert(root, price, buf);
	}

	void inorder() {
		inorder(root);
	}

	void preorder() {
		inorder(root);
	}

	void postorder() {
		revorder(root);
	}

	BSTree() {
		root = nullptr;
	}
};

void instructions() {
	std::cout << "\n\n[HLP] Instructions:"
			  << "\n[HLP] i) Insert a new item."
			  << "\n[HLP] o) View the tree in order."
			  << "\n[HLP] r) View the tree in reversed order."
			  << "\n[HLP] d) Delete an item by price."
			  << "\n";
}

int main(int argc, char** argv) {
	std::string buf;
	BSTree t;

	bool run = true;
	instructions();
	while(run) {
		std::cout << "\n> ";
		buf.clear();
		std::getline(std::cin, buf);
		switch (buf.at(0)) {
			case 'i':
				t.insert();
				break;
			case 'o':
				t.inorder();
				break;
			case 'r':
				t.postorder();
				break;
			case 'd':
				std::cout << "\n[SRY] Deletion is not implemented, sorry!";
				break;
			default:
				instructions();
				break;
		}

	}
	return 0;
}
