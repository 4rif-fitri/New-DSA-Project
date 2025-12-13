#include <iomanip>
#include <iostream>
#include <windows.h>
#include <string>
#include <limits>
#undef max
using namespace std;

#include "Room.h"

void optionType(int bar, HANDLE hConsole) {
	// Senarai pilihan: 0=Family, 1=Deluxe, 2=Standard, 3=VIP
	const char* options[] = { "Family", "Deluxe", "Standard", "VIP" };
	int num_options = 4;

	for (int i = 0; i < num_options; ++i) {
		if (i > 0) {
			SetConsoleTextAttribute(hConsole, 7);
			cout << " | "; // Pemisah antara pilihan
		}

		// Serlahkan pilihan semasa (bar == i)
		if (i == bar) {
			SetConsoleTextAttribute(hConsole, 46); // Warna Serlah (Contoh: Latar Hijau, Teks Putih)
		}
		else {
			SetConsoleTextAttribute(hConsole, 7);  // Warna Biasa (Contoh: Putih)
		}

		cout << options[i];
	}

	// Pastikan warna dikembalikan kepada standard di hujung baris
	SetConsoleTextAttribute(hConsole, 7);
	cout << "\r"; // Kembalikan kursor ke awal baris
}

string setName() {
	string name;
	cout << "Name Room : ";
	getline(cin, name);
	return name;
}

string setType(HANDLE hConsole) {
	string type;
	char choi;
	int bar = 0;
	const int MAX_CHOICE = 3; // 0 1 2 3
	while (true) {
		cout << "Type of Room : ";

		optionType(bar, hConsole);

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

double setPrice() {
	double price;
	cout << "Price : ";
	cin >> price;
	return price;
}

bool sambung() {
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

//									 Callback func
void displayDoneAdd(HANDLE hConsole, function<void(string)> aaa) {
	system("cls");
	SetConsoleTextAttribute(hConsole, 10);
	aaa("Done Add Room...");
	SetConsoleTextAttribute(hConsole, 7);
}

void Room::AddRoom(HANDLE hConsole) {
	while (true) {
		system("cls");
		aaa("Add Room");
		ShowAll();

		string name;
		string type;
		string payment;
		double price;
		Node* pNew = new Node();

		cout << "\nMasukkan Detail Room\n";
		name = setName();
		type = setType(hConsole);
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

		displayDoneAdd(hConsole, aaa);
		ShowAll();

		if (!sambung()) {
			break;
		}
	}
	cout << "Pess ESC to back";
}

