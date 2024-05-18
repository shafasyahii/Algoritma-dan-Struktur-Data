# <h1 align="center">Tugas 2 CPMK 2 – SubCPMK 5 </h1>
<p align="center">Shafa Syahida</p>

### 1. Buatlah sebuah fungsi program untuk menghilangkan duplikasi data pada unsorted linked list (single atau double atau circular)   

```C++
#include <iostream>
using namespace std;

// Struktur untuk node linked list
struct Node {
    int data;
    Node* next;
};

// Fungsi untuk membuat node baru
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

// Fungsi untuk menghilangkan duplikasi data pada linked list
void removeDuplicates(Node** head) {
    if (*head == nullptr) {
        return;
    }

    Node* current = *head;
    while (current != nullptr) {
        Node* runner = current;
        while (runner->next != nullptr) {
            if (runner->next->data == current->data) {
                Node* temp = runner->next;
                runner->next = runner->next->next;
                delete temp;
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
    }
}

// Fungsi untuk menampilkan linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Fungsi utama
int main() {
    // Membuat linked list
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(2);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(4);
    head->next->next->next->next->next = createNode(2);

    // Menampilkan linked list sebelum menghilangkan duplikasi
    cout << "Linked List sebelum menghilangkan duplikasi: ";
    printList(head);

    // Menghilangkan duplikasi
    removeDuplicates(&head);

    // Menampilkan linked list setelah menghilangkan duplikasi
    cout << "Linked List setelah menghilangkan duplikasi: ";
    printList(head);

    return 0;
}
```
#### Output:


Dalam program ini, fungsi ```removeDuplicates``` digunakan untuk menghilangkan duplikasi data pada linked list. Fungsi ini bekerja dengan cara mengikuti setiap node dalam linked list dan membandingkan data setiap node dengan data node berikutnya. Jika data node berikutnya sama dengan data node sebelumnya, maka node berikutnya dihapus. Fungsi ini dilakukan secara rekursif untuk setiap node dalam linked list. Fungsi ```printList``` digunakan untuk menampilkan linked list. Fungsi ini mengikuti setiap node dalam linked list dan mencetak data setiap node.

Dalam fungsi main, linked list dibuat dan kemudian fungsi ```removeDuplicates``` dipanggil untuk menghilangkan duplikasi. Setelah menghilangkan duplikasi, linked list dinyalakan kembali menggunakan fungsi ```printList```.

### 2. Buatlah sebuah algoritma dan fungsi program untuk menghapus node di tengah single linked list!  

```C++
#include <iostream>
using namespace std;

// Struktur untuk node linked list
struct Node {
    int data;
    Node* next;
};

// Fungsi untuk membuat node baru
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

// Fungsi untuk menghapus node di tengah linked list
void deleteNode(Node** head, int value) {
    if (*head == nullptr) {
        return;
    }

    if ((*head)->data == value) {
        Node* temp = *head;
        *head = (*head)->next;
        delete temp;
        return;
    }

    Node* current = *head;
    while (current->next != nullptr) {
        if (current->next->data == value) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            return;
        }
        current = current->next;
    }
}

// Fungsi untuk menampilkan linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Fungsi utama
int main() {
    // Membuat linked list
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    // Menampilkan linked list sebelum menghapus node
    cout << "Linked List sebelum menghapus node: ";
    printList(head);

    // Menghapus node dengan nilai 3
    deleteNode(&head, 3);

    // Menampilkan linked list setelah menghapus node
    cout << "Linked List setelah menghapus node: ";
    printList(head);

    return 0;
}
```
#### Output:


Dalam program ini, fungsi ```deleteNode``` digunakan untuk menghapus node di tengah single linked list. Fungsi ini bekerja dengan cara mengikuti setiap node dalam linked list dan membandingkan data setiap node dengan nilai yang ingin dihapus. Jika data node sama dengan nilai yang ingin dihapus, maka node tersebut dihapus. Fungsi ini dilakukan secara rekursif untuk setiap node dalam linked list. Fungsi ```printList``` digunakan untuk menampilkan linked list. Fungsi ini mengikuti setiap node dalam linked list dan mencetak data setiap node.

Dalam fungsi main, linked list dibuat dan kemudian fungsi ```deleteNode``` dipanggil untuk menghapus node dengan nilai 3. Setelah menghapus node, linked list dinyalakan kembali menggunakan fungsi ```printList```.

### 3. Buatlah sebuah program untuk mengecek apakah linked list adalah sebuah palindrom! 

```C++
#include <iostream>
#include <stack>

using namespace std;

struct Node {
  int data;
  Node* next;
};

// Deklarasi fungsi untuk membuat node baru
Node* newNode(int data) {
  Node* new_node = new Node;
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

// Fungsi untuk memeriksa apakah linked list adalah palindrom
bool isPalindrome(Node* head) {
  // Deklarasi stack untuk menyimpan node
  stack<Node*> s;

  // Menempatkan node ke dalam stack
  Node* temp = head;
  while (temp != NULL) {
    s.push(temp);
    temp = temp->next;
  }

  // Membandingkan node dari awal dan akhir linked list
  temp = head;
  while (temp != NULL && !s.empty()) {
    if (temp->data != s.top()->data) {
      return false;
    }
    temp = temp->next;
    s.pop();
  }

  // Jika semua node terbandingkan dan cocok, maka linked list adalah palindrom
  return true;
}

// Fungsi untuk mencetak linked list
void printList(Node* head) {
  Node* temp = head;
  while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

int main() {
  // Membangun linked list
  Node* head = newNode(1);
  head->next = newNode(2);
  head->next->next = newNode(2);
  head->next->next->next = newNode(1);

  // Mencetak linked list
  cout << "Linked list: ";
  printList(head);

  // Memeriksa apakah linked list adalah palindrom
  bool isPal = isPalindrome(head);
  if (isPal) {
    cout << "Linked list adalah palindrom" << endl;
  } else {
    cout << "Linked list bukan palindrom" << endl;
  }

  return 0;
}
```
#### Output:


Program di atas adalah program sederhana yang memeriksa apakah linked list yang diberikan adalah palindrom atau bukan. Palindrom adalah sebuah kata, frasa, angka, atau urutan karakter lain yang dibaca sama maju dan mundur, mengabaikan spasi, tanda baca, dan huruf besar.

Program ini menggunakan struktur ```Node``` untuk menyimpan data dan pointer ke node berikutnya. Fungsi ```newNode``` digunakan untuk membuat node baru dengan data yang diberikan dan mengembalikan pointer ke node tersebut.

Fungsi utama ```isPalindrome``` berfungsi untuk mengecek apakah linked list adalah palindrom. Fungsi ini bekerja dengan langkah-langkah berikut:
- Menempatkan semua node linked list ke dalam stack.
- Mengulangi linked list dari awal dan akhir secara bersamaan.
- Membandingkan data node saat ini dengan data node yang dikeluarkan dari stack.

Jika data node tidak cocok, maka linked list bukan palindrom dan fungsi ini mengembalikan ```false```. Jika semua node terbandingkan dan cocok, maka linked list adalah palindrom dan fungsi ini mengembalikan ```true```. Fungsi ```printList``` digunakan untuk mencetak linked list.

Pada fungsi main, linked list dibangun, dicetak, dan kemudian diperiksa apakah linked list adalah palindrom atau bukan.