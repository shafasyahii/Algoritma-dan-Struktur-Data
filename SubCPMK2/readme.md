# <h1 align="center">Tugas 2 CPMK 2 – SubCPMK 2 </h1>
<p align="center">Shafa Syahida</p>

### 1. Terdapat tiga algoritma sorting yang umum digunakan yakni, Bubble Sort, Selection Sort, dan Merge Sort. Berikan penjelasan alur dari masing-masing algoritma tersebut, dan jelaskan runtime dari best case dan worst case masing-masing algoritma! 

1. Bubble Sort

- Alur:
1. Lakukan perulangan sebanyak n-1 kali, di mana n adalah jumlah elemen dalam array.
2. Pada setiap perulangan, bandingkan setiap elemen dengan elemen di sebelahnya.
3. Jika elemen pertama lebih besar dari elemen kedua, tukar posisinya.
4. Lakukan hal ini hingga seluruh elemen terurut.

- Runtime:
1. Best Case: ```O(n)``` => Terjadi ketika array sudah terurut, sehingga tidak ada pertukaran yang perlu dilakukan.
2. Worst Case: ```O(n^2)``` => Terjadi ketika array terbalik, sehingga membutuhkan n-1 perulangan untuk mengurutkan semua elemen.

2. Selection Sort

- Alur:
1. Temukan elemen terkecil dalam array.
2. Tukar elemen terkecil dengan elemen pertama dalam array.
3. Ulangi langkah 1 dan 2 untuk elemen berikutnya, hingga seluruh elemen terurut.

- Runtime:
1. Best Case: ```O(n)``` => Terjadi ketika array sudah terurut, sehingga elemen terkecil mudah ditemukan pada setiap perulangan.
2. Worst Case: ```O(n^2)``` => Terjadi ketika array teracak, sehingga membutuhkan n perulangan untuk menemukan elemen terkecil pada setiap iterasi.

3. Merge Sort

- Alur:
1. Bagi array menjadi dua bagian secara rekursif.
2. Urutkan kedua bagian secara terpisah menggunakan Merge Sort.
3. Gabungkan kedua bagian yang terurut menjadi satu array terurut.

- Runtime:
1. Best Case: ```O(n log n)``` => Terjadi ketika array terbagi secara merata pada setiap pembagian rekursif.
2. Worst Case: ```O(n log n)``` => Terjadi ketika array selalu terbagi tidak merata pada setiap pembagian rekursif.

##### Kesimpulan:

- Bubble Sort: Algoritma ini sederhana dan mudah dipahami, namun memiliki runtime yang lambat untuk array besar.
- Selection Sort: Algoritma ini lebih cepat daripada Bubble Sort untuk array besar, namun masih memiliki runtime yang lambat dibandingkan Merge Sort.
- Merge Sort: Algoritma ini memiliki runtime yang paling efisien (O(n log n)) untuk semua kasus, namun implementasinya lebih kompleks.

### 2. Buatlah fungsi dari salah satu algoritma sorting pada soal nomor 1, dan berikan penjelasan pada program tersebut 


### 3. Tulislah sebuah fungsi untuk mensorting dan mengecek dua buah array of strings, sehingga menghasilkan “anagram” dan “tidak anagram” 


### 4. Tulislah sebuah fungsi program dengan asumsi sebagai berikut: Terdapat dua buah sorted array A dan B yang memiliki tipe data sama, dimana array A memiliki indeks yang cukup untuk menampung array B. Gabungkan array B kedalam array A, kemudian urutkan array tersebut! 


## Guided 

```C++
#include <iostream>

using namespace std;

const int maksimalQueue = 5;
int front = 0;
int back = 0;

string queueTeller[5];

bool isFull() {
    if (back == maksimalQueue) {
        return true;
    } else {
        return false;
    }
}

bool isEmpty() {
    if (back == 0) {
        return true;
    } else {
        return false;
    }
}

void enqueueAntrian(string data) {
    if (isFull()) {
        cout << "Antrian Penuh" << endl;
    } else {
        if (isEmpty()) {
            queueTeller[0] = data;
            front++;
            back++;
        } else {
            queueTeller[back] = data;
            back++;
        }
    }
}

void dequeueAntrian() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}

int countQueue() {
    return back;
}

void clearQueue() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

void viewQueue() {
    cout << "Data antrian teller: " << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if (queueTeller[i] != "") {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

int main() {
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}
```
Kode ini digunakan untuk membuat simulasi antrian teller bank. Kode ini menggunakan array of string untuk menyimpan data antrian, dan beberapa fungsi untuk melakukan operasi pada antrian tersebut.

Berikut adalah fungsi-fungsi yang terdapat pada kode tersebut:

isFull(): Fungsi ini digunakan untuk mengecek apakah antrian sudah penuh.
isEmpty(): Fungsi ini digunakan untuk mengecek apakah antrian masih kosong.
enqueueAntrian(string data): Fungsi ini digunakan untuk menambahkan data (nama nasabah) ke dalam antrian.
dequeueAntrian(): Fungsi ini digunakan untuk mengeluarkan data (nama nasabah) dari antrian.
countQueue(): Fungsi ini digunakan untuk menghitung jumlah data yang ada di dalam antrian.
clearQueue(): Fungsi ini digunakan untuk menghapus semua data yang ada di dalam antrian.
viewQueue(): Fungsi ini digunakan untuk menampilkan data yang ada di dalam antrian.

Pada fungsi main(), program terlebih dahulu menambahkan dua nama nasabah, yaitu "Andi" dan "Maya", ke dalam antrian. Kemudian, program menampilkan isi antrian dan jumlah antrian. Setelah itu, program mengeluarkan satu data dari antrian, lalu menampilkan kembali isi antrian dan jumlah antrian. Terakhir, program menghapus semua data yang ada di dalam antrian, dan kemudian menampilkan kembali isi antrian dan jumlah antrian.

## Unguided

### 1. Ubahlah penerapan konsep queue pada bagian guided dari array menjadi linked list

```C++
#include <iostream>

using namespace std;

// Node structure for linked list implementation
struct Node {
    string data;
    Node* next;
};

class Queue {
public:
    Queue() {
        front = rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(string data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
        } else {
            Node* temp = front;
            front = front->next;

            if (front == nullptr) {
                rear = nullptr;
            }

            delete temp;
        }
    }

    int countQueue() {
        int count = 0;
        Node* current = front;

        while (current != nullptr) {
            count++;
            current = current->next;
        }

        return count;
    }

    void clearQueue() {
        Node* current = front;

        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }

        front = rear = nullptr;
    }

    void viewQueue() {
        cout << "Data antrian teller: " << endl;
        Node* current = front;

        for (int i = 1; i <= 5; i++) {
            if (current != nullptr) {
                cout << i << ". " << current->data << endl;
                current = current->next;
            } else {
                cout << i << ". (kosong)" << endl;
            }
        }
    }

private:
    Node* front;
    Node* rear;
};

int main() {
    Queue queueTeller;

    queueTeller.enqueue("Andi");
    queueTeller.enqueue("Maya");
    queueTeller.enqueue("Rina");
    queueTeller.enqueue("Budi");
    queueTeller.enqueue("Doni");
    queueTeller.viewQueue();
    cout << "Jumlah antrian = " << queueTeller.countQueue() << endl;
    queueTeller.dequeue();
    queueTeller.dequeue();
    queueTeller.viewQueue();
    cout << "Jumlah antrian = " << queueTeller.countQueue() << endl;
    queueTeller.clearQueue();
    queueTeller.viewQueue();
    cout << "Jumlah antrian = " << queueTeller.countQueue() << endl;

    return 0;
}
```
#### Output:
![image](https://github.com/shafasyahii/Praktikum-Struktur-Data-Assignment/assets/162096931/d5c8b1c3-93b7-4f74-85c9-1b3f1ff77d22)

Pada kode ini, struct Node digunakan untuk mendefinisikan struktur data node dalam linked list. Setiap node memiliki dua atribut: data untuk menyimpan data antrian (nama nasabah) dan next untuk menunjuk ke node berikutnya dalam antrian.

Fungsi-fungsi untuk operasi queue (seperti enqueueAntrian(), dequeueAntrian(), countQueue(), clearQueue(), dan viewQueue()) telah dimodifikasi untuk bekerja dengan linked list.

Perubahan utama pada kode ini adalah:

Tipe data queue: Tipe data queue diubah dari array of string menjadi Node*.
Operasi enqueue dan dequeue: Operasi enqueue dan dequeue dimodifikasi untuk menambahkan dan menghapus node dalam linked list.
Operasi viewQueue: Operasi viewQueue dimodifikasi untuk menelusuri linked list dan menampilkan data pada setiap node.

Dengan menggunakan linked list, queue dapat menampung data tanpa batasan maksimum dan lebih efisien dalam hal penggunaan memori, terutama ketika antrian bertambah panjang.

### 2. Dari nomor 1 buatlah konsep antri dengan atribut Nama mahasiswa dan NIM Mahasiswa

```C++
#include <iostream>
#include <string>

using namespace std;

// Node structure for linked list implementation
struct Node {
    string NamaMahasiswa;
    string NIMMahasiswa;
    Node* next;
};

class Queue {
public:
    Queue() {
        front = rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(string NamaMahasiswa, string NIMMahasiswa) {
        Node* newNode = new Node();
        newNode->NamaMahasiswa = NamaMahasiswa;
        newNode->NIMMahasiswa = NIMMahasiswa;
        newNode->next = nullptr;

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
        } else {
            Node* temp = front;
            front = front->next;

            if (front == nullptr) {
                rear = nullptr;
            }

            delete temp;
        }
    }

    int countQueue() {
        int count = 0;
        Node* current = front;

        while (current != nullptr) {
            count++;
            current = current->next;
        }

        return count;
    }

    void clearQueue() {
        Node* current = front;

        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }

        front = rear = nullptr;
    }

    void viewQueue() {
        cout << "Data antrian teller: " << endl;
        Node* current = front;

        for (int i = 1; i <= 5; i++) {
            if (current != nullptr) {
                cout << i << ". Nama: " << current->NamaMahasiswa << ", NIM: " << current->NIMMahasiswa << endl;
                current = current->next;
            } else {
                cout << i << ". (kosong)" << endl;
            }
        }
    }

private:
    Node* front;
    Node* rear;
};

int main() {
    Queue queueTeller;

    queueTeller.enqueue("Andi", "12345678");
    queueTeller.enqueue("Maya", "23456789");
    queueTeller.enqueue("Rina", "34567890");
    queueTeller.enqueue("Budi", "45678901");
    queueTeller.enqueue("Doni", "56789012");
    queueTeller.viewQueue();
    cout << "Jumlah antrian = " << queueTeller.countQueue() << endl;
    queueTeller.dequeue();
    queueTeller.dequeue();
    queueTeller.viewQueue();
    cout << "Jumlah antrian = " << queueTeller.countQueue() << endl;
    queueTeller.clearQueue();
    queueTeller.viewQueue();
    cout << "Jumlah antrian = " << queueTeller.countQueue() << endl;

    return 0;
}
```
#### Output:
![image](https://github.com/shafasyahii/Praktikum-Struktur-Data-Assignment/assets/162096931/72c1e47f-85ee-46c8-aa1b-5a658049f510)

Perubahan utama pada kode ini adalah:

Struktur data node: Struktur data node diperbarui untuk menyertakan dua atribut baru: namaMahasiswa dan nimMahasiswa.
Operasi enqueue dan dequeue: Operasi enqueue dan dequeue dimodifikasi untuk memperbarui data namaMahasiswa dan nimMahasiswa pada node yang ditambahkan atau dihapus.
Operasi viewQueue: Operasi viewQueue dimodifikasi untuk menampilkan data namaMahasiswa dan nimMahasiswa pada setiap node.

Dengan perubahan ini, antrian dapat menyimpan informasi yang lebih lengkap tentang mahasiswa, yaitu nama dan NIM mereka.