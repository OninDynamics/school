#include <iostream>
#include <string>
using namespace std;

template<typename T>
class DList {
	struct Node {
		T content;
		Node* prev;
		Node* next;
	};

	unsigned int members;
	Node *head, *tail;

	void swap(Node* a, Node* b) {
		T temp = a->content;
		a->content = b->content;
		b->content = temp;
	}

	bool sorted() {
		if (members < 2) { return true; }

		Node* cur = head;

		while (cur->next != nullptr) {
			cerr << "while(cur!=null)\n";
			if (cur->content.prior > cur->next->content.prior) {
				cerr << "while(cur!=null) is false\n";
				return false;
			}
			cur = cur->next;
		}
		return true;
	}

	void sort() {
		if (members > 1) {
			Node* cur = head;

			do {
				cerr << "traversing " << members << " nodes...\n";
				while (cur != head) {
					if (cur->content.prior < cur->next->content.prior) {
						swap(cur, cur->next);
					}
				}
			} while (!sorted());
		}
	}

public:
	void show_all() {
		Node* cur = head;
		if (members != 0) {
			do {
				cout << "\n"<< cur->content.ptos() << ": " << cur->content.name << '\n';
				cur = cur->next;
			} while (cur->next != head);
		}
	}

	void put(T addend) {
		if (members == 0) {
			head = new Node {addend, nullptr, nullptr};
			head->prev = head;
			head->next = head;
			tail = head;
			members++;
		} else {
			Node* next = new Node {addend, tail, nullptr};
			tail = next;
			members++;
			sort();
		}
	}

	void pop(unsigned int id) {
		if (members != 0 && id < members) {
			Node* cur = head;
			unsigned int i = 1;
			while (i <= id) {
				cur = cur->next;
			}
			cur->prev->next = cur->next;
			delete cur;
			members--;
		}
	}

	void pop(string name) {
		if (members != 0) {
			Node* cur = head;
			for (unsigned int i = 0; i < members; cur = cur->next) {
				if (cur->content.name == name) {
					cur->prev->next = cur->next;
					delete cur;
					members--;
				}
			}
		}
	}

	DList() {
		head	= nullptr;
		tail	= nullptr;
		members = 0;
	}
};

enum Priority {
	HIGH= 1,
	MED = 2,
	LOW = 3,
};

struct Task {
	string name;
	Priority prior;

	char ptos() {
		switch (prior) {
			case HIGH: return 'H';
			case MED:  return 'M';
			case LOW:  return 'L';
			default:   return '?';
		}
	}
};

void help() {
	cout << "=== Terrible To-do List ===\n"
		 << "h) Show this help\n"
		 << "s) Show the list\n"
		 << "a) Add a task to the list\n"
		 << "d) Delete a task\n"
		 << "q) Quit\n\n";
}

void new_task(string& buf, DList<Task>& todo) {
	Task new_task;
	cout << "\nName the task: ";
	getline(cin, new_task.name);

	bool input_valid = false;
	do {
		buf.clear();
		cout << "\nAssign a Priority, where 1 is highest and 3 is lowest: ";
		getline(cin, buf);

		try { new_task.prior = static_cast<Priority>(stoi(buf)); input_valid = true;}
		catch (...) {
			cout << "\nInvalid input!";
			continue;
		}
	} while (!input_valid);

	todo.put(new_task);
}

void del_task(string& buf, DList<Task>& todo) {
	
	buf.clear();
	cout << "\nSelect a task to be deleted (number starting at 1, or name): ";
	todo.show_all();
	getline(cin, buf);
	unsigned int id;
	try {
		todo.pop(stoi(buf));
	} catch (...) {
		todo.pop(buf);
	}
}

int main() {
	DList<Task> todo;
	string buf;

	bool exit = false;

	do {
		try {
			buf.clear();
			cout << "\n> ";
			getline(cin, buf);
			switch (buf.at(0)) {
				default:
					help(); break;
				case 's': todo.show_all(); break;
				case 'a': new_task(buf, todo); break;
				case 'd': del_task(buf, todo); break;
				case 'q': exit = true;
			}
		} catch (...) {
			cout << "\nWhoops, an error occurred!\n";
			continue;
		}
	} while (!exit);
	return 0;
}
