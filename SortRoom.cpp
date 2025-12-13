#include <iostream>
using namespace std;
#include "Room.h"
void Room::SortRoom(HANDLE hConsole) {
    system("cls");
    aaa("Sort Room by Price");

    if (totalRoom == 1) {
        ShowAll();
        //SetConsoleTextAttribute(hConsole, 12);
        cout << "No Need To sort kerana room ada satu";
        //SetConsoleTextAttribute(hConsole, 7);
        cout << "\nTekan ESC to Back";
        return;
    }

    // --- Bubble Sort Implementation (Menukar Pointers) ---
    Node* end = nullptr;
    bool swapped;

    do {
        swapped = false;
        Node* curr = pHead;
        Node* prev = nullptr;

        while (curr->link != end) {
            Node* next = curr->link;

            // Jika harga curr LEBIH BESAR daripada harga next, tukar NODE (Ascending: Termurah ke Termahal)
            if (curr->price > next->price) {
                // TUKAR SUSUNAN NODE (3 LANGKAH)

                // 1. Ubah penunjuk head/prev
                if (curr == pHead) {
                    pHead = next;
                }
                else {
                    prev->link = next;
                }

                // 2. Sambungkan curr kepada link asal next
                curr->link = next->link;

                // 3. Sambungkan next kepada curr
                next->link = curr;

                // Tetapkan semula pointer prev dan curr untuk kitaran seterusnya
                prev = next;
                swapped = true;
            }
            else {
                // Jika tiada pertukaran
                prev = curr;
                curr = curr->link;
            }
        }
        end = curr;
    } while (swapped);

    SetConsoleTextAttribute(hConsole, 10);
    cout << "Sort By Harga (Termurah ke Termahal)\n\n";
    SetConsoleTextAttribute(hConsole, 7);

    ShowAll();

    cout << "\nTekan ESC to Back";
    _getch();
}