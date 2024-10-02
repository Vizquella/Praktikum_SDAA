#include <iostream>
using namespace std;

struct Commander {
    string nama;
    string kemampuan;
    int level;
    Commander* next;
};

Commander* head = nullptr;

void tambahCommander(string nama, string kemampuan, int level) {
    Commander* CommanderBaru = new Commander();
    CommanderBaru->nama = nama;
    CommanderBaru->kemampuan = kemampuan;
    CommanderBaru->level = level;
    CommanderBaru->next = nullptr;

    if (head == nullptr) {
        head = CommanderBaru;
    } else {
        Commander* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = CommanderBaru;
    }
    cout << "Commander " << nama << " berhasil ditambahkan!\n";
}

void tampilkanCommander() {
    if (head == nullptr) {
        cout << "Tidak ada Commander yang tersedia.\n";
    } else {
        Commander* temp = head;
        int nomor = 1;
        cout << "Daftar Commander Magic Chess:\n";
        while (temp != nullptr) {
            cout << nomor << ". Nama: " << temp->nama
                 << ", Kemampuan: " << temp->kemampuan
                 << ", Level: " << temp->level << endl;
            temp = temp->next;
            nomor++;
        }
    }
}

void updateCommander(int posisi, string nama, string kemampuan, int level) {
    if (head == nullptr) {
        cout << "Tidak ada Commander untuk diupdate.\n";
        return;
    }

    Commander* temp = head;
    int nomor = 1;
    while (temp != nullptr && nomor < posisi) {
        temp = temp->next;
        nomor++;
    }

    if (temp == nullptr) {
        cout << "Commander pada posisi tersebut tidak ditemukan.\n";
    } else {
        temp->nama = nama;
        temp->kemampuan = kemampuan;
        temp->level = level;
        cout << "Commander berhasil diupdate!\n";
    }
}

void hapusCommander(int posisi) {
    if (head == nullptr) {
        cout << "Tidak ada Commander untuk dihapus.\n";
        return;
    }

    Commander* temp = head;
    if (posisi == 1) {
        head = head->next;
        delete temp;
        cout << "Commander berhasil dihapus!\n";
        return;
    }

    Commander* sebelumnya = nullptr;
    int nomor = 1;
    while (temp != nullptr && nomor < posisi) {
        sebelumnya = temp;
        temp = temp->next;
        nomor++;
    }

    if (temp == nullptr) {
        cout << "Commander pada posisi tersebut tidak ditemukan.\n";
    } else {
        sebelumnya->next = temp->next;
        delete temp;
        cout << "Commander berhasil dihapus!\n";
    }
}

int main() {
    int pilihan;

    do {
        cout << "\nMenu Commander Magic Chess\n";
        cout << "1. Tambah Commander\n";
        cout << "2. Tampilkan Daftar Commander\n";
        cout << "3. update Commander\n";
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
            tambahCommander(nama, kemampuan, level);
        } else if (pilihan == 2) {
            tampilkanCommander();
        } else if (pilihan == 3) {
            int posisi;
            string nama, kemampuan;
            int level;
            cout << "Pilih nomor Commander yang ingin diupdate: ";
            cin >> posisi;
            cout << "Nama baru Commander: ";
            cin.ignore();
            getline(cin, nama);
            cout << "Kemampuan baru Commander: ";
            getline(cin, kemampuan);
            cout << "Level baru Commander: ";
            cin >> level;
            updateCommander(posisi, nama, kemampuan, level);
        } else if (pilihan == 4) {
            int posisi;
            cout << "Pilih nomor Commander yang ingin dihapus: ";
            cin >> posisi;
            hapusCommander(posisi);
        } else if (pilihan != 5) {
            cout << "Pilihan tidak valid\n";
        }


    } while (pilihan != 5);

    cout << "Arigathanks Gozaimuch!\n";
    return 0;
}
