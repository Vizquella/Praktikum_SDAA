#include <iostream>
#include <string>

using namespace std;

const int maks_commander = 100;

struct Commander {
    string nama;
    string kemampuan;
    int level;
};

struct CommanderList {
    Commander commanders[maks_commander];
    int count;
};

void tambahCommander(CommanderList* list, string nama, string kemampuan, int level) {
    if (list->count < maks_commander) {
        Commander newcommander;
        newcommander.nama = nama;
        newcommander.kemampuan = kemampuan;
        newcommander.level = level;
        list->commanders[list->count] = newcommander;
        list->count++;
        cout << "Commander " << nama << " berhasil ditambahkan!\n";
    } else {
        cout << "Daftar Commander penuh!\n";
    }
}

void tampilkanCommanders(CommanderList* list) {
    if (list->count == 0) {
        cout << "Tidak ada commander yang tersedia.\n";
    } else {
        cout << "Daftar Commander Magic Chess:\n";
        for (int i = 0; i < list->count; i++) {
            cout << i + 1 << ". Nama: " << list->commanders[i].nama
                 << ", Kemampuan: " << list->commanders[i].kemampuan
                 << ", Level: " << list->commanders[i].level << endl;
        }
    }
}

void updateCommander(CommanderList* list, int index, string nama, string kemampuan, int level) {
    if (index >= 0 && index < list->count) {
        list->commanders[index].nama = nama;
        list->commanders[index].kemampuan = kemampuan;
        list->commanders[index].level = level;
        cout << "Commander berhasil diperbarui!\n";
    } else {
        cout << "Commander tidak ditemukan!\n";
    }
}

void hapusCommander(CommanderList* list, int index) {
    if (index >= 0 && index < list->count) {
        for (int i = index; i < list->count - 1; i++) {
            list->commanders[i] = list->commanders[i + 1];
        }
        list->count--;
        cout << "Commander berhasil dihapus!\n";
    } else {
        cout << "Commander tidak ditemukan!\n";
    }
}

// Fungsi utama
int main() {
    CommanderList commanderList;
    commanderList.count = 0;

    int pilihan;
    do {
        cout << "\nMenu Commander Magic Chess\n";
        cout << "1. Tambah Commander\n";
        cout << "2. Tampilkan Daftar Commander\n";
        cout << "3. Update Commander\n";
        cout << "4. Hapus Commander\n";
        cout << "5. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> pilihan;

        if (pilihan == 1) {
            string nama, kemampuan;
            int level;
            cout << "Nama Commander: ";
            cin.ignore();
            getline(cin, nama);
            cout << "Kemampuan Commander: ";
            getline(cin, kemampuan);
            cout << "Level Commander: ";
            cin >> level;
            tambahCommander(&commanderList, nama, kemampuan, level);
        } else if (pilihan == 2) {
            tampilkanCommanders(&commanderList);
        } else if (pilihan == 3) {
            int index;
            string nama, kemampuan;
            int level;
            cout << "Pilih nomor Commander yang ingin diupdate: ";
            cin >> index;
            cout << "Nama baru Commander: ";
            cin.ignore();
            getline(cin, nama);
            cout << "Kemampuan baru Commander: ";
            getline(cin, kemampuan);
            cout << "Level baru Commander: ";
            cin >> level;
            updateCommander(&commanderList, index - 1, nama, kemampuan, level);
        } else if (pilihan == 4) {
            int index;
            cout << "Pilih nomor Commander yang ingin dihapus: ";
            cin >> index;
            hapusCommander(&commanderList, index - 1);
        }

    } while (pilihan != 5);

    cout << "Arigathanks Gozaimuch!\n";
    return 0;
}
