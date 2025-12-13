#include <iostream>
#include <limits>
#include <iomanip>
#include <algorithm>
#include <windows.h>
#include <string>
#undef max
using namespace std;
#include "Room.h"

void showMenuCari(string listCari[], int baris, int length, HANDLE hConsole, function<void(string)>aaa) {
	system("cls");
	aaa("Carian");

	for (int i = 0; i < length; i++){
		bool selected = (i == baris);
	
		if (selected) {
			SetConsoleTextAttribute(hConsole, 46);
			cout << " > " << listCari[i] << endl;
		}else {
			SetConsoleTextAttribute(hConsole, 7);
			cout << "   " << listCari[i] << endl;
		}
		SetConsoleTextAttribute(hConsole, 7);
	}
	cout << endl;
	aaa("Guna Arow Up Or Down To Select");
	cout << "Pess ESC dua kali to Back";

}

void Room::printTableFind(string typeFind, int dataCarian, double hargaCarian) {
	if (typeFind == "number") {

		Node* curr = pHead;
		
		while (curr != nullptr){
			bool isFound = false;
			if (isFound == false) {
				if (curr->roomNumber == dataCarian) {
					cout << curr->roomNumber << " " << curr->name << endl;
					isFound == true;
				}

			}
			if (isFound == true) {
				break;
			}
			curr = curr->link;
		}

	}
	else if (typeFind == "price") {


		Node* curr = pHead;

		while (curr != nullptr) {
			if (curr->price == hargaCarian) {
				cout << curr->roomNumber << " " << curr->name << " " << curr->price << endl;
			}
			curr = curr->link;
		}

	}
}

void findByNumber() {

}

void findByPrice() {

}

void Room::SearchRoom(HANDLE hConsole) {
	
	string listCari[] = {
		"Cari Room Number",
		"Cari Harga",
	};

	int length = sizeof(listCari) / sizeof(*listCari); //2
	int baris = 0;
	char arrow;

	while (true){
		showMenuCari(listCari ,baris, length, hConsole, aaa);
		arrow = _getch();
		if (arrow == 27) break;

		if (arrow == 0 || arrow == -32) {
			switch (_getch()){
			
			case 72:
				baris = baris == 0 ? length - 1 : baris - 1;
				break;

			case 80:
				baris = (baris + 1) % length;
				break;

			}
		}

		if (arrow == 13) {
			system("cls");

			if (baris == 0) {
				int numberRoom;
				cout << "Masukkan Nombor Room : ";
				cin >> numberRoom;
				printTableFind("number", numberRoom, 0.0);
				//findByNumber();
			}
			else if (baris == 1) {
				//findByNumber();
				double priceRoom;
				cout << "Masukkan Harga Room : ";
				cin >> priceRoom;
				printTableFind("price", 0, priceRoom);
			}

			cout << "Pess ESC to Back";
			_getch();
		}

	}

}