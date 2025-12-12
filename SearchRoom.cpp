#include <iostream>#include <limits>
#include <iomanip>
#include <algorithm>#include <iomanip>
#include <iostream>
#include <windows.h>
#include <string>
#undef max
#include <limits>
using namespace std;
#include "Room.h"
string toLower(const string& str) {
    string lower_str = str;
    for (char& c : lower_str) {
        c = tolower(c);
    }
    return lower_str;
}
void Room::SearchRoom(HANDLE hConsole) {
    while (true) {
        // --- 1. Menu Pilihan Carian ---
        const char* options[] = {
            "1. Search by Room Number",
            "2. Search by Name",
            "3. Search by Type",
            "4. Back to Main Menu"
        };
        int num_options = 4;
        int baris = 2; // *** Mula pada pilihan 'Search by Type' (Indeks 2) ***
        char choice_menu;

        while (true) {
            system("cls");
            aaa("Search Room");
            cout << "Pilih Kriteria Carian:\n";

            for (int i = 0; i < num_options; ++i) {
                bool selected = (i == baris);
                if (selected) {
                    SetConsoleTextAttribute(hConsole, 46);
                    cout << " > " << options[i] << endl;
                }
                else {
                    SetConsoleTextAttribute(hConsole, 7);
                    cout << "   " << options[i] << endl;
                }
            }
            SetConsoleTextAttribute(hConsole, 7);

            choice_menu = _getch();

            if (choice_menu == 27) return;

            if (choice_menu == 0 || choice_menu == -32) {
                switch (_getch()) {
                case 72: // UP
                    baris = (baris == 0 ? num_options - 1 : baris - 1);
                    break;
                case 80: // DOWN
                    baris = (baris + 1) % num_options;
                    break;
                }
            }

            if (choice_menu == 13) { // ENTER ditekan
                break;
            }
        }

        if (baris == 3) break; // Keluar jika pilih 'Back to Main Menu'

        // Hanya teruskan jika pilihan adalah 'Search by Type' (baris == 2)
        if (baris != 2) {
            // Jika pengguna memilih nombor atau nama, anda boleh implementasikannya di sini
            // Buat masa ini, kita biarkan ia teruskan ke akhir atau ulangi
            cout << "\nPilihan tidak disokong buat masa ini. Sila pilih 'Search by Type'.";
            _getch();
            continue;
        }

        // --- 2. Input Carian ---
        string searchTerm = "";
        system("cls");
        aaa(options[baris]);

        cout << "Masukkan Jenis Room (cth: Family, VIP, Standard): ";
        // Pastikan buffer bersih sebelum getline
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, searchTerm);
        searchTerm = toLower(searchTerm); // Tukar kepada huruf kecil


        // --- 3. Paparan Hasil Carian ---
        Node* temps = pHead;
        int resultCount = 0;

        cout << "\n--- HASIL CARIAN BERDASARKAN JENIS: " << searchTerm << " ---\n";

        // Header Ringkas
        SetConsoleTextAttribute(hConsole, 11);
        cout << setw(15) << "No. Room" << setw(20) << "Name" << setw(15) << "Type"
            << setw(10) << "Price" << setw(10) << "Status" << endl;
        SetConsoleTextAttribute(hConsole, 7);
        cout << "------------------------------------------------------------------------\n";


        // Lintas Senarai Pautan dan Bandingkan Jenis
        while (temps != nullptr) {

            // Logik Carian Jenis Bilik
            if (toLower(temps->type).find(searchTerm) != string::npos) {
                // toLower(temps->type).find(searchTerm) != string::npos 
                // bermakna 'searchTerm' ditemui di dalam 'temps->type' 
                // (contoh: cari 'fam' akan temui 'Family')

                // Paparkan Node yang sepadan
                cout << setw(15) << temps->roomNumber
                    << setw(20) << temps->name
                    << setw(15) << temps->type
                    << setw(10) << fixed << setprecision(2) << temps->price
                    << setw(10) << temps->isaVailable
                    << endl;
                resultCount++;
            }
            temps = temps->link;
        }

        cout << "\n" << resultCount << " bilik ditemui.\n";

        // --- 4. Tanyakan Sambung ---
        cout << "\nTeruskan carian? (y/n) ";
        char choice_cont;
        cin >> ws >> choice_cont;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (tolower(choice_cont) != 'y') {
            break;
        }
    }
    cout << "\nTekan sebarang kekunci untuk kembali ke Menu Utama.";
    _getch();
}