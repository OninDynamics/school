#include "onind_collections.h"
#include <stdexcept>

namespace onind {
	template<typename T>
	class CDLList : private ICollection<T> {
		struct Node {
			T content;
			Node* prev;
			Node* next;
		};

		unsigned int members;
		Node* head;
		Node* tail;
		Node* cur;
		
	public:
		T pop_head() {
			if (members == 0) {
				throw std::length_error("List is empty.");
			}

			T popped = head->content;
			Node* old_head = head;
			Node* new_head = head->next;
			head = new_head;
			delete old_head;

			tail->next = head;
			members--;
			return popped;
		}

		void push_tail(T addend) {
			if (members == 0) {
				Node* new_item = new Node { addend, nullptr, nullptr };
				head = new_item;
				tail = new_item;
				cur  = new_item;
				members++;
			} else {
				Node* new_item = new Node { addend, tail, head };
				tail->next = new_item;
				head->prev = new_item;
				tail = new_item;
				members++;
			}
		}

		void push_head(T addend) {
			if (members == 0) {
				Node* new_item = new Node { addend, nullptr, nullptr };
				head = new_item;
				tail = new_item;
				cur  = new_item;
				members++;
			} else {
				Node* new_item = new Node { addend, tail, head };
				tail->next = new_item;
				head->prev = new_item;
				head = new_item;
				members++;
			}
		}

		T get_cur() {
			if (members == 0) {
				throw (std::length_error("List is empty."));
			}
			return cur->content;
		}

		T prev() {
			if ( members == 0 ) {
				throw (std::length_error("List is empty."));
			} else if ( members > 1 && cur == nullptr ) {
				cur = head;
			} else {
				cur = cur->prev;
			}

			return cur->content;
		}

		T next() {
			if ( members == 0 ) {
				throw (std::length_error("List is empty."));
			} else if ( members > 1 && cur == nullptr ) {
				cur = head;
			} else {
				cur = cur->next;
			}

			return cur->content;
		}

		CDLList() {
			head    = nullptr;
			tail    = nullptr;
			cur     = nullptr;
			members = 0;
		}
	};
}
