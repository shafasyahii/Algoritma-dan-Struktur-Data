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