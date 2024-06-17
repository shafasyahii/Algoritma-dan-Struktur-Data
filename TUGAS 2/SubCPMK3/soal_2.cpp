#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// Fungsi untuk melakukan binary search pada string
int binarySearch(const string& kalimat, char huruf) {
    int left = 0;
    int right = kalimat.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (kalimat[mid] == huruf) {
            return mid; // Huruf ditemukan pada indeks mid
        } else if (kalimat[mid] < huruf) {
            left = mid + 1; // Cari di bagian kanan
        } else {
            right = mid - 1; // Cari di bagian kiri
        }
    }

    return -1; // Huruf tidak ditemukan
}

int main() {
    string kalimat;
    char huruf;

    cout << "Masukkan kalimat atau huruf: ";
    getline(cin, kalimat);

    cout << "Masukkan huruf yang ingin dicari: ";
    cin >> huruf;

    // Ubah semua huruf menjadi lowercase untuk pencarian yang case-insensitive
    transform(kalimat.begin(), kalimat.end(), kalimat.begin(), ::tolower);

    int hasil = binarySearch(kalimat, huruf);

    if (hasil != -1) {
        cout << "Huruf '" << huruf << "' ditemukan pada indeks ke-" << hasil << endl;
    } else {
        cout << "Huruf '" << huruf << "' tidak ditemukan dalam kalimat atau huruf yang diinput." << endl;
    }

    return 0;
}