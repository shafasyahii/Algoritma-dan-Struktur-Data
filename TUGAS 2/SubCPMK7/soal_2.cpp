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