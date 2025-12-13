#include <iomanip>
#include <iostream>
#include <windows.h>
#include <string>
#include <limits>
using namespace std;
#undef max

#include "Room.h"

void Room::optionType(int bar) {
	const string options[] = { "Family", "Deluxe", "Standard", "VIP" };
	int num_options = sizeof(options)/ sizeof(*options);

	for (int i = 0; i < num_options; ++i) {
		if (i > 0) {
			removeBackgroundText();
			cout << " | ";
		}

		if (i == bar) setBackgroundText();
		else removeBackgroundText();

		cout << options[i];
	}

	removeBackgroundText();
	cout << "\r"; // Kembalikan kursor ke awal baris
}

string Room::setName() {
	string name;
	while (true) {
		cout << "Name Room : ";
		getline(cin >> ws, name);
		if (!name.empty()) {
			return name;
		}
	}
}

string Room::setType() {
	string type;
	char choi;
	int bar = 0;
	const int MAX_CHOICE = 3; // 0 1 2 3
	while (true) {
		cout << "Type of Room : ";

		optionType(bar);

		choi = _getch();
		if (choi == 0 || choi == -32) {
			switch (_getch()) {
			case 75: // (LEFT ARROW)
				bar = (bar == 0) ? MAX_CHOICE : bar - 1;
				break;
			case 77: // (RIGHT ARROW)
				bar = (bar == MAX_CHOICE) ? 0 : bar + 1;
				break;
			}
		}
		if (choi == 13) { // ENTER
			if (bar == 0) type = "Family";
			else if (bar == 1) type = "Deluxe";
			else if (bar == 2) type = "Standard";
			else if (bar == 3) type = "VIP";
			break;
		}
	}
	cout << endl;//!
	return type;
}

double Room::setPrice() {
	double price;

	while (true) {
		cout << "Price : ";
		cin >> price;

		if (!cin.fail() && price >= 0) {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return price;
		}

		cout << "Input tidak sah. Masukkan nombor sahaja.\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}

bool Room::sambung() {
	char c;
	cout << "Nak sambung? (y/n) : ";
	cin >> ws >> c;

	//clear buffer
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	//clear buffer

	if (c == 'y') {
		return true;
	}
	else {
		return false;
	}

}

void Room::displayDoneAdd() {
	system("cls");
	setColorText();
	printLabel("Done Add Room...");
	removeColorText();
}

void Room::AddRoom(HANDLE hConsole) {
	while (true) {
		system("cls");
		printLabel("Add Room");
		ShowAll();

		string name;
		string type;
		string payment;
		double price;
		Node* pNew = new Node();

		cout << "\nMasukkan Detail Room\n";
		name = setName();
		type = setType();
		price = setPrice();

		totalRoom = totalRoom++;
		pNew->roomNumber = totalRoom;
		pNew->name = name;
		pNew->price = price;
		pNew->type = type;
		pNew->isaVailable = "Yes";
		pNew->dateChackIn = " - ";
		pNew->dateChackOut = " - ";
		pNew->payment = " - ";
		pNew->payment = "-";
		pNew->link = nullptr;

		if (pHead == nullptr) {
			pHead = pNew;
		}
		else {
			Node* temp = pHead;
			while (temp->link != nullptr) {
				temp = temp->link;
			}
			temp->link = pNew;
		}

		displayDoneAdd();
		ShowAll();

		if (!sambung()) {
			break;
		}
	}
	cout << "Pess ESC to back";
}

