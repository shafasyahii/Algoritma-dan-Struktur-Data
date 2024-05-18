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