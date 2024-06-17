#include <iostream>
#include <string>

using namespace std;

// Create a structure named 'buku' with arrays of size 5
struct buku {
    string judul_buku[5];
    string pengarang[5];
    string penerbit[5];
    int tebal_halaman[5];
    double harga_buku[5];
};

int main() {
    // Initialize and fill the 'buku' structure
    buku favorit;
    favorit.judul_buku[0] = "The Catcher in the Rye";
    favorit.judul_buku[1] = "Catch-22";
    favorit.judul_buku[2] = "To Kill a Mockingbird";
    favorit.judul_buku[3] = "1984";
    favorit.judul_buku[4] = "Brave New World";

    favorit.pengarang[0] = "J.D. Salinger";
    favorit.pengarang[1] = "Joseph Heller";
    favorit.pengarang[2] = "Harper Lee";
    favorit.pengarang[3] = "George Orwell";
    favorit.pengarang[4] = "Aldous Huxley";

    favorit.penerbit[0] = "Little, Brown and Company";
    favorit.penerbit[1] = "Simon & Schuster";
    favorit.penerbit[2] = "Harper & Row";
    favorit.penerbit[3] = "Secker and Warburg";
    favorit.penerbit[4] = "Chatto & Windus";

    favorit.tebal_halaman[0] = 277;
    favorit.tebal_halaman[1] = 453;
    favorit.tebal_halaman[2] = 281;
    favorit.tebal_halaman[3] = 328;
    favorit.tebal_halaman[4] = 199;

    favorit.harga_buku[0] = 9.99;
    favorit.harga_buku[1] = 12.99;
    favorit.harga_buku[2] = 7.99;
    favorit.harga_buku[3] = 10.99;
    favorit.harga_buku[4] = 8.99;

    // Display the content of the 'buku' structure
    for (int i = 0; i < 5; i++) {
        cout << "\tBuku Favorit Saya" << endl;
        cout << "\tJudul Buku : " << favorit.judul_buku[i] << endl;
        cout << "\tPengarang : " << favorit.pengarang[i] << endl;
        cout << "\tPenerbit : " << favorit.penerbit[i] << endl;
        cout << "\tTebal Halaman: " << favorit.tebal_halaman[i] << " halaman" << endl;
        cout << "\tHarga Buku : Rp " << favorit.harga_buku[i] << endl;
        cout << "-------------------------" << endl;
    }

    return 0;
}