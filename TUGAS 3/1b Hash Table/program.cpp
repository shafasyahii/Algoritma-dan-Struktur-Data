#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <functional>

using namespace std;

class HashTable {
    int size;
    vector<list<pair<string, int>>> table;

public:
    HashTable(int s) {
        size = s;
        table.resize(s);
    }

    int hashFunction(string key) {
        int hash = 0;
        for (char c : key) {
            hash += c;
        }
        return hash % size;
    }

    void insert(string key, int value) {
        int index = hashFunction(key);
        table[index].push_back({key, value});
    }

    void search(string key) {
        int index = hashFunction(key);
        for (auto& pair : table[index]) {
            if (pair.first == key) {
                cout << "Key found: " << pair.first << " Value: " << pair.second << endl;
                return;
            }
        }
        cout << "Key not found." << endl;
    }
};

int main() {
    HashTable h(5);

    h.insert("apple", 5);
    h.insert("banana", 7);
    h.insert("orange", 3);

    h.search("apple");
    h.search("banana");
    h.search("grape");

    return 0;
}

