# <h1 align="center">Laporan Praktikum Modul Rekursif</h1>
<p align="center">Shafa Syahida</p>

## Dasar Teori

Rekursif adalah sebuah algoritma yang berisi pemanggilan dirinya sendiri sehingga menghasilkan looping. Harus ada batasan di dalam rekursif sehingga looping dapat dibatalkan, jika tidak maka akan terjadi infinity loop dan dapat menyebabkan memori penuh [1]. Rekursi adalah suatu proses dengan salah satu langkah dalam prosedur tersebut menjalankan prosedur itu sendiri [2]. Dalam pemrograman komputer, rekursi dicontohkan saat sebuah fungsi didefinisikan dalam bentuk sederhana, bahkan versi terkecil dari dirinya. Solusi dari permasalahan kemudian dirancang dengan menggabungkan solusi-solusi yang didapat dari versi sederhana dari permasalahan [3].

![Screenshot 2024-06-07 105552](https://github.com/shafasyahii/Praktikum-Struktur-Data-Assignment/assets/162096931/0fce1228-9ab9-49bb-a0d9-51bba4708044)

Fungsi rekursif merupakan salah satu jenis relasi. Misalkan terdapat himpunan A sebagai domain dan himpunan B seabgai codomain, maka suatu relasi disebut fungsi jika relasi tersebut menghubungkan setiap elemen di dalam A ke tepat satu elemen di dalam B [4]. Fungsi rekursif adalah fungsi yang mengacu pada dirinya sendiri. Fungsi rekursif disusun atas dua bagian, yaitu basis dan rekurens. Basis berisi nilai awal yang tidak mengacu pada dirinya sendiri. Bagian ini berfungsi untuk memberikan nilai yang terdefinisi pada fungsi rekursif dan sekaligus menghentikan proses rekursi. Rekurens merupakan bagian fungsi yang mendefinisikan argumen fungsi dalam terminologi dirinya sendiri. Setiap kali fungsi tersebut melakukan bagian rekurens maka argumen dari fungsi tersebut harus lebih dekat pada basisnya [5].

Adapun aturan rekursif sebagai berikut [6]:

1. Punya kasus dasar
- Kasus yang sangat sederhana yang dapat memproses input tanpa perlu melakukan rekursif (memanggil method) lagi
2. Rekursif mengarah ke kasus dasar
3. “You gotta believe”. Asumsikan rekursif bekerja benar. Pada proses pemanggilan rekursif, asumsikan bahwa pemanggilan rekursif (untuk problem yang lebih kecil) adalah benar.
Contoh: ```pangkatRekursif (x, n)```
- Asumsikan: ```pangkatRekursif (x, n - 1)``` menghasilkan nilai yang benar.
- Nilai tersebut harus diapakan sehingga menghasilkan nilai ```pangkatRekursif (x, n)``` yang benar?
- Jawabannya: dikalikan dengan ```x```
4. Aturan penggabungan: Hindari duplikasi pemanggilan rekursif untuk sub-problem yang sama.

## Referensi
[1] M. Ahmad. (2016, 30 Desember). Memahami Cara Kerja Fungsi Rekursif. Diakses pada 27 Mei 2024, dari https://www.petanikode.com/fungsi-rekursif/.

[2] F. A. T. Tobing and A. Chandra, “Analisis Perbandingan Fibonacci dengan Iterasi dan Rekursi Terhadap Efektifitas Waktu,” J. Sains dan Teknol. Widya, vol. 1, no. 2, pp. 188–195, 2022, [Online]. Available: https://jurnal.amikwidyaloka.ac.id/index.php/jstekwid

[3] https://id.m.wikipedia.org/wiki/Rekursi. Diakses pada 27 Mei 2024

[4] R. Munir, *Struktur Diskrit*, ITB, 2008

[5] S. Herlambang, “Implementasi Fungsi Rekursif Dalam Algoritma dan Perbandingannya dengan Fungsi Iteratif,” p. 6, 2018, [Online]. Available: https://informatika.stei.itb.ac.id/~rinaldi.munir/Matdis/2008-2009/Makalah2008/Makalah0809-079.pdf

[6] S. Setiawan, R. Manurung, and A. Azurat, “Struktur Data dan Algoritma Dasar-dasar Rekursif Devide and Conquer Mengulang : Maximum Contiguous subsequence,” 2010.

