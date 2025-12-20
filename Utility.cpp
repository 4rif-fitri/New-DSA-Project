#include "Room.h"

void Room::printLabel(string text) {
	cout << tl;
	for (int i = 0; i < 30; i++) cout << hor;
	cout << endl;

	cout << ver << setw(16) << text << endl;

	cout << bl;
	for (int i = 0; i < 30; i++) cout << hor;
	cout << endl << endl;
}

void Room::printLabel(string text1, string text2) {
	cout << endl;
	cout << tl;
	for (int i = 0; i < 30; i++) cout << hor;
	cout << endl;

	cout << ver << text1 << endl;
	cout << ver << text2 << endl;

	cout << bl;
	for (int i = 0; i < 30; i++) cout << hor;
	cout << endl << endl;
}

void Room::printHeaderTable() {
	cout << tl;

	for (int i = 0; i < 7; i++) {
		for (int i = 0; i < 14; i++) cout << hor;
		cout << tee_top;
	}

	for (int i = 0; i < 14; i++) cout << hor;
	cout << tr << endl;

	cout << ver
		<< setw(14) << "Number Room" << ver
		<< setw(14) << "Name" << ver
		<< setw(14) << "Type" << ver
		<< setw(14) << "Price" << ver
		<< setw(14) << "Available" << ver
		<< setw(14) << "Date ChackIn" << ver
		<< setw(14) << "Date ChackIn" << ver
		<< setw(14) << "Peyment" << ver
		<< endl;

	cout << th;

	for (int i = 0; i < 7; i++) {
		for (int i = 0; i < 14; i++) cout << hor;
		cout << ddd;
	}

	for (int i = 0; i < 14; i++) cout << hor;
	cout << th_right << endl;
}

void Room::printBodyTable(Node* temps) {
	cout << ver
		<< setw(14) << temps->roomNumber << ver
		<< setw(14) << temps->name << ver
		<< setw(14) << temps->type << ver
		<< setw(14) << temps->price << ver
		<< setw(14) << temps->isaVailable << ver
		<< setw(14) << temps->dateChackIn << ver
		<< setw(14) << temps->dateChackOut << ver
		<< setw(14) << temps->payment << ver
		<< endl;
}

void Room::printFooterTable() {
	cout << bl;
	for (int i = 0; i < 7; i++) {
		for (int i = 0; i < 14; i++) cout << hor;
		cout << aaa;
	}
	for (int i = 0; i < 14; i++) cout << hor;
	cout << sss << endl;
}

void Room::ShowAll() {
	printHeaderTable();

	Node* temps = pHead;

	if (totalRoom == 0) {
		cout << ver << setw(120) << ver << endl;
		cout << ver << setw(14 * 4) << "No Data Yet" << setw(64) << ver << endl;
		cout << ver << setw(120) << ver << endl;
	}
	else {
		while (temps != nullptr) {
			printBodyTable(temps);
			temps = temps->link;
		}

	}
	printFooterTable();

}

double Room::getDoublee(string textInput, string textError) {
	double input;
	while (true) {
		cout << textInput;;
		cin >> input;
		if (!cin.fail() && input >= 0) {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return input;
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << textError << "\n";
	}
}

double Room::getIntt(string textInput, string textError) {
	double input;
	while (true) {
		cout << textInput;;
		cin >> input;
		if (!cin.fail() && input >= 0) {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return input;
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << textError << "\n";
	}
}

string Room::getStringg(string textInput, string textError) {
	string name;
	while (true) {
		cout << textInput;
		getline(cin >> ws, name);
		if (!name.empty()) {
			return name;
		}
		else {
			cout << textError << endl;
		}
	}
}

void Room::setColorText() {
	SetConsoleTextAttribute(hConsole, 10);
}

void Room::removeColorText() {
	SetConsoleTextAttribute(hConsole, 7);
}

void Room::setBackgroundText() {
	SetConsoleTextAttribute(hConsole, 0x1F);
}

void Room::removeBackgroundText() {
	SetConsoleTextAttribute(hConsole, 7);
}

int Room::getTextCode(string text) {
	int code = -1;

	if (text == "merah") code = 1;
	else if (text == "biru") code = 2;
	else if (text == "cyan") code = 3;
	else if (text == "kuning") code = 4;
	else if (text == "hijau") code = 5;
	else if (text == "hitam") code = 6;
	else if (text == "putih") code = 7;

	return code;
}

int Room::getBackCode(string text) {
	int code = -1;

	if (text == "merah") code = BACKGROUND_RED;
	else if (text == "biru") code = BACKGROUND_BLUE;
	else if (text == "cyan") code = BACKGROUND_GREEN | BACKGROUND_BLUE;
	else if (text == "kuning") code = BACKGROUND_RED | BACKGROUND_GREEN;
	else if (text == "hijau") code = BACKGROUND_GREEN;
	else if (text == "hitam") code = 0;
	else if (text == "putih") code = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE;

	return code;
}

void Room::setColorText(string warna) {
	SetConsoleTextAttribute(hConsole, getTextCode(warna));
}

void Room::setBackgroundText(string warna) {
	SetConsoleTextAttribute(hConsole, getBackCode(warna));
}