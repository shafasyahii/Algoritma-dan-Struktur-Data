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