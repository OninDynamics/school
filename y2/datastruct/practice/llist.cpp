#include <stdexcept>

namespace onind {
	template <typename T>
	class ICollection {
		virtual T operator[](unsigned int &id) { return at(id); }
		virtual T at(unsigned int &id) = 0;
	};

	// Singly Linked List
	template <typename T>
	class SList : private ICollection<T> {
		unsigned int members;

		struct Node {
			T content;
			Node* next;
		};

		Node* head;
		Node* tail;

		Node* index(unsigned int &index) {
			Node* cur = head;

			if (index > members) {
				throw (std::out_of_range("Index out of bounds."));
				return nullptr;
			}

			if (members == 0 || head == nullptr) {
				throw (std::length_error("List is empty."));
				return nullptr;
			}

			for (unsigned int i; i < index; i++) {
				if (cur->next == nullptr) {
					return cur;
				} else {
					cur = cur->next;
				}
			}
		}

		/*
		char check() {
			char out = 0b00000000;
			if ( (members == 0) != (head == nullptr) )
				out += 0b00000001;

			return out;
		}*/

	public:
		T at(unsigned int &id) {
			Node* a = index(id);
			return a->content;
		}

		Node operator[] (unsigned int index) {
			return at(index);
		}

		Node* append(T addend) {
			members++;

			if (head == nullptr) {
				Node* head = new Node;

				head->content = addend;
				head->next = nullptr;

				tail = head;
				return head;
			} else {
				Node* new_node = new Node;
				tail->next = new_node;

				new_node->content = addend;
				new_node->next = nullptr;

				tail = new_node;
				return new_node;
			}
		}

		void remove(Node* subtrahend) {
			Node* next_node = subtrahend->next;
			Node* prev_node = head;

			while (prev_node->next != subtrahend) {
				prev_node = prev_node->next;
			}

			prev_node->next = next_node;
			delete subtrahend;
			members--;
		}

		SList() {
			head = nullptr;
			tail = head;
			members = 0;
		}

		SList(T& initial) {
			head = new Node;
			head->content = initial;
			head->next = nullptr;
			tail = head;
			members = 1;
		}

		~SList() {
			Node* cur = head;
			Node* nxt;

			while (cur->next != nullptr) {
				nxt = cur->next;
				delete cur;
				cur = nxt;
			}
			delete cur;
		}
	};
}

int main() {
	onind::SList<int> list;
	list.append(8);
	return 0;
}
