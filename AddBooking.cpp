#include "Room.h"

void Room::jalan(int baris, Node*& targetNode) { // dapatkan node yg user pilih
	targetNode = pHead;
	for (int i = 0; i < baris; i++){
		targetNode = targetNode->link;
	}
}

void Room::bookInputData(int baris) {
	Node* targetNode;

	string isTersedia, typePayment;
	string optionsAvailable[] = {
		"Free",
		"Booked"
	};
	string optionPayment[] = {
		"Bankin",
		"Cash",
	};
	string tarikhIn, tarikhOut;

	int tahunIn,tahunOut, mountIn,dayIN, mountOut, dayOut;
	int countPilihanAvailable = sizeof(optionsAvailable) / sizeof(*optionsAvailable);
	int countPilihanPayment = sizeof(optionsAvailable) / sizeof(*optionsAvailable);

	jalan(baris, targetNode);
	system("cls");
	printLabel("Add Booking Room");
	ShowOne(targetNode);

	cout << "Sila Masukkan Detail Booking > " << endl;
	isTersedia = optionBaris<string>(optionsAvailable, countPilihanAvailable);

	if (isTersedia == "Free") {
		tarikhIn = "-";
		tarikhOut = "-";
		typePayment = "-";
	}
	else if (isTersedia == "Booked") {
		cout << endl;
		tahunIn = getIntt("Masukkan Tahun Masuk :", "Masukkan Nombor sahaja");
		mountIn = getIntt("Masukkan Bulan Masuk :", "Masukkan Nombor sahaja");
		dayIN = getIntt("Masukkan Hari Masuk :","Masukkan Nombor sahaja");
		
		cout << endl;
		tahunOut = getIntt("Masukkan Tahun keluar :", "Masukkan Nombor sahaja");
		mountOut = getIntt("Masukkan Bulan Masuk :", "Masukkan Nombor sahaja");
		dayOut = getIntt("Masukkan hari Masuk :", "Masukkan Nombor sahaja");
	
		cout << endl;
		typePayment = optionBaris<string>(optionPayment, countPilihanPayment);

		tarikhIn = to_string(tahunIn) + "/" + to_string(mountIn) + "/" + to_string(dayIN);
		tarikhOut = to_string(tahunOut) + "/" + to_string(mountOut) + "/" + to_string(dayOut);
	}

	targetNode->dateChackIn = tarikhIn;
	targetNode->dateChackOut = tarikhOut;
	targetNode->payment = typePayment;
	targetNode->isaVailable= isTersedia;

	return;
}

void Room::AddbookingMain() {
	char choice = -1;
	int baris = 0;

	while (true) {
		system("cls");
		printLabel("Add Booking Room");
		ShowTableSelect(baris);

		string action = handleArrow(baris, totalRoom);

		if (action == "enter") bookInputData(baris);

		if (action == "esc") break; //esc
	}
}