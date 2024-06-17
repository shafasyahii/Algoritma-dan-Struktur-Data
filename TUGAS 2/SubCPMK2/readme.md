# <h1 align="center">Tugas 2 CPMK 2 – SubCPMK 2 </h1>
<p align="center">Shafa Syahida</p>

### 1. Terdapat tiga algoritma sorting yang umum digunakan yakni, Bubble Sort, Selection Sort, dan Merge Sort. Berikan penjelasan alur dari masing-masing algoritma tersebut, dan jelaskan runtime dari best case dan worst case masing-masing algoritma! 

#### Bubble Sort

##### Alur:
1. Lakukan perulangan sebanyak n-1 kali, di mana n adalah jumlah elemen dalam array.
2. Pada setiap perulangan, bandingkan setiap elemen dengan elemen di sebelahnya.
3. Jika elemen pertama lebih besar dari elemen kedua, tukar posisinya.
4. Lakukan hal ini hingga seluruh elemen terurut.

##### Runtime:
- Best Case: ```O(n)``` => Terjadi ketika array sudah terurut, sehingga tidak ada pertukaran yang perlu dilakukan.
- Worst Case: ```O(n^2)``` => Terjadi ketika array terbalik, sehingga membutuhkan n-1 perulangan untuk mengurutkan semua elemen.

#### Selection Sort

##### Alur:
1. Temukan elemen terkecil dalam array.
2. Tukar elemen terkecil dengan elemen pertama dalam array.
3. Ulangi langkah 1 dan 2 untuk elemen berikutnya, hingga seluruh elemen terurut.

##### Runtime:
- Best Case: ```O(n)``` => Terjadi ketika array sudah terurut, sehingga elemen terkecil mudah ditemukan pada setiap perulangan.
- Worst Case: ```O(n^2)``` => Terjadi ketika array teracak, sehingga membutuhkan n perulangan untuk menemukan elemen terkecil pada setiap iterasi.

#### Merge Sort

##### Alur:
1. Bagi array menjadi dua bagian secara rekursif.
2. Urutkan kedua bagian secara terpisah menggunakan Merge Sort.
3. Gabungkan kedua bagian yang terurut menjadi satu array terurut.

##### Runtime:
- Best Case: ```O(n log n)``` => Terjadi ketika array terbagi secara merata pada setiap pembagian rekursif.
- Worst Case: ```O(n log n)``` => Terjadi ketika array selalu terbagi tidak merata pada setiap pembagian rekursif.

#### Kesimpulan:

- Bubble Sort: sederhana dan mudah dipahami, namun memiliki runtime yang lambat untuk array besar.
- Selection Sort: lebih cepat daripada Bubble Sort untuk array besar, namun masih memiliki runtime yang lambat dibandingkan Merge Sort.
- Merge Sort: memiliki runtime yang paling efisien (O(n log n)) untuk semua kasus, namun implementasinya lebih kompleks.

### 2. Buatlah fungsi dari salah satu algoritma sorting pada soal nomor 1, dan berikan penjelasan pada program tersebut 

#### Bubble Sorting

```C++
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void bubble_sort(string arr[], int length){
    bool not_sorted = true;
    int j=0;
    string tmp;

    while (not_sorted){
        not_sorted = false;
        j++;
        for (int i=0; i < length - j; i++){
            if (arr[i] > arr[i + 1]) {
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                not_sorted = true;
            }
        }
    }
}

void print_array(string a[], int length) {
    for(int i=0; i<length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main() {

    int length = 10;
    string a[] = {"siti", "situ", "sana", "ana", "ani", "caca", "cici", "dida", "dodo", "dadi"};

    cout << "Nama-nama sebelum sorting: " << endl;
    print_array(a, length);

    bubble_sort(a, length);

    cout << "\nNama-nama setelah sorting: " << endl;
    print_array(a, length);
}
```
#### Output:
![image](https://github.com/shafasyahii/Praktikum-Struktur-Data-Assignment/assets/162096931/0a6e192c-aa4c-4fb7-973b-3d3e0c09236c)

Kode di atas digunakan untuk mengurutkan sebuah array string menggunakan algoritma sorting bubble sort. Algoritma bubble sort adalah salah satu algoritma sorting yang paling sederhana, tetapi memiliki kompleksitas waktu beraturan O(n^2), dimana n adalah panjang array. Hal ini disebabkan karena proses perbandingan dan penggantian elemen array yang dilakukan dalam setiap iterasi, yang mencapai n-1 iterasi. Algoritma bubble sort memiliki kompleksitas ruang beraturan O(1), dimana ruang yang dibutuhkan untuk menyimpan array dan beberapa variabel bantu. Hal ini disebabkan karena tidak ada alokasi memori yang berubah-ubah selama proses sorting.

Fungsi ```bubble_sort``` menerima array string dan panjang array sebagai parameter. Fungsi ```print_array``` digunakan untuk menampilkan isi array string.
Dalam fungsi ```main()```, array string ```a``` didefinisikan dengan panjang 10 dan isinya adalah beberapa nama. Proses sorting dilakukan dengan menyebutkan fungsi ```bubble_sort``` dengan parameter array ```a``` dan panjang ```length```. Setelah sorting, isi array ```a``` dicetak menggunakan fungsi ```print_array```. Terakhir, program akan menampilkan nama-nama sebelum sorting dan setelah sorting.

### 3. Tulislah sebuah fungsi untuk mensorting dan mengecek dua buah array of strings, sehingga menghasilkan “anagram” dan “tidak anagram” 

```C++
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isAnagram(const string& str1, const string& str2) {
    if (str1.length() != str2.length()) {
        return false;
    }

    string temp1 = str1;
    string temp2 = str2;

    sort(temp1.begin(), temp1.end());
    sort(temp2.begin(), temp2.end());

    return temp1 == temp2;
}

int main() {
    string str1, str2;

    cout << "Masukkan string 1: ";
    cin >> str1;

    cout << "Masukkan string 2: ";
    cin >> str2;

    if (isAnagram(str1, str2)) {
        cout << "Anagram" << endl;
    } else {
        cout << "Tidak anagram" << endl;
    }

    return 0;
}
```
#### Output :
![Screenshot 2024-05-16 202238](https://github.com/shafasyahii/Algoritma-dan-Struktur-Data/assets/162096931/ad3ef189-12a3-4c00-8e4f-9f1ee31ad0e3)

Fungsi ```isAnagram``` mengambil dua parameter: ```str1``` dan ```str2```, yang merupakan dua buah string yang akan dicek apakah mereka adalah anagram atau tidak.

Fungsi ini pertama-tama memeriksa apakah panjang kedua string sama. Jika tidak, maka fungsi langsung mengembalikan ```false```, karena anagram harus memiliki panjang yang sama.

Kemudian, fungsi membuat dua buah string temporary, ```temp1``` dan ```temp2```, yang merupakan salinan dari ```str1``` dan ```str2```. Fungsi sort dari library ```<algorithm>``` digunakan untuk mengurutkan karakter-karakter dalam kedua string temporary.

Terakhir, pada main program fungsi memeriksa apakah kedua string temporary sama. Jika sama, maka fungsi mengembalikan ```true```, yang berarti ```str1``` dan ```str2``` adalah anagram. Jika tidak sama, maka fungsi mengembalikan ```false```, yang berarti ```str1``` dan ```str2``` tidak anagram.

### 4. Tulislah sebuah fungsi program dengan asumsi sebagai berikut: Terdapat dua buah sorted array A dan B yang memiliki tipe data sama, dimana array A memiliki indeks yang cukup untuk menampung array B. Gabungkan array B kedalam array A, kemudian urutkan array tersebut! 

```C++
#include <iostream>

using namespace std;

void mergeArrays(int A[], int m, int B[], int n, int C[]) {
  int i = 0, j = 0, k = 0;

  // Lintasi kedua array dan masukkan elemen yang lebih kecil ke dalam C
  while (i < m && j < n) {
    if (A[i] <= B[j]) {
      C[k++] = A[i++];
    } else {
      C[k++] = B[j++];
    }
  }

  // Salin elemen yang tersisa dari A
  while (i < m) {
    C[k++] = A[i++];
  }

  // Salin elemen yang tersisa dari B
  while (j < n) {
    C[k++] = B[j++];
  }
}

int main() {
  int A[] = {2, 5, 8, 12};
  int m = sizeof(A) / sizeof(A[0]);
  int B[] = {1, 3, 4, 9};
  int n = sizeof(B) / sizeof(B[0]);

  // asumsi ruang yang cukup di C untuk menampung kedua array
  int C[m + n];

  mergeArrays(A, m, B, n, C);

  cout << "Merged and sorted array: ";
  for (int i = 0; i < m + n; i++) {
    cout << C[i] << " ";
  }
  cout << endl;

  return 0;
}
```
#### Output :
![Screenshot 2024-05-16 204417](https://github.com/shafasyahii/Algoritma-dan-Struktur-Data/assets/162096931/707f6a97-e111-40c9-835b-5a058f908962)

Fungsi utama program ini terletak pada fungsi ```mergeArrays```. Fungsi ini menerima lima buah parameter yaitu:

- A: Array pertama yang ingin digabungkan (integer)
- m: Ukuran dari array A (integer)
- B: Array kedua yang ingin digabungkan (integer)
- n: Ukuran dari array B (integer)
- C: Array kosong yang akan menjadi tempat hasil penggabungan (integer)

Di dalam fungsi ```mergeArrays```, terdapat tiga variable iterator yaitu ```i```, ```j```, dan ```k```. ```i``` dan ```j``` digunakan untuk menelusuri array A dan B, sedangkan ```k``` digunakan untuk menandai posisi elemen berikutnya pada array C.

Proses penggabungan dilakukan dengan membandingkan elemen terdepan dari kedua array (A[i] dan B[j]). Elemen yang lebih kecil kemudian disalin ke dalam array C dan iterator terkait (i atau j) dimajukan. Proses ini terus berulang hingga salah satu array telah habis. Setelah itu, sisa elemen dari array yang belum habis disalin ke dalam array C.

Pada fungsi main, program mendeklarasikan dua buah array yaitu A dan B yang sudah terurut. Ukuran dari kedua array tersebut kemudian dihitung menggunakan operator ```sizeof``` dan dibagi dengan ukuran dari elemen tunggal (sizeof(A[0])). Array kosong C kemudian dialokasikan dengan ukuran yang cukup untuk menampung seluruh elemen dari kedua array (m + n).

Setelah itu, fungsi ```mergeArrays``` dipanggil untuk menggabungkan array A dan B ke dalam array C. Hasil penggabungan yang berupa array C yang sudah terurut kemudian ditampilkan ke konsol.
