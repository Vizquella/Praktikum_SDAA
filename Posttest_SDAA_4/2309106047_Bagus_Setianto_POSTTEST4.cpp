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

void pushCommander(string nama, string kemampuan, int level) {
    Commander* CommanderBaru = new Commander();
    CommanderBaru->nama = nama;
    CommanderBaru->kemampuan = kemampuan;
    CommanderBaru->level = level;
    CommanderBaru->next = head;
    head = CommanderBaru;
    cout << "Commander " << nama << " berhasil ditambahkan ke Stack!\n";
}

void popCommander() {
    if (head == nullptr) {
        cout << "Stack kosong, tidak ada Commander yang bisa di-pop.\n";
        return;
    }
    Commander* temp = head;
    head = head->next;
    cout << "Commander " << temp->nama << " berhasil di-pop dari Stack!\n";
    delete temp;
}

void enqueueCommander(string nama, string kemampuan, int level) {
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
    cout << "Commander " << nama << " berhasil ditambahkan ke Queue!\n";
}

void dequeueCommander() {
    if (head == nullptr) {
        cout << "Queue kosong, tidak ada Commander yang bisa di-dequeue.\n";
        return;
    }
    Commander* temp = head;
    head = head->next;
    cout << "Commander " << temp->nama << " berhasil di-dequeue dari Queue!\n";
    delete temp;
}


int main() {
    int pilihan;

    do {
        cout << "\nMenu Commander Magic Chess\n";
        cout << "1. Tambah Commander (Linked List)\n";
        cout << "2. Tampilkan Daftar Commander\n";
        cout << "3. Update Commander\n";
        cout << "4. Hapus Commander\n";
        cout << "5. Push Commander ke Stack\n";
        cout << "6. Pop Commander dari Stack\n";
        cout << "7. Enqueue Commander ke Queue\n";
        cout << "8. Dequeue Commander dari Queue\n";
        cout << "9. Keluar\n";
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
        } else if (pilihan == 5) {
            string nama, kemampuan;
            int level;
            cout << "Nama Commander untuk Stack: ";
            cin.ignore();
            getline(cin, nama);
            cout << "Kemampuan Commander: ";
            getline(cin, kemampuan);
            cout << "Level Commander: ";
            cin >> level;
            pushCommander(nama, kemampuan, level);
        } else if (pilihan == 6) {
            popCommander();
        } else if (pilihan == 7) {
            string nama, kemampuan;
            int level;
            cout << "Nama Commander untuk Queue: ";
            cin.ignore();
            getline(cin, nama);
            cout << "Kemampuan Commander: ";
            getline(cin, kemampuan);
            cout << "Level Commander: ";
            cin >> level;
            enqueueCommander(nama, kemampuan, level);
        } else if (pilihan == 8) {
            dequeueCommander();
        } else if (pilihan != 9) {
            cout << "Pilihan tidak valid\n";
        }

    } while (pilihan != 9);

    cout << "Arigathanks Gozaimuch!\n";
    return 0;
}
