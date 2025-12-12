#include <iostream>
using namespace std;
#include "Room.h"
void Room::SortRoom(HANDLE hConsole) {
    system("cls");
    aaa("Sort Room by Price");

    if (pHead == nullptr || pHead->link == nullptr) {
        SetConsoleTextAttribute(hConsole, 12);
        cout << "Tidak cukup bilik untuk diisih (Kurang dari 2 bilik).";
        SetConsoleTextAttribute(hConsole, 7);
        _getch();
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
    // --- Tamat Bubble Sort Menukar Pointers ---

    SetConsoleTextAttribute(hConsole, 10);
    cout << "Bilik berjaya diisih mengikut Harga (Termurah ke Termahal). Susunan Link asal diubah.\n\n";
    SetConsoleTextAttribute(hConsole, 7);

    ShowAll(); // Paparkan senarai yang telah diisih

    cout << "\nTekan sebarang kekunci untuk kembali ke Menu Utama.";
    _getch();
}