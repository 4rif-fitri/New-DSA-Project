#include "Room.h"

void Room::optionType(int colum, string options[],int count_pilihan) {


	for (int i = 0; i < count_pilihan; ++i) {
		if (i > 0) {
			removeBackgroundText();
			cout << " | ";
		}

		if (i == colum) setBackgroundText();
		else removeBackgroundText();

		cout << options[i];
	}

	removeBackgroundText();
	cout << "\r"; // Kembalikan kursor ke awal baris
}


string Room::getType() {
	string options[] = { "Family", "Deluxe", "Standard", "VIP" };
	int count_pilihan = sizeof(options) / sizeof(*options);

	string type;
	char keybord;
	int colum = 0;
	
	while (true) {
		cout << "Type of Room : ";
		optionType(colum, options, count_pilihan);

		keybord = _getch(); //when click keyboard

		if (keybord == 0 || keybord == -32) {
			switch (_getch()) { //click keyboard

			case 75: // LEFT 
				colum = (colum == 0) ? count_pilihan : colum - 1;
				break;
			case 77: // RIGHT
				colum = (colum == count_pilihan) ? 0 : colum + 1;
				break;
			}

		}

		if (keybord == 13) { // click enter
			if (colum == 0) type = "Family";
			else if (colum == 1) type = "Deluxe";
			else if (colum == 2) type = "Standard";
			else if (colum == 3) type = "VIP";
			break;
		}
	}
	cout << endl;//!
	return type;
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

void Room::AddRoom() {
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
		name = getStringg("Name Room :","Name Room Tidak boleh kosong");
		type = getType();
		price = getDoublee("Price : ",
			"Masukkan nombor sahaja");

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

