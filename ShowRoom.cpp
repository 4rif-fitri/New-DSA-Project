#include "Room.h"

void Room::ShowRoomMain() {
	system("cls");
	printLabel("All Data Room....");
	ShowAll();
	printLabel("Pess ESC to back");
	_getch();
}