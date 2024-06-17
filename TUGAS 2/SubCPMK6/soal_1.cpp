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