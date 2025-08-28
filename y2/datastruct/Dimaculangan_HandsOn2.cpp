// ...yes, this is a fork of HandsOn1.

#define USER_PROMPT "> "
#include <iostream>
#include <string>
#include <vector>

template <typename T>
class DList {
	struct Node {
		T content;
		Node* prev;
		Node* next;
	};

	Node* head;
	Node* tail;
	unsigned int members;

	void first_item(T addend) {
		Node* new_node = new Node {
			addend,
			nullptr,
			nullptr
		};
		head = new_node;
		tail = new_node;
		members++;
	}

public:

	bool empty() {
		return (members == 0);
	}

	unsigned int size() {
		return members;
	}

	void push_front(T addend) {
		if (members == 0) {
			first_item(addend);
		} else {
			Node* new_node = new Node {
				addend,
				nullptr,
				head
			};
			head->prev = new_node;
			head = new_node;
			members++;
		}
	}

	void push_back(T addend) {
		if (members == 0) {
			first_item(addend);
		} else {
			Node* new_node = new Node {
				addend,
				tail,
				nullptr
			};
			tail->next = new_node;
			tail = new_node;
			members++;
		}
	}

	T pop_back() {
		if (empty()) {
			throw (std::length_error("List is empty."));
		} else {
			Node* old_tail = tail;
			T popped = old_tail->content;
			
			tail = tail->prev;
			tail->next = nullptr;

			delete old_tail;
			members--;
			return popped;
		}
	}

	T pop_front() {
		if (empty()) {
			throw (std::length_error("List is empty."));
		} else {
			Node* old_head = head;
			T popped = old_head->content;
			
			head = head->next;
			head->prev = nullptr;

			delete old_head;
			members--;
			return popped;
		}
	}

	void show() {
		if (empty()) {
			std::cout << "\nThe list is empty!\n";
		} else {
			Node* cur = head;

		}
	}
}

	std::vector<T> vectorize() {
	}

	DList() {
		members = 0;
		head = nullptr;
		tail = nullptr;
	}

};

void show_menu() {
	std::cout << "\nActions:"
		<< "\n1) Show this menu"
		<< "\n2) Add to Play Next"
		<< "\n3) Add to Queue"
		<< "\n4) Show current playlist"
		<< "\n5) Remove first item (Start)"
		<< "\n6) Remove last item (End)"
		<< "\n7) Quit program"
		<< '\n' << USER_PROMPT;
}

int main() { 
	std::string buf;
	std::cout << "=== Extremely Basic Playlist Manager :D ===";

	DList<std::string> playlist = DList<std::string>();

	int action = 0;
	while ( action != 5 ) {
		show_menu();
		buf.clear();
		std::getline(std::cin, buf);
		try { action = std::stoi(buf);}
		catch (...) {
			std::cout << "invalid arg\n";
			continue;
		}
		switch (action) {
			case 2:
				playlist.push_front(new_item()); break;
			case 3:
				playlist.show_items(); break;
			case 4:
				playlist.remove_head(); break;
			case 5:
				std::cout << "\n=== Final List ===\n";
				playlist.show_items();
				std::cout << "\n==== Goodbye! ====\n";
				return 0;
		}
	}

	return 0;
}
