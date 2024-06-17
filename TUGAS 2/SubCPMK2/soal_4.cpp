#include <iostream>

using namespace std;

void mergeArrays(int A[], int m, int B[], int n, int C[]) {
  int i = 0, j = 0, k = 0;

  // Lintasi kedua array dan masukkan elemen yang lebih kecil ke dalam C
  while (i < m && j < n) {
    if (A[i] <= B[j]) {
      C[k++] = A[i++];
    } else {
      C[k++] = B[j++];
    }
  }

  // Salin elemen yang tersisa dari A
  while (i < m) {
    C[k++] = A[i++];
  }

  // Salin elemen yang tersisa dari B
  while (j < n) {
    C[k++] = B[j++];
  }
}

int main() {
  int A[] = {2, 5, 8, 12};
  int m = sizeof(A) / sizeof(A[0]);
  int B[] = {1, 3, 4, 9};
  int n = sizeof(B) / sizeof(B[0]);

  // asumsi ruang yang cukup di C untuk menampung kedua array
  int C[m + n];

  mergeArrays(A, m, B, n, C);

  cout << "Merged and sorted array: ";
  for (int i = 0; i < m + n; i++) {
    cout << C[i] << " ";
  }
  cout << endl;

  return 0;
}