#include <iostream>
using namespace std;

void Hanoi(int n, char asal, char tujuan, char sementara) {
    if (n == 1) {
        cout << "Pindahkan cakram 1 dari " << asal << " ke " << tujuan << endl;
        return;
    }
    Hanoi(n - 1, asal, sementara, tujuan);
    cout << "Pindahkan cakram " << n << " dari " << asal << " ke " << tujuan << endl;
    Hanoi(n - 1, sementara, tujuan, asal);
}

int main() {
    int n = 3;
    Hanoi(n, 'A', 'C', 'B');
    return 0;
}
