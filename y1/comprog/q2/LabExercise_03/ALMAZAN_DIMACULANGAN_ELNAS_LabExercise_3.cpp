/* Written by:	Dimaculangan, Gionne Niño P.
 *				Almazan, Christian Lesbert N.
 * at Time(UTC):2025-01-22T13:34:00+08:00
 * Description:
 * Onin was about to sleep until Vhanna asked him about this whole thing
 *
 * A lot of the cli logic is copied from Onin's previous works, perhaps
 * he should turn it into a header file
 *
 * Nothing else much to say, really
 */

#define PROMPT "> "	// Want to change the cli prompt? Change it here

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Every possible action
enum Action {
	_,			// display help by default
	newacc,		// new account
	list,		// list all registered accounts
	wdrw,		// withdraw money
	dpst,		// deposit money
	bal,		// balance inquiry
	quit,		// idk what this does
};

Action ParseAction(char c) {
	switch ( tolower(c) ) {
		case 'n': return newacc;
		case 'l': return list;
		case 'd': return dpst;
		case 'w': return wdrw;
		case 'b': return bal;
		case 'q': return quit;
		default: return _;
	}
}


void help() {
	cout << "\n ======= Available commands: =======\n"
		 << " h:\tRead this help\n"
		 << " n:\tCreate a New Account\n"
		 << " l:\tList all accounts\n"
		 << " b:\tView your Balance\n"
		 << " d:\tDeposit Money\n"
		 << " w:\tWidthdraw Money\n"
		 << " q:\tQuit the program\n";
}

struct BankAccount {
	unsigned long long	balance;// balance, in cents
	string				owner;	// account owner
};

void enroll(vector<BankAccount>* bank) {
	BankAccount newacc;

	cout << "\nState your full name: ";

	cout << '\n' << PROMPT;
	getline(cin, newacc.owner);

	cout << "\nAccount created!"
		 << "\nYour account number: "
		 << bank->size();

	bank->push_back(newacc);

}

void browse(vector<BankAccount>* bank) {
	if ( bank->empty() ) {
		cout << "\n(no accounts found)\n";
	} else {
		cout << "\n\n Number  Owner"
			 << "\n===============";
		for (unsigned int i = 0; i < bank->size(); i++) {
			cout << "\n "
				 << i << "\t"
				 << bank->at(i).owner;
		}
		cout << "\n\n";
	}
}

void deposit(vector<BankAccount>* bank) {
	string buf;
	BankAccount* acc;
	cout << "\nDepositing...\nEnter account number: ";

	while(true) {
		buf.clear();
		cout << '\n' << PROMPT;
		cin >> buf;
		cin.ignore();

		try {
			acc = &(bank->at(stoi(buf)));
			break;
		} catch (...) {
			cerr << "Please, a valid account number: ";
		}
	}

	cout << "\nEnter amount to deposit, in PHP: ";

	while(true) {
		buf.clear();
		cout << '\n' << PROMPT;
		cin >> buf;
		cin.ignore();

		try {
			unsigned long long cheque = static_cast<int>(stof(buf) * 100);
			acc->balance += cheque;
			break;
		} catch (...) {
			cerr << "Please, a valid deposit amount: ";
		}
	}

	cout << "\nDeposit finished, thank you "
		 << acc->owner
		 << "!\n";
}

void withdraw(vector<BankAccount>* bank) {
	string buf;
	BankAccount* acc;
	cout << "\nWithdrawing...\nEnter account number: ";

	while(true) {
		buf.clear();
		cout << '\n' << PROMPT;
		cin >> buf;
		cin.ignore();

		try {
			acc = &(bank->at(stoi(buf)));
			break;
		} catch (...) {
			cerr << "Please, a valid account number: ";
		}
	}

	cout << "\nEnter amount to withdraw, in PHP: ";

	while(true) {
		buf.clear();
		cout << '\n' << PROMPT;
		cin >> buf;
		cin.ignore();

		try {
			unsigned long long cash = static_cast<int>(stof(buf) * 100);
			if (cash > acc->balance) {
				cerr << "An amount less than your balance, please: ";
				continue;
			} else {
				acc->balance -= cash;
			}
			break;
		} catch (...) {
			cerr << "Please, a valid amount to withdraw: ";
		}
	}

	cout << "\nWithdraw finished, thank you "
		 << acc->owner
		 << "!\n";
}

void viewbal(vector<BankAccount>* bank) {
	string buf;
	BankAccount* acc;
	cout << "\nBalance Inquiry...\nEnter account number: ";

	while(true) {
		buf.clear();
		cout << '\n' << PROMPT;
		cin >> buf;
		cin.ignore();

		try {
			acc = &(bank->at(stoi(buf)));
			break;
		} catch (...) {
			cerr << "Please, a valid account number: ";
		}
	}

	cout << "\nHello, "
		 << acc->owner
		 << "!\nYour current account balance is: "
		 << static_cast<float>(acc->balance) / 100
		 << "PHP.\n";
}

int main() {
	string buf;
	vector<BankAccount> bank;

	cout << "\n+----------------------------------+"
		 << "\n| Poorly-designed Banking Software |"
		 << "\n+--------------v0.1.0--------------+\n";

	help();

	while (true) {
		buf.clear();

		cout << '\n' << PROMPT;

		cin >> buf;
		cin.ignore();
		switch (ParseAction(buf.at(0))) {
			case _:			help(); break;
			case newacc:	enroll(&bank); break;
			case list:		browse(&bank); break;
			case dpst:		deposit(&bank); break;
			case wdrw:		withdraw(&bank); break;
			case bal:		viewbal(&bank); break;
			case quit:		return 0;
		}
	}
}
