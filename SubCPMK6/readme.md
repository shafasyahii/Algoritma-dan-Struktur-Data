# <h1 align="center">Tugas 2 CPMK 2 – SubCPMK 6 </h1>
<p align="center">Shafa Syahida</p>

### 1. Tulislah sebuah program dari operasi stack seperti pop, push, isEmpty, isFull, dll(min 5)!   

```C++
#include <iostream>
using namespace std;

// Maksimum ukuran stack
const int MAX_SIZE = 2;

// Struktur data stack
struct Stack {
    int data[MAX_SIZE];
    int top;
};

// Membuat stack baru
void createStack(Stack& s) {
    s.top = -1;
}

// Memeriksa apakah stack kosong
bool isEmpty(const Stack& s) {
    return s.top == -1;
}

// Memeriksa apakah stack penuh
bool isFull(const Stack& s) {
    return s.top == MAX_SIZE - 1;
}

// Menambahkan elemen ke stack (push)
void push(Stack& s, int value) {
    if (isFull(s)) {
        cout << "Stack penuh! Tidak dapat menambahkan elemen." << endl;
        return;
    }
    s.data[++s.top] = value;
}

// Menghapus elemen dari stack (pop)
void pop(Stack& s) {
    if (isEmpty(s)) {
        cout << "Stack kosong! Tidak ada elemen yang dapat dihapus." << endl;
        return;
    }
    --s.top;
}

// Mengosongkan stack (MakeNull)
void makeNull(Stack& s) {
    s.top = -1;
}

// Menampilkan elemen pada stack
void displayStack(const Stack& s) {
    if (isEmpty(s)) {
        cout << "Stack kosong." << endl;
        return;
    }
    cout << "Elemen pada stack:" << endl;
    for (int i = s.top; i >= 0; --i) {
        cout << s.data[i] << " ";
    }
    cout << endl;
}

int main() {
    Stack myStack;
    createStack(myStack);

    int choice, value;
    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Tambah elemen ke stack" << endl;
        cout << "2. Hapus elemen teratas dari stack" << endl;
        cout << "3. Kosongkan stack" << endl;
        cout << "4. Tampilkan elemen pada stack" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan Anda: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> value;
                push(myStack, value);
                break;
            case 2:
                if (!isEmpty(myStack)) {
                    cout << "Elemen teratas: " << myStack.data[myStack.top] << endl;
                    pop(myStack);
                } else {
                    cout << "Stack kosong! Tidak ada elemen yang dapat dihapus." << endl;
                }
                break;
            case 3:
                makeNull(myStack);
                cout << "Stack telah dikosongkan." << endl;
                break;
            case 4:
                displayStack(myStack);
                break;
            case 5:
                cout << "Terima kasih!" << endl;
                return 0;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    }

    return 0;
}
```
#### Output:
![Screenshot 2024-05-19 010352](https://github.com/shafasyahii/Algoritma-dan-Struktur-Data/assets/162096931/34c88e66-9ffb-429a-b08b-7195a42500e0)

### 2. Tulislah sebuah program untuk mensortir sebuah stack, sehingga item dengan nilai terkecil menjadi top pada stack tersebut! Diperbolehkan menggunakan tambahan temporary stack, namun tidak diperbolehkan untuk menyalin dari struktur data yang lain seperti array.  Program stack yang dibuat dapat menggunakan operasi stack seperti push, pop, peek, dan isEmpty.  

```C++
#include <iostream>
#include <stack>

using namespace std;

// Deklarasi fungsi untuk mengurutkan stack
void sortStack(stack<int>& s) {
  // Deklarasi stack sementara
  stack<int> temp;

  // Urutkan elemen stack
  while (!s.empty()) {
    // Ambil elemen teratas dari stack utama
    int top = s.top();
    s.pop();

    // Masukkan elemen ke stack sementara dengan urutan yang benar
    while (!temp.empty() && temp.top() > top) {
      s.push(temp.top());
      temp.pop();
    }

    // Masukkan elemen teratas dari stack utama ke stack sementara
    temp.push(top);
  }

  // Pindahkan elemen dari stack sementara kembali ke stack utama
  while (!temp.empty()) {
    s.push(temp.top());
    temp.pop();
  }
}

int main() {
  // Inisialisasi stack
  stack<int> s;

  // Masukkan elemen ke dalam stack
  s.push(5);
  s.push(2);
  s.push(4);
  s.push(1);
  s.push(3);

  // Urutkan stack
  sortStack(s);

  // Cetak elemen stack yang telah diurutkan
  while (!s.empty()) {
    cout << s.top() << " ";
    s.pop();
  }

  return 0;
}
```
#### Output:
![Screenshot 2024-05-19 010648](https://github.com/shafasyahii/Algoritma-dan-Struktur-Data/assets/162096931/4ba86558-35f8-4c08-9f14-a247013a9432)
