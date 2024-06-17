# <h1 align="center">Laporan Praktikum Modul Priority Queue</h1>
<p align="center">Shafa Syahida</p>

## Dasar Teori

### Priority Queue

Priority Queue adalah suatu bentuk struktur data yang berbasiskan struktur Queue pada umumnya. Pada priority Queue, terdapat salah satu bentuk implementasi yaitu implementasi menggunakan struktur data heaps. Dalam implementasi ini ada 3 pokok atribut yaitu heaps, comparator, dan last. Dengan menggunakan fasilitas heap ini kita bisa melakukan insert atau remove elemen dalam kompleksitas waktu logaritmik. Pada priority Queue ini, secara keseluruhan akan dibentuk sebuah pohon biner yang seimbang. Dalam pembuatan pohon biner ini diusahakan ketinggian yang terbentuk adalah minimum. Keminimuman tinggi pohon inilah yang menyebabkan kompleksitas waktu dalam memanipulasi daun menjadi fungsi logaritmik [1].

Struktur Priority Queue :

![Screenshot 2024-05-20 122259](https://github.com/shafasyahii/Praktikum-Struktur-Data-Assignment/assets/162096931/50f545db-cc6c-47fe-9718-2663c34ef1b6)

Heap menunjuk pada akar, last menunjuk pada elemen akhir, dan comparator menunjukan pembanding untuk menipulasi posisi [1].

#### Penggunaan dalam Algoritma
Priority Queue banyak digunakan dalam berbagai algoritma untuk memecahkan berbagai masalah. Beberapa penggunaan Priority Queue dalam algoritma antara lain:

- Algoritma Dijkstra: Digunakan untuk menemukan jalur terpendek dalam graf berbobot positif. Priority Queue memungkinkan pemilihan simpul berikutnya dengan bobot terkecil selama proses pencarian jalur terpendek.
- Algoritma A (A-Star): Sering digunakan dalam permasalahan pencarian jarak terpendek dengan heuristik. Priority Queue membantu memilih simpul berikutnya berdasarkan nilai fungsi heuristik dan jarak yang sudah dilalui.
- Algoritma Huffman: Digunakan dalam kompresi data, di mana elemen-elemen dengan frekuensi kemunculan yang lebih tinggi diberikan prioritas lebih tinggi saat pembuatan pohon Huffman.
- Penjadwalan Tugas: Priority Queue membantu dalam menentukan urutan penjadwalan tugas berdasarkan prioritas yang telah ditentukan.

## Referensi
[1] A. Nurcholis, S. Batara N, and M. Octamanullah, “Penerapan struktur data Heap Priority Queue pada algoritma Djikstra untuk mendapatkan kompleksitas O((n + m)log n),” pp. 1–4, 2020.