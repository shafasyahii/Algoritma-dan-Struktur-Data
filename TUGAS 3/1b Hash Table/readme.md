# <h1 align="center">Laporan Praktikum Modul Hash Table</h1>
<p align="center">Shafa Syahida</p>

## Dasar Teori

![Screenshot 2024-06-04 165113](https://github.com/shafasyahii/Praktikum-Struktur-Data-Assignment/assets/162096931/f0969902-2af4-4742-b998-55e3f9369093)

Tabel hash adalah sebuah cara untuk menyimpan suatu data pada memori ke dalam baris-baris dan kolom-kolom sehingga membentuk tabel yang dapat diakses dengan cepat [1]. Setiap sel yang merupakan pertemuan antara baris dan kolom di dalam tabel hash dimana data diarsipkan disebut dengan slot [2]. Sebuah tabel hash dapat dibuat dari dua bagian, yaitu sebuah larik atau array dan sebuah fungsi untuk memetakan, yang disebut dengan fungsi hash atau hash function. Fungsi hash adalah pemetaan ke dalam larik sesuai dengan kunci-kunci yang diberikan, dengan kata lain fungsi hash mendistribusikan data yang dimasukkan oleh pengguna ke dalam tabel atau larik yang telah disediakan [3].

Algoritma Hash dapat melakukan proses tambah, hapus dan pencarian dalam waktu yang konstan [4]. Waktu konstan ini juga disebut sebagai kekompleksan waktu O(1). Teknik Hash merupakan suatu metode yang secara langsung mengakses data record dalam suatu tabel dengan melakukan penghitungan pada key yang menjadi alamat record pada tabel. Key merupakan suatu data yang unik dapat berupa nomor atau karakter string [5]. 

Hash table menggunakan memori penyimpanan utama berbentuk array dengan tambahan algoritma untuk mempercepat pemrosesan data. Pada intinya hash table merupakan penyimpanan data menggunakan key value yang didapat dari nilai data itu sendiri. Dengan key value tersebut didapat hash value. Jadi hash function merupakan suatu fungsi sederhana untuk mendapatkan hash value dari key value suatu data. Yang perlu diperhatikan untuk membuat hash function adalah:

- ukuran array/table size(m),
- key value/nilai yang didapat dari data(k),
- hash value/hash index/indeks yang dituju(h).

### 1. Fungsi
Fungsi hash membuat pemetaan antara kunci dan nilai, hal ini dilakukan melalui penggunaan rumus matematika yang dikenal sebagai fungsi hash. Hasil dari fungsi hash disebut sebagai nilai hash atau hash. Nilai hash adalah representasi dari string karakter asli tetapi biasanya lebih kecil dari aslinya.

### 2. Operasi
Di C++, operasi tabel hash melibatkan berbagai tugas untuk penanganan data yang efisien:

- Insertion: Menambahkan pasangan nilai kunci ke tabel.
- Search: Menemukan nilai menggunakan kunci yang sesuai.
- Deletion: Menghapus pasangan nilai kunci sesuai kebutuhan.
- Resizing: Menyesuaikan ukuran tabel untuk mengoptimalkan kinerja.
- Collision Handling: Mengelola situasi ketika beberapa kunci dipetakan ke indeks yang sama.
- Load Factor Maintenance: Memastikan keseimbangan optimal antara elemen dan ukuran tabel.
- Traversal: Mengulangi pasangan nilai kunci untuk mengakses atau memproses data.
- Clearing: Mengosongkan tabel hash dengan menghapus semua elemen.

### 3. Collison
Berikut contoh penggunaan hash table dengan hash function sederhana yaitu memodulus key value dengan ukuran array : h = k (mod m)

Misal kita memiliki array dengan ukuran 13, maka hash function : h = k (mod 13).

Dengan hash function tersebut didapat :

k	H
7	7
13	0
25	12
27	1
39	0
Perhatikan range dari h untuk sembarang nilai k.

Maka data 7 akan disimpan pada index 7, data 13 akan disimpan pada index 0, dst..

Untuk mencari kembali suatu data, maka kita hanya perlu menggunakan hash function yang sama sehingga mendapatkan hash index yang sama pula.

Misal : mencari data 25 → h = 25 (mod 13) = 12

Namun pada penerapannya, seperti contoh di atas terdapat tabrakan (collision) pada k = 13 dan k = 39. Collision berarti ada lebih dari satu data yang memiliki hash index yang sama, padahal seperti yang kita ketahui, satu alamat / satu index array hanya dapat menyimpan satu data saja.

Untuk meminimalkan collision gunakan hash function yang dapat mencapai seluruh indeks/alamat. Dalam contoh di atas gunakan m untuk me-modulo k. Perhatikan bila kita menggunakan angka m untuk me-modulo k maka pada indeks yang lebih besar dari dan sama dengan m di hash table tidak akan pernah terisi (memori yang terpakai semakin kecil), kemungkinan terjadi collision juga semakin besar.

Karena memori yang terbatas dan untuk masukan data yang belum diketahui tentu collision tidak dapat dihindari.

Berikut ini cara-cara yang digunakan untuk mengatasi collision :

1.   Closed hashing (Open Addressing)

Close hashing menyelesaikan collision dengan menggunakan memori yang masih ada tanpa menggunakan memori diluar array yang digunakan. Closed hashing mencari alamat lain apabila alamat yang akan dituju sudah terisi oleh data. 3 cara untuk mencari alamat lain tersebut :

Ø Linear Probing
Apabila telah terisi, linear probing mencari alamat lain dengan bergeser 1 indeks dari alamat sebelumnya hingga ditemukan alamat yang belum terisi data, dengan rumus

(h+1) mod m.

Ø Quadratic Probing
Quadratic Probing mencari alamat baru untuk ditempati dengan proses perhitungan kuadratik yang lebih kompleks. Tidak ada formula baku pada quadratic probing ini,anda dapat menentukan sendiri formula yang akan digunakan.

Contoh formula quadratic probing untuk mencari alamat baru:

h,(h+i2)mod m,(h-i2)mod m, … ,(h+((m-1)/2)2)mod m, (h-((m-1)/2)2)mod m

dengan i = 1,2,3,4, … , ((m-1)/2)

Mksud formula di atas adalah jika alamat h telah terisi, maka alamat lain yang digunakan adalah (h+1)mod m, jika telah terisi gunakan alamat (h-1)mod m,  jika telah terisi gunakan alamat (h+4)mod m, jika telah terisi gunakan alamat (h-4)mod m, dan seterusnya.

Jadi jika m=23,maka nilai maksimal i adalah : ((23-1)/2)=11.

- Linear Probing
Pada saat terjadi collision, maka akan mencari posisi yang kosong di bawah tempat terjadinya collision, jika masih penuh terus ke bawah, hingga ketemu tempat yang kosong. Jika tidak ada tempat yang kosong berarti HashTable sudah penuh.
- Quadratic Probing
Penanganannya hampir sama dengan metode linear, hanya lompatannya tidak satu-satu, tetapi quadratic ( 12, 22, 32, 42, ... )
- Double Hashing
Pada saat terjadi collision, terdapat fungsi hash yang kedua untuk menentukan posisinya kembali.

2. Open hashing (Separate Chaining)
Pada dasarnya separate chaining membuat tabel yang digunakan untuk proses hashing menjadi sebuah array of pointer yang masing-masing pointernya diikuti oleh sebuah linked list, dengan chain (mata rantai) 1 terletak pada array of pointer, sedangkan chain 2 dan seterusnya berhubungan dengan chain 1 secara memanjang.

Kelemahan dari open hashing adalah bila data menumpuk pada satu/sedikit indeks sehingga terjadi linked list yang panjang.

## Referensi
[1] Barnes & Noble, Hash Tables, *Sparknotes*, http://www.sparknotes.com/ cs/searching/hashtables/section1.html.

[2] Department of Computer Science, the University of Auckland, *Data Structures and Algorithm*, http://www.cs.auckland.ac.nz/software/ AlgAnim/hash_tables.html.

[3] J. Prestiliano, “Aplikasi Tabel Hash dalam Pengarsipan dan Pencarian Data,” J. Teknol., vol. 4, no. 1, pp. 41–56, 2007.

[4] M.A. Weiss, *Data Structures and Algorithm Analysis in Java*, 3rd ed. Pearson Education, USA, 2012.

[5] V. Mutiawani, “HASHTABLE SEBAGAI ALTERNATIF DARI ALGORITMA PENCARIAN BINER PADA APLIKASI E-ACESIA,” Informatika, 2014.