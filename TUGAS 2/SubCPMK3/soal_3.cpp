#include <iostream>
#include <string>

using namespace std;

int findStringIndex(string arr[], int n, string target) {
  for (int i = 0; i < n; i++) {
    if (arr[i] == target) {
      return i;
    }
  }
  return -1; // jika tidak ditemukan
}

int main() {
  string arr[] = {"Adi", "", "", "", "bermain", "", "bola", "", "", "sedang"};
  int n = sizeof(arr) / sizeof(arr[0]);
  string target = "bola";

  int index = findStringIndex(arr, n, target);

  if (index != -1) {
    cout << "Kata '" << target << "' ditemukan pada indeks " << index << endl;
  } else {
    cout << "Kata '" << target << "' tidak ditemukan" << endl;
  }

  return 0;
}