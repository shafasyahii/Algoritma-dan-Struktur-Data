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