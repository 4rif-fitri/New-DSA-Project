#include "Room.h"

template<typename T>
void Room::showOptionBaris(int colum, T options[], int count_pilihan) {
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


template<typename T>
T Room::optionBaris(T optionss[], int count_pilihan) {
	string type;
	char keybord;
	int colum = 0;

	while (true) {
		cout << "Type of Room : ";
		showOptionBaris<T>(colum, optionss, count_pilihan);

		keybord = _getch(); //when click keyboard

		if (keybord == 0 || keybord == -32) {
			switch (_getch()) { //click keyboard

                case 75: // LEFT
                    colum = (colum == 0) ? count_pilihan - 1 : colum - 1;
                    break;

                case 77: // RIGHT
                    colum = (colum == count_pilihan - 1) ? 0 : colum + 1;
                    break;
			}

		}

		if (keybord == 13) break; //click enter
	}
	cout << endl;//!
	return optionss[colum];
}
void Room::test() {
	string options[] = { "Family", "Deluxe", "Standard", "VIP" };
	int lenght = (sizeof(options) / sizeof(*options));
	optionBaris<string>(options, lenght);
}