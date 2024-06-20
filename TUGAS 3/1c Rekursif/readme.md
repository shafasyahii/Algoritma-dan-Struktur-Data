# <h1 align="center">Rekursif</h1>
<p align="center">Shafa Syahida</p>

## Penjelasan

Rekursif adalah algoritma yang melakukan looping, memanggil dirinya sendiri untuk menyelesaikan masalah. Penting untuk mendefinisikan batasan agar putaran ini tidak tak terhingga dan menghabiskan memori. Tanpa batasan, algoritma akan terjebak dalam "infinity loop" dan program macet. Rekursif adalah teknik ampuh, namun harus digunakan cermat dengan batasan jelas [1]. Rekursi adalah proses berulang di mana suatu langkah dijalankan dengan cara menjalankan langkah yang sama [2]. Rekursi dalam pemrograman komputer dapat dianalogikan sebagai sebuah fungsi yang mendefinisikan dirinya sendiri dalam bentuk yang lebih kecil dan sederhana. Solusi untuk suatu permasalahan kompleks kemudian dibangun dengan menggabungkan solusi-solusi dari versi-versi sederhana tersebut [3].

![Screenshot 2024-06-07 105552](https://github.com/shafasyahii/Praktikum-Struktur-Data-Assignment/assets/162096931/0fce1228-9ab9-49bb-a0d9-51bba4708044)

Fungsi rekursif dapat dikategorikan sebagai salah satu jenis relasi. Dalam konteks ini, anggaplah terdapat himpunan A sebagai domain dan himpunan B sebagai codomain. Suatu relasi dikatakan sebagai fungsi jika setiap elemen dalam himpunan A terhubung dengan tepat satu elemen di dalam himpunan B [4]. Fungsi rekursif bekerja dengan cara memecah masalah besar menjadi masalah yang lebih kecil dan serupa, dan menyelesaikannya secara berulang hingga mencapai basis. Bagian basis, seperti ekor memberikan nilai awal dan menghentikan proses rekursi. Bagian rekurens mendefinisikan argumen fungsi dengan menggunakan dirinya sendiri, memastikan argumen semakin dekat ke basis pada setiap pemanggilan. Fungsi rekursif menawarkan cara yang elegan dan ringkas untuk menyelesaikan masalah yang dapat dipecah menjadi sub-masalah yang serupa [5].

Adapun aturan rekursif sebagai berikut [6]:

1. Kasus Dasar:
- Harus ada kondisi yang paling sederhana di mana masalah dapat diselesaikan tanpa perlu rekursif lagi.
- Kondisi ini disebut kasus dasar.

2. Rekursif Menuju Kasus Dasar:
- Setiap langkah rekursif harus membawa kita lebih dekat ke kasus dasar.
- Dengan kata lain, setiap langkah rekursif harus memperkecil masalah.

3. Asumsi Rekursif:
- Untuk menyelesaikan masalah rekursif, kita perlu asumsikan bahwa pemanggilan rekursif untuk sub-masalah yang lebih kecil sudah menghasilkan jawaban yang benar.
- Asumsi ini memungkinkan kita untuk membangun solusi dari solusi sub-masalah.

4. Menghindari Duplikasi:
- Pastikan untuk tidak memanggil sub-masalah yang sama secara berulang dalam proses rekursif.
- Hal ini dapat dilakukan dengan teknik seperti memoisasi atau tabel hasil.

Contoh: Fungsi ```pangkatRekursif(x, n)``` menghitung pangkat ```x``` berpangkat ```n```.

Kasus dasar: Jika ```n = 0```, maka ```x^n = 1```.

Rekursif menuju kasus dasar: Jika ```n > 0```, maka ```x^n = x * x^(n-1)```.

Asumsi rekursif: Asumsikan bahwa ```pangkatRekursif(x, n-1)``` menghasilkan nilai yang benar.

Penggabungan: Untuk menghitung ```x^n```, kalikan ```x^(n-1)``` dengan ```x```.

## Program
```C++
#include <iostream>

using namespace std;

int faktorial(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * faktorial(n - 1);
  }
}

int main() {
  int n;

  cout << "Masukkan bilangan: ";
  cin >> n;

  cout << n << "! = " << faktorial(n) << endl;

  return 0;
}
```

#### Penjelasan Alur Program
1. Fungsi ```faktorial(int n)```:
Merupakan fungsi rekursif yang menerima parameter ```n``` (bilangan yang ingin dihitung faktorialnya). Memiliki dua kondisi: Jika ```n``` sama dengan 0, maka fungsi akan mengembalikan nilai 1 (faktorial 0 selalu 1). Jika ```n``` tidak sama dengan 0, maka fungsi akan mengembalikan hasil perkalian ```n``` dengan pemanggilan rekursif fungsi ```faktorial(n - 1)```. Pemanggilan rekursif ini akan terus berulang hingga ```n``` mencapai 0.

2. Fungsi main():
Meminta input bilangan dari pengguna dan menyimpannya dalam variabel ```n```. Kemudian memanggil fungsi ```faktorial(n)``` untuk menghitung faktorial dari bilangan ```n```. Terakhir, program akan menampilkan hasil perhitungan faktorial pada layar.

## Referensi
[1] M. Ahmad. (2016, 30 Desember). Memahami Cara Kerja Fungsi Rekursif. Diakses pada 27 Mei 2024, dari https://www.petanikode.com/fungsi-rekursif/.

[2] F. A. T. Tobing and A. Chandra, “Analisis Perbandingan Fibonacci dengan Iterasi dan Rekursi Terhadap Efektifitas Waktu,” J. Sains dan Teknol. Widya, vol. 1, no. 2, pp. 188–195, 2022, [Online]. Available: https://jurnal.amikwidyaloka.ac.id/index.php/jstekwid

[3] https://id.m.wikipedia.org/wiki/Rekursi. Diakses pada 27 Mei 2024

[4] R. Munir, *Struktur Diskrit*, ITB, 2008

[5] S. Herlambang, “Implementasi Fungsi Rekursif Dalam Algoritma dan Perbandingannya dengan Fungsi Iteratif,” p. 6, 2018, [Online]. Available: https://informatika.stei.itb.ac.id/~rinaldi.munir/Matdis/2008-2009/Makalah2008/Makalah0809-079.pdf

[6] S. Setiawan, R. Manurung, and A. Azurat, “Struktur Data dan Algoritma Dasar-dasar Rekursif Devide and Conquer Mengulang : Maximum Contiguous subsequence,” 2010.

