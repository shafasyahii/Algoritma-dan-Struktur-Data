# <h1 align="center">Tugas 2 CPMK 2 – SubCPMK 7 </h1>
<p align="center">Shafa Syahida</p>

### 1. Tulislah sebuah program dari operasi queue seperti enqueue/add, dequeue/remove, isEmpty, isFull, dll(min 5)! 

```C++
#include <iostream>

using namespace std;

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
![image](https://github.com/shafasyahii/Algoritma-dan-Struktur-Data/assets/162096931/db9df6e7-ca5d-4cd7-ae3c-1817d551d852)

### 2. Sebuah selter hewan terlantar, yang mana hanya menerima kucing dan anjing, menerapkan konsep “first in, first out” dalam proses adopsi. Orang-orang yang hendak mengadopsi harus mengikuti aturan berikut: 1) mengadopsi hewan yang paling “tua” (berdasarkan waktu masuk ke selter) dan tidak dapat memilih kucing atau anjing; 2) memilih antara kucing atau anjing, namun akan menerima yang paling tua. Buatlah data struktur untuk mengimplementasikan kondisi tersebut, silahkan menggunakan beberapa operasi queue seperti enquee, dequeueAny, dequeueDog, dan dequeueCat.   

```C++
#include <iostream>
#include <queue>

using namespace std;

// Struktur untuk menampung informasi hewan
struct Animal {
  string type; // "anjing" atau "kucing"
  int age; // Usia hewan (dalam bulan)
  int arrivalTime; // Waktu masuk ke shelter (dalam bulan)
};

// Deklarasi queue untuk menampung hewan
queue<Animal> animalQueue;

// Fungsi enqueue untuk menambahkan hewan baru ke shelter
void enqueueAnimal(string type, int age) {
  Animal newAnimal;
  newAnimal.type = type;
  newAnimal.age = age;
  newAnimal.arrivalTime = time(NULL); // Mengambil waktu saat ini
  animalQueue.push(newAnimal);
}

// Fungsi dequeueAny untuk mengeluarkan hewan tertua (berdasarkan waktu masuk) tanpa mempertimbangkan jenis hewan
Animal dequeueAny() {
  if (animalQueue.empty()) {
    cout << "Shelter kosong!" << endl;
    return Animal{};
  }

  Animal oldestAnimal = animalQueue.front();
  animalQueue.pop();
  return oldestAnimal;
}

// Fungsi dequeueDog untuk mengeluarkan anjing tertua
Animal dequeueDog() {
  Animal oldestDog;
  while (!animalQueue.empty()) {
    Animal currentAnimal = animalQueue.front();
    if (currentAnimal.type == "anjing") {
      oldestDog = currentAnimal;
      animalQueue.pop();
      break;
    } else {
      animalQueue.push(currentAnimal); // Pindahkan hewan lain ke belakang queue
      animalQueue.pop();
    }
  }

  if (oldestDog.type != "anjing") {
    cout << "Tidak ada anjing di shelter saat ini!" << endl;
    return Animal{};
  }

  return oldestDog;
}

// Fungsi dequeueCat untuk mengeluarkan kucing tertua
Animal dequeueCat() {
  Animal oldestCat;
  while (!animalQueue.empty()) {
    Animal currentAnimal = animalQueue.front();
    if (currentAnimal.type == "kucing") {
      oldestCat = currentAnimal;
      animalQueue.pop();
      break;
    } else {
      animalQueue.push(currentAnimal); // Pindahkan hewan lain ke belakang queue
      animalQueue.pop();
    }
  }

  if (oldestCat.type != "kucing") {
    cout << "Tidak ada kucing di shelter saat ini!" << endl;
    return Animal{};
  }

  return oldestCat;
}

int main() {
  // Contoh penggunaan fungsi
  enqueueAnimal("anjing", 12);
  enqueueAnimal("kucing", 8);
  enqueueAnimal("anjing", 5);

  Animal oldestAnimal = dequeueAny();
  cout << "Hewan tertua: " << oldestAnimal.type << " (" << oldestAnimal.age << " bulan)" << endl;

  Animal oldestDog = dequeueDog();
  cout << "Anjing tertua: " << oldestDog.type << " (" << oldestDog.age << " bulan)" << endl;

  Animal oldestCat = dequeueCat();
  cout << "Kucing tertua: " << oldestCat.type << " (" << oldestCat.age << " bulan)" << endl;

  return 0;
}
```
#### Output:
![Screenshot 2024-05-19 013208](https://github.com/shafasyahii/Algoritma-dan-Struktur-Data/assets/162096931/5f0dff4b-fc97-45b8-a09c-9d2e377b37bf)
