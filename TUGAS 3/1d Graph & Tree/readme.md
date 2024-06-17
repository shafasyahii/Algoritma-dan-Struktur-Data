# <h1 align="center">Laporan Praktikum Modul Priority Graph dan Tree</h1>
<p align="center">Shafa Syahida</p>

## Dasar Teori

### Graph
Graph merupakan representasi dari suatu masalah yang digambarkan sebagai sekumpulan noktah atau simpul (vertex) yang dihubungkan dengan sekumpulan garis atau sisi (edge) [1]. Graf G didefisikan : pasangan himpunan (V, E) dengan notasi G = (V, E). Dalam hal ini, V adalah himpunan tidak kosong dari simpulsimpul (vertices atau node) dan E adalah himpunan sisi (edges atau arcs) yang menghubungkan sepasang simpul [2].  Secara geometri graf digambarkan sebagai sekumpulan noktah (simpul) di dalam bidang dua dimensi yang dihubungkan dengan sekumpulan garis (sisi) [3]. 

Ada beberapa cara untuk menyimpan graph di dalam sitem komputer. Struktur data bergantung pada struktur graph dan algoritma yang digunakan untuk memanipulasi graph. Secara teori salah satu dari keduanya dapat dibedakan antara struktur list dan matriks, tetapi dalam penggunaannya struktur terbaik yang sering digunakan adalah kombinasi keduanya.
1. Graph tak berarah (undirected graph atau non-directed graph)
- Urutan simpul dalam sebuah busur tidak dipentingkan. Misal busur e1 dapat disebut busur AB atau BA

2. Graph berarah (directed graph) 
- Urutan simpul mempunyai arti. Misal busur AB adalah e1 sedangkan busur BA adalah e8.

3. Graph Berbobot (Weighted Graph)
- Jika setiap busur mempunyai nilai yang menyatakan hubungan antara 2 buah simpul, maka busur tersebut dinyatakan memiliki bobot.
- Bobot sebuah busur dapat menyatakan panjang sebuah jalan dari 2 buah titik, jumlah rata-rata kendaraan perhari yang melalui sebuah jalan, dll.

Terdapat istilah – istilah yang berkaitan dengan graph, yaitu :
- Vertex : himpunan node/titik pada sebuah graph.
- Edge : garis yang menghubungkan tiap node/vertex.
- Adjacent : dua buah titik dikatakan berdekatan juka dua buah titik tersebut terhubung dengan sebuah sisi.
- Weight : Sebuah graph dikatakan berbobot apabila terdapat sebuah fungsi bobot bernilai real pada himpunan Edge.
- Path : walk dengan setiap vertex berbeda. Walk didefinisikan sebagai ururtan vertex dan edge. Diawali dengan origin vertex dan diakhiri dengan terminus vertex.
- Cycle : siklus atau sirkuit yang berawal dan berakhir pada simpul yang sama.

### Tree
Pohon ( tree) adalah graph terhubung yang tidak mengandung sirkuit. Pohon (tree) merupakan stuktur data yang tidak linier yang digambarkan dengan hubungan yang bersifat hirarkis antar satu elemen [4]. 

#### Sifat-sifat pohon
Misalkan G = (V, E) adalah graf takberarah sederhana dan jumlah simpulnya n. Maka, semua pernyataan di bawah ini adalah ekivalen [5]:
1. G adalah pohon.
2. Setiap pasang simpul di dalam G terhubung dengan lintasan tunggal.
3. G terhubung dan memiliki m = n – 1 buah sisi.
4. G tidak mengandung sirkuit dan memiliki m = n – 1 buah sisi.
5. G tidak mengandung sirkuit dan penambahan satu sisi pada graf akan membuat hanya satu sirkuit.
6. G terhubung dan semua sisinya adalah jembatan. 

#### Jenis-jenis pohon
Ada Beberapa Jenis TREE di antaranya :

1. BINARY TREE
Tree dengan syarat bahwa tiap node hanya boleh memiliki maksimal dua sub pohon dan kedua subpohon harus terpisah.
Kelebihan struktur Binary Tree :
- Mudah dalam penyusunan algoritma sorting
- Searching data relatif cepat
- Fleksibel dalam penambahan dan penghapusan data

Dari Binary Tree ini, ada 2 tipe :
- Full Binary Tree : Semua node, kecuali leaf pasti memiliki 2 anak dan tiap subpohon memiliki panjang path yang sama.
- Complete Binary Tree : Tree yang mirip dengan full binary tree, tapi tiap subtree boleh memiliki panjang path yang berbeda dan tiap node (kecuali leaf) memiliki 2 anak.

2. SKEWED BINARY TREE
Binary tree yang semua nodenya (kecuali leaf) hanya memiliki satu anak.

#### Operasi
1. Create: membentuk sebuah tree baru yang kosong.
2. Insert: menambah node ke dalam Tree.
Jika data yang akan dimasukkan lebih besar daripada elemen root, maka akan diletakkan di node sebelah kanan, sebaliknya jika lebih kecil maka akan diletakkan di node sebelah kiri. Untuk data pertama akan menjadi elemen root.
3. PreOrder: cetak node yang dikunjungi, kunjungi left, kunjungi right
4. InOrder: kunjungi left, cetak node yang dikunjungi, kunjungi right
5. PostOrder: kunjungi left, kunjungi right, cetak node yang dikunjungi

## Referensi
[1] I. Afrianto, “Penyelesaian Masalah Minimum Spanning Tree (Mst) Menggunakan Ant Colony System (Acs),” *Komputa  J. Ilm. Komput.* dan Inform., vol. 1, no. 2, 2012, doi: 10.34010/komputa.v1i2.59.

[2] T. Nudiyanto and E. Susanti, “Efisiensi Penggunaan Matriks In-Degree Untuk Mengkontruksi Spanning-Tree pada Graf Berarah,” *J. Edukasi dan Sains Mat.*, vol. 5, no. 1, pp. 1–15, 2019.

[3] S. Rizki, “Penerapan Teori Graf Untuk Menyelesaikan Masalah Minimum Spanning Tree (Mst) Menggunakan Algoritma Kruskal,” *AKSIOMA J. Math. Educ.,* vol. 1, no. 2, 2012, doi: 10.24127/ajpm.v1i2.68.

[4] F. Latifah, “PENYIMPANAN DATA DALAM TEKNIK PEMROGRAMAN ( kajian algorithma pohon pada teknik pemrograman ),” vol. XIII, no. 2, pp. 23–32, 2016, [Online]. Available: http://ejournal.nusamandiri.ac.id/ejurnal/index.php/techno/article/view/357/287

[5] A. Muntaha, “Graf Pohon dan Implementasinya dalam beberapa persoalan,” p. 11, 2020.