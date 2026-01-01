/*
	description: just to Show Data

	@author Arif Fitri

 */
#include "Room.h"

void Room::ShowRoomMain() {
	system("cls"); //clear screen
	printLabel("All Data Room...."); //label kat atas 
	ShowAll();	//show all room dalam table
	printLabel("Pess ESC to back");	//label kat bawah
	_getch();//stop sekejap dapatkan action from user, sebelum back ke page sebelum ni
}