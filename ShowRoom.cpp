#include "Room.h"

void Room::ShowRoom() {
	system("cls");
	printLabel("All Data Room....");
	ShowAll();
	printLabel("Pess ESC to back");
	_getch();
}