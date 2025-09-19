#define CLI_PROMPT "\n> "

#include <iostream>
#include <string>
#include <stdexcept>

template<typename T>
class CDLList {
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

using namespace std;

void opt() {
	cout << "\n=== Options ===\n"
		 << "h) Show this Help\n"
		 << "a) Add a Character to the End of the Roster\n"
		 << "d) Delete the First Character\n"
		 << ">) Show Next Character\n"
		 << "<) Show Prev Character\n"
		 << "q) Quit Program\n";
}

int main() {
	string buf;
	CDLList<string> list;

	bool cli_continue = true;

	cout << "\n=== Extremely Rudimentary Character Manager ===\n"
		 << "                   (h for help)\n";

	do {
		buf.clear();
		cout << CLI_PROMPT;

		getline(cin, buf);

		char option;
		try {
			option = buf.at(0);
		} catch (...) {
			cout << "\nWhoops, an input error occurred!\n";
			continue;
		}

		// monstrous heckig switch statement
		switch (option) {
			case 'a':
				buf.clear();
				cout << "Character Name: ";
				getline(cin, buf);
				list.push_tail(buf);
				cout << "Character Added: " << buf << '\n';
				break;

			case 'd':
				try {
					string bye = list.pop_head();
					cout << "\nDeleted Character: " << bye << '\n';
				} catch (length_error e) { cout << "(No characters!)\n"; }
				buf.clear();
				break;

			case '<':
				buf.clear();
				cout << "Prev. Character: ";
				try { cout << list.prev(); }
				catch (length_error e) { cout << "(No characters!)"; }
				cout << '\n';
				break;

			case '>':
				buf.clear();
				cout << "Next Character: ";
				try { cout << list.next(); }
				catch (length_error e) { cout << "(No characters!)"; }
				cout << '\n';
				break;

			case 'q':
				cout << "\n\n=== Farewell! ===\n";
				cli_continue = false;
				break;

			default:
				opt();
				break;
		}
	} while (cli_continue);
}
