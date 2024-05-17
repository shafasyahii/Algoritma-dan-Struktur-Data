# <h1 align="center">Tugas 2 CPMK 2 – SubCPMK 3 </h1>
<p align="center">Shafa Syahida</p>

### 1. Terdapat dua algoritma searching yang umum digunakan yakni, Binary Search dan Linear Search. Berikan penjelasan alur dari masing-masing algoritma tersebut, dan jelaskan runtime dari best case dan worst case masing-masing algoritma!   

#### Binary Search
Algoritma Binary Search hanya dapat digunakan pada kumpulan data yang sudah terurut. Algoritma ini bekerja dengan cara membagi kumpulan data menjadi dua bagian secara berulang, dan membuang setengah bagian yang tidak mungkin berisi nilai yang dicari. Proses ini diulang hingga nilai yang dicari ditemukan atau seluruh kumpulan data telah diperiksa.

##### Alur:
1. Inisialisasi variabel ```low``` sebagai indeks elemen pertama dan ```high``` sebagai indeks elemen terakhir dalam kumpulan data.
2. Lakukan loop while ```low``` lebih kecil dari atau sama dengan ```high```.
- Hitung nilai tengah (mid) sebagai rata-rata low dan high.
- Bandingkan nilai pada elemen ke-mid dengan nilai yang dicari.
Jika sama, kembalikan nilai mid.
Jika lebih kecil, ubah nilai high menjadi mid - 1 dan ulangi langkah 2.
Jika lebih besar, ubah nilai low menjadi mid + 1 dan ulangi langkah 2.
3. Jika loop selesai, nilai yang dicari tidak ditemukan, kembalikan nilai -1.

##### Runtime:
- Best Case: ```O(1)``` => Jika nilai yang dicari ditemukan pada elemen tengah pada iterasi pertama.
- Worst Case: ```O(log n)``` => Jika nilai yang dicari tidak ditemukan dan algoritma harus memeriksa setengah dari kumpulan data pada setiap iterasi.

#### Linear Search
Algoritma Linear Search bekerja dengan cara membandingkan nilai yang dicari dengan setiap elemen dalam kumpulan data secara berurutan. Jika nilai yang dicari ditemukan, maka posisinya dalam kumpulan data akan dikembalikan. Jika nilai yang dicari tidak ditemukan, maka algoritma akan mengembalikan nilai -1.

##### Alur:
1. Inisialisasi variabel ```i``` sebagai penunjuk ke elemen pertama dalam kumpulan data.
2. Lakukan loop while ```i``` lebih kecil dari panjang kumpulan data.
3. Bandingkan nilai pada elemen ke-```i``` dengan nilai yang dicari.
Jika sama, kembalikan nilai i.
Jika tidak sama, tingkatkan nilai i dan ulangi langkah 2.
4. Jika loop selesai, nilai yang dicari tidak ditemukan, kembalikan nilai -1.

##### Runtime:
- Best Case: ```O(1)``` - Jika nilai yang dicari ditemukan pada elemen pertama dalam kumpulan data.
- Worst Case: ```O(n)``` - Jika nilai yang dicari tidak ditemukan dan algoritma harus memeriksa semua elemen dalam kumpulan data.

##### Kesimpulan:

Algoritma Binary Search umumnya lebih efisien daripada Linear Search, terutama untuk kumpulan data yang besar. Namun, Binary Search hanya dapat digunakan pada kumpulan data yang sudah terurut. Linear Search dapat digunakan pada kumpulan data yang tidak terurut, tetapi akan kurang efisien untuk kumpulan data yang besar.

### 2. Buatlah fungsi dari salah satu algoritma searching pada soal nomor 1, dan berikan penjelasan pada program tersebut  

```C++
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
```
#### Output:
![image](https://github.com/shafasyahii/Praktikum-Struktur-Data-Assignment/assets/162096931/29f55d58-d38c-4192-9cdb-f6df23fbd639)

Kode di atas digunakan untuk melakukan binary search pada string. Fungsi ```binarySearch``` menerima dua parameter yaitu ```kalimat``` yang berisi sebuah string dan ```huruf``` yang berisi sebuah karakter. Fungsi ini menggunakan algoritma binary search untuk mencari posisi karakter ```huruf``` dalam string ```kalimat```. Jika karakter ```huruf``` ditemukan, fungsi akan mengembalikan indeksnya. Jika karakter ```huruf``` tidak ditemukan, fungsi akan mengembalikan -1. Selama belum menemukan karakter yang dicarit, fungsi ini akan melakukan iterasi sampai batas kiri lebih besar dari batas kanan. Pada setiap iterasi, fungsi akan membagi data menjadi dua bagian dan memilih bagian tengah untuk dibandingkan dengan karakter yang ingin dicari. Jika karakter yang dicari lebih besar dari karakter pada indeks tengah, maka fungsi akan melakukan pencarian pada bagian kanan. Sebaliknya, jika karakter yang dicari lebih kecil dari karakter pada indeks tengah, maka fungsi akan melakukan pencarian pada bagian kiri. Proses ini akan terus dilakukan sampai karakter dicari ditemukan atau bagian data habis.

### 3. Tulislah sebuah fungsi program dengan kondisi sebagai berikut: Terdapat sebuah sorted array of strings yang mana terdapat string kosong diantaranya, carilah lokasi/indeks dari kata yang dicari! 

```C++
#include <iostream>
#include <string>

using namespace std;

int findStringIndex(string arr[], int n, string target) {
  for (int i = 0; i < n; i++) {
    if (arr[i] == target) {
      return i;
    }
  }
  return -1; // jika tidak ditemukan
}

int main() {
  string arr[] = {"Adi", "", "", "", "bermain", "", "bola", "", "", "sedang"};
  int n = sizeof(arr) / sizeof(arr[0]);
  string target = "bola";

  int index = findStringIndex(arr, n, target);

  if (index != -1) {
    cout << "Kata '" << target << "' ditemukan pada indeks " << index << endl;
  } else {
    cout << "Kata '" << target << "' tidak ditemukan" << endl;
  }

  return 0;
}
```
#### Output:


Fungsi ```findStringIndex``` menerima tiga parameter: ```arr``` adalah array of strings, ```n``` adalah jumlah elemen dalam array, dan ```target``` adalah string yang ingin dicari.

Fungsi ini menggunakan loop untuk mengiterasi elemen-elemen dalam array. Pada setiap iterasi, fungsi membandingkan elemen array dengan ```target```. Jika elemen array sama dengan ```target```, maka fungsi mengembalikan indeks elemen tersebut.

Jika tidak ditemukan, fungsi mengembalikan nilai ```-1```.

Dalam main program, kita membuat array of strings ```arr``` dan mengisi nilai-nilai yang diberikan. Kemudian kita panggil fungsi ```findStringIndex``` dengan parameter ```arr```, ```n```, dan ```target```. Kemudian program akan menampilkan hasilnya pada konsol.