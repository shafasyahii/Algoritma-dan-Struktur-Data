# <h1 align="center">Tugas 2 CPMK 2 – SubCPMK 4 </h1>
<p align="center">Shafa Syahida</p>

### 1. Berikan penjelasan dari struct dan buatlah sebuah contoh program dari struct 

Struct atau Struktur adalah koleksi dari variabel yang dinyatakan dengan sebuah nama, dengan sifat setiap variabel dapat memiliki tipe yang berlainan. Struktur biasa dipakai untuk mengelompokkan beberapa informasi yang berkaitan menjadi sebuah satu kesatuan. Biasanya penamaan antar variabel di dalam struct saling berkaitan dan mendukung satu gagasan. Di dalam sebuah struct dapat dimungkinkan terdapat sebuah struct lagi. Hal ini dapat diartikan struct di dalam struct. Hampir sama dengan nested loop, yaitu for di dalam for. Struktur mempunyai persamaan dengan array yaitu pengalokasian memori untuk elemen-elemennya sudah di tentukan sebelum program dijalankan. Sedangkan perbedaannya, array memiliki tipe data dari elemen-elennya harus sama dan elemen-elemennya diaksesmenggunakan indeks dan struct memiliki tipe data dari elemen-elennya tidak harus sama dan elemen-elemennya diakses menggunakan identifier atau nama variabel.

#### Cara membuat struct
Struct dapat dibuat dengan kata kunci struct kemudian diikuti dengan nama struct dan isinya.
![image](https://github.com/shafasyahii/Praktikum-Struktur-Data-Assignment/assets/162096931/e2dc8ae6-7fdd-40a4-909c-691143199c93)

contoh :
```C++
struct Mahasiswa
{
    char *name;
    char *address;
    int age;
};
```

#### Program

```C++
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
```
#### Output:
![image](https://github.com/shafasyahii/Praktikum-Struktur-Data-Assignment/assets/162096931/7724986d-8afc-41c0-9e6a-64b64ce1ac14)

Program di atas digunakan untuk menyimpan dan mengeluarkan informasi tentang lima buku favorit. Program ini menggunakan struktur data bernama ```buku``` untuk menyimpan data-data tersebut. Struktur buku terdiri dari lima array, yaitu ```judul_buku```, ```pengarang```, ```penerbit```, ```tebal_halaman```, dan ```harga_buku```, yang berukuran masing-masing 5. Array-array ini akan digunakan untuk menyimpan judul, nama pengarang, nama penerbit, tebal halaman, dan harga buku-buku favorit. Dalam fungsi ```main()```, variabel favorit dideklarasikan sebagai instance dari struktur buku. Kemudian, data-data buku favorit diinisialisasi dan disimpan ke dalam array-array tersebut. Setelah itu, data-data tersebut dicetak menggunakan perulangan ```for``` dan fungsi ```cout```.