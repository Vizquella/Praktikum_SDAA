#include <iostream>
#include <cmath>
using namespace std;

struct Commander {
    string nama;
    string kemampuan;
    int level;
    Commander* next;
};

Commander* head = nullptr;

void tambahCommander(string nama, string kemampuan, int level) {
    Commander* commanderBaru = new Commander();
    commanderBaru->nama = nama;
    commanderBaru->kemampuan = kemampuan;
    commanderBaru->level = level;
    commanderBaru->next = nullptr;

    if (head == nullptr) {
        head = commanderBaru;
    } else {
        Commander* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = commanderBaru;
    }
    cout << "Commander " << nama << " berhasil ditambahkan!\n";
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

Commander* merge(Commander* left, Commander* right) {
    if (!left) return right;
    if (!right) return left;

    Commander* result = nullptr;
    if (left->level <= right->level) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }
    return result;
}

Commander* findMiddle(Commander* start) {
    if (start == nullptr) return nullptr;
    Commander* slow = start;
    Commander* fast = start->next;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Commander* mergeSort(Commander* start) {
    if (!start || !start->next) return start;
    Commander* middle = findMiddle(start);
    Commander* nextOfMiddle = middle->next;
    middle->next = nullptr;
    Commander* left = mergeSort(start);
    Commander* right = mergeSort(nextOfMiddle);
    Commander* sorted = merge(left, right);
    return sorted;
}

Commander* partition(Commander* start, Commander* end, Commander** newHead, Commander** newEnd) {
    Commander* pivot = end;
    Commander* prev = nullptr;
    Commander* current = start;
    Commander* tail = pivot;
    while (current != pivot) {
        if (current->level > pivot->level) {
            if (*newHead == nullptr) *newHead = current;
            prev = current;
            current = current->next;
        } else {
            if (prev) prev->next = current->next;
            Commander* temp = current->next;
            current->next = nullptr;
            tail->next = current;
            tail = current;
            current = temp;
        }
    }
    if (*newHead == nullptr) *newHead = pivot;
    *newEnd = tail;
    return pivot;
}

Commander* quickSortRecur(Commander* start, Commander* end) {
    if (!start || start == end) return start;

    Commander* newHead = nullptr;
    Commander* newEnd = nullptr;

    Commander* pivot = partition(start, end, &newHead, &newEnd);

    if (newHead != pivot) {
        Commander* temp = newHead;
        while (temp->next != pivot) temp = temp->next;
        temp->next = nullptr;
        newHead = quickSortRecur(newHead, temp);
        temp = findMiddle(newHead);
        temp->next = pivot;
    }
    pivot->next = quickSortRecur(pivot->next, newEnd);
    return newHead;
}

void quickSort() {
    Commander* tail = head;
    while (tail != nullptr && tail->next != nullptr) tail = tail->next;
    head = quickSortRecur(head, tail);
}

void mergeSortAscending() {
    head = mergeSort(head);
}

void quickSortDescending() {
    quickSort();
}

void tampilkanCommander(bool ascending) {
    if (head == nullptr) {
        cout << "Tidak ada Commander yang tersedia.\n";
    } else {
        if (ascending) {
            mergeSortAscending();
        } else {
            quickSortDescending();
        }

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

void pushCommander(string nama, string kemampuan, int level) {
    Commander* commanderBaru = new Commander();
    commanderBaru->nama = nama;
    commanderBaru->kemampuan = kemampuan;
    commanderBaru->level = level;
    commanderBaru->next = head;
    head = commanderBaru;
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
    Commander* commanderBaru = new Commander();
    commanderBaru->nama = nama;
    commanderBaru->kemampuan = kemampuan;
    commanderBaru->level = level;
    commanderBaru->next = nullptr;

    if (head == nullptr) {
        head = commanderBaru;
    } else {
        Commander* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = commanderBaru;
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

int min(int x, int y) {
    return (x <= y) ? x : y;
}

int fibonacciSearch(Commander* head, int x) {
    int fib2 = 0;
    int fib1 = 1;
    int fib = fib2 + fib1;

    Commander* temp = head;
    int n = 0;
    while (temp != nullptr) {
        n++;
        temp = temp->next;
    }

    int offset = -1;

    while (fib < n) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib2 + fib1;
    }

    temp = head;
    while (fib > 1) {
        int i = min(offset + fib2, n - 1);
        Commander* commanderAtIndex = head;
        int index = 0;
        while (index < i && commanderAtIndex != nullptr) {
            commanderAtIndex = commanderAtIndex->next;
            index++;
        }

        if (commanderAtIndex->level < x) {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        } else if (commanderAtIndex->level > x) {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        } else {
            return i;
        }
    }

    if (fib1 && temp->level == x) {
        return offset + 1;
    }

    return -1;
}

int getSize(Commander* head) {
    int size = 0;
    Commander* temp = head;
    while (temp != nullptr) {
        size++;
        temp = temp->next;
    }
    return size;
}

int jumpSearch(Commander* head, int x) {
    int step = sqrt(getSize(head));
    Commander* prev = nullptr;
    Commander* temp = head;


    while (temp != nullptr && temp->level < x) {
        prev = temp;
        for (int i = 0; i < step && temp != nullptr; i++) {
            temp = temp->next;
        }
    }


    while (prev != nullptr && prev->level < x) {
        prev = prev->next;
    }

    if (prev != nullptr && prev->level == x) {
        return 1;
    }

    return -1;
}

#define NO_OF_CHARS 256
void badCharHeuristic(string str, int size, int badchar[NO_OF_CHARS]) {
    for (int i = 0; i < NO_OF_CHARS; i++) {
        badchar[i] = -1;
    }
    for (int i = 0; i < size; i++) {
        badchar[(int)str[i]] = i;
    }
}

int boyerMooreSearch(Commander* head, string pattern) {
    int m = pattern.size();
    int badchar[NO_OF_CHARS];

    badCharHeuristic(pattern, m, badchar);

    Commander* temp = head;
    int position = 1; 

    while (temp != nullptr) {
        string text = temp->nama;
        int n = text.size();
        int s = 0;

        while (s <= (n - m)) {
            int j = m - 1;

            while (j >= 0 && pattern[j] == text[s + j])
                j--;

            if (j < 0) {
                return position;
                s += (s + m < n) ? m - badchar[text[s + m]] : 1;
            } else {
                s += max(1, j - badchar[text[s + j]]);
            }
        }

        temp = temp->next;
        position++;
    }

    return -1;
}




int main() {
    int pilihan;

    do {
        cout << "\nMenu Commander Magic Chess\n";
        cout << "1. Tambah Commander (Linked List)\n";
        cout << "2. Tampilkan Daftar Commander (Ascending/Descending)\n";
        cout << "3. Update Commander\n";
        cout << "4. Hapus Commander\n";
        cout << "5. Push Commander ke Stack\n";
        cout << "6. Pop Commander dari Stack\n";
        cout << "7. Enqueue Commander ke Queue\n";
        cout << "8. Dequeue Commander dari Queue\n";
        cout << "9. Cari Commander menggunakan Fibonacci Search\n";
        cout << "10. Cari Commander menggunakan Jump Search\n";
        cout << "11. Cari Commander menggunakan Boyer-Moore Search\n";
        cout << "12. Keluar\n";
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
            int sort_choice;
            cout << "Pilih urutan: 1 untuk Ascending, 2 untuk Descending: ";
            cin >> sort_choice;
            tampilkanCommander(sort_choice == 1);
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
        }else if (pilihan == 9) {
            int level;
            cout << "Masukkan level Commander yang dicari: ";
            cin >> level;
            int result = fibonacciSearch(head, level);
            if (result != -1)
                cout << "Commander ditemukan pada posisi " << result << ".\n";
            else
                cout << "Commander tidak ditemukan.\n";
        } else if (pilihan == 10) {
            int level;
            cout << "Masukkan level Commander yang dicari: ";
            cin >> level;
            int result = jumpSearch(head, level);
            if (result != -1)
                cout << "Commander ditemukan pada posisi " << result << ".\n";
            else
                cout << "Commander tidak ditemukan.\n";
        } else if (pilihan == 11) {
            string nama;
            cout << "Masukkan nama Commander yang dicari: ";
            cin.ignore();
            getline(cin, nama);
            int result = boyerMooreSearch(head, nama);
            if (result != -1)
                cout << "Commander ditemukan pada posisi " << result << ".\n";
            else
                cout << "Commander tidak ditemukan.\n";
        }else if (pilihan != 12) {
            cout << "Pilihan tidak valid\n";
        }

    } while (pilihan != 12);

    cout << "Baik Terimakasih Atas Perhatiannya\n";
    return 0;
}
