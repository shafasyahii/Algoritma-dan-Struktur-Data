#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isAnagram(const string& str1, const string& str2) {
    if (str1.length() != str2.length()) {
        return false;
    }

    string temp1 = str1;
    string temp2 = str2;

    sort(temp1.begin(), temp1.end());
    sort(temp2.begin(), temp2.end());

    return temp1 == temp2;
}

int main() {
    string str1, str2;

    cout << "Masukkan string 1: ";
    cin >> str1;

    cout << "Masukkan string 2: ";
    cin >> str2;

    if (isAnagram(str1, str2)) {
        cout << "Anagram" << endl;
    } else {
        cout << "Tidak anagram" << endl;
    }

    return 0;
}