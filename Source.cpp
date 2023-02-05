#include <iostream>
#include <string>
#include <map>

using namespace std;

class Person {
	string name, address, phoneNumber;

public:
	Person(string n, string a, string p) {
		name = n;
		address = a;
		phoneNumber = p;
	}

	void print() {
		cout << "Name: " << name << "\nPhone Number: " << phoneNumber << "\nAddress: " << address << endl;
	}
};

/*void driver(multimap<string, Person*>, multimap<string, Person*>);
int insert(multimap<string, Person*>, multimap<string, Person*>);
int search(multimap<string, Person*>, multimap<string, Person*>);*/

int insert(multimap<string, Person*>& searchName, multimap<string, Person*>& searchNumber) {
	string name, address,phoneNumber;
	cout << "Enter name (. to stop) : ";
	getline(cin, name, '.');
	cout << "Enter address (. to stop) : ";
	getline(cin,address,'.');
	cout << "Enter phone number : ";
	cin >> phoneNumber;

	Person* p = new Person(name, address, phoneNumber);

	searchName.insert(pair<string, Person*>(name, p));
	searchNumber.insert(pair<string, Person*>(phoneNumber, p));

	return 0;
}

int search(multimap<string, Person*>& searchName, multimap<string, Person*>& searchNumber) {
	int option;
	do {
		cout << "Enter 1. Search by name  2. Search by phone number: " << endl;
		cin >> option;

		if (option == 1) {
			string name;
			cout << "Enter name: ";
			cin >> name;

			auto it = searchName.equal_range(name);

			if (it.first == it.second) {
				cout << "No entries found" << endl;
			}

			else {
				for (auto itr = it.first; itr != it.second; itr++) {
					itr->second->print();
				}
			}
		}

		else if (option == 2) {
			string phoneNumber;
			cout << "Enter phone number: ";
			cin >> phoneNumber;

			auto it = searchNumber.equal_range(phoneNumber);

			if (it.first == it.second) {
				cout << "No entries found" << endl;
			}

			else {
				for (auto itr = it.first; itr != it.second; itr++) {
					itr->second->print();
				}
				cout << endl;
			}
		}
	} while (option < 1 || option > 2);

	return 0;
}

void driver(multimap<string, Person*>& searchName, multimap<string, Person*>& searchNumber) {
	int option;
	do {
		cout << "Enter 1. Insert   2.Search: ";
		cin >> option;

		if (option == 1) {
			int result = insert(searchName, searchNumber);
			if (result == 0)
				cout << "Insertion successful" << endl;
		}

		else if (option == 2) {
			int result = search(searchName, searchNumber);
			if (result == 0)
				cout << "Search complete" << endl;
		}
	} while (option >= 1 && option <= 2);
}

int main() {
	multimap<string, Person*> searchName, searchNumber;
	driver(searchName, searchNumber);

	for (auto itr = searchName.begin(); itr != searchName.end(); itr++) {
		delete itr->second;
	}
	searchName.clear();
	searchNumber.clear();

	return 0;
}