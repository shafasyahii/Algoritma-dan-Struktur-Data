#include <iostream>
#include <queue>

using namespace std;

int main() {
    // Deklarasi priority queue
    priority_queue<int> pq;

    // Menambahkan elemen ke priority queue
    pq.push(5);
    pq.push(3);
    pq.push(8);
    pq.push(1);
    pq.push(9);

    // Menampilkan elemen priority queue
    cout << "Priority Queue: ";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    return 0;
}