### Buatlah kode program yang lebih efisien untuk mencari adanya duplikasi pada array
```C++
#include <iostream>
using namespace std;

bool cekDuplikat(int arr[]){
    int panjangArr = 4;
    for(int i=0; i<panjangArr; i++){
        for(int j=i+1; j<panjangArr; j++){
            if(arr[i]==arr[j]){
                return true;
            }
        }
    }
    return false;
}

int main(void)
{
    int arrA[] = {2, 1, 3, 1};
    cout << cekDuplikat(arrA);

    return 0;
}
```

### Kode program setelah diubah
```C++
#include <iostream>
#include <unordered_set>

using namespace std;

bool cekDuplikat(int arr[], int n) {
  // Gunakan unordered_set untuk menyimpan elemen yang telah dilihat
  unordered_set<int> s;

  // Masukkan setiap elemen array ke dalam set
  for (int i = 0; i < n; ++i) {
    if (s.find(arr[i]) != s.end()) {
      // Elemen ditemukan duplikat
      return true;
    }
    s.insert(arr[i]);
  }

  // Tidak ada duplikat yang ditemukan
  return false;
}

int main() {
  int arrA[] = {2, 1, 3, 1};
  int n = sizeof(arrA) / sizeof(arrA[0]);

  if (cekDuplikat(arrA, n)) {
    cout << "Array memiliki duplikat" << endl;
  } else {
    cout << "Array tidak memiliki duplikat" << endl;
  }

  return 0;
}
```

#### Penjelasan:
1. ```unordered_set```: Digunakan untuk menyimpan elemen yang telah dilihat dengan cara yang efisien.
2. Iterasi: Kode mengiterasi array dan memasukkan setiap elemen ke dalam set.
3. Pemeriksaan Duplikat: Jika elemen sudah ada di set, maka duplikat ditemukan dan fungsi mengembalikan ```true```.
4. Penyimpanan: Elemen baru ditambahkan ke set, memungkinkan pemeriksaan duplikat yang cepat di masa mendatang.
5. Kompleksitas: Algoritma ini memiliki kompleksitas waktu rata-rata O(n), yang lebih efisien daripada solusi nested loop O(n^2).

#### Kelebihan:
- Lebih cepat, terutama untuk array besar.
- Lebih mudah dipahami dan dipelihara.
- Menggunakan struktur data yang umum dan efisien.

#### Kelemahan:
- Membutuhkan memori tambahan untuk menyimpan set.
- Tidak dapat mempertahankan urutan elemen asli dalam array.