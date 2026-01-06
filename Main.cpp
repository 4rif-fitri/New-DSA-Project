/*
	description:
	Main of the program

	@author Arif Fitri

 */
#include <iostream>
using namespace std;
#include "Room.h"

void main() {

	Room room; //create object

	//list manu
	string menuList[] = { 
		"Add Room",
		"Show Table Room",
		"Sort Room By harga",
		"Search Room By Price",
		"Add Booking Room",
		//"Delete Room",
		"Exit",
	};

	int length = sizeof(menuList) / sizeof(*menuList); //get panjang list menuList
	int baris = 0;	//start dari kosong untuk manu

	while (true) {	//infinity loop
		//show manu yg boleh select array guna arrow up/down 
		room.ShowMenu("Resort Pasific Sumatra Booking","","Guna Arrow Up/Down untuk pilih","",baris,length,menuList);

		string action = room.handleArrow(baris, length); //get key from user keybord

		if (action == "enter") { // enter
			room.clear(); // clear screen
			if (baris == 0) room.AddRoomMain();
			else if (baris == 1) room.ShowRoomMain();
			else if (baris == 2) room.SortRoomMain();
			else if (baris == 3) room.SearchRoomMain();
			else if (baris == 4) room.AddbookingMain();
			else if (baris == 5) break; ///exit
		}
	}

	room.clear(); // clear screen
	room.printLabel("Program Tamat"); //and prog
}






	//if (action == "enter") { // enter
		//	room.clear(); // clear screen
		//	if		(baris == 0) room.AddRoomMain(); 
		//	else if (baris == 1) room.ShowRoomMain();
		//	else if (baris == 2) room.SortRoomMain();
		//	else if (baris == 3) room.SearchRoomMain();
		//	else if (baris == 4) room.AddbookingMain();
		//	else if (baris == 5) room.DeleteRoomMain();
		//	else if (baris == 6) break;
		//}