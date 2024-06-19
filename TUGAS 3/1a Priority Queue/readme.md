# <h1 align="center">Priority Queue</h1>
<p align="center">Shafa Syahida</p>

## Penjelasan

### Priority Queue

Priority Queue adalah adalah suatu bentuk struktur data berdasarkan struktur Queue umum.  Salah satu bentuk implementasi Priority Queue adalah dengan menggunakan struktur data heaps. Implementasi ini memiliki tiga atribut utama: Heaps, Comparator, dan Load Fungsi heap ini memungkinkan Anda menyisipkan atau menghapus elemen dengan kompleksitas waktu logaritmik. Pohon biner seimbang dibentuk secara keseluruhan dari Priority Queue ini. Saat pohon biner ini dibuat, ketinggian minimum dipertahankan. Ketinggian pohon minimum ini menambah kompleksitas waktu saat mengubah daun menjadi fungsi logaritmik [1].

Struktur Priority Queue :

![Screenshot 2024-05-20 122259](https://github.com/shafasyahii/Praktikum-Struktur-Data-Assignment/assets/162096931/50f545db-cc6c-47fe-9718-2663c34ef1b6)

Heap mengacu pada elemen teratas dalam struktur data yang mirip pohon, last mengacu pada elemen terakhir dalam daftar, dan comparator mengacu pada fungsi yang digunakan untuk membandingkan elemen dan menentukan posisinya dalam struktur data. [1].

#### Penggunaan dalam Algoritma
Priority Queue, atau antrian prioritas, memainkan peran penting dalam berbagai algoritma untuk menyelesaikan berbagai permasalahan. Berikut beberapa contoh penerapannya [2]:

1. Algoritma Pencarian Jalur Terpendek
Algoritma Dijkstra digunakan untuk menemukan jalur terpendek dalam graf berbobot positif. Priority Queue membantu memilih simpul berikutnya dengan bobot terkecil selama proses pencarian, sehingga mengoptimalkan efisiensi.

2. Algoritma Pencarian Heuristik
Algoritma A (A-Star) sering digunakan dalam permasalahan pencarian jarak terpendek dengan heuristik. Priority Queue membantu memilih simpul berikutnya berdasarkan kombinasi nilai fungsi heuristik dan jarak yang sudah dilalui, menghasilkan solusi yang lebih cepat dan akurat.

3. Algoritma Kompresi Data
Algoritma Huffman digunakan dalam kompresi data, di mana elemen-elemen dengan frekuensi kemunculan yang lebih tinggi diprioritaskan saat membangun pohon Huffman. Hal ini menghasilkan representasi data yang lebih ringkas dan efisien.

4. Penjadwalan Tugas
Priority Queue membantu menentukan urutan penjadwalan tugas berdasarkan prioritas yang telah ditentukan. Tugas dengan prioritas tinggi didahulukan, memastikan kelancaran dan efisiensi proses.

Secara keseluruhan, Priority Queue merupakan alat yang penting dalam berbagai algoritma, memungkinkan solusi yang lebih optimal dan efisien untuk berbagai permasalahan komputasi.

## Program
```C++
#include <iostream>
#include <queue>

using namespace std;

int main() {
    // Deklarasi priority queue
    priority_queue<int> pq;

    // Menambahkan elemen ke priority queue
    pq.push(5);
    pq.push(3);
    pq.push(8);
    pq.push(1);
    pq.push(9);

    // Menampilkan elemen priority queue
    cout << "Priority Queue: ";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    return 0;
}
```

#### Penjelasan Alur Program
1. Implementasi program ini memanfaatkan pustaka ```iostream``` untuk menangani input atau output dan ```queue``` untuk mengelola antrian prioritas.

2. Variabel bernama ```pq ``` dideklarasikan sebagai antrian prioritas yang mampu menyimpan elemen bertipe integer.

3. Elemen 5, 3, 8, 1, dan 9 dimasukkan ke dalam antrian prioritas menggunakan fungsi ```push```.

4. Elemen-elemen dalam antrian prioritas kemudian ditampilkan melalui perulangan ```while``` yang berlanjut hingga antrian prioritas kosong. Pada setiap iterasi, elemen teratas dengan prioritas tertinggi diambil menggunakan fungsi ```top``` dan dihapus menggunakan fungsi ```pop```. Elemen tersebut kemudian ditampilkan ke layar.

5. Terakhir, program akan menampilkan elemen-elemen antrian prioritas dalam urutan prioritas terbalik, yaitu 9, 8, 5, 3, dan 1.

## Referensi
[1] A. Nurcholis, S. Batara N, and M. Octamanullah, “Penerapan struktur data Heap Priority Queue pada algoritma Djikstra untuk mendapatkan kompleksitas O((n + m)log n),” pp. 1–4, 2020.

[2] F. Amarizuki, "Priority Queue: Konsep dan Penggunaan dalam Algoritma," Medium, 2024, [Online]. Available: https://medium.com/@furatamarizuki/priority-queue-konsep-dan-penggunaan-dalam-algoritma-f4c1cd117ba.