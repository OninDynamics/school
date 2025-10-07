/* ...yes, this is a fork of HandsOn1.
 * It's probably much more robust, though. One could probably extract all this
 * into separate header + source files, inside a namespace like "onind-coll" or
 * something... one can dream.
 * 
 * If I have some excess motivation, I might put a source + header somewhere
 * in here: https://github.com/OninDynamics/school/tree/master/y2/datastruct/
 *
 * (I share my code with my classmates to teach them. I don't push exams to
 * GitHub until past the deadline... unless I get too excited. Surely my git
 * log would be some evidence... hopefully)
 */

#define USER_PROMPT "> "
#include <iostream>
#include <string>

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
		} else if (members == 1) {
			Node* old_tail = tail;
			T popped = old_tail->content;
			delete old_tail;
			head = nullptr;
			members--;
			return popped;
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
		} else if (members == 1) {
			Node* old_head = head;
			T popped = old_head->content;
			delete old_head;
			head = nullptr;
			members--;
			return popped;
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

	void list_forward() {
		std::cout << "\nShowing List...\n";
		if (empty()) {
			std::cout << "The list is empty!\n";
		} else {
			Node* cur = head;
			while (cur != nullptr) {
				if (cur == head) {
					std::cout << "NEXT:\t" << cur->content << "\n";
				} else if (cur == tail) {
					std::cout << "LAST:\t" << cur->content << "\n";
				} else {
					std::cout << "\t" << cur->content << "\n";
				}

				cur = cur->next;
			}
		}
	}

	void list_backward() {
		std::cout << "\nShowing List...\n";
		if (empty()) {
			std::cout << "The list is empty!\n";
		} else {
			Node* cur = tail;
			while (cur != nullptr) {
				if (cur == head) {
					std::cout << "NEXT:\t" << cur->content << "\n";
				} else if (cur == tail) {
					std::cout << "LAST:\t" << cur->content << "\n";
				} else {
					std::cout << "\t" << cur->content << "\n";
				}
				cur = cur->prev;
			}
		}
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
		<< "\n4) Show What's Next"		// Forward traverse
		<< "\n5) Show Latest Additions" // Reverse traverse
		<< "\n6) Remove Next Song"		// Remove First
		<< "\n7) Remove Last Addition"	// Remove Last
		<< "\n8) Quit program"
		<< '\n' << USER_PROMPT;
}

std::string new_item() {
	std::string buf;
	std::cout << "\nProvide a song name: ";
	std::getline(std::cin, buf);
	return buf;
}

int main() { 
	std::string buf;
	std::cout << "=== Extremely Basic Playlist Manager :D ===";

	DList<std::string> playlist = DList<std::string>();

	int action = 0;
	while ( action != 8) {
		show_menu();
		buf.clear();
		std::getline(std::cin, buf);
		try { action = std::stoi(buf);}
		catch (...) {
			std::cout << "invalid arg\n";
			continue;
		}
		try {
			switch (action) {
				case 2:
					playlist.push_front(new_item()); break;

				case 3:
					playlist.push_back(new_item()); break;

				case 4:
					playlist.list_forward(); break;

				case 5:
					playlist.list_backward(); break;

				case 6:
					std::cout << "\nRemoved song: \"" << playlist.pop_front() << "\"\n";
					break;

				case 7:
					std::cout << "\nRemoved song: \"" << playlist.pop_back() << "\"\n";
					break;

				case 8:
					std::cout << "\n=== Final List ===\n";
					playlist.list_forward(); break;
					std::cout << "\n==== Goodbye! ====\n";
					return 0;
			}
		} catch (std::exception& e) {
			std::cout << "\n=== Whoops! ERROR: " << e.what() << " ===\n";
			continue;
		}
	}

	return 0;
}
