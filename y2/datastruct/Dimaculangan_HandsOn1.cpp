#define USER_PROMPT "> "
#include <iostream>
#include <string>

template <typename T>
class LList {
	struct Node {
		T content;
		Node* next;
	};

	Node* head;
	unsigned int members;

public:

	void show_items() {
		std::cout << "\n=== Your Shopping Cart ===\n";
		if (members != 0) {
			Node* iter = head;
			
			float total = 0;
			while (iter->next != nullptr) {
				total += iter->content.price;
				iter->content.show_item();
				iter = iter->next;
			}
			total += iter->content.price;
			iter->content.show_item();
			std::cout << "Total: " << total << "PHP\n";
		} else {
			std::cout << "\nYour cart is empty!\n";
		}
	}

	void append_head(T addend) {
		if (members == 0) {
			head = new Node;
			head->content = addend;
			head->next = nullptr;
		} else {
			Node* new_head = new Node;
			new_head->content = addend;
			new_head->next = head;
			head = new_head;
		}
		members++;
	}

	void remove_head() {
		if (members == 0) return;
		else {
			Node* old_head = head;
			head = head->next;
			delete old_head;
			members--;
		}
	}

	LList() {
		members = 0;
		head = nullptr;
	}

};

struct ShopItem {
	std::string name;
	float price;

	void show_item() {
		std::cout << "PHP" << price << ": \"" << name << "\"\n";
	}
};

ShopItem new_item() {
	ShopItem new_item;
	std::string buf;
	std::cout << "\nName your item: ";
	std::getline(std::cin, buf);

	new_item.name = buf;

	while (true) {
		buf.clear();
		std::cout << "Provide a price: ";
		std::getline(std::cin, buf);
		try {
			new_item.price = std::stof(buf);
			std::cout << "\nNew Item \"" << new_item.name
				<< "\" worth " << new_item.price << "PHP.\n";
			break;
		} catch (...) {
			std::cout << "\nThat's not a valid price! (Numbers only!)";
			continue;
		}

	}

	return new_item;
}

void show_menu() {
	std::cout << "\nActions:"
		<< "\n1) Show this menu"
		<< "\n2) Add an item"
		<< "\n3) Show current cart"
		<< "\n4) Remove last item"
		<< "\n5) Checkout and quit"
		<< '\n' << USER_PROMPT;
}

int main() { 
	std::string buf;
	std::cout << "=== Extremely Basic Shopping Cart :D ===";

	LList<ShopItem> cart = LList<ShopItem>();

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
				cart.append_head(new_item()); break;
			case 3:
				cart.show_items(); break;
			case 4:
				cart.remove_head(); break;
			case 5:
				std::cout << "\n=== Final Cart ===\n";
				cart.show_items();
				std::cout << "\n===  Goodbye!  ===\n";
				return 0;
		}
	}

	return 0;
}
