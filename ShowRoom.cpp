#include <iostream>
using namespace std;
#include "Room.h"

void Room::ShowRoom(HANDLE hConsole) {
	system("cls");
	ShowAll();
	cout << "Pess ESC to back";
}