#include <vector>
// #include <stdexcept>

template <typename T>
class BSTree {
	struct Node {
		T content;
		Node* l;
		Node* r;
		Node(T addend) {
			content = addend;
			l = nullptr;
			r = nullptr;
		}
		bool is_leaf() {
			return (l == nullptr) && (r == nullptr);
		}
	};

	Node* root;
	unsigned int members;

	Node* insert(Node* parent, T addend) {
		if (parent == nullptr) {
			return new Node(addend);
			members++;
		}
		if (addend < parent->content) {
			parent->l = insert(parent->l, addend);
		} else if (addend > parent->content) {
			parent->r = insert(parent->r, addend);
		}
		return parent;
	}

	bool exists(Node* parent, T key) {
		if (parent == nullptr) return false;
		if (parent->data == key) return true;
		else if (key < parent->data) return exists(parent->l, key);
		else if (key > parent->data) return exists(parent->r, key);
	}

	Node* find(T key) {
		Node* cur = root;
		while (cur != nullptr) {
			if (cur->content == key) return cur;
			else if (cur->content > key) cur = cur->l;
			else if (cur->content < key) cur = cur->r;
		}
		return nullptr;
	}

	Node* find_parent_of(T key) {
		Node* cur = root;
		while (cur != nullptr) {
			if (cur == root) return root;
			if ((cur->l->content == key) || (cur->r->content == key)) return cur;
			else if (cur->content > key) cur = cur->l;
			else if (cur->content < key) cur = cur->r;
		}
		return nullptr;
	}

	void enum_dec(std::vector<T>& output, Node* cur) {
		if (cur != nullptr) {
			enum_asc(output, cur->l);
			output.push_back(cur->content);
			enum_asc(output, cur->r);
		}
	}

	void enum_asc(std::vector<T>& output, Node* cur) {
		if (cur != nullptr) {
			enum_asc(output, cur->l);
			output.push_back(cur->content);
			enum_asc(output, cur->r);
		}
	}

public:
	void insert(T addend) {
		insert(root, addend);
	}

	bool exists(T key) {
		return exists(root, key);
	}

	void remove(T key) {
		Node* victim = find(key);
		if (victim == nullptr)
			return;

		if (victim->is_leaf()) {
			delete victim;
			members--;
		} else if (victim->l == nullptr) {
			victim->content = victim->r->content;

		}
	}

	// Translate the BSTree into an ordered vector
	std::vector<T> enumerate() {
		std::vector<T> out(members);
		enum_asc(out, root);
		return out;
	}

	BSTree() {
		root = nullptr;
		members = 0;
	}

	// Allow for converting from vectors
	// (yes, static_cast<vector> compatibility)
	BSTree(std::vector<T> in) {
		root = nullptr;
		members = 0;
		for (T i : in) {
			insert(i);
		}
	}
};
