#include <iostream>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include <functional> 
#include <string>
#include <limits>
#undef max
#include "Room.h"

using namespace std;

class Utility : public Room{

	void printLabel(string text);
	void printLabel(string text1, string text2);

	void printHeaderTable();
	void printBodyTable(Node* temps);
	void printFooterTable();

	void ShowAll();
	void ShowOne(Node* one);

	double getDoublee(string textInput, string textError);
	double getIntt(string textInput, string textError);
	string getStringg(string textInput, string textError);

	int getTextCode(string text);
	int getBackCode(string text);

	void setColorText();
	void removeColorText();
	void setBackgroundText();
	void removeBackgroundText();

	void setColorText(string warna);
	void setBackgroundText(string warna);

	bool sambung();

	string handleArrow(int& baris, int length) {
		char key = _getch();

		if (key == 27) return "esc";      // ESC
		if (key == 13) return "enter";    // ENTER
		if (key == 0 || key == -32) {
			switch (_getch()) {
			case 72: // UP
				baris = (baris == 0) ? length - 1 : baris - 1;
				break;
			case 80: // DOWN
				baris = (baris + 1) % length;
				break;
			}
		}
		return "";
	}

	void ShowTableSelect(int baris);

	void ShowMenu(string text, string text2, string text3, string text4, int baris, int length, string listCari[]);

	void getDate(int& tahun, int& mount, int& day, string type);

};